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
P 1950 3200
F 0 "J3" H 1900 4017 50  0000 C CNN
F 1 "Micro_SD_Card_Det" H 1900 3926 50  0000 C CNN
F 2 "TinySound:AMPHENOL_1140084168" H 4000 3900 50  0001 C CNN
F 3 "https://www.hirose.com/product/en/download_file/key_name/DM3/category/Catalog/doc_file_id/49662/?file_category_id=4&item_id=195&is_series=1" H 1950 3300 50  0001 C CNN
	1    1950 3200
	-1   0    0    -1  
$EndComp
$Comp
L TinySound:STM32G030KxT U2
U 1 1 5FCB3865
P 5950 2750
F 0 "U2" H 5300 1800 50  0000 C CNN
F 1 "STM32G030KxT" H 6450 1800 50  0000 C CNN
F 2 "Package_QFP:LQFP-32_7x7mm_P0.8mm" H 6600 950 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2864618.pdf" H 6650 950 50  0001 C CNN
F 4 "3246910" H 6650 950 50  0001 C CNN "Farnell"
	1    5950 2750
	1    0    0    -1  
$EndComp
$Comp
L TinySound:MAX98360xxxL+ U1
U 1 1 5FCB6021
P 9400 2700
F 0 "U1" H 9150 2250 50  0000 C CNN
F 1 "MAX98360AENL+" H 9800 2250 50  0000 C CNN
F 2 "Package_BGA:Maxim_WLP-9_1.595x1.415_Layout3x3_P0.4mm_Ball0.27mm_Pad0.25mm_NSMD" H 9400 1400 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX98360A-MAX98360D.pdf" H 9300 2100 50  0001 C CNN
F 4 "3288145" H 9400 1400 50  0001 C CNN "Farnell"
	1    9400 2700
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
P 10800 2650
F 0 "J2" H 10718 2325 50  0000 C CNN
F 1 "Conn_01x02" H 10718 2416 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 10800 2650 50  0001 C CNN
F 3 "~" H 10800 2650 50  0001 C CNN
	1    10800 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 2600 10150 2600
Wire Wire Line
	10500 2600 10500 2650
Wire Wire Line
	10500 2650 10600 2650
Wire Wire Line
	10600 2750 10500 2750
Wire Wire Line
	10500 2750 10500 2800
Wire Wire Line
	10500 2800 10350 2800
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
P 6100 4650
F 0 "D1" H 6093 4395 50  0000 C CNN
F 1 "LED" H 6093 4486 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6100 4650 50  0001 C CNN
F 3 "~" H 6100 4650 50  0001 C CNN
	1    6100 4650
	-1   0    0    1   
$EndComp
$Comp
L Device:R R4
U 1 1 5FCBF606
P 5550 4650
F 0 "R4" V 5343 4650 50  0000 C CNN
F 1 "R" V 5434 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5480 4650 50  0001 C CNN
F 3 "~" H 5550 4650 50  0001 C CNN
	1    5550 4650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5FCBFD75
P 1100 4000
F 0 "#PWR012" H 1100 3750 50  0001 C CNN
F 1 "GND" H 1105 3827 50  0000 C CNN
F 2 "" H 1100 4000 50  0001 C CNN
F 3 "" H 1100 4000 50  0001 C CNN
	1    1100 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 3700 1100 3700
Wire Wire Line
	1100 3700 1100 4000
$Comp
L power:+3V3 #PWR07
U 1 1 5FCC05C7
P 3600 2450
F 0 "#PWR07" H 3600 2300 50  0001 C CNN
F 1 "+3V3" H 3615 2623 50  0000 C CNN
F 2 "" H 3600 2450 50  0001 C CNN
F 3 "" H 3600 2450 50  0001 C CNN
	1    3600 2450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5FCC0BD0
P 3600 3800
F 0 "#PWR010" H 3600 3550 50  0001 C CNN
F 1 "GND" H 3605 3627 50  0000 C CNN
F 2 "" H 3600 3800 50  0001 C CNN
F 3 "" H 3600 3800 50  0001 C CNN
	1    3600 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3300 3600 3300
