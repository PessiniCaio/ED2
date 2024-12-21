CC = gcc
CFLAGS = -Wall -Wextra -g
EXEC = programa
SRCS = main.c BolhaCParada.c BolhaSemParada.c
OBJS = $(SRCS:.c=.o)

all: $(EXEC)
	./$(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q *.o $(EXEC)