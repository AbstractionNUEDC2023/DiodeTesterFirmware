# What's this?
This repository stores Diode tester project's firmware source code for NUEDC traning homework.
# Developing On Linux
## Using GNU Make + arm-none-eabi-gcc
This is the way I use.
### Install Development Environment
In order to compile this project, you need:
1. make
2. arm-none-eabi-gcc

You can install it on Ubuntu by running
```
sudo apt-get update
sudo apt-get install make arm-none-eabi-gcc
```
### Compile
Compiling this project is very simple.You only need to run this:
```
make -j
```
## Using Segger Embedded Studio
Just open Segger Embedded Studio Project On SeggerEmbeddedStudio Folder and happy coding :)  
(This has been tested)
# Developing On Windows
On windows you can use either make + arm-none-eabi-gcc or MDK-ARM, Segger Embedded Studio and IAR.Just open right project and happy coding :)  
(Only Segger Embedded Studio tested)

# Hardware Usage

## Oscillscope Mode And VI Curve Ploting Mode
By default, this firmware starting at Oscilloscope Mode.You can change into VI Curve Ploting Mode by push K1 on the stm32 board.Notice that you must stop the Oscilloscope before changing the mode.Because that if don't stop the Oscilloscope and change the mode may cause oscilloscope curve lays above the VI curve.
## Start and Stop
On Oscilloscope Mode, this firmware will run all the time by default.You can stop it by pushing K0 on the stm32 board.And on VI Curve Plotting Mode this firmware will run a VI curve scan and then stop.You can also push K0 on the stm32 board to restart another VI curve scan.
# Hardware
This particular project needs to build a specific circuit.Which is a V-I transformer.My solution just like this:  
![SCH](./Sch.png)

# Known issues

1. V-I Converter has no output clamping, which may cause circuit outputing a dangerous high voltage that will destroy internal adc of stm32
2. Key scan has serious problems that long push will be recgonize as multiple pushes.