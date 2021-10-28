mqtt: pub.o mqtt.o sensor.o
	gcc $(CFLAGS) -o mqtt.out pub.o mqtt.o sensor.o -lmosquitto
pub.o: pub.c mqtt.h sensor.h
	gcc $(CFLAGS) -c pub.c 
mqtt.o: mqtt.c mqtt.h
	gcc $(CFLAGS) -c mqtt.c -lmosquitto
sensor.o: sensor.c sensor.h
	gcc $(CFLAGS) -c sensor.c
clean:
	rm -f *.o mqtt.out