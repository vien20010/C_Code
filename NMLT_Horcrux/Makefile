CC=gcc
CFLAGS=-I.
DEPS = Debug.h
OBJ = NMLT_Horcrux.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

NMLT_Horcrux: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
