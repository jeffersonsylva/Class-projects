# Sample Makefile for cpsc 2620 Assignment 2
# 24-feb-15
# RB

# compile command
CC = g++11
# linker command
LN = g++11
# compile options
CCFLAGS = -std=c++11 -Wall -I/home/lib2620/lect/include/
# libraries needed for linking
LIBS = -lpthread -lX11
# linking options, for example location of libraries
LFLAGS = 

# targets
# list of executables built by the Makefile
EXECUTABLES = p1a p1b p2 p3
all: $(EXECUTABLES)

# dependencies for each executable
# specifies which object files are needed for each executable and when
# the executable should be rebuilt
p1b: exp1.o main1.o
p1a: exp2.o main1.o
p2: turtle.o koch.o
p3: sudoku.o main3.o

# one common linking command
$(EXECUTABLES):
	$(LN) $(LFLAGS) $^ $(LIBS) -o $@


# default rule for compiling .cc files
%.o : %.cc
	$(CC) -c $(CCFLAGS) $<

.PHONY : clean
clean:
	rm -f *.o *~ $(EXECUTABLES)

# dependencies for each object file (can be generated automatically)
# determines when the object file is recompiled
exp1.o: exp1.cc

turtle.o : turtle.cc turtle.h
koch.o: turtle.h koch.cc
sudoku.o: sudoku.h sudoku.cc
main3.o: main3.cc sudoku.h

