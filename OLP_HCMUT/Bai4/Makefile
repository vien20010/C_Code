CC=gcc
CFLAGS=-I.
DEPS = Debug.h
OBJ = Bai4.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Bai4: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)