EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Cooler Controller for Switch"
Date "2020-06-20"
Rev "1"
Comp "Carlos Pantelides"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L coolercontroller-rescue:ATMEGA328-P-coolercontroller-rescue IC1
U 1 1 5EEE3DB4
P 5050 4250
F 0 "IC1" H 4300 5500 50  0000 L BNN
F 1 "ATMEGA328-P" H 5450 2850 50  0000 L BNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 5050 4250 50  0001 C CIN
F 3 "" H 5050 4250 50  0000 C CNN
	1    5050 4250
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:D-coolercontroller-rescue D3
U 1 1 5EEE3F39
P 8100 2650
F 0 "D3" H 8100 2750 50  0000 C CNN
F 1 "D" H 8100 2550 50  0000 C CNN
F 2 "Diode_THT:D_5W_P12.70mm_Horizontal" H 8100 2650 50  0001 C CNN
F 3 "" H 8100 2650 50  0000 C CNN
	1    8100 2650
	0    1    1    0   
$EndComp
$Comp
L coolercontroller-rescue:D-coolercontroller-rescue D4
U 1 1 5EEE40DE
P 8100 3750
F 0 "D4" H 8100 3850 50  0000 C CNN
F 1 "D" H 8100 3650 50  0000 C CNN
F 2 "Diode_THT:D_5W_P12.70mm_Horizontal" H 8100 3750 50  0001 C CNN
F 3 "" H 8100 3750 50  0000 C CNN
	1    8100 3750
	0    1    1    0   
$EndComp
$Comp
L coolercontroller-rescue:D-coolercontroller-rescue D2
U 1 1 5EEE4175
P 8100 1550
F 0 "D2" H 8100 1650 50  0000 C CNN
F 1 "D" H 8100 1450 50  0000 C CNN
F 2 "Diode_THT:D_5W_P12.70mm_Horizontal" H 8100 1550 50  0001 C CNN
F 3 "" H 8100 1550 50  0000 C CNN
	1    8100 1550
	0    1    1    0   
$EndComp
$Comp
L coolercontroller-rescue:CONN_01X04-coolercontroller-rescue P1
U 1 1 5EEE435B
P 2450 4350
F 0 "P1" H 2450 4600 50  0000 C CNN
F 1 "POWER" V 2550 4350 50  0000 C CNN
F 2 "Connector_Molex:Molex_SPOX_5268-04A_1x04_P2.50mm_Horizontal" H 2450 4350 50  0001 C CNN
F 3 "" H 2450 4350 50  0000 C CNN
	1    2450 4350
	-1   0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:CONN_01X04-coolercontroller-rescue P2
U 1 1 5EEE4495
P 6750 3200
F 0 "P2" H 6750 3450 50  0000 C CNN
F 1 "SENSORS" V 6850 3200 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 6750 3200 50  0001 C CNN
F 3 "" H 6750 3200 50  0000 C CNN
	1    6750 3200
	1    0    0    1   
$EndComp
$Comp
L coolercontroller-rescue:R-coolercontroller-rescue R3
U 1 1 5EEE44CE
P 7450 3450
F 0 "R3" V 7530 3450 50  0000 C CNN
F 1 "10K" V 7450 3450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P20.32mm_Horizontal" V 7380 3450 50  0001 C CNN
F 3 "" H 7450 3450 50  0000 C CNN
	1    7450 3450
	0    -1   -1   0   
$EndComp
$Comp
L coolercontroller-rescue:R-coolercontroller-rescue R1
U 1 1 5EEE4624
P 3300 3600
F 0 "R1" V 3380 3600 50  0000 C CNN
F 1 "2K" V 3300 3600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3230 3600 50  0001 C CNN
F 3 "" H 3300 3600 50  0000 C CNN
	1    3300 3600
	0    -1   -1   0   
$EndComp
$Comp
L coolercontroller-rescue:R-coolercontroller-rescue R2
U 1 1 5EEE5DDA
P 6800 4600
F 0 "R2" V 6880 4600 50  0000 C CNN
F 1 "10K" V 6800 4600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 6730 4600 50  0001 C CNN
F 3 "" H 6800 4600 50  0000 C CNN
	1    6800 4600
	0    -1   -1   0   
