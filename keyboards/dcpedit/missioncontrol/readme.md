# M122ION CONTROL

![Mission Control](https://i.imgur.com/1ZAMhn9.jpeg)

Misson Control is a replacement PCB for the IBM Model M122 keyboard

* Keyboard Maintainer: [dcpedit](https://github.com/dcpedit)
* Hardware Supported: Blackpill STM32F411
* Hardware Availability: https://github.com/dcpedit/mission-control

Make example for this keyboard (after setting up your build environment):

    make dcpedit/missioncontrol/standard:default

Make example for LCD display support

    make dcpedit/missioncontrol/lcd:default

Flashing example for this keyboard:

    make dcpedit/missioncontrol/standard:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the left-most key on the top row and plug in the keyboard
* **Physical reset button**: On the PCB, while holding down the BOOT button, press and release the RESET button
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available