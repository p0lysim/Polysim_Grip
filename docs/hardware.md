# Hardware

## CAD file

| Property | Value |
|---|---|
| File | [`cad/grip-g1.step`](../cad/grip-g1.step) |
| Format | STEP ISO 10303-21, AP214 (`AUTOMOTIVE_DESIGN`) |
| Source | Autodesk Fusion, design revision **v91** |
| Units | Millimetres |
| Content | Exact B-rep solids (133 bodies), not meshes |

## Assembly tree

```
Grip G1                 Shell, top plate, collar, knurled locking ring
├── Button              Side push button
├── Joystick V2         Analog thumb stick (X/Y + click)
└── PCB_GRIP_V2         Grip electronics
    ├── U1, U4, U5, U7  Integrated circuits (microcontroller, power)
    ├── C1–C5, C7, C8   Capacitors
    ├── R1–R6, R14      Resistors
    ├── L1, D1          Inductor, diode (power stage)
    ├── LED1, LED4      LEDs
    ├── CN1, J1         Connectors
    └── SW1             Switch
```

## Pinout (firmware side)

| Signal | MCU pin | Mode |
|---|---|---|
| Side button | `A0` | `INPUT_PULLUP`, active low |
| Thumb stick click | `A1` | `INPUT_PULLUP`, active low |
| Thumb stick X | `A2` | Analog input |
| Thumb stick Y | `A3` | Analog input |
| Status LED | `D2` | Output, always on |
| I2C SDA | `A4` | To the base |
| I2C SCL | `A5` | To the base |

## Connection to the base

The grip screws onto the joystick base with the knurled ring. The base connects at least
**power, ground, SDA and SCL**, and reads the grip as described in [i2c-protocol.md](i2c-protocol.md).
