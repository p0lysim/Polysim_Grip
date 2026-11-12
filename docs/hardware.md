# Hardware

The easiest way to build the grip is the
**[Polysim Grip – 3D printable kit](https://polysim.fr/products/polysim-grip-3d-printable-kit)**,
with the **[assembly tutorial on YouTube](https://www.youtube.com/watch?v=2aSrMxbHL8U)**.

## How it connects

<p align="center">
  <img src="images/wiring.svg" alt="Connection diagram: grip PCB to the base over a 4-wire I2C cable" width="900">
</p>

- The **thumb stick** and the **side button** go to the **grip PCB** (ATmega328P, I2C slave `0x55`).
- A **4-wire cable** (VCC, GND, SDA, SCL) leaves the grip through the bottom connector and plugs into
  **GRIP_IN** on the **Y encoder PCB**, which passes it on to the **GRIP** connector of the **base PCB**.
- The **base PCB** (ATmega32U4) also reads the X and Y encoders (`ENC_1`, `ENC_2`) and sends everything to the PC over USB.
- The grip's **ICSP header (J1)** is only used to upload the firmware.

## Parts to print

All STL files are in [`../cad/stl/`](../cad/stl). The full assembly, with the PCB, is in
[`../cad/step/grip-g1.step`](../cad/step/grip-g1.step).