$EndComp
$Comp
L coolercontroller-rescue:CONN_01X02-coolercontroller-rescue P6
U 1 1 5EEE64F1
P 9300 3650
F 0 "P6" H 9300 3800 50  0000 C CNN
F 1 "PWM3" V 9400 3650 50  0000 C CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 9300 3650 50  0001 C CNN
F 3 "" H 9300 3650 50  0000 C CNN
	1    9300 3650
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:CONN_01X02-coolercontroller-rescue P4
U 1 1 5EEE65EE
P 9250 1450
F 0 "P4" H 9250 1600 50  0000 C CNN
F 1 "PWM1" V 9350 1450 50  0000 C CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 9250 1450 50  0001 C CNN
F 3 "" H 9250 1450 50  0000 C CNN
	1    9250 1450
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:CONN_01X02-coolercontroller-rescue P5
U 1 1 5EEE6685
P 9250 2550
F 0 "P5" H 9250 2700 50  0000 C CNN
F 1 "PWM2" V 9350 2550 50  0000 C CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Vertical" H 9250 2550 50  0001 C CNN
F 3 "" H 9250 2550 50  0000 C CNN
	1    9250 2550
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:LED-coolercontroller-rescue D1
U 1 1 5EEE66E5
P 2750 3600
F 0 "D1" H 2750 3700 50  0000 C CNN
F 1 "LED" H 2750 3500 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2750 3600 50  0001 C CNN
F 3 "" H 2750 3600 50  0000 C CNN
	1    2750 3600
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR02
U 1 1 5EEE70D6
P 6950 4050
F 0 "#PWR02" H 6950 3800 50  0001 C CNN
F 1 "GND" H 6950 3900 50  0000 C CNN
F 2 "" H 6950 4050 50  0000 C CNN
F 3 "" H 6950 4050 50  0000 C CNN
	1    6950 4050
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR03
U 1 1 5EEEAACC
P 3600 3650
F 0 "#PWR03" H 3600 3400 50  0001 C CNN
F 1 "GND" H 3600 3500 50  0000 C CNN
F 2 "" H 3600 3650 50  0000 C CNN
F 3 "" H 3600 3650 50  0000 C CNN
	1    3600 3650
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR04
U 1 1 5EEEB9C5
P 3950 5600
F 0 "#PWR04" H 3950 5350 50  0001 C CNN
F 1 "GND" H 3950 5450 50  0000 C CNN
F 2 "" H 3950 5600 50  0000 C CNN
F 3 "" H 3950 5600 50  0000 C CNN
	1    3950 5600
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:PWR_FLAG-coolercontroller-rescue #FLG05
U 1 1 5EEEC8A2
P 2500 6000
F 0 "#FLG05" H 2500 6095 50  0001 C CNN
F 1 "PWR_FLAG" H 2500 6180 50  0000 C CNN
F 2 "" H 2500 6000 50  0000 C CNN
F 3 "" H 2500 6000 50  0000 C CNN
	1    2500 6000
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:VCC-coolercontroller-rescue #PWR06
U 1 1 5EEECF1C
P 3050 4200
F 0 "#PWR06" H 3050 4050 50  0001 C CNN
F 1 "VCC" H 3050 4350 50  0000 C CNN
F 2 "" H 3050 4200 50  0000 C CNN
F 3 "" H 3050 4200 50  0000 C CNN
	1    3050 4200
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:VCC-coolercontroller-rescue #PWR07
U 1 1 5EEED640
P 3900 3050
F 0 "#PWR07" H 3900 2900 50  0001 C CNN
F 1 "VCC" H 3900 3200 50  0000 C CNN
F 2 "" H 3900 3050 50  0000 C CNN
F 3 "" H 3900 3050 50  0000 C CNN
	1    3900 3050
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:VCC-coolercontroller-rescue #PWR08
U 1 1 5EEED68A
P 2100 3600
F 0 "#PWR08" H 2100 3450 50  0001 C CNN
F 1 "VCC" H 2100 3750 50  0000 C CNN
F 2 "" H 2100 3600 50  0000 C CNN
F 3 "" H 2100 3600 50  0000 C CNN
	1    2100 3600
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:VCC-coolercontroller-rescue #PWR09
U 1 1 5EEED8CC
P 7250 4600
F 0 "#PWR09" H 7250 4450 50  0001 C CNN
F 1 "VCC" H 7250 4750 50  0000 C CNN
F 2 "" H 7250 4600 50  0000 C CNN
F 3 "" H 7250 4600 50  0000 C CNN
	1    7250 4600
	1    0    0    -1  
