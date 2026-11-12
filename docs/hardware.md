# Hardware

Build the grip with the **[Polysim Grip kit](https://polysim.fr/products/polysim-grip-3d-printable-kit)**
and the **[assembly tutorial on YouTube](https://www.youtube.com/watch?v=2aSrMxbHL8U)**.

<p align="center">
  <img src="images/grip-exploded.gif" alt="Rotating exploded view of the Polysim Grip G1" width="260">
</p>

## How it connects

<p align="center">
  <img src="images/wiring.svg" alt="Connection diagram from the PCB renders" width="900">
</p>

| From | To | Wires |
|---|---|---|
| Thumb stick (FPC ribbon) | Grip PCB **CN1** | X · GND · SW · Y · 5V |
| Side button | Grip PCB **U7** | BTN · GND · GND · 12 V backlight |
| Grip PCB **U5** | Y encoder PCB **GRIP_IN**, through the 4-pole jack | GND · SCL · SDA · 5V |
| Y encoder PCB **U5 (GRIP OUT)** | Base PCB **GRIP** | GND · SCL · SDA · VCC |
| Y encoder PCB **U4 (ENC Y)** | Base PCB **ENC_Y** | GND · SCL · SDA · VCC |
| X encoder PCB **U2** | Base PCB **ENC_X** | GND · SCL · SDA · VCC |
| Base PCB **USB-C** | PC | USB |

- The grip PCB (ATmega328P, 16 MHz crystal) is an I2C slave at `0x55`. Pin **D2** switches on its MT3608
  boost converter, which powers the side button's **12 V backlight**.
- GRIP_IN on the Y encoder PCB is a simple pass-through to its GRIP OUT connector.
- On the base PCB, a **PCA9548A** I2C multiplexer puts the Y encoder, the X encoder and the grip on separate channels
  (0, 1 and 2) of the ATmega32U4.
- The grip's **ICSP header (J1)** is only used to upload the firmware.

## Parts to print

STL and 3MF files are in [`../cad/stl/`](../cad/stl) and [`../cad/3mf/`](../cad/3mf).
The full assembly, with the PCB, is in [`../cad/step/grip-g1.step`](../cad/step/grip-g1.step).
