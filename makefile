CC=g++
FLAGS=-O0 -g -std=c++2a
SHARED_LIB:=-lcurses
SANITIZER:=-fsanitize=address,undefined,signed-integer-overflow
WARNINGS:=-Wall -Wextra
FILES:=chat.cpp screens.cpp networking.cpp

all: 
	$(CC) $(FLAGS) $(SANITIZER) $(WARNINGS) $(FILES) $(SHARED_LIB) -o chat.out