$EndComp
NoConn ~ 4150 3450
NoConn ~ 4150 3750
$Comp
L coolercontroller-rescue:PWR_FLAG-coolercontroller-rescue #FLG011
U 1 1 5EEF0619
P 2500 5550
F 0 "#FLG011" H 2500 5645 50  0001 C CNN
F 1 "PWR_FLAG" H 2500 5730 50  0000 C CNN
F 2 "" H 2500 5550 50  0000 C CNN
F 3 "" H 2500 5550 50  0000 C CNN
	1    2500 5550
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR012
U 1 1 5EEF06A2
P 3050 4300
F 0 "#PWR012" H 3050 4050 50  0001 C CNN
F 1 "GND" H 3050 4150 50  0000 C CNN
F 2 "" H 3050 4300 50  0000 C CNN
F 3 "" H 3050 4300 50  0000 C CNN
	1    3050 4300
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:+12V-coolercontroller-rescue #PWR013
U 1 1 5EEF13CF
P 3300 4500
F 0 "#PWR013" H 3300 4350 50  0001 C CNN
F 1 "+12V" H 3300 4640 50  0000 C CNN
F 2 "" H 3300 4500 50  0000 C CNN
F 3 "" H 3300 4500 50  0000 C CNN
	1    3300 4500
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:VCC-coolercontroller-rescue #PWR014
U 1 1 5EEF50A5
P 6650 3700
F 0 "#PWR014" H 6650 3550 50  0001 C CNN
F 1 "VCC" H 6650 3850 50  0000 C CNN
F 2 "" H 6650 3700 50  0000 C CNN
F 3 "" H 6650 3700 50  0000 C CNN
	1    6650 3700
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR015
U 1 1 5EEF50EF
P 6300 2900
F 0 "#PWR015" H 6300 2650 50  0001 C CNN
F 1 "GND" H 6300 2750 50  0000 C CNN
F 2 "" H 6300 2900 50  0000 C CNN
F 3 "" H 6300 2900 50  0000 C CNN
	1    6300 2900
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR016
U 1 1 5EEF5568
P 8100 2250
F 0 "#PWR016" H 8100 2000 50  0001 C CNN
F 1 "GND" H 8100 2100 50  0000 C CNN
F 2 "" H 8100 2250 50  0000 C CNN
F 3 "" H 8100 2250 50  0000 C CNN
	1    8100 2250
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR017
U 1 1 5EEF55B2
P 8100 3350
F 0 "#PWR017" H 8100 3100 50  0001 C CNN
F 1 "GND" H 8100 3200 50  0000 C CNN
F 2 "" H 8100 3350 50  0000 C CNN
F 3 "" H 8100 3350 50  0000 C CNN
	1    8100 3350
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR018
U 1 1 5EEF5690
P 8100 4500
F 0 "#PWR018" H 8100 4250 50  0001 C CNN
F 1 "GND" H 8100 4350 50  0000 C CNN
F 2 "" H 8100 4500 50  0000 C CNN
F 3 "" H 8100 4500 50  0000 C CNN
	1    8100 4500
	1    0    0    -1  
$EndComp
NoConn ~ 6050 3250
NoConn ~ 6050 3350
NoConn ~ 6050 3550
NoConn ~ 6050 3650
NoConn ~ 6050 3750
NoConn ~ 6050 3850
NoConn ~ 6050 4000
NoConn ~ 6050 4100
NoConn ~ 6050 4200
NoConn ~ 6050 4300
NoConn ~ 6050 4400
NoConn ~ 6050 4500
NoConn ~ 6050 4950
NoConn ~ 6050 5050
NoConn ~ 6050 5150
NoConn ~ 6050 5250
NoConn ~ 6050 5350
$Comp
L coolercontroller-rescue:+12V-coolercontroller-rescue #PWR019
U 1 1 5EEFDB98
P 8600 1150
F 0 "#PWR019" H 8600 1000 50  0001 C CNN
F 1 "+12V" H 8600 1290 50  0000 C CNN
F 2 "" H 8600 1150 50  0000 C CNN
F 3 "" H 8600 1150 50  0000 C CNN
	1    8600 1150
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:+12V-coolercontroller-rescue #PWR020
U 1 1 5EEFE26E
P 8600 2250
F 0 "#PWR020" H 8600 2100 50  0001 C CNN
F 1 "+12V" H 8600 2390 50  0000 C CNN
F 2 "" H 8600 2250 50  0000 C CNN
F 3 "" H 8600 2250 50  0000 C CNN
	1    8600 2250
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:+12V-coolercontroller-rescue #PWR021
U 1 1 5EEFE2D8
P 8650 3400
F 0 "#PWR021" H 8650 3250 50  0001 C CNN
F 1 "+12V" H 8650 3540 50  0000 C CNN
F 2 "" H 8650 3400 50  0000 C CNN
F 3 "" H 8650 3400 50  0000 C CNN
	1    8650 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4600 6550 4600
