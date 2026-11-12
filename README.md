<div align="center">

# Polysim Grip G1

**An open, 3D-printable flight simulator joystick grip with a thumb stick, a side button and an I2C interface.**

[![Printables](https://img.shields.io/badge/Printables-Download-FA6831?style=for-the-badge&logo=printables&logoColor=white)](https://www.printables.com/model/1278269-3d-printable-flight-simulator-joystick-grip)
[![Thingiverse](https://img.shields.io/badge/Thingiverse-Download-248BFB?style=for-the-badge&logo=thingiverse&logoColor=white)](https://www.thingiverse.com/thing:6879827)
[![MakerWorld](https://img.shields.io/badge/MakerWorld-Coming%20soon-9E9E9E?style=for-the-badge&logo=bambulab&logoColor=white)](#-download)
[![Kit](https://img.shields.io/badge/Polysim%20Shop-Get%20the%20kit-111111?style=for-the-badge&logo=shopify&logoColor=white)](https://polysim.fr/products/polysim-grip-3d-printable-kit)

[![License: Sustainable Use](https://img.shields.io/badge/License-Sustainable%20Use%201.0-blue.svg)](LICENSE.md)
![CAD: STEP AP214](https://img.shields.io/badge/CAD-STEP%20AP214-informational)
![Firmware: Arduino](https://img.shields.io/badge/Firmware-Arduino-00979D?logo=arduino&logoColor=white)

<img src="docs/images/grip-g1.png" alt="Polysim Grip G1 – CAD render" width="420">

</div>

---

## 🎯 Overview

A 3D-printable flight sim joystick grip with an **analog thumb stick** (X/Y + click) and a **side button**.
An onboard Arduino-compatible microcontroller sends the inputs to the joystick base over **I2C**
(address `0x55`). A knurled ring locks the grip onto the base.

This repository contains the CAD files (STL + STEP), the firmware and the technical docs.

## 📥 Download

| Platform | Status | Link |
|---|---|---|
| **Printables** | ✅ Available | [3D printable flight simulator joystick grip](https://www.printables.com/model/1278269-3d-printable-flight-simulator-joystick-grip) |
| **Thingiverse** | ✅ Available | [thing:6879827](https://www.thingiverse.com/thing:6879827) |
| **MakerWorld** | 🕒 Coming soon | — |

The CAD files are also in this repository:

| Folder | Content |
|---|---|
| [`cad/stl/`](cad/stl) | One STL per printable part (mm, assembly orientation: rotate each part flat in your slicer) |
| [`cad/step/`](cad/step) | Full assembly as STEP, including the PCB and electronic components |
| [`cad/3mf/`](cad/3mf) | Ready-to-print plates (coming soon) |

## 🔧 Hardware

### 🛒 Get the kit

The easiest way to build the grip is the
**[Polysim Grip – 3D printable kit](https://polysim.fr/products/polysim-grip-3d-printable-kit)**
from the Polysim shop, with the main button and the thumb stick. Print the parts, then assemble them with the kit.

### How it connects

<p align="center">
  <img src="docs/images/wiring.svg" alt="Connection diagram: thumb stick and side button wired to the grip PCB (ATmega328P), which talks to the joystick base over a 4-wire I2C cable" width="860">
</p>

More details are in [docs/hardware.md](docs/hardware.md).

## 💾 Firmware

The firmware runs on the **ATmega328P** of the grip PCB. It only uses the built-in `Wire` library,
so there is nothing to install. The grip PCB has **no USB port**: you program it through its
**ICSP header (J1, 2×3 pins)** with an ISP programmer (a USBasp, or a spare Arduino flashed with *Arduino as ISP*).

### Upload with the Arduino IDE

1. **Install the Arduino IDE** (2.x) from [arduino.cc/en/software](https://www.arduino.cc/en/software).
2. **Download this repository** (*Code → Download ZIP*) and unzip it.
3. In the IDE, open **File → Open…** and select `firmware/polysim_grip/polysim_grip.ino`.
4. Select **Tools → Board → Arduino AVR Boards → Arduino Nano** (ATmega328P).
5. Select your programmer in **Tools → Programmer**: **USBasp**, or **Arduino as ISP**.
6. Connect the programmer to the **ICSP header J1** of the grip PCB. Pin 1 is MISO; match it with the programmer cable.
7. Click **Sketch → Upload Using Programmer** (`Ctrl+Shift+U`). Wait until the IDE says *Done uploading*.
8. Unplug the programmer and connect the grip to the base. The **status LED lights up**: the grip is ready.

> ⚠️ **Do not click *Tools → Burn Bootloader*.** It rewrites the chip's clock fuses and can make the grip PCB stop responding.

> **Prototyping on a regular Arduino Nano?** Plug it in with USB, pick its port in **Tools → Port**,
> then click **Upload** (➜). If it fails on a clone, set **Tools → Processor → ATmega328P (Old Bootloader)**.

## 🔌 I2C protocol

The joystick base (I2C master) writes a register number, then reads the value:

| Register | Value | Size | Format |
|---|---|---|---|
| `0x01` | Side button | 1 byte | `≈0xFF` released, `≈0x00` pressed |
| `0x02` | Thumb stick click | 1 byte | `≈0xFF` released, `≈0x00` pressed |
| `0x03` | X axis | 2 bytes | Big-endian, `0`–`1023` |
| `0x04` | Y axis | 2 bytes | Big-endian, `0`–`1023` |

The full specification and a master-side Arduino example are in [docs/i2c-protocol.md](docs/i2c-protocol.md).

## 📄 License

Released under the [Sustainable Use License 1.0](LICENSE.md):

- ✅ Personal, non-commercial and internal use, modification and free redistribution.
- ❌ Commercial use (for example selling printed grips or kits) is not permitted.

Redistributed copies must include the license, and modified copies must say they were modified.
