RM = rm -f
OBJECTFILE = main.o
LIBRARYPATH = /usr/lib
INCLUDE_PATH = /usr/include

createEXE:
	make -f makefile.basic clean 
	make -f makefile.basic
	make -f makefile.basic install
	make -f makefile.basic clean 

	make -f makefile.graph clean 
	make -f makefile.graph
	make -f makefile.graph install
	make -f makefile.graph clean 

	@ echo "\nEXECUTABLE FILE CREATION"
	gcc -Wall -c main.c
	gcc -Wall -o graph.out $(OBJECTFILE) -lgraph -ldatastructures
	$(RM) $(OBJECTFILE)
	# export LD LIBRARY_PATH=$(LIBRARYPATH)

FILE = main.c
CC = gcc
FLAGS = -Wall -lGRAPH
OUTPUT = graph.out
all:
	$(CC) $(FILE) $(FLAGS) -o $(OUTPUT)
