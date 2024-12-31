CC = gcc
CFLAGS = -Wall -Wextra -g
EXEC = programa
SRCS = main.c BolhaCParada.c BolhaSemParada.c BinaryInsertionsort.c Bucketsort.c Heapsort.c Insertionsort.c Mergesort.c Quicksort.c Radixsort.c Selectionsort.c Shellsort.c
OBJS = $(SRCS:.c=.o)

all: $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q *.o $(EXEC)