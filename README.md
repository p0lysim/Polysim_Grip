<div align="center">

# Polysim Grip G1

**An open, 3D-printable flight simulator joystick grip with a thumb stick, a side button and an I2C interface.**

[![Compatible with Polysim Base](https://img.shields.io/badge/Compatible%20with-Polysim%20Base-1f6feb?style=for-the-badge&logo=github&logoColor=white)](https://github.com/p0lysim/Polysim_Base)

[![Printables](https://img.shields.io/badge/Printables-Download-FA6831?style=for-the-badge&logo=printables&logoColor=white)](https://www.printables.com/model/1278269-3d-printable-flight-simulator-joystick-grip)
[![Thingiverse](https://img.shields.io/badge/Thingiverse-Download-248BFB?style=for-the-badge&logo=thingiverse&logoColor=white)](https://www.thingiverse.com/thing:6879827)
[![MakerWorld](https://img.shields.io/badge/MakerWorld-Coming%20soon-9E9E9E?style=for-the-badge&logo=bambulab&logoColor=white)](#-download)

[![License: Sustainable Use](https://img.shields.io/badge/License-Sustainable%20Use%201.0-blue.svg)](LICENSE.md)
![CAD: STEP AP214](https://img.shields.io/badge/CAD-STEP%20AP214-informational)
![Firmware: Arduino](https://img.shields.io/badge/Firmware-Arduino-00979D?logo=arduino&logoColor=white)

<img src="docs/images/grip-g1-cover.jpg" alt="Polysim Grip G1 – 3D-printed grip held in hand" width="720">

<a href="https://polysim.fr/products/polysim-grip-3d-printable-kit"><img src="docs/images/buy-kit.svg" alt="Buy the Polysim Grip kit on polysim.fr" width="236"></a>

</div>

---

## 🎯 Overview

A 3D-printable joystick grip with a thumb stick and a side button. It talks to the joystick base over I2C.

> 🔗 **Made for the [Polysim Base](https://github.com/p0lysim/Polysim_Base).** The grip locks onto the base with its
> knurled ring and plugs in through the 4-pole jack. The base reads it and sends everything to the PC over USB.

## 📥 Download

| Files | Folder | Printables | Thingiverse | MakerWorld |
|---|---|---|---|---|
| **STL** – one per part | [`cad/stl`](cad/stl) | [Download](https://www.printables.com/model/1278269-3d-printable-flight-simulator-joystick-grip) | [Download](https://www.thingiverse.com/thing:6879827) | 🕒 Coming soon |
| **3MF** – print plates | [`cad/3mf`](cad/3mf) | — | — | 🕒 Coming soon |
| **STEP** – full assembly with PCB | [`cad/step`](cad/step) | — | — | — |

## 🛒 Get the kit

The **[Polysim Grip kit](https://polysim.fr/products/polysim-grip-3d-printable-kit)** contains **every component
needed for the assembly**. You only have to **print the plastic parts in PLA or PETG**, then follow the assembly video.

<p align="center">
  <a href="https://polysim.fr/products/polysim-grip-3d-printable-kit"><img src="docs/images/buy-kit.svg" alt="Buy the Polysim Grip kit on polysim.fr" width="236"></a>
</p>

| Exploded view | Assembly tutorial |
|:---:|:---:|
| <img src="docs/images/grip-exploded.gif" alt="Rotating exploded view of the Polysim Grip G1" width="240"> | <a href="https://www.youtube.com/watch?v=2aSrMxbHL8U"><img src="https://img.youtube.com/vi/2aSrMxbHL8U/hqdefault.jpg" alt="Polysim grip G1 assembly tutorial" width="360"></a> |

## 🔌 How it connects

<p align="center">
  <img src="docs/images/wiring.svg" alt="Connection diagram from PCB renders: thumb stick on CN1, side button on U7, grip U5 to GRIP_IN on the Y encoder PCB, GRIP OUT to GRIP on the base PCB, X and Y encoders on ENC_X and ENC_Y, base to the PC over USB-C" width="900">
</p>

The BASE side (encoder PCBs and base PCB) belongs to the [Polysim Base](https://github.com/p0lysim/Polysim_Base) project.
More details are in [docs/hardware.md](docs/hardware.md).

## 💾 Firmware

The grip PCB has no USB port: flash it through its **ICSP header (J1)** with a USBasp or an *Arduino as ISP*.

1. In the Arduino IDE, open `firmware/polysim_grip/polysim_grip.ino`.
2. Select **Tools → Board → Arduino Nano**, then **Tools → Programmer → USBasp** (or *Arduino as ISP*).
3. Connect the programmer to J1, then click **Sketch → Upload Using Programmer**.

On a brand-new chip, run **Tools → Burn Bootloader** once first: it sets the fuses for the 16 MHz crystal.

## 📡 I2C protocol

See [docs/i2c-protocol.md](docs/i2c-protocol.md).

## 📄 License

Released under the [Sustainable Use License 1.0](LICENSE.md):

- ✅ Personal, non-commercial and internal use, modification and free redistribution.
- ❌ Commercial use (for example selling printed grips or kits) is not permitted.

Redistributed copies must include the license, and modified copies must say they were modified.