Wire Wire Line
	6950 4600 7250 4600
Wire Wire Line
	7700 3450 7600 3450
Wire Wire Line
	6050 4750 8950 4750
Wire Wire Line
	6050 4850 8950 4850
Wire Wire Line
	8950 4650 8950 4450
Wire Wire Line
	8950 4950 8950 5150
Wire Wire Line
	8950 5150 9550 5150
Wire Wire Line
	2950 3600 3150 3600
Wire Wire Line
	2100 3600 2550 3600
Wire Wire Line
	3900 3050 3900 3150
Wire Wire Line
	3900 3150 4150 3150
Wire Wire Line
	4150 5350 3950 5350
Wire Wire Line
	4150 5450 3950 5450
Wire Wire Line
	3950 5350 3950 5450
Wire Wire Line
	3450 3600 3600 3600
Wire Wire Line
	3600 3600 3600 3650
Wire Wire Line
	2650 4200 3050 4200
Wire Wire Line
	2650 4300 2750 4300
Wire Wire Line
	2650 4500 3300 4500
Connection ~ 7700 3450
Wire Wire Line
	7800 2000 7700 2000
Wire Wire Line
	7700 2000 7700 3100
Wire Wire Line
	7700 4200 7800 4200
Wire Wire Line
	6050 3450 7300 3450
Wire Wire Line
	6050 5450 6350 5450
Wire Wire Line
	6350 5450 6350 3250
Wire Wire Line
	6350 3250 6550 3250
Wire Wire Line
	6400 3050 6550 3050
Wire Wire Line
	6450 3700 6450 3350
Wire Wire Line
	6450 3350 6550 3350
Wire Wire Line
	8100 2200 8100 2250
Wire Wire Line
	8100 3300 8100 3350
Wire Wire Line
	8100 4400 8100 4500
Connection ~ 6550 4600
Connection ~ 3950 5450
Connection ~ 2750 4300
Wire Wire Line
	2650 4400 2750 4400
Wire Wire Line
	2750 4400 2750 4300
Connection ~ 7700 3100
Wire Wire Line
	7700 3100 7800 3100
Connection ~ 8100 2850
Connection ~ 8100 3950
Connection ~ 8100 1750
Wire Wire Line
	8100 1400 8600 1400
Wire Wire Line
	8100 1700 8100 1750
Wire Wire Line
	8100 1750 9050 1750
Wire Wire Line
	9050 1750 9050 1500
Wire Wire Line
	9050 2500 8600 2500
Wire Wire Line
	8100 2800 8100 2850
Wire Wire Line
	8100 2850 9050 2850
Wire Wire Line
	9050 2850 9050 2600
Wire Wire Line
	8100 3600 8650 3600
Wire Wire Line
	8100 3900 8100 3950
Wire Wire Line
	8100 3950 9100 3950
Wire Wire Line
	9100 3950 9100 3700
Connection ~ 8600 1400
Connection ~ 8600 2500
Connection ~ 8650 3600
Wire Wire Line
	8600 1150 8600 1400
Wire Wire Line
	8600 2250 8600 2500
Wire Wire Line
	8650 3400 8650 3600
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR022
U 1 1 5EEFE96F
P 2850 5550
F 0 "#PWR022" H 2850 5300 50  0001 C CNN
F 1 "GND" H 2850 5400 50  0000 C CNN
F 2 "" H 2850 5550 50  0000 C CNN
F 3 "" H 2850 5550 50  0000 C CNN
	1    2850 5550
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:VCC-coolercontroller-rescue #PWR023
U 1 1 5EEFE9B3
P 2850 6000
F 0 "#PWR023" H 2850 5850 50  0001 C CNN
F 1 "VCC" H 2850 6150 50  0000 C CNN
F 2 "" H 2850 6000 50  0000 C CNN
F 3 "" H 2850 6000 50  0000 C CNN
	1    2850 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 5550 2850 5550
Wire Wire Line
	2500 6000 2850 6000
