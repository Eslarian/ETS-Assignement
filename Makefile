########################################################################
# COSC1076 - Advanced Programming Techniques
# Summer 2015 Assignment #2
# Full Name        : EDIT HERE
# Student Number   : EDIT HERE
# Course Code      : EDIT HERE
# Program Code     : EDIT HERE
# Start up code provided by David Shaw
# Based on 2014 code by Paul Miller and Virginia King
########################################################################
CC= gcc
CFLAGS=-ansi -Wall -pedantic -g
TARGETS=ets_utility.o ets_main.o ets_menu.o ets_options.o file_load.o list.o compare.o ETS      
HEADERS=*h

###################################
# put your Makefile targets in here
###################################
all: $(TARGETS) 

warning: *.c
	$(CC) $(CFLAGS) $^ -o ETS

ETS: ets_main.o ets_menu.o ets_options.o file_load.o list.o compare.o ets_utility.o
	$(CC) $(CFLAGS) $^ -o $@

ets_main.o:ets_main.c ets_menu.h
	$(CC) $(CFLAGS) -c ets_main.c

ets_menu.o:ets_menu.c ets_menu.h file_load.h ets_options.h
	$(CC) $(CFLAGS) -c ets_menu.c

ets_options.o:ets_options.c ets_options.h file_load.h 
	$(CC) $(CFLAGS) -c ets_options.c

file_load.o:file_load.c file_load.h list.h 
	$(CC) $(CFLAGS) -c file_load.c

list.o:list.c list.h compare.h
	$(CC) $(CFLAGS) -c list.c

compare.o:compare.c compare.h ets_utility.h
	$(CC) $(CFLAGS) -c compare.c

ets_utility.o:ets_utility.c ets_utility.h ets_type.h
	$(CC) $(CFLAGS) -c ets_utility.c

.PHONY:clean

clean:
	rm -f *.o ETS

########################################################################
# Move this target to the end of the Makefile to zip up your code 
# when submitting. Please add any additional files you add to your 
# project and delete ones your remove. Do not submit your .dat files, 
# your .bin files, containing directories. We only want the files that 
# are part of your implementation
########################################################################

archive:
	zip $(USER) ets_main.c ets_options.c ets_options.h ets_type.h \
	ets_menu.c ets_menu.h ets_utility.h ets_utility.c file_load.c file_load.h list.c list.h  Makefile readme.txt
