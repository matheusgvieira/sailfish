import os
import get_temp
import subprocess

pathproject = "/home/pi/sailfish"

def read_audio_devices(words):
    
    if words == "temperatura":
        return "Temperatura = " + str(get_temp.get_pos_element(-1, 'data'))

    elif words == "aquecedor":
        return "Aquecedor = " + str(get_temp.get_pos_element(-1, 'state'))   

    elif words == "led azul":
        response =  subprocess.check_output('{}/led/./rgb.out blue'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")

    elif words == "desligar led azul" or "Desligar led azul":
        response =  subprocess.check_output('{}/led/./rgb.out offblue'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")
        
    elif words == "led vermelho":
        response =  subprocess.check_output('{}/led/./rgb.out red'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")
        
    elif words == "desligar led vermelho" or words == "Desligar led vermelho":
        response =  subprocess.check_output('{}/led/./rgb.out offred'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")

    elif words == "led verde":
        response =  subprocess.check_output('{}/led/./rgb.out green'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")

    elif words == "desligar led verde" or words == "Desligar led verde":
        response =  subprocess.check_output('{}/led/./rgb.out offgreen'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")

    elif words == "desligar luz" or words == "Desligar luz":
        response =  subprocess.check_output('{}/led/./rgb.out off'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")

    elif words == "sinal":
        response =  subprocess.check_output('{}/buzzer/./buzzer.out 1'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")
    
    elif words == "desligar sinal":
        response =  subprocess.check_output('{}/buzzer/./buzzer.out 0'.format(pathproject), shell=True)
        return response.decode('utf-8').rstrip("\n")

    else:
        return 0

    

    

    