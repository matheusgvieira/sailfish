sensor: main.o sensor.o
	gcc $(CFLAGS) -o sensor.out main.o sensor.o
main.o: main.c sensor.h
	gcc $(CFLAGS) -c main.c
sensor.o: sensor.c sensor.h
	gcc $(CFLAGS) -c sensor.c
clean:
	rm -f *.o sensor.out