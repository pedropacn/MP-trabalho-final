CC = g++
CFLAGS = -std=c++11 -lncurses
OBJECTS = common.o gerenciadorItens.o gerenciadorListas.o main.o

all : $(OBJECTS)
	$(CC) $(OBJECTS) -o run $(CFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	find . -name '*.o' -exec rm '{}' \;
	find . -name 'run' -exec rm '{}' \;
