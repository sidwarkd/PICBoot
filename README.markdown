PICBoot Bootloader
==================

Under Active Devlopment
-----------------------
I'm currently developing this bootloader for the EmbeddedFun platform. It **IS NOT** in a working state yet. I will post more info as it becomes functional. The end product will be an SD card-based bootloader that will read raw hex files created in MPLAB to program the target device.

Organization of Source Files
----------------------------
The approach taken in the development of this bootloader is a modularized one. The firmware has been created by essentially gluing together different modules. Each piece of the bootloader is a module including the main application piece itself. In this manner we can move modules around between projects without having to surgically remove them from one project and painfully insert them into another. My goal is to make the modules as plug-and-play as possible. Each module has a top-level folder under the *modules* folder and is named to reflect its purpose. Under each module folder is a folder for header files and a folder for source files name *h* and *src* respectively. New modules should be added in this manner.

The *bin* folder contains the output and the *test* folder contains the MPLAB project used to build hex files for testing the bootloader operation.

