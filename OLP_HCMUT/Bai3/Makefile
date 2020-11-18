CC=gcc
CFLAGS=-I.
DEPS=BubbleSort.h Debug.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
Bai3: Bai3.c BubbleSort.c 
	$(CC) -o Bai3 Bai3.c BubbleSort.c -I.

CC=gcc
CFLAGS=-I.
DEPS = BubbleSort.h Debug.h
OBJ = Bai3.o BubbleSort.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Bai3: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)