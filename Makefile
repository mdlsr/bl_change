.DEFAULT_GOAL := make
CC = g++
CFLAGS = -g -Wall 
Main.o:
		$(CC) $(CFLAGS) -c src/Main.cpp -o out/Main.o 
make: Main.o
		$(CC) $(CFLAGS) out/Main.o -o out/a.out
clean:
		rm -Rf out/*
install:
ifeq ($(shell test -e /usr/bin/bl_change && echo -n yes), yes)
	$(error 'it seems that bl_change is already installed')
else
	cp out/a.out /usr/bin/bl_change
	chown root /usr/bin/bl_change
	chmod a-w /usr/bin/bl_change
	chmod u+s /usr/bin/bl_change
endif

uninstall:
	rm /usr/bin/bl_change;
	