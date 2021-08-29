rgb: main.o rgb.o
	gcc $(CFLAGS) -o rgb.out main.o rgb.o
main.o: main.c rgb.h
	gcc $(CFLAGS) -c main.c
rgb.o: rgb.c rgb.h
	gcc $(CFLAGS) -c rgb.c
clean:
	rm -f *.o rgb.out