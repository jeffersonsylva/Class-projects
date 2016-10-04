# Sample Makefile for cpsc 2620 Assignment 2
# 24-feb-15
# RB

# compile command
CC = g++11
# linker command
LN = g++
# compile options
CCFLAGS = -std=c++11 -Wall
# libraries needed for linking
LIBS =
# linking options, for example location of libraries
LFLAGS = 

# targets
# list of executables built by the Makefile
EXECUTABLES = p1a p1b p2 p3
all: $(EXECUTABLES)

# dependencies for each executable
# specifies which object files are needed for each executable and when
# the executable should be rebuilt
p1b: main1shared.o
p1a: main1new.o
p2: Automaton1D.o main2.o
p3: IStack.o main3.o

# one common linking command
$(EXECUTABLES):
	$(LN) $(LFLAGS) $(LIBS) $^ -o $@


# default rule for compiling .cc files
%.o : %.cc
	$(CC) -c $(CCFLAGS) $<

.PHONY : clean
clean:
	rm -f *.o *~ $(EXECUTABLES)

# dependencies for each object file (can be generated automatically)
# determines when the object file is recompiled
main1shared.o: A.h
main1new.o : A.h
Automaton1D.o : Automaton1D.cc Automaton1D.h
main2.o: Automaton1D.h main2.cc
main3.o: IStack.h
IStack.o: IStack.cc IStack.h
