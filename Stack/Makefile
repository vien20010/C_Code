CC=gcc
CFLAGS=-I.
DEPS = Stack.h Debug.h
OBJ = Test.o Stack.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Test: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)