$Comp
L coolercontroller-rescue:PWR_FLAG-coolercontroller-rescue #FLG024
U 1 1 5EEFEF4F
P 2500 5150
F 0 "#FLG024" H 2500 5245 50  0001 C CNN
F 1 "PWR_FLAG" H 2500 5330 50  0000 C CNN
F 2 "" H 2500 5150 50  0000 C CNN
F 3 "" H 2500 5150 50  0000 C CNN
	1    2500 5150
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:+12V-coolercontroller-rescue #PWR025
U 1 1 5EEFFB14
P 2850 5150
F 0 "#PWR025" H 2850 5000 50  0001 C CNN
F 1 "+12V" H 2850 5290 50  0000 C CNN
F 2 "" H 2850 5150 50  0000 C CNN
F 3 "" H 2850 5150 50  0000 C CNN
	1    2850 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 5150 2850 5150
Wire Wire Line
	6050 3150 6550 3150
Wire Wire Line
	7700 3450 7700 4200
Wire Wire Line
	6550 4600 6650 4600
Wire Wire Line
	3950 5450 3950 5600
Wire Wire Line
	2750 4300 3050 4300
Wire Wire Line
	7700 3100 7700 3450
Wire Wire Line
	8100 2850 8100 2900
Wire Wire Line
	8100 3950 8100 4000
Wire Wire Line
	8100 1750 8100 1800
Wire Wire Line
	8600 1400 9050 1400
Wire Wire Line
	8600 2500 8100 2500
Wire Wire Line
	8650 3600 9100 3600
$Comp
L Transistor_BJT:BC549 Q1
U 1 1 5EF114A2
P 8000 2000
F 0 "Q1" H 8191 2046 50  0000 L CNN
F 1 "BC549" H 8191 1955 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8200 1925 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 8000 2000 50  0001 L CNN
	1    8000 2000
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC549 Q2
U 1 1 5EF14101
P 8000 3100
F 0 "Q2" H 8191 3146 50  0000 L CNN
F 1 "BC549" H 8191 3055 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8200 3025 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 8000 3100 50  0001 L CNN
	1    8000 3100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC549 Q3
U 1 1 5EF14DFA
P 8000 4200
F 0 "Q3" H 8191 4246 50  0000 L CNN
F 1 "BC549" H 8191 4155 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8200 4125 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 8000 4200 50  0001 L CNN
	1    8000 4200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5EF2D9FA
P 7150 3800
F 0 "J1" H 7230 3792 50  0000 L CNN
F 1 "RESET_BUTTON" H 7230 3701 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7150 3800 50  0001 C CNN
F 3 "~" H 7150 3800 50  0001 C CNN
	1    7150 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 4600 6550 3800
Wire Wire Line
	6550 3800 6950 3800
Wire Wire Line
	6950 3900 6950 4050
Wire Wire Line
	8950 4450 9550 4450
Wire Wire Line
	9550 4450 9550 4600
Wire Wire Line
	9550 5150 9550 5050
$Comp
L coolercontroller-rescue:VCC-coolercontroller-rescue #PWR010
U 1 1 5EEED916
P 9550 5050
F 0 "#PWR010" H 9550 4900 50  0001 C CNN
F 1 "VCC" H 9550 5200 50  0000 C CNN
F 2 "" H 9550 5050 50  0000 C CNN
F 3 "" H 9550 5050 50  0000 C CNN
	1    9550 5050
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:GND-coolercontroller-rescue #PWR01
U 1 1 5EEE4DCF
P 9550 4600
F 0 "#PWR01" H 9550 4350 50  0001 C CNN
F 1 "GND" H 9550 4450 50  0000 C CNN
F 2 "" H 9550 4600 50  0000 C CNN
F 3 "" H 9550 4600 50  0000 C CNN
	1    9550 4600
	1    0    0    -1  
$EndComp
$Comp
L coolercontroller-rescue:CONN_01X04-coolercontroller-rescue P3
U 1 1 5EEE5726
P 9150 4800
F 0 "P3" H 9150 5050 50  0000 C CNN
F 1 "RS232" V 9250 4800 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 9150 4800 50  0001 C CNN
F 3 "" H 9150 4800 50  0000 C CNN
	1    9150 4800
	1    0    0    1   
$EndComp
Wire Wire Line
	6450 3700 6650 3700
Wire Wire Line
	6400 2900 6300 2900
Wire Wire Line
	6400 2900 6400 3050
$EndSCHEMATC
