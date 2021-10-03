CC = gcc
CFLAGS = -Wall
	
main: ListaDinamica.o main.c
	$(CC) -o main ListaDinamica.o main.c
	
ListaEstatica.o: ListaDinamica.c ListaDinamica.h
	$(CC) -c ListaDinamica.c
	
clean:
	rm main *.o

executa: main
	./main
