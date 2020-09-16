-Check if device is present
setserial -g /dev/ttyACM[0123456789]

-Wipe AVR
dfu-programmer at90usb162 erase --force

-Program AVR
dfu-programmer at90usb162 flash "xxxx".hex
