CC = gcc
CFLAGS = -Wall -Wextra -g -fno-stack-protector
LDFLAGS = -Wl,--stack,16777216
EXEC = programa
SRCS = main.c BolhaCParada.c BolhaSemParada.c BinaryInsertionsort.c Bucketsort.c Heapsort.c Insertionsort.c Mergesort.c QuickSortIni.c QuickSortCentro.c QuickSortMediana.c Radixsort.c Selectionsort.c Shellsort.c Menus.c Utils.c
OBJS = $(SRCS:.c=.o)

all: $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q *.o $(EXEC)