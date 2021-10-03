CC = gcc
CFLAGS = -Wall
programa = conjunto

conjunto: main.c conjunto.c
	$(CC) -o $(programa) conjunto.c main.c

executa: conjunto
	./$(programa)

clean:
	rm $(programa)
