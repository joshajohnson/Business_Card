EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:business_card
LIBS:business_card_board-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "PCB Business Card"
Date "2018-06-22"
Rev "1.0"
Comp "Josh Johnson"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PIC12F1822 U1
U 1 1 5B2C9C1F
P 5700 2950
F 0 "U1" H 5700 3250 60  0000 C CNN
F 1 "PIC12F1822" H 5700 2650 60  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 5700 2950 60  0001 C CNN
F 3 "" H 5700 2950 60  0001 C CNN
	1    5700 2950
	1    0    0    -1  
$EndComp
Text GLabel 5050 2900 0    60   Input ~ 0
RA5
Text GLabel 6350 3600 0    60   Input ~ 0
RA5
$Comp
L LED D1
U 1 1 5B2C9CE5
P 7650 2850
F 0 "D1" H 7650 2950 50  0000 C CNN
F 1 "LED" H 7650 2750 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 7650 2850 50  0001 C CNN
F 3 "" H 7650 2850 50  0001 C CNN
	1    7650 2850
	0    -1   -1   0   
$EndComp
$Comp
L LED D2
U 1 1 5B2C9D3E
P 7950 2850
F 0 "D2" H 7950 2950 50  0000 C CNN
F 1 "LED" H 7950 2750 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 7950 2850 50  0001 C CNN
F 3 "" H 7950 2850 50  0001 C CNN
	1    7950 2850
	0    1    1    0   
$EndComp
$Comp
L LED D3
U 1 1 5B2C9DDC
P 8100 3150
F 0 "D3" H 8100 3250 50  0000 C CNN
F 1 "LED" H 8100 3050 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 8100 3150 50  0001 C CNN
F 3 "" H 8100 3150 50  0001 C CNN
	1    8100 3150
	0    -1   -1   0   
$EndComp
$Comp
L LED D4
U 1 1 5B2C9DE2
P 8400 3150
F 0 "D4" H 8400 3250 50  0000 C CNN
F 1 "LED" H 8400 3050 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 8400 3150 50  0001 C CNN
F 3 "" H 8400 3150 50  0001 C CNN
	1    8400 3150
	0    1    1    0   
$EndComp
$Comp
L LED D5
U 1 1 5B2C9E39
P 8550 3450
F 0 "D5" H 8550 3550 50  0000 C CNN
F 1 "LED" H 8550 3350 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 8550 3450 50  0001 C CNN
F 3 "" H 8550 3450 50  0001 C CNN
	1    8550 3450
	0    -1   -1   0   
$EndComp
$Comp
L LED D6
U 1 1 5B2C9E3F
P 8850 3450
F 0 "D6" H 8850 3550 50  0000 C CNN
F 1 "LED" H 8850 3350 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 8850 3450 50  0001 C CNN
F 3 "" H 8850 3450 50  0001 C CNN
	1    8850 3450
	0    1    1    0   
$EndComp
$Comp
L LED D7
U 1 1 5B2C9EC1
P 9200 3300
F 0 "D7" H 9200 3400 50  0000 C CNN
F 1 "LED" H 9200 3200 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 9200 3300 50  0001 C CNN
F 3 "" H 9200 3300 50  0001 C CNN
	1    9200 3300
	0    -1   -1   0   
$EndComp
$Comp
L LED D8
U 1 1 5B2C9EC7
P 9500 3300
F 0 "D8" H 9500 3400 50  0000 C CNN
F 1 "LED" H 9500 3200 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 9500 3300 50  0001 C CNN
F 3 "" H 9500 3300 50  0001 C CNN
	1    9500 3300
	0    1    1    0   
$EndComp
$Comp
L LED D9
U 1 1 5B2CA239
P 9850 3150
F 0 "D9" H 9850 3250 50  0000 C CNN
F 1 "LED" H 9850 3050 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 9850 3150 50  0001 C CNN
F 3 "" H 9850 3150 50  0001 C CNN
	1    9850 3150
	0    -1   -1   0   
