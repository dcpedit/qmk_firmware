# Pillz Mod

Pillz Mod is a replacement PCB for the Kinesis Advantage/Contoured keyboard

* Keyboard Maintainer: [dcpedit](https://github.com/dcpedit)
* Hardware Supported: Blackpill STM32F411
* Hardware Availability: https://github.com/dcpedit/pillzmod

Make example for this keyboard (after setting up your build environment):

    make dcpedit/pillzmod/standard:default

Make example for LCD display support

    make dcpedit/pillzmod/lcd:default

Flashing example for this keyboard:

    make dcpedit/pillzmod/standard:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the left-most large key on the top row and plug in the keyboard
* **Physical reset button**: On the PCB, while holding down the BOOT button, press and release the RESET button
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
