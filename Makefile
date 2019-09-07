CC=gcc
CFLAGS=-Wall -fPIC -no-pie -m64 -s

all: modules mloader

mloader: mloader.c
	$(CC) $(CFLAGS) -pthread mloader.c -ldl -o mloader; mv mloader distribute

modules:
	$(CC) -Og -nostdlib -c mystery_bois/*.c; mv *.o mystery_bois; bash dump_text.sh; mv boi*bin distribute

clean:
	rm mystery_bois/*.o distribute/boi* distribute/mloader
