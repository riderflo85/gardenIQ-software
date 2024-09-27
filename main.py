import time
from machine import Timer, Pin

from software import loop_exchange_usb


# ------- small setup to on and off onbaord led -------
led = Pin("LED", Pin.OUT)
led.on()
time.sleep(2)
led.off()
# -----------------------------------------------------

exchange_usb_time = Timer()
exchange_usb_time.init(mode=Timer.PERIODIC, period=100, callback=loop_exchange_usb)

# Necessary to avoid run RPEL !
while True: pass
