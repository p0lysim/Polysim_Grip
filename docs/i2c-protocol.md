# I2C protocol

This document specifies the interface exposed by the grip firmware
([`firmware/polysim_grip/polysim_grip.ino`](../firmware/polysim_grip/polysim_grip.ino)).
It is written for people who implement the joystick base (the I2C master).

## Bus parameters

| Parameter | Value |
|---|---|
| Grip role | Slave |
| 7-bit address | **`0x55`** |
| Clock | Set by the master. 100 kHz (Arduino default) or 400 kHz |
| Pull-ups | Internal pull-ups are enabled on the grip; external pull-ups (e.g. 4.7 kΩ) are recommended |

## Transaction model

Each read takes two transactions: write the register number, then read N bytes.

```
Master: START | 0x55 + W | REG | STOP
Master: START | 0x55 + R | byte[0] … byte[N-1] | STOP
```

The selected register is kept: the master can read the same register again without rewriting it.

## Register map

| Reg. | Name | Size | Content | Values |
|---|---|---|---|---|
| `0x01` | `BTN` | 1 byte | Low 8 bits of `analogRead(A0)` | `≈0xFF` released, `≈0x00` pressed (active low) |
| `0x02` | `JOYCLIC` | 1 byte | Low 8 bits of `analogRead(A1)` | `≈0xFF` released, `≈0x00` pressed (active low) |
| `0x03` | `X` | 2 bytes | Unsigned, **big-endian** (MSB first) | `0`–`1023`, center ≈ `512` |
| `0x04` | `Y` | 2 bytes | Unsigned, **big-endian** (MSB first) | `0`–`1023`, center ≈ `512` |
| other | — | — | No data | Reads return `0x00` |

### Master-side recommendations

- **Buttons:** treat a value **below 128** as pressed. Don't compare with `0` or `255` exactly.
- **Axes:** always request **2 bytes**, then `value = (byte0 << 8) | byte1`.
- Calibration, dead zone and axis inversion are done by the master. The grip sends raw values.

## Master example (Arduino)

```cpp
#include <Wire.h>

const uint8_t GRIP_ADDR = 0x55;

uint16_t gripRead(uint8_t reg, uint8_t len) {
  Wire.beginTransmission(GRIP_ADDR);
  Wire.write(reg);
  if (Wire.endTransmission() != 0) return 0xFFFF;   // grip missing / bus error

  Wire.requestFrom(GRIP_ADDR, len);
  uint16_t v = 0;
  while (Wire.available()) v = (v << 8) | Wire.read();
  return v;
}

void setup() {
  Wire.begin();            // master
  Serial.begin(115200);
}

void loop() {
  bool     btn   = gripRead(0x01, 1) < 128;
  bool     click = gripRead(0x02, 1) < 128;
  uint16_t x     = gripRead(0x03, 2);
  uint16_t y     = gripRead(0x04, 2);

  Serial.print(btn);   Serial.print(' ');
  Serial.print(click); Serial.print(' ');
  Serial.print(x);     Serial.print(' ');
  Serial.println(y);
  delay(10);
}
```

## Timing

- The grip samples its 4 inputs continuously, about every 0.45 ms.
- A full poll (4 registers) moves about 18 bytes on the bus: about 2 ms at 100 kHz, about 0.5 ms at 400 kHz.
