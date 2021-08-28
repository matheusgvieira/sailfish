main: Ex2.o gpio_sysfs.o
	gcc Ex2.o gpio_sysfs.o -o Ex2.out
Ex3.out: Ex3.o gpio_dev_mem.o
	gcc Ex3.o gpio_dev_mem.o -o Ex3.out