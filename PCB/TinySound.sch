EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Micro_SD_Card_Det J3
U 1 1 5FCAA9C1
P 1500 3200
F 0 "J3" H 1450 4017 50  0000 C CNN
F 1 "Micro_SD_Card_Det" H 1450 3926 50  0000 C CNN
F 2 "TinySound:AMPHENOL_1140084168" H 3550 3900 50  0001 C CNN
F 3 "https://www.hirose.com/product/en/download_file/key_name/DM3/category/Catalog/doc_file_id/49662/?file_category_id=4&item_id=195&is_series=1" H 1500 3300 50  0001 C CNN
	1    1500 3200
	-1   0    0    -1  
$EndComp
$Comp
L TinySound:STM32G030KxT U2
U 1 1 5FCB3865
P 6150 2750
F 0 "U2" H 5500 1800 50  0000 C CNN
F 1 "STM32G030KxT" H 6650 1800 50  0000 C CNN
F 2 "Package_QFP:LQFP-32_7x7mm_P0.8mm" H 6800 950 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2864618.pdf" H 6850 950 50  0001 C CNN
F 4 "3246910" H 6850 950 50  0001 C CNN "Farnell"
	1    6150 2750
	1    0    0    -1  
$EndComp
$Comp
L TinySound:MAX98360xxxL+ U1
U 1 1 5FCB6021
P 9600 2700
F 0 "U1" H 9350 2250 50  0000 C CNN
F 1 "MAX98360AENL+" H 10000 2250 50  0000 C CNN
F 2 "TinySound:Maxim_WLP-9_1.595x1.415_Layout3x3_P0.4mm_Ball0.27mm_Pad0.25mm_NSMD" H 9600 1400 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX98360A-MAX98360D.pdf" H 9500 2100 50  0001 C CNN
F 4 "3288145" H 9600 1400 50  0001 C CNN "Farnell"
	1    9600 2700
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5FCB68CA
P 1650 1500
F 0 "J1" H 1568 1717 50  0000 C CNN
F 1 "Conn_01x02" H 1568 1626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1650 1500 50  0001 C CNN
F 3 "~" H 1650 1500 50  0001 C CNN
	1    1650 1500
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5FCB6E00
P 11000 2650
F 0 "J2" H 10918 2325 50  0000 C CNN
F 1 "Conn_01x02" H 10918 2416 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 11000 2650 50  0001 C CNN
F 3 "~" H 11000 2650 50  0001 C CNN
	1    11000 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 2600 10350 2600
Wire Wire Line
	10700 2600 10700 2650
Wire Wire Line
	10700 2650 10800 2650
Wire Wire Line
	10800 2750 10700 2750
Wire Wire Line
	10700 2750 10700 2800
Wire Wire Line
	10700 2800 10550 2800
Wire Wire Line
	1850 1500 2500 1500
Wire Wire Line
	2500 1500 2500 1350
Wire Wire Line
	1850 1600 2500 1600
Wire Wire Line
	2500 1600 2500 1750
$Comp
L power:+3V3 #PWR02
U 1 1 5FCBD9C1
P 2500 1350
F 0 "#PWR02" H 2500 1200 50  0001 C CNN
F 1 "+3V3" H 2515 1523 50  0000 C CNN
F 2 "" H 2500 1350 50  0001 C CNN
F 3 "" H 2500 1350 50  0001 C CNN
	1    2500 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5FCBE120
P 2500 1750
F 0 "#PWR05" H 2500 1500 50  0001 C CNN
F 1 "GND" H 2505 1577 50  0000 C CNN
F 2 "" H 2500 1750 50  0001 C CNN
F 3 "" H 2500 1750 50  0001 C CNN
	1    2500 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5FCBEC3B
P 6300 4650
F 0 "D1" H 6293 4395 50  0000 C CNN
F 1 "LED" H 6293 4486 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6300 4650 50  0001 C CNN
F 3 "~" H 6300 4650 50  0001 C CNN
	1    6300 4650
	-1   0    0    1   