Wire Wire Line
	3600 3300 3600 3400
Wire Wire Line
	2850 3100 3600 3100
$Comp
L power:+3V3 #PWR01
U 1 1 5FCC1D2E
P 5950 1150
F 0 "#PWR01" H 5950 1000 50  0001 C CNN
F 1 "+3V3" H 5965 1323 50  0000 C CNN
F 2 "" H 5950 1150 50  0001 C CNN
F 3 "" H 5950 1150 50  0001 C CNN
	1    5950 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5FCC22BB
P 5950 3850
F 0 "#PWR011" H 5950 3600 50  0001 C CNN
F 1 "GND" H 5955 3677 50  0000 C CNN
F 2 "" H 5950 3850 50  0001 C CNN
F 3 "" H 5950 3850 50  0001 C CNN
	1    5950 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3750 5950 3850
Wire Wire Line
	5950 1150 5950 1200
$Comp
L power:+3V3 #PWR06
U 1 1 5FCC3350
P 9400 2100
F 0 "#PWR06" H 9400 1950 50  0001 C CNN
F 1 "+3V3" H 9415 2273 50  0000 C CNN
F 2 "" H 9400 2100 50  0001 C CNN
F 3 "" H 9400 2100 50  0001 C CNN
	1    9400 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 2100 9400 2150
$Comp
L power:GND #PWR09
U 1 1 5FCC3BFC
P 9400 3300
F 0 "#PWR09" H 9400 3050 50  0001 C CNN
F 1 "GND" H 9405 3127 50  0000 C CNN
F 2 "" H 9400 3300 50  0001 C CNN
F 3 "" H 9400 3300 50  0001 C CNN
	1    9400 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 3200 9400 3250
$Comp
L power:GND #PWR014
U 1 1 5FCC4260
P 6550 4750
F 0 "#PWR014" H 6550 4500 50  0001 C CNN
F 1 "GND" H 6555 4577 50  0000 C CNN
F 2 "" H 6550 4750 50  0001 C CNN
F 3 "" H 6550 4750 50  0001 C CNN
	1    6550 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 4650 6550 4650
Wire Wire Line
	6550 4650 6550 4750
Wire Wire Line
	5950 4650 5700 4650
$Comp
L Device:C C2
U 1 1 5FCD3FFB
P 6600 1400
F 0 "C2" H 6715 1446 50  0000 L CNN
F 1 "4.7u" H 6715 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6638 1250 50  0001 C CNN
F 3 "~" H 6600 1400 50  0001 C CNN
	1    6600 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5FCD4387
P 8350 2650
F 0 "C4" H 8235 2604 50  0000 R CNN
F 1 "10u" H 8235 2695 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8388 2500 50  0001 C CNN
F 3 "~" H 8350 2650 50  0001 C CNN
	1    8350 2650
	1    0    0    1   
$EndComp
Wire Wire Line
	3600 3400 3750 3400
Wire Wire Line
	3750 3400 3750 3350
Connection ~ 3600 3400
Wire Wire Line
	3600 3400 3600 3700
Wire Wire Line
	3600 2450 3600 2500
Wire Wire Line
	3750 3050 3750 3000
Wire Wire Line
	3750 3000 3600 3000
Connection ~ 3600 3000
Wire Wire Line
	3600 3000 3600 3100
Wire Wire Line
	3250 3000 2850 3000
Wire Wire Line
	3250 3200 2850 3200
Wire Wire Line
	3250 3400 2850 3400
Wire Wire Line
	2850 3700 3600 3700
Connection ~ 3600 3700
Wire Wire Line
	3600 3700 3600 3800
Wire Wire Line
	2850 3600 3250 3600
NoConn ~ 2850 3500
NoConn ~ 2850 2800
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
	5400 4650 5050 4650
Text Label 5050 4650 0    50   ~ 0
LED
Wire Wire Line
	3600 2500 3350 2500
Connection ~ 3600 2500
Wire Wire Line
	3600 2500 3600 3000
Wire Wire Line
	3350 2500 3350 2550
