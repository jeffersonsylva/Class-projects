# Sample Makefile for cpsc 2620 Assignment 4
# 1-apr-15
# RB

# compile command
CC = g++11
# linker command
LN = g++11
# compile options
CCFLAGS = -std=c++11 -Wall 
# libraries needed for linking
LIBS = 
# linking options, for example location of libraries
LFLAGS = 

# targets
# list of executables built by the Makefile
EXECUTABLES = p
all: $(EXECUTABLES)

# dependencies for each executable
# specifies which object files are needed for each executable
# if any of the .o files listed is updated then the linking command
# will be called so that you have an up to date executable
p: main.o 

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
main.o: main.cc slist.h

