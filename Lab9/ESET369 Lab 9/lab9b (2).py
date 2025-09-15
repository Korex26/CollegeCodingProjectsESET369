import machine as pico
from machine import Pin,PWM
from utime import sleep

pwm=PWM(Pin(14))
pwm.freq(50)
pwm.duty_u16(0)
up=Pin(10,Pin.IN)
down=Pin(11,Pin.IN)
left=Pin(12,Pin.IN)
right=Pin(13,Pin.IN)

adc0=pico.ADC(0)

while True:
    if down.value()==0:
        pwm.duty_u16(0)        
    elif left.value()==0:
        
        pwm.duty_u16(10000)        
    elif up.value()==0:
        pwm.duty_u16(100000000)
    elif right.value()==0:
        while True:
            adc_raw = adc0.read_u16()

            pwm.duty_u16(int(adc_raw/10)*10)
        if right.value()==0:
            break
    
    
    

    sleep(0.1)
