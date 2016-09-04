CC = gcc
LDFLAGS = -lm
CFLAGS = -Wall -Ofast -fstrict-aliasing -march=native
OBJECTS = mathlib.o matrixlib.o matrixbench.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

matrixbench: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

clean:
	@echo cleaning oop
	@rm -f $(OBJECTS)
