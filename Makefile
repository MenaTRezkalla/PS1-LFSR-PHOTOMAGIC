CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

.PHONY: all clean lint PhotoMagic.a

all: PhotoMagic test PhotoMagic.a

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

PhotoMagic: main.o FibLFSR.o PhotoMagic.o
	$(CC) $(CFLAGS) -o PhotoMagic main.o FibLFSR.o PhotoMagic.o $(LIB)

test: test.o FibLFSR.o
	$(CC) $(CFLAGS) -o test test.o FibLFSR.o $(LIB)

clean:
	rm *.o PhotoMagic test PhotoMagic.a

lint:
	cpplint *.cpp *.hpp

PhotoMagic.a:
	ar rcs PhotoMagic.a FibLFSR.o PhotoMagic.o FibLFSR.cpp FibLFSR.hpp PhotoMagic.cpp PhotoMagic.hpp