$EndComp
$Comp
L Device:R R4
U 1 1 5FCBF606
P 5750 4650
F 0 "R4" V 5543 4650 50  0000 C CNN
F 1 "R" V 5634 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5680 4650 50  0001 C CNN
F 3 "~" H 5750 4650 50  0001 C CNN
	1    5750 4650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5FCBFD75
P 650 4000
F 0 "#PWR012" H 650 3750 50  0001 C CNN
F 1 "GND" H 655 3827 50  0000 C CNN
F 2 "" H 650 4000 50  0001 C CNN
F 3 "" H 650 4000 50  0001 C CNN
	1    650  4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	700  3700 650  3700
Wire Wire Line
	650  3700 650  4000
$Comp
L power:+3V3 #PWR07
U 1 1 5FCC05C7
P 3800 2300
F 0 "#PWR07" H 3800 2150 50  0001 C CNN
F 1 "+3V3" H 3815 2473 50  0000 C CNN
F 2 "" H 3800 2300 50  0001 C CNN
F 3 "" H 3800 2300 50  0001 C CNN
	1    3800 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5FCC0BD0
P 3800 3800
F 0 "#PWR010" H 3800 3550 50  0001 C CNN
F 1 "GND" H 3805 3627 50  0000 C CNN
F 2 "" H 3800 3800 50  0001 C CNN
F 3 "" H 3800 3800 50  0001 C CNN
	1    3800 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 3300 3800 3400
$Comp
L power:+3V3 #PWR01
U 1 1 5FCC1D2E
P 6150 1150
F 0 "#PWR01" H 6150 1000 50  0001 C CNN
F 1 "+3V3" H 6165 1323 50  0000 C CNN
F 2 "" H 6150 1150 50  0001 C CNN
F 3 "" H 6150 1150 50  0001 C CNN
	1    6150 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5FCC22BB
P 6150 3850
F 0 "#PWR011" H 6150 3600 50  0001 C CNN
F 1 "GND" H 6155 3677 50  0000 C CNN
F 2 "" H 6150 3850 50  0001 C CNN
F 3 "" H 6150 3850 50  0001 C CNN
	1    6150 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3750 6150 3850
Wire Wire Line
	6150 1150 6150 1200
$Comp
L power:+3V3 #PWR06
U 1 1 5FCC3350
P 9600 2100
F 0 "#PWR06" H 9600 1950 50  0001 C CNN
F 1 "+3V3" H 9615 2273 50  0000 C CNN
F 2 "" H 9600 2100 50  0001 C CNN
F 3 "" H 9600 2100 50  0001 C CNN
	1    9600 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 2100 9600 2150
$Comp
L power:GND #PWR09
U 1 1 5FCC3BFC
P 9600 3300
F 0 "#PWR09" H 9600 3050 50  0001 C CNN
F 1 "GND" H 9605 3127 50  0000 C CNN
F 2 "" H 9600 3300 50  0001 C CNN
F 3 "" H 9600 3300 50  0001 C CNN
	1    9600 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 3200 9600 3250
$Comp
L power:GND #PWR014
U 1 1 5FCC4260
P 6750 4750
F 0 "#PWR014" H 6750 4500 50  0001 C CNN
F 1 "GND" H 6755 4577 50  0000 C CNN
F 2 "" H 6750 4750 50  0001 C CNN
F 3 "" H 6750 4750 50  0001 C CNN
	1    6750 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4650 6750 4650
Wire Wire Line
	6750 4650 6750 4750
Wire Wire Line
	6150 4650 5900 4650
$Comp
L Device:C C2
U 1 1 5FCD3FFB
P 6800 1400
F 0 "C2" H 6915 1446 50  0000 L CNN
F 1 "4.7u" H 6915 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6838 1250 50  0001 C CNN
F 3 "~" H 6800 1400 50  0001 C CNN
	1    6800 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5FCD4387
P 8550 2650
F 0 "C4" H 8435 2604 50  0000 R CNN
F 1 "10u" H 8435 2695 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8588 2500 50  0001 C CNN
F 3 "~" H 8550 2650 50  0001 C CNN
	1    8550 2650
	1    0    0    1   
$EndComp
Wire Wire Line
	3800 3400 3950 3400
Wire Wire Line
	3950 3400 3950 3350
