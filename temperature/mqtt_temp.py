import paho.mqtt.client as paho
broker="172.18.0.4"
port=1883
import subprocess
import time
def on_publish(client,userdata,result):             #create function for callback
    print("data published \n")
    pass
client1= paho.Client("control1")                           #create client object
client1.on_publish = on_publish                          #assign function to callback
client1.connect(broker,port)                                 #establish connection


pathproject = "/home/pi/sailfish"


while True:
    temp = subprocess.check_output('{}/temperature/./sensor.out '.format(pathproject), shell=True)
    ret= client1.publish("/teste",str(temp))                   #publish
    time.sleep(10)