$Comp
L Device:R R1
U 1 1 5FCDC9FC
P 3350 2700
F 0 "R1" H 3280 2654 50  0000 R CNN
F 1 "10k" H 3280 2745 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3280 2700 50  0001 C CNN
F 3 "~" H 3350 2700 50  0001 C CNN
	1    3350 2700
	-1   0    0    1   
$EndComp
Wire Wire Line
	3350 2850 3350 2900
Wire Wire Line
	2850 2900 3350 2900
$Comp
L power:GND #PWR03
U 1 1 5FCEB40B
P 6150 1600
F 0 "#PWR03" H 6150 1350 50  0001 C CNN
F 1 "GND" H 6155 1427 50  0000 C CNN
F 2 "" H 6150 1600 50  0001 C CNN
F 3 "" H 6150 1600 50  0001 C CNN
	1    6150 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 1200 6150 1200
Wire Wire Line
	6150 1200 6150 1250
Connection ~ 5950 1200
Wire Wire Line
	5950 1200 5950 1750
Wire Wire Line
	6150 1200 6600 1200
Wire Wire Line
	6600 1200 6600 1250
Connection ~ 6150 1200
Wire Wire Line
	6150 1550 6150 1600
$Comp
L power:GND #PWR04
U 1 1 5FCEF82B
P 6600 1600
F 0 "#PWR04" H 6600 1350 50  0001 C CNN
F 1 "GND" H 6605 1427 50  0000 C CNN
F 2 "" H 6600 1600 50  0001 C CNN
F 3 "" H 6600 1600 50  0001 C CNN
	1    6600 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 1600 6600 1550
Wire Wire Line
	8350 2500 8350 2400
Wire Wire Line
	8350 2150 8500 2150
Connection ~ 9400 2150
Wire Wire Line
	9400 2150 9400 2200
Wire Wire Line
	9400 3250 8350 3250
Wire Wire Line
	8350 3250 8350 2900
Connection ~ 9400 3250
Wire Wire Line
	9400 3250 9400 3300
$Comp
L Device:R R2
U 1 1 5FCF2402
P 7200 3300
F 0 "R2" H 7130 3254 50  0000 R CNN
F 1 "10k" H 7130 3345 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7130 3300 50  0001 C CNN
F 3 "~" H 7200 3300 50  0001 C CNN
	1    7200 3300
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR08
U 1 1 5FCF33C9
P 7200 3100
F 0 "#PWR08" H 7200 2950 50  0001 C CNN
F 1 "+3V3" H 7215 3273 50  0000 C CNN
F 2 "" H 7200 3100 50  0001 C CNN
F 3 "" H 7200 3100 50  0001 C CNN
	1    7200 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 3100 7200 3150
Wire Wire Line
	7200 3450 7200 3500
Wire Wire Line
	7200 3500 6850 3500
Wire Wire Line
	7200 3500 7700 3500
Connection ~ 7200 3500
Text Label 7700 3500 2    50   ~ 0
NRST
Text Label 2450 4650 2    50   ~ 0
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
Text Label 2450 4450 2    50   ~ 0
SWCLK
Wire Wire Line
	2450 4450 1800 4450
Wire Wire Line
	1800 4550 2450 4550
Wire Wire Line
	2450 4650 1800 4650
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
P 7950 2650
F 0 "C3" H 7835 2604 50  0000 R CNN
F 1 "100n" H 7835 2695 50  0000 R CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7988 2500 50  0001 C CNN
F 3 "~" H 7950 2650 50  0001 C CNN
	1    7950 2650
	1    0    0    1   
$EndComp
Wire Wire Line
	7950 2500 7950 2400
Wire Wire Line
	7950 2400 8350 2400
Connection ~ 8350 2400
Wire Wire Line
	8350 2400 8350 2150
Wire Wire Line
	7950 2800 7950 2900
Wire Wire Line
	7950 2900 8350 2900
Connection ~ 8350 2900
Wire Wire Line
	8350 2900 8350 2800
Text Label 8550 2400 0    50   ~ 0
AU_EN
Text Label 8500 3000 0    50   ~ 0
AU_BCLK
Text Label 8500 2800 0    50   ~ 0
AU_LRCLK
Text Label 8500 2900 0    50   ~ 0
AU_DIN
Wire Wire Line
	8500 2800 8900 2800
