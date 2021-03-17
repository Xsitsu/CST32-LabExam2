#**************************************
# Makefile
#
# Makefile for lab exam language
#
# Author: Jacob Locke
#
# Date: March 17. 2021
#

SRC := src
OBJ := obj
INCL := hdr

CC=g++
COPTS=-Wall -g -c -O0 -std=c++11 -I$(INCL) -I./

SRCS := $(wildcard $(SRC)/*.cpp)
OBJS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

PROG = lang

all: $(PROG)

objs: $(OBJS)

clean:
	rm -rf $(OBJ)
	rm -f *.o
	rm -f $(PROG)
	rm -f langlex.c
	rm -f langparse.c
	rm -f langparse.h

$(PROG): $(PROG).o langparse.o langlex.o $(OBJS)
	$(CC) $(OBJS) langlex.o langparse.o $@.o  -o $@

$(TESTPROG): $(TESTPROG).o langparse.o langlex.o $(OBJS)
	$(CC) $(OBJS) langlex.o langparse.o $@.o  -o $@

langlex.c: lang.l langparse.c
	flex -o langlex.c lang.l

langlex.o: langlex.c
	$(CC) $(COPTS) -Wno-sign-compare $? -o $@

langparse.c: lang.y
	bison --defines=langparse.h lang.y -o langparse.c

langparse.o: langparse.c
		$(CC) $(COPTS) $? -o $@

%.o: %.cpp
	$(CC) $(COPTS) $? -o $@

$(OBJ)/%.o: $(SRC)/%.cpp obj
	$(CC) $(COPTS) $< -o $@

obj:
	mkdir -p $(OBJ)
