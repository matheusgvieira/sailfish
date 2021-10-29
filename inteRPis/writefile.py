from get_temp import get_pos_element
import time

def writefile(value):
    f = open("/home/pi/sailfish/mqtt-nodered/temperature.txt", "w")
    f.write(value)
    f.close()

while(1):
    writefile(str(get_pos_element(-1, 'data')))
    time.sleep(5)