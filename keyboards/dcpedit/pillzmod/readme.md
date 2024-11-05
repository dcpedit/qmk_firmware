# Pillz Mod

Pillz Mod is a replacement PCB for the Kinesis Advantage/Contoured keyboard

* Keyboard Maintainer: [dcpedit](https://github.com/dcpedit)
* Hardware Supported: Blackpill STM32F411, Pro Micro, Elite-Pi
* Hardware Availability: https://github.com/dcpedit/pillzmod

Make example for this keyboard (after setting up your build environment):

    make dcpedit/pillzmod:default

Make example for Elite-Pi

    make dcpedit/pillzmod/rp2040:default

Make example for blackpill

    make dcpedit/pillzmod/blackpill:default

Flashing example for this keyboard:

    make dcpedit/pillzmod/standard:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: On the PCB, hold down reset while plugging in (Pro-Micro) or double-tap reset (rp2040)
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
