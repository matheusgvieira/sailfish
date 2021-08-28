buzzer: main.o buzzer.o
	gcc $(CFLAGS) -o buzzer.out main.o buzzer.o
main.o: main.c buzzer.h
	gcc $(CFLAGS) -c main.c
buzzer.o: buzzer.c buzzer.h
	gcc $(CFLAGS) -c buzzer.c
clean:
	rm -f *.o buzzer.out