Wire Wire Line
	8900 2900 8500 2900
Wire Wire Line
	8500 3000 8900 3000
Wire Wire Line
	8550 2400 8900 2400
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
Text Label 2450 4750 2    50   ~ 0
BOOT0_WAKEUP
Wire Wire Line
	2450 4750 1800 4750
Text Label 4250 3400 0    50   ~ 0
BOOT0_WAKEUP
Wire Wire Line
	4250 3400 4900 3400
$Comp
L Device:R R3
U 1 1 5FD23182
P 4900 3800
F 0 "R3" H 4830 3754 50  0000 R CNN
F 1 "10k" H 4830 3845 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4830 3800 50  0001 C CNN
F 3 "~" H 4900 3800 50  0001 C CNN
	1    4900 3800
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5FD23433
P 4900 4050
F 0 "#PWR013" H 4900 3800 50  0001 C CNN
F 1 "GND" H 4905 3877 50  0000 C CNN
F 2 "" H 4900 4050 50  0001 C CNN
F 3 "" H 4900 4050 50  0001 C CNN
	1    4900 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 4050 4900 3950
Wire Wire Line
	4900 3650 4900 3400
Connection ~ 4900 3400
Wire Wire Line
	4900 3400 5050 3400
Wire Wire Line
	4900 3400 4900 2000
Wire Wire Line
	4900 2000 5050 2000
Text Label 4450 2100 0    50   ~ 0
AU_BCLK
Text Label 4450 2200 0    50   ~ 0
AU_DIN
Text Label 4450 2400 0    50   ~ 0
AU_LRCLK
Wire Wire Line
	5050 2400 4450 2400
Wire Wire Line
	4450 2200 5050 2200
Wire Wire Line
	5050 2100 4450 2100
NoConn ~ 5050 2300
Text Label 4450 2500 0    50   ~ 0
AU_EN
Wire Wire Line
	4450 2500 5050 2500
NoConn ~ 5050 2600
NoConn ~ 5050 2700
Text Label 7250 2000 2    50   ~ 0
LED
Wire Wire Line
	7250 2000 6850 2000
NoConn ~ 6850 2100
NoConn ~ 6850 2200
NoConn ~ 5050 2800
Text Label 4450 2900 0    50   ~ 0
TX
Text Label 4450 3000 0    50   ~ 0
RX
Wire Wire Line
	4450 3000 5050 3000
Wire Wire Line
	5050 2900 4450 2900
NoConn ~ 6850 3100
NoConn ~ 6850 3200
NoConn ~ 6850 3300
NoConn ~ 6850 2900
NoConn ~ 6850 2300
NoConn ~ 5050 3100
NoConn ~ 5050 3200
Wire Wire Line
	5050 3500 4250 3500
Wire Wire Line
	4250 3300 5050 3300
Text Label 4250 3300 0    50   ~ 0
SWDIO
Text Label 4250 3500 0    50   ~ 0
SWCLK
Text Label 7250 2400 2    50   ~ 0
SD_CS
Wire Wire Line
	7250 2700 6850 2700
Wire Wire Line
	7250 2800 6850 2800
Wire Wire Line
	7250 2600 6850 2600
Wire Wire Line
	6850 2500 7250 2500
Text Label 7250 2700 2    50   ~ 0
SD_MOSI
Text Label 7250 2800 2    50   ~ 0
SD_CLK
Text Label 7250 2600 2    50   ~ 0
SD_MISO
Text Label 7250 2500 2    50   ~ 0
SD_DET
Wire Wire Line
	7250 2400 6850 2400
$Comp
L Device:C C5
U 1 1 5FD9203D
P 3750 3200
F 0 "C5" H 3865 3246 50  0000 L CNN
F 1 "10u" H 3865 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3788 3050 50  0001 C CNN
F 3 "~" H 3750 3200 50  0001 C CNN
	1    3750 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5FD94C91