Connection ~ 3800 3400
Wire Wire Line
	3800 3400 3800 3700
Wire Wire Line
	3800 2300 3800 2350
Wire Wire Line
	3950 3050 3950 3000
Wire Wire Line
	3950 3000 3800 3000
Wire Wire Line
	3800 3000 3800 3100
Wire Wire Line
	3250 3000 2400 3000
Wire Wire Line
	3250 3200 2400 3200
Connection ~ 3800 3700
Wire Wire Line
	3800 3700 3800 3800
Wire Wire Line
	2400 3600 3250 3600
Text Label 3250 2900 2    50   ~ 0
SD_CS
Text Label 3250 3000 2    50   ~ 0
SD_MOSI
Text Label 3250 3200 2    50   ~ 0
SD_CLK
Text Label 3250 3400 2    50   ~ 0
SD_MISO
Text Label 3250 3600 2    50   ~ 0
SD_DET
Wire Wire Line
	5600 4650 5250 4650
Text Label 5250 4650 0    50   ~ 0
LED
Connection ~ 3800 2350
Wire Wire Line
	3250 2350 3250 2400
$Comp
L Device:R R1
U 1 1 5FCDC9FC
P 3250 2550
F 0 "R1" H 3180 2504 50  0000 R CNN
F 1 "10k" H 3180 2595 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3180 2550 50  0001 C CNN
F 3 "~" H 3250 2550 50  0001 C CNN
	1    3250 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	2400 2900 3250 2900
$Comp
L power:GND #PWR03
U 1 1 5FCEB40B
P 6350 1600
F 0 "#PWR03" H 6350 1350 50  0001 C CNN
F 1 "GND" H 6355 1427 50  0000 C CNN
F 2 "" H 6350 1600 50  0001 C CNN
F 3 "" H 6350 1600 50  0001 C CNN
	1    6350 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 1200 6350 1200
Wire Wire Line
	6350 1200 6350 1250
Connection ~ 6150 1200
Wire Wire Line
	6150 1200 6150 1750
Wire Wire Line
	6350 1200 6800 1200
Wire Wire Line
	6800 1200 6800 1250
Connection ~ 6350 1200
Wire Wire Line
	6350 1550 6350 1600
$Comp
L power:GND #PWR04
U 1 1 5FCEF82B
P 6800 1600
F 0 "#PWR04" H 6800 1350 50  0001 C CNN
F 1 "GND" H 6805 1427 50  0000 C CNN
F 2 "" H 6800 1600 50  0001 C CNN
F 3 "" H 6800 1600 50  0001 C CNN
	1    6800 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1600 6800 1550
Wire Wire Line
	8550 2500 8550 2400
Wire Wire Line
	8550 2150 8700 2150
Connection ~ 9600 2150
Wire Wire Line
	9600 2150 9600 2200
Wire Wire Line
	9600 3250 8550 3250
Wire Wire Line
	8550 3250 8550 2900
Connection ~ 9600 3250
Wire Wire Line
	9600 3250 9600 3300
$Comp
L Device:R R2
U 1 1 5FCF2402
P 7400 3300
F 0 "R2" H 7330 3254 50  0000 R CNN
F 1 "10k" H 7330 3345 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7330 3300 50  0001 C CNN
F 3 "~" H 7400 3300 50  0001 C CNN
	1    7400 3300
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR08
U 1 1 5FCF33C9
P 7400 3100
F 0 "#PWR08" H 7400 2950 50  0001 C CNN
F 1 "+3V3" H 7415 3273 50  0000 C CNN
F 2 "" H 7400 3100 50  0001 C CNN
F 3 "" H 7400 3100 50  0001 C CNN
	1    7400 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3100 7400 3150
Wire Wire Line
	7400 3450 7400 3500
Wire Wire Line
	7400 3500 7050 3500
Wire Wire Line
	7400 3500 7900 3500
