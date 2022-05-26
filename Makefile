# This makefile builds an executable % for each %.cpp file.

CC = g++
CXXFLAGS = -Wall -Werror -std=c++2a -g -O0

sources := $(shell find . -name *.cpp)
targets := $(basename $(sources))

all: $(targets)

$(targets): %: %.cpp

.PHONY = clean

clean:
	$(RM) $(targets)