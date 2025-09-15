import machine as pico
from machine import Pin
from utime import sleep

adc0=pico.ADC(0)
adc4=pico.ADC(4)

red=Pin(15,Pin.OUT)
green=Pin(16,Pin.OUT)
blue=Pin(17,Pin.OUT)

while True:
    tempraw=adc4.read_u16()
    adc_raw = adc0.read_u16()
    
    voltage=((adc_raw/65535)*3.3)
    print("voltageraw =",adc_raw)
    print("voltage =", voltage)
    

    tempconv=tempraw*3.3/65535
    tempc=27-(tempconv-0.706)/0.001721
    tempf=tempc*9/5+32
    
    print("raw temp=", tempraw)
    print("temp =", tempf)
    print()
    
    if voltage <1:
        red.value(1)
        green.value(1)
        blue.value(1)
    elif voltage>=1 and voltage<2:
        red.value(0)
        green.value(1)
        blue.value(1)
    elif voltage >=2 and voltage <3:
        red.value(1)
        green.value(0)
        blue.value(1)
    elif voltage >3:
        red.value(1)
        green.value(1)
        blue.value(0)
    sleep(0.5)
    