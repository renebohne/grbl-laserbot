# grbl-laserbot
fork of grbl-mega RAMPS 1.4 and modified for Makeblock Laserbot with Mega Pi board


# Installation

Connect the Mega Pi
Start your Arduino IDE and open the grbl.ino file in the /Arduino subdirectory of this repostiory.
Make sure that you selected the board "Arduno/Genuino Mega or Mega 2560" in your Arduino IDE and select the serial port that connects to your Mega Pi.
Upload the sketch.

# Configuration

The following configuration is used and you can find it in the file laserbot.nc in this repository:
```
$0=10 (Step pulse time)
$1=255 (Step idle delay)
$2=0 (Step pulse invert)
$3=1 (Step direction invert)
$4=0 (Invert step enable pin)
$5=0 (Invert limit pins)
$6=0 (Invert probe pin)
$10=1 (Status report options)
$11=0.020 (Junction deviation)
$12=0.002 (Arc tolerance)
$13=0 (Report in inches)
$20=1 (Soft limits enable)
$21=0 (Hard limits enable)
$22=1 (Homing cycle enable)
$23=10 (Homing direction invert)
$24=500.000 (Homing locate feed rate)
$25=2000.000 (Homing search seek rate)
$26=250 (Homing switch debounce delay)
$27=5.000 (Homing switch pull-off distance)
$30=1000 (Maximum spindle speed)
$31=0 (Minimum spindle speed)
$32=1 (Laser-mode enable)
$100=87.580 (X-axis travel resolution)
$101=87.580 (Y-axis travel resolution)
$102=4000.000 (Z-axis travel resolution)
$110=18000.000 (X-axis maximum rate)
$111=18000.000 (Y-axis maximum rate)
$112=300.000 (Z-axis maximum rate)
$120=400.000 (X-axis acceleration)
$121=400.000 (Y-axis acceleration)
$122=0.028 (Z-axis acceleration)
$130=350.000 (X-axis maximum travel)
$131=350.000 (Y-axis maximum travel)
$132=200.000 (Z-axis maximum travel)
```

# Usage with lasergrbl

Install from http://lasergrbl.com
Select the right serial port and upload the settings from laserbot.nc from this repository.
You can now send your gcode to your laserbot. For a first test, feel free to use rectangle.gcode from this repository.
For my logic, I use the following preamble in my gcode:
```
$H
G92 X320 Y0
M5
G0 X0 Y0
G28.1
```

# Usage with Visicut

Download from http://www.visicut.org
Select example settings or keep your current settings.
More details will follow. In general, you need to use the generic grbl driver from visicut and add the following preamble:
```
$H
G92 X320 Y0
M5
G0 X0 Y0
G28.1
```
