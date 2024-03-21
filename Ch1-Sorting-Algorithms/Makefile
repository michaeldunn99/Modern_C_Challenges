#Makefile for the Modern C Challenges
IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR =bin/obj

DEPS=$(wildcard $(IDIR)/*.h)

OBJ=$(patsubst src/%.c, $(ODIR)/%.o, $(wildcard src/*.c))

$(ODIR)/%.o: src/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sort: $(OBJ)
	$(CC) -o bin/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~core $(INCDIR)/*~