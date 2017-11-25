/***********************************************************************
This sketch compiles and uploads Grbl to your 328p-based Arduino! 

To use:
- First make sure you have imported Grbl source code into your Arduino
  IDE. There are details on our Github website on how to do this.

- Select your Arduino Board and Serial Port in the Tools drop-down menu.
  NOTE: Grbl only officially supports 328p-based Arduinos, like the Uno.
  Using other boards will likely not work!

- Then just click 'Upload'. That's it!

For advanced users:
  If you'd like to see what else Grbl can do, there are some additional
  options for customization and features you can enable or disable. 
  Navigate your file system to where the Arduino IDE has stored the Grbl 
  source code files, open the 'config.h' file in your favorite text 
  editor. Inside are dozens of feature descriptions and #defines. Simply
  comment or uncomment the #defines or alter their assigned values, save
  your changes, and then click 'Upload' here. 

Copyright (c) 2015 Sungeun K. Jeon
Released under the MIT-license. See license.txt for details.
***********************************************************************/

#include "grbl.h"

// Do not alter this file!

/*
 * 
$0=10
$1=255
$2=0
$3=1
$4=0
$5=0
$6=0
$10=1
$11=0.020
$12=0.002
$13=0
$20=1
$21=0
$22=1
$23=10
$24=500.000
$25=2000.000
$26=250
$27=5.000
$30=1000
$31=0
$32=1
$100=87.580
$101=87.580
$102=4000.000
$110=18000.000
$111=18000.000
$112=300.000
$120=400.000
$121=400.000
$122=0.028
$130=350.000
$131=350.000
$132=200.000

 * 
 */