Text Label 7900 3500 2    50   ~ 0
NRST
Text Label 2450 4750 2    50   ~ 0
NRST
$Comp
L Connector_Generic:Conn_01x02 J5
U 1 1 5FCF8687
P 1600 4950
F 0 "J5" H 1680 4942 50  0000 L CNN
F 1 "Conn_01x02" H 1680 4851 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1600 4950 50  0001 C CNN
F 3 "~" H 1600 4950 50  0001 C CNN
	1    1600 4950
	-1   0    0    -1  
$EndComp
Text Label 2450 4550 2    50   ~ 0
SWDIO
Wire Wire Line
	1800 4550 2450 4550
Wire Wire Line
	2750 4650 1800 4650
Text Label 2150 4950 2    50   ~ 0
TX
Text Label 2150 5050 2    50   ~ 0
RX
Wire Wire Line
	2150 4950 1800 4950
Wire Wire Line
	1800 5050 2150 5050
$Comp
L Device:C C3
U 1 1 5FD0449D
P 8150 2650
F 0 "C3" H 8035 2604 50  0000 R CNN
F 1 "100n" H 8035 2695 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8188 2500 50  0001 C CNN
F 3 "~" H 8150 2650 50  0001 C CNN
	1    8150 2650
	1    0    0    1   
$EndComp
Wire Wire Line
	8150 2500 8150 2400
Wire Wire Line
	8150 2400 8550 2400
Connection ~ 8550 2400
Wire Wire Line
	8550 2400 8550 2150
Wire Wire Line
	8150 2800 8150 2900
Wire Wire Line
	8150 2900 8550 2900
Connection ~ 8550 2900
Wire Wire Line
	8550 2900 8550 2800
Text Label 8750 2400 0    50   ~ 0
AU_EN
Text Label 8700 3000 0    50   ~ 0
AU_BCLK
Text Label 8700 2800 0    50   ~ 0
AU_LRCLK
Text Label 8700 2900 0    50   ~ 0
AU_DIN
Wire Wire Line
	8700 2800 9100 2800
Wire Wire Line
	9100 2900 8700 2900
Wire Wire Line
	8700 3000 9100 3000
Wire Wire Line
	8750 2400 9100 2400
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 5FD1DD1A
P 1600 4550
F 0 "J4" H 1680 4542 50  0000 L CNN
F 1 "Conn_01x04" H 1680 4451 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1600 4550 50  0001 C CNN
F 3 "~" H 1600 4550 50  0001 C CNN
	1    1600 4550
	-1   0    0    -1  
$EndComp
Text Label 4200 3400 0    50   ~ 0
SWCLK_BOOT0_WAKEUP
Wire Wire Line
	4200 3400 5100 3400
$Comp
L Device:R R3
U 1 1 5FD23182
P 5100 3800
F 0 "R3" H 5030 3754 50  0000 R CNN
F 1 "10k" H 5030 3845 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5030 3800 50  0001 C CNN
F 3 "~" H 5100 3800 50  0001 C CNN
	1    5100 3800
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5FD23433
P 5100 4050
F 0 "#PWR013" H 5100 3800 50  0001 C CNN
F 1 "GND" H 5105 3877 50  0000 C CNN
F 2 "" H 5100 4050 50  0001 C CNN
F 3 "" H 5100 4050 50  0001 C CNN
	1    5100 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4050 5100 3950
Wire Wire Line
	5100 3650 5100 3400
Connection ~ 5100 3400
Wire Wire Line
	5100 3400 5250 3400
Wire Wire Line
	5100 3400 5100 2000
Wire Wire Line
	5100 2000 5250 2000
Text Label 4650 2100 0    50   ~ 0
AU_BCLK
Text Label 4650 2200 0    50   ~ 0
AU_DIN
Text Label 4650 2400 0    50   ~ 0
AU_LRCLK
Wire Wire Line
	5250 2400 4650 2400
Wire Wire Line
	4650 2200 5250 2200
Wire Wire Line
	5250 2100 4650 2100
NoConn ~ 5250 2300
Text Label 4650 2500 0    50   ~ 0
AU_EN
Wire Wire Line
	4650 2500 5250 2500
NoConn ~ 5250 2600
NoConn ~ 5250 2700
Text Label 7450 2000 2    50   ~ 0
LED
Wire Wire Line
	7450 2000 7050 2000
