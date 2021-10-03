CC = gcc
CFLAGS = -Wall
	
main: Pilha.o main.c
	$(CC) -o main Pilha.o main.c
	
Pilha.o: Pilha.c Pilha.h
	$(CC) -c Pilha.c
	
clean:
	rm main *.o

executa: main
	./main