P 6150 1400
F 0 "C1" H 6265 1446 50  0000 L CNN
F 1 "100n" H 6265 1355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6188 1250 50  0001 C CNN
F 3 "~" H 6150 1400 50  0001 C CNN
	1    6150 1400
	1    0    0    -1  
$EndComp
Connection ~ 8500 2150
Wire Wire Line
	8500 2150 9400 2150
Wire Wire Line
	8500 2600 8500 2150
Wire Wire Line
	8900 2600 8500 2600
Text Label 8550 2600 0    50   ~ 0
AU_GAIN
$Comp
L TinySound:MAX98360xxxB+ U3
U 1 1 5FCCC494
P 9400 4350
F 0 "U3" H 9150 3900 50  0000 C CNN
F 1 "MAX98360xxxB+" H 9800 3900 50  0000 C CNN
F 2 "TinySound:FC2QFN-10" H 9400 3050 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX98360A-MAX98360D.pdf" H 9300 3750 50  0001 C CNN
	1    9400 4350
	1    0    0    -1  
$EndComp
Text Label 8500 4050 0    50   ~ 0
AU_EN
Text Label 8500 4650 0    50   ~ 0
AU_BCLK
Text Label 8500 4450 0    50   ~ 0
AU_LRCLK
Text Label 8500 4550 0    50   ~ 0
AU_DIN
Wire Wire Line
	8500 4450 8900 4450
Wire Wire Line
	8900 4550 8500 4550
Wire Wire Line
	8500 4650 8900 4650
Wire Wire Line
	8500 4050 8900 4050
$Comp
L power:GND #PWR0101
U 1 1 5FCDB536
P 9400 4950
F 0 "#PWR0101" H 9400 4700 50  0001 C CNN
F 1 "GND" H 9405 4777 50  0000 C CNN
F 2 "" H 9400 4950 50  0001 C CNN
F 3 "" H 9400 4950 50  0001 C CNN
	1    9400 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0102
U 1 1 5FCDB99C
P 9400 3750
F 0 "#PWR0102" H 9400 3600 50  0001 C CNN
F 1 "+3V3" H 9415 3923 50  0000 C CNN
F 2 "" H 9400 3750 50  0001 C CNN
F 3 "" H 9400 3750 50  0001 C CNN
	1    9400 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 3750 9400 3800
Wire Wire Line
	9350 4850 9350 4900
Wire Wire Line
	9350 4900 9400 4900
Wire Wire Line
	9400 4900 9400 4950
Wire Wire Line
	9400 4900 9450 4900
Wire Wire Line
	9450 4900 9450 4850
Connection ~ 9400 4900
Wire Wire Line
	9900 4250 10150 4250
Wire Wire Line
	10150 4250 10150 2600
Connection ~ 10150 2600
Wire Wire Line
	10150 2600 10500 2600
Wire Wire Line
	9900 4450 10350 4450
Wire Wire Line
	10350 4450 10350 2800
Connection ~ 10350 2800
Wire Wire Line
	10350 2800 9900 2800
$Comp
L Device:R R5
U 1 1 5FCBAC28
P 8200 4050
F 0 "R5" H 8270 4096 50  0000 L CNN
F 1 "100k" H 8270 4005 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8130 4050 50  0001 C CNN
F 3 "~" H 8200 4050 50  0001 C CNN
	1    8200 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5FCBB239
P 8200 4450
F 0 "R6" H 8270 4496 50  0000 L CNN
F 1 "100k" H 8270 4405 50  0000 L CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 8130 4450 50  0001 C CNN
F 3 "~" H 8200 4450 50  0001 C CNN
	1    8200 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 4600 8200 4900
Wire Wire Line
	8200 4900 9350 4900
Connection ~ 9350 4900
Wire Wire Line
	8200 3900 8200 3800
Wire Wire Line
	8200 3800 9400 3800
Connection ~ 9400 3800
Wire Wire Line
	9400 3800 9400 3850
Wire Wire Line
	8200 4200 8200 4250
Wire Wire Line
	8200 4250 8900 4250
Connection ~ 8200 4250
Wire Wire Line
	8200 4250 8200 4300
$EndSCHEMATC
