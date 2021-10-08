import speech_recognition as sr
from datetime import date
from time import sleep
import os

r = sr.Recognizer()
mic = sr.Microphone()

print("########### Ouvindo ################")

while True:
    with mic as source:
        audio = r.listen(source)
    try:
        words = r.recognize_google(audio, language='pt-BR')
        print(words)

        if words == "azul":
            os.system('../led/./rgb.out blue')
        
        if words == "vermelho":
            os.system('../led/./rgb.out red')

        if words == "verde":
            os.system('../led/./rgb.out green')

        if words == "sinal":
            os.system('../buzzer/./buzzer.out 1')
        
        if words == "temperatura":
            os.system('../voice_temperature/./sensor.out')

        if words == "desligar sinal":
            os.system('../buzzer/./buzzer.out 0')

        if words == "Desligar luz":
            os.system('../led/./rgb.out off')

        if words == "exit":
            print("...")
            sleep(1)
            print("...")
            sleep(1)
            print("...")
            sleep(1)
            print("Goodbye")
            break
    except:
        print("Não entendi")
