![Sailfish](images/logo.svg)

> Develop an embedded system that by capturing audio and using a Google Assistant API to identify and interpret the incoming audio content in order to control by voice the temperature of a pool.

## Requirements
* Capture audio with a microphone and use the Raspberry Pi's internal hardware.
* Develop software layer capable of connecting Google Assistant API with microprocessor.
* Define and configure key phrases for pool temperature control.
* Develop pool PID control system.
* Develop software layer capable of connecting PID control with Google Assistant.
* Create hardware capable of capturing pool temperature
* Communicate hardware layer with pool heating system.
* Trigger alarm for possible adversities.
* Display temperature data using Node-Red.
* Send temperature data using protocol

## Technologies

### Hardware
<img  alt="Raspberry" width="20px" src="https://cdn.worldvectorlogo.com/logos/raspberry-pi.svg" /> Raspberry Pi 3 B+

<img  alt="ATSAMD21" width="20px" src="https://cdn.iconscout.com/icon/free/png-512/espressif-2752195-2285012.png" /> ATSAMD21+

### Software
<img  alt="Python" width="20px" src="https://raw.githubusercontent.com/github/explore/80688e429a7d4ef2fca1e82350fe8e3517d3494d/topics/python/python.png" /> Python

<img  alt="C" width="20px" src="https://img.icons8.com/color/452/c-programming.png" /> C

<img  alt="C++" width="20px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/ISO_C%2B%2B_Logo.svg/1822px-ISO_C%2B%2B_Logo.svg.png" /> C++

### APis
<img  alt="google" width="20px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/cb/Google_Assistant_logo.svg/270px-Google_Assistant_logo.svg.png" /> Google Assistant

<img  alt="Node-RED" width="20px" src="https://nodered.org/about/resources/media/node-red-icon-2.png" /> Node-RED 

## Schedule
|  PC 	|                                                               Contents                                                               	| Date       	|
|:---:	|:------------------------------------------------------------------------------------------------------------------------------------:	|------------	|
| PC1 	| Project proposal (justification, objectives, requirements, benefits, literature review).                                             	| 06/08/2021 	|
| PC2 	| Functional prototype of the project, using the most basic tools from the development board, ready-made libraries, etc.               	| 03/09/2021 	|
| PC3 	| Refinement of the prototype, adding basic system resources (multiple processes and threads, pipes, signals, semaphores, MUTEX etc.). 	| 08/10/2021 	|
| PC4 	| Refinement of the prototype, adding real-time Linux features.                                                                        	| 22/10/2021 	|

## Diagram
![Schematic](images/diagram.png)

## Run Project

```sh
make runproject
```


