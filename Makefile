# Esto es un comentario. 
# La variable CC se utiliza para especificar el compilador a utilizar
CC=g++
# La variable CFLAGS se utiliza para pasarle opciones al compilador 
CFLAGS=-c -Wall

all: main

main: main.o funciones.o 
	$(CC) funciones.o main.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

juego.o: funciones.cpp
	$(CC) $(CFLAGS) funciones.cpp

clean:
	rm -rf *o main

