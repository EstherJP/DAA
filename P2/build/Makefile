IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -O3 -std=c++17 -g -lstdc++

ODIR=../src

LIBS=-lm

_OBJ = main.o tapeBase.o ReadTape.o WriteTape.o instruction.o memory.o RAM.o program.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/tapeBase.o: $(ODIR)/tapeBase.cpp $(IDIR)/tapeBase.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/memory.o: $(ODIR)/memory.cpp $(IDIR)/memory.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/ReadTape.o: $(ODIR)/ReadTape.cpp $(IDIR)/ReadTape.hpp $(IDIR)/tapeBase.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/WriteTape.o: $(ODIR)/WriteTape.cpp $(IDIR)/WriteTape.hpp $(IDIR)/tapeBase.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/instruction.o: $(ODIR)/instruction.cpp $(IDIR)/instruction.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/program.o: $(ODIR)/program.cpp $(IDIR)/program.hpp $(IDIR)/instruction.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/RAM.o: $(ODIR)/RAM.cpp $(IDIR)/RAM.hpp $(IDIR)/instruction.hpp $(IDIR)/program.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/tapeBase.hpp $(IDIR)/ReadTape.hpp $(IDIR)/instruction.hpp $(IDIR)/WriteTape.hpp $(IDIR)/RAM.hpp $(IDIR)/program.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~