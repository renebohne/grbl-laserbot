# grbl-laserbot
fork of grbl-mega RAMPS 1.4 and modified for Makeblock Laserbot with Mega Pi board


# Installation

Connect the Mega Pi
Start your Arduino IDE and open the Arduino.ino file in the /Arduino subdirectory of this repostiory.

Make sure that you selected the board "Arduno/Genuino Mega or Mega 2560" in your Arduino IDE and select the serial port that connects to your Mega Pi.

Upload the sketch.

# Configuration


The axis that carries the laser is the y-axis. The other axis is the x-axis. Make sure, that the endstop, that the x-axis runs into is connected to the first "servo port" and the endstop for the y-axis is connected to the second "servo port".


The following configuration is used and you can find it in the file laserbot.nc in this repository:
```
$0=10 (Step pulse time)
$1=255 (Step idle delay)
$2=0 (Step pulse invert)
$3=0 (Step direction invert)
$4=0 (Invert step enable pin)
$5=0 (Invert limit pins)
$6=0 (Invert probe pin)
$10=1 (Status report options)
$11=0.020 (Junction deviation)
$12=0.002 (Arc tolerance)
$13=0 (Report in inches)
$20=0 (Soft limits enable)
$21=0 (Hard limits enable)
$22=1 (Homing cycle enable)
$23=11 (Homing direction invert)
$24=500.000 (Homing locate feed rate)
$25=2000.000 (Homing search seek rate)
$26=250 (Homing switch debounce delay)
$27=5.000 (Homing switch pull-off distance)
$30=255 (Maximum spindle speed)
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
$130=360.000 (X-axis maximum travel)
$131=350.000 (Y-axis maximum travel)
$132=200.000 (Z-axis maximum travel)
```


# General notes

Max Feedrate: The laser can move up to 200mm per second = 12.000 mm per minute

Engraving area: Up to 383mm×367mm

1.6W 445nm blue-violet diode laser

MegaPi uses	DRV8825		


# Usage with lasergrbl

Install from http://lasergrbl.com

Select the right serial port and upload the settings from laserbot.nc from this repository.

You can now send your gcode to your laserbot. For a first test, feel free to use rectangle.gcode from this repository.

# Usage with Visicut

Download from http://www.visicut.org

Select example settings or keep your current settings.

More details will follow. In general, you need to use the generic grbl driver from visicut.

# LaserWeb

I tested this firmware with LaserWeb4 and it does work!
More information here: (https://github.com/LaserWeb/LaserWeb4)[https://github.com/LaserWeb/LaserWeb4]


# MegaPi Pin mapping

```									
Steppers												
 Port1			Port2			Port3			Port4		
Function Arduino Pin	Pin Name	MCU Pin#	Arduino Pin	Pin Name	MCU Pin#	Arduino Pin	Pin Name	MCU Pin#	Arduino Pin	Pin Name	MCU Pin#
Dir	D11	PB5	24	D7	PH4	16	D6	PH3	15	D4	PG5	1
Step	D12	PB6	25	D8	PH5	17	D9	PH6	18	D5	PE3	5
Sleep	D18	PD3	46	D19	PD2	45	D3	PE5	7	D2	PE4	6
Reset	D31	PC6	59	D38	PD7	80	D49	PL0	35	A1	PF1	96
MS1	D34	PC3	56	D37	PC0	53	D43	PL6	41	A4	PF4	93
MS2	D33	PC4	57	D40	PG1	52	D47	PL2	37	A3	PF3	94
MS3	D32	PC5	58	D41	PG0	51	D48	PL1	36	A2	PF2	95
Enable	D35	PC2	55	D36	PC1	54	D42	PL7	42	A5	PF5	92

Endstop X/1	A6	PF6	91									
Endstop Y/2	A7	PF7	90									
Endstop Z/3	A8	PK0	89									
Endstop E/4	A9	PK1	88									
A10	PK2	87									
A11	PK3	86									
A12	PK4	85									
A13	PK5	84									
A14	PK6	83									
A15	PK7	82									
Laser1 12V	D10	PB4	23	OC2A								
Laser2 12V	A0	PF0	97									

Header 2x2 P12												
D16	PH1	13									
D17	PH0	12									
D21	PD0	43									
D20	PD1	44									

Header 5x2 P15												
D39	PG2	70									
D29	PA7	71									
D27	PA5	73									
D25	PA3	75									
D23	PA0	77									
D30	PC7	60									
D28	PA6	72									
D26	PA4	74									
D24	PA2	76									
D22	PJ7	78									

Header 3x2 ICSP												
D52											
D50											
D51											

LED blue	D13	PB7	26									

I2C												
10k PullUp	D20	PD1	44									
10k PullUp	D21	PD0	43									

USB	UART 0	D0/D1										
Raspi	UART 2	D16/D17										
BLE	UART 3	D14/D15										
```
