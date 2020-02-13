IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g -lstdc++

ODIR=../src

LIBS=-lm

_OBJ = main.o matrix.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/matrix.o: $(ODIR)/matrix.cpp $(IDIR)/matrix.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(ODIR)/matrix.cpp $(IDIR)/matrix.hpp $(IDIR)/strategyBase.hpp $(IDIR)/strategy.hpp $(IDIR)/context.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~