PICBoot Bootloader
==================

Alpha Release
-----------------------
The PICBoot bootloader is currently in a working state and can reprogram a 
PIC18F27J53 microcontroller from a hex file on a FAT-formatted SD card. It is
definitely alpha software and has only been through a few rudimentary tests. An 
example application is included in the **example** folder that illustrates how 
to set up an application to use the bootloader.

Behavior
--------
Once programmed onto the target microcontroller the bootloader uses the state of 
a switch at startup to determine whether to enter bootload mode or run the main 
application. In bootload mode it will look for a file on the root of the 
attached SD card for a file called **platform.hex**. There is currently very 
little error checking and there is room for a lot of improvements but it is 
functional. If you have the inclination to contribute I'd certainly welcome any
enhancements to the code.

Features and Future Enhancement
-------------------------------
The current features of the PICBoot bootloader are few and far between:
*   Reads raw hex file produced by IDE.
*   Doesn't require any software or connection to a computer to program (field reprogrammable)
*   Implements a simple code protection mechanism to prevent user applications from overwriting the bootloader

Here is my current wish list for enhancements and future capabilities:
*   Implement buffered reading of hex files. Reading hex files 1 byte at a time has a major speed impact.
*   Optimize and shorten the convert\_hex\_digit function in hexreader.c
*   Implement software flag to indicate mode instead of the switch state
*   Replace Petit FatFS with FatFS to unlock more file options