NoConn ~ 7050 2100
NoConn ~ 7050 2200
NoConn ~ 5250 2800
Text Label 4650 2900 0    50   ~ 0
TX
Text Label 4650 3000 0    50   ~ 0
RX
Wire Wire Line
	4650 3000 5250 3000
Wire Wire Line
	5250 2900 4650 2900
NoConn ~ 7050 3100
NoConn ~ 7050 3200
NoConn ~ 7050 3300
NoConn ~ 7050 2900
NoConn ~ 7050 2300
NoConn ~ 5250 3100
NoConn ~ 5250 3200
Wire Wire Line
	4450 3300 5250 3300
Text Label 4450 3300 0    50   ~ 0
SWDIO
Text Label 7450 2400 2    50   ~ 0
SD_CS
Wire Wire Line
	7450 2700 7050 2700
Wire Wire Line
	7450 2800 7050 2800
Wire Wire Line
	7450 2600 7050 2600
Wire Wire Line
	7050 2500 7450 2500
Text Label 7450 2700 2    50   ~ 0
SD_MOSI
Text Label 7450 2800 2    50   ~ 0
SD_CLK
Text Label 7450 2600 2    50   ~ 0
SD_MISO
Text Label 7450 2500 2    50   ~ 0
SD_DET
Wire Wire Line
	7450 2400 7050 2400
$Comp
L Device:C C5
U 1 1 5FD9203D
P 3950 3200
F 0 "C5" H 4065 3246 50  0000 L CNN
F 1 "10u" H 4065 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3988 3050 50  0001 C CNN
F 3 "~" H 3950 3200 50  0001 C CNN
	1    3950 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5FD94C91
P 6350 1400
F 0 "C1" H 6465 1446 50  0000 L CNN
F 1 "100n" H 6465 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6388 1250 50  0001 C CNN
F 3 "~" H 6350 1400 50  0001 C CNN
	1    6350 1400
	1    0    0    -1  
$EndComp
Connection ~ 8700 2150
Wire Wire Line
	8700 2150 9600 2150
Wire Wire Line
	8700 2600 8700 2150
Wire Wire Line
	9100 2600 8700 2600
Text Label 8750 2600 0    50   ~ 0
AU_GAIN
$Comp
L TinySound:MAX98360xxxB+ U3
U 1 1 5FCCC494
P 9600 4350
F 0 "U3" H 9350 3900 50  0000 C CNN
F 1 "MAX98360xxxB+" H 10000 3900 50  0000 C CNN
F 2 "TinySound:FC2QFN-10" H 9600 3050 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX98360A-MAX98360D.pdf" H 9500 3750 50  0001 C CNN
	1    9600 4350
	1    0    0    -1  
$EndComp
Text Label 8700 4050 0    50   ~ 0
AU_EN
Text Label 8700 4650 0    50   ~ 0
AU_BCLK
Text Label 8700 4450 0    50   ~ 0
AU_LRCLK
Text Label 8700 4550 0    50   ~ 0
AU_DIN
Wire Wire Line
	8700 4450 9100 4450
Wire Wire Line
	9100 4550 8700 4550
Wire Wire Line
	8700 4650 9100 4650
Wire Wire Line
	8700 4050 9100 4050
$Comp
L power:GND #PWR0101
U 1 1 5FCDB536
P 9600 4950
F 0 "#PWR0101" H 9600 4700 50  0001 C CNN
F 1 "GND" H 9605 4777 50  0000 C CNN
F 2 "" H 9600 4950 50  0001 C CNN
F 3 "" H 9600 4950 50  0001 C CNN
	1    9600 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0102
U 1 1 5FCDB99C
P 9600 3750
F 0 "#PWR0102" H 9600 3600 50  0001 C CNN
F 1 "+3V3" H 9615 3923 50  0000 C CNN
F 2 "" H 9600 3750 50  0001 C CNN
F 3 "" H 9600 3750 50  0001 C CNN
	1    9600 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 3750 9600 3800
Wire Wire Line
	9550 4850 9550 4900
Wire Wire Line
	9550 4900 9600 4900
Wire Wire Line
	9600 4900 9600 4950
Wire Wire Line
	9600 4900 9650 4900
