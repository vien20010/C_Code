CC=gcc
CFLAGS=-I.
DEPS = Sort.h Debug.h
OBJ = TestSort.o Sort.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TestSort: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)