To build AVRISP-MKII:

make clean && make MCU=atmega32u2 F_CPU=16000000 BOARD=SOMAKEITU2 && avrdude -c avr109 -p m32u2 -P /dev/tty.usbmodemfa121 -U flash:w:AVRISP-MKII.hex

To build BootloaderCDC:

make clean && make MCU=atmega32u2 F_CPU=16000000 BOARD=SOMAKEITU2 FLASH_SIZE_KB=32 BOOT_SECTION_SIZE_KB=4 && avrdude -c avrisp2 -p m32u2 -P usb -e -U flash:w:BootloaderCDC.hex