$EndComp
$Comp
L LED D10
U 1 1 5B2CA23F
P 10150 2850
F 0 "D10" H 10150 2950 50  0000 C CNN
F 1 "LED" H 10150 2750 50  0000 C CNN
F 2 "business_card_footprints:LED_1206_NO_REFDES" H 10150 2850 50  0001 C CNN
F 3 "" H 10150 2850 50  0001 C CNN
	1    10150 2850
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5B2CAC73
P 7300 3600
F 0 "R6" V 7380 3600 50  0000 C CNN
F 1 "50R" V 7300 3600 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7230 3600 50  0001 C CNN
F 3 "" H 7300 3600 50  0001 C CNN
	1    7300 3600
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5B2CACB4
P 7300 3300
F 0 "R5" V 7380 3300 50  0000 C CNN
F 1 "50R" V 7300 3300 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7230 3300 50  0001 C CNN
F 3 "" H 7300 3300 50  0001 C CNN
	1    7300 3300
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5B2CAEA1
P 7300 3000
F 0 "R4" V 7380 3000 50  0000 C CNN
F 1 "50R" V 7300 3000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7230 3000 50  0001 C CNN
F 3 "" H 7300 3000 50  0001 C CNN
	1    7300 3000
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5B2CAF0D
P 7300 2700
F 0 "R3" V 7380 2700 50  0000 C CNN
F 1 "50R" V 7300 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 7230 2700 50  0001 C CNN
F 3 "" H 7300 2700 50  0001 C CNN
	1    7300 2700
	0    1    1    0   
$EndComp
$Comp
L GND #PWR01
U 1 1 5B2CB546
P 6900 2700
F 0 "#PWR01" H 6900 2450 50  0001 C CNN
F 1 "GND" H 6900 2550 50  0000 C CNN
F 2 "" H 6900 2700 50  0001 C CNN
F 3 "" H 6900 2700 50  0001 C CNN
	1    6900 2700
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW2
U 1 1 5B2CB81A
P 3700 3350
F 0 "SW2" H 3750 3450 50  0000 L CNN
F 1 "SW_Push" H 3700 3290 50  0000 C CNN
F 2 "business_card_footprints:KSEK43GLFS_NoREFDES" H 3700 3550 50  0001 C CNN
F 3 "" H 3700 3550 50  0001 C CNN
	1    3700 3350
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW1
U 1 1 5B2CB897
P 3700 3000
F 0 "SW1" H 3750 3100 50  0000 L CNN
F 1 "SW_Push" H 3700 2940 50  0000 C CNN
F 2 "business_card_footprints:KSEK43GLFS_NoREFDES" H 3700 3200 50  0001 C CNN
F 3 "" H 3700 3200 50  0001 C CNN
	1    3700 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5B2CB9B1
P 3500 3500
F 0 "#PWR02" H 3500 3250 50  0001 C CNN
F 1 "GND" H 3500 3350 50  0000 C CNN
F 2 "" H 3500 3500 50  0001 C CNN
F 3 "" H 3500 3500 50  0001 C CNN
	1    3500 3500
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5B2CBA2F
P 4050 2700
F 0 "R1" V 4130 2700 50  0000 C CNN
F 1 "10k" V 4050 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 3980 2700 50  0001 C CNN
F 3 "" H 4050 2700 50  0001 C CNN
	1    4050 2700
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR03
U 1 1 5B2CBE48
P 5050 2650
F 0 "#PWR03" H 5050 2500 50  0001 C CNN
F 1 "VCC" H 5050 2800 50  0000 C CNN
F 2 "" H 5050 2650 50  0001 C CNN
F 3 "" H 5050 2650 50  0001 C CNN
	1    5050 2650
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR04
U 1 1 5B2CC306
P 4150 2550
F 0 "#PWR04" H 4150 2400 50  0001 C CNN
F 1 "VCC" H 4150 2700 50  0000 C CNN
F 2 "" H 4150 2550 50  0001 C CNN
F 3 "" H 4150 2550 50  0001 C CNN
	1    4150 2550
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR05
U 1 1 5B2CCCEA
P 6850 1350
F 0 "#PWR05" H 6850 1200 50  0001 C CNN
F 1 "VCC" H 6850 1500 50  0000 C CNN
F 2 "" H 6850 1350 50  0001 C CNN
F 3 "" H 6850 1350 50  0001 C CNN
	1    6850 1350
	1    0    0    -1  
$EndComp
$Comp
L Battery_Cell BT1
U 1 1 5B2CCD83
P 6850 1550
F 0 "BT1" H 6950 1650 50  0000 L CNN
F 1 "Battery_Cell" H 6950 1550 50  0000 L CNN
F 2 "" V 6850 1610 50  0001 C CNN
F 3 "" V 6850 1610 50  0001 C CNN
	1    6850 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 5B2CCDCC
P 6850 1650
F 0 "#PWR06" H 6850 1400 50  0001 C CNN
F 1 "GND" H 6850 1500 50  0000 C CNN
F 2 "" H 6850 1650 50  0001 C CNN
F 3 "" H 6850 1650 50  0001 C CNN
	1    6850 1650
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR07
U 1 1 5B2CD45F
P 6350 1350
F 0 "#PWR07" H 6350 1200 50  0001 C CNN
F 1 "VCC" H 6350 1500 50  0000 C CNN
F 2 "" H 6350 1350 50  0001 C CNN
F 3 "" H 6350 1350 50  0001 C CNN
	1    6350 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 5B2CD4A6
P 6350 1650
F 0 "#PWR08" H 6350 1400 50  0001 C CNN
F 1 "GND" H 6350 1500 50  0000 C CNN
F 2 "" H 6350 1650 50  0001 C CNN
F 3 "" H 6350 1650 50  0001 C CNN
	1    6350 1650
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5B2CD517
P 6350 1500
F 0 "C1" H 6375 1600 50  0000 L CNN
F 1 "0.1u" H 6375 1400 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6388 1350 50  0001 C CNN
F 3 "" H 6350 1500 50  0001 C CNN
	1    6350 1500
	1    0    0    -1  
$EndComp
$Comp
L PICKit3_Programmer J1
U 1 1 5B2CDB28
P 5450 1500
F 0 "J1" H 5450 1850 60  0000 C CNN
F 1 "PICKit3_Programmer" H 5450 1150 60  0000 C CNN
F 2 "business_card_footprints:Pin_Header_Straight_1x06_Pitch2.54mm_SMD" H 5300 1600 60  0001 C CNN
F 3 "" H 5300 1600 60  0001 C CNN
	1    5450 1500
	1    0    0    -1  
$EndComp
Text GLabel 4950 1250 0    60   Input ~ 0
VPP/~MCLR
Text GLabel 4950 3100 0    60   Input ~ 0
VPP/~MCLR
$Comp
L R R2
U 1 1 5B2CE6AD
P 4250 2700
F 0 "R2" V 4330 2700 50  0000 C CNN
F 1 "10k" V 4250 2700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 4180 2700 50  0001 C CNN
F 3 "" H 4250 2700 50  0001 C CNN
	1    4250 2700
	1    0    0    -1  
