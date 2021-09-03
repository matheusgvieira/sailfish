# Example without Google Assistant
# video: https://youtu.be/R1SFP3t7Gwo

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
        if audio:
            words = r.recognize_google(audio)
            print(words)

            if words == "blue":
                os.system('../led/./rgb.out blue')
            
            if words == "red":
                os.system('../led/./rgb.out red')

            if words == "green":
                os.system('../led/./rgb.out green')

            if words == "off":
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

    except sr.UnkownValueError:
        print("Não entendi")