Wire Wire Line
	9650 4900 9650 4850
Connection ~ 9600 4900
Wire Wire Line
	10100 4250 10350 4250
Wire Wire Line
	10350 4250 10350 2600
Connection ~ 10350 2600
Wire Wire Line
	10350 2600 10700 2600
Wire Wire Line
	10100 4450 10550 4450
Wire Wire Line
	10550 4450 10550 2800
Connection ~ 10550 2800
Wire Wire Line
	10550 2800 10100 2800
$Comp
L Device:R R5
U 1 1 5FCBAC28
P 8400 4050
F 0 "R5" H 8470 4096 50  0000 L CNN
F 1 "100k" H 8470 4005 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8330 4050 50  0001 C CNN
F 3 "~" H 8400 4050 50  0001 C CNN
	1    8400 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5FCBB239
P 8400 4450
F 0 "R6" H 8470 4496 50  0000 L CNN
F 1 "100k" H 8470 4405 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8330 4450 50  0001 C CNN
F 3 "~" H 8400 4450 50  0001 C CNN
	1    8400 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 4600 8400 4900
Wire Wire Line
	8400 4900 9550 4900
Connection ~ 9550 4900
Wire Wire Line
	8400 3900 8400 3800
Wire Wire Line
	8400 3800 9600 3800
Connection ~ 9600 3800
Wire Wire Line
	9600 3800 9600 3850
Wire Wire Line
	8400 4200 8400 4250
Wire Wire Line
	8400 4250 9100 4250
Connection ~ 8400 4250
Wire Wire Line
	8400 4250 8400 4300
$Comp
L Device:R R9
U 1 1 5FCD2F32
P 3550 2550
F 0 "R9" H 3480 2504 50  0000 R CNN
F 1 "10k" H 3480 2595 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3480 2550 50  0001 C CNN
F 3 "~" H 3550 2550 50  0001 C CNN
	1    3550 2550
	-1   0    0    1   
$EndComp
Connection ~ 7400 3500
Wire Wire Line
	2400 3700 3800 3700
Wire Wire Line
	2400 3300 3800 3300
Wire Wire Line
	2400 3100 3800 3100
Wire Wire Line
	3250 2350 3550 2350
Wire Wire Line
	2400 3400 3550 3400
Wire Wire Line
	3550 2400 3550 2350
Connection ~ 3550 2350
Wire Wire Line
	3550 2350 3800 2350
$Comp
L Device:R R8
U 1 1 5FD0A263
P 2800 2550
F 0 "R8" H 2730 2504 50  0000 R CNN
F 1 "10k" H 2730 2595 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2730 2550 50  0001 C CNN
F 3 "~" H 2800 2550 50  0001 C CNN
	1    2800 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	3550 2700 3550 3400
Wire Wire Line
	3800 2350 3800 3000
Connection ~ 3800 3000
Wire Wire Line
	3250 2700 3250 2900
$Comp
L Device:R R7
U 1 1 5FD29A52
P 2500 2550
F 0 "R7" H 2430 2504 50  0000 R CNN
F 1 "10k" H 2430 2595 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2430 2550 50  0001 C CNN
F 3 "~" H 2500 2550 50  0001 C CNN
	1    2500 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	2500 2700 2500 2800
Wire Wire Line
	2500 2800 2400 2800
Wire Wire Line
	2400 3500 2800 3500
Wire Wire Line
	2800 3500 2800 2700
Wire Wire Line
	3250 2350 2800 2350
Wire Wire Line
	2800 2350 2800 2400
Connection ~ 3250 2350
Wire Wire Line
	2500 2400 2500 2350
Wire Wire Line
	2500 2350 2800 2350
Connection ~ 2800 2350
Wire Wire Line
	2450 4750 1800 4750
Text Label 2750 4650 2    50   ~ 0
SWCLK_BOOT0_WAKEUP
Wire Wire Line
	2450 4450 1800 4450
Text Label 2450 4450 2    50   ~ 0
GPIO
Text Label 4450 3500 0    50   ~ 0
GPIO
Wire Wire Line
	4450 3500 5250 3500
$EndSCHEMATC