$EndComp
NoConn ~ 5050 1750
Text GLabel 4950 1550 0    60   Input ~ 0
ICSPDAT
Text GLabel 4950 1700 0    60   Input ~ 0
ICSPCLK
Text GLabel 6350 2550 1    60   Input ~ 0
ICSPDAT
Text GLabel 6500 2550 1    60   Input ~ 0
ICSPCLK
$Comp
L GND #PWR09
U 1 1 5B2D092D
P 4300 1550
F 0 "#PWR09" H 4300 1300 50  0001 C CNN
F 1 "GND" H 4300 1400 50  0000 C CNN
F 2 "" H 4300 1550 50  0001 C CNN
F 3 "" H 4300 1550 50  0001 C CNN
	1    4300 1550
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR010
U 1 1 5B2D0A4F
P 4300 1200
F 0 "#PWR010" H 4300 1050 50  0001 C CNN
F 1 "VCC" H 4300 1350 50  0000 C CNN
F 2 "" H 4300 1200 50  0001 C CNN
F 3 "" H 4300 1200 50  0001 C CNN
	1    4300 1200
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5B2D0CEC
P 10150 3150
F 0 "R8" V 10230 3150 50  0000 C CNN
F 1 "50R" V 10150 3150 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 10080 3150 50  0001 C CNN
F 3 "" H 10150 3150 50  0001 C CNN
	1    10150 3150
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5B2D0DF2
P 9850 2850
F 0 "R7" V 9930 2850 50  0000 C CNN
F 1 "50R" V 9850 2850 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 9780 2850 50  0001 C CNN
F 3 "" H 9850 2850 50  0001 C CNN
	1    9850 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 3600 9200 3450
Connection ~ 9200 3600
Wire Wire Line
	9500 3600 9500 3450
Connection ~ 9500 3600
Wire Wire Line
	9500 3000 9500 3150
Connection ~ 9500 3000
Wire Wire Line
	9200 3000 9200 3150
Connection ~ 9200 3000
Connection ~ 10150 2700
Connection ~ 9850 2700
Connection ~ 10150 3300
Connection ~ 9850 3300
Connection ~ 8850 3600
Connection ~ 8550 3600
Connection ~ 8550 3300
Connection ~ 8850 3300
Connection ~ 8400 3300
Connection ~ 8100 3300
Connection ~ 8100 3000
Connection ~ 8400 3000
Connection ~ 7950 2700
Connection ~ 7950 3000
Connection ~ 7650 3000
Connection ~ 7650 2700
Wire Wire Line
	7450 2700 10150 2700
Wire Wire Line
	5050 2650 5050 2800
Wire Wire Line
	6350 3600 7150 3600
Wire Wire Line
	6350 3100 6450 3100
Wire Wire Line
	6450 3100 6450 3300
Wire Wire Line
	6450 3300 7150 3300
Wire Wire Line
	6350 3000 7150 3000
Wire Wire Line
	7450 3000 9500 3000
Wire Wire Line
	7450 3600 9500 3600
Wire Wire Line
	7450 3300 10150 3300
Wire Wire Line
	6350 2900 7150 2900
Wire Wire Line
	7150 2900 7150 2700
Connection ~ 3500 3350
Wire Wire Line
	3900 3000 5050 3000
Connection ~ 4050 3000
Wire Wire Line
	3500 3000 3500 3500
Wire Wire Line
	4050 2850 4050 3000
Wire Wire Line
	3900 3350 5050 3350
Connection ~ 4250 3350
Wire Wire Line
	5050 1350 4300 1350
Wire Wire Line
	5050 1450 4300 1450
Wire Wire Line
	5050 1250 4950 1250
Wire Wire Line
	5050 1550 4950 1550
Wire Wire Line
	5050 1650 4950 1650
Wire Wire Line
	4950 1650 4950 1700
Wire Wire Line
	6350 2800 6650 2800
Wire Wire Line
	6350 2550 6350 2900
Connection ~ 6350 2900
Wire Wire Line
	6500 2550 6500 3000
Connection ~ 6500 3000
Wire Wire Line
	6650 2800 6650 2700
Wire Wire Line
	6650 2700 6900 2700
Wire Wire Line
	5050 3100 4950 3100
Wire Wire Line
	5050 3350 5050 3100
Wire Wire Line
	4250 2850 4250 3350
Wire Wire Line
	4050 2550 4250 2550
Connection ~ 4150 2550
Wire Wire Line
	4300 1450 4300 1550
Wire Wire Line
	4300 1350 4300 1200
$EndSCHEMATC