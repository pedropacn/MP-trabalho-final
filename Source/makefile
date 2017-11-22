CC = g++
CFLAGS = -std=c++11
OBJECTS = gerenciadorItens.o gerenciadorListas.o main.o

all : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o run

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean:
	find . -name '*.o' -exec rm '{}' \;
	find . -name 'run' -exec rm '{}' \;
