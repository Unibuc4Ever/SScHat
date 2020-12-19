CC=g++
FLAGS=-O0 -g -std=c++2a
SHARED_LIB:=-lcurses -lpthread
SANITIZER:=-fsanitize=address,undefined,signed-integer-overflow
WARNINGS:=-Wall -Wextra
FILES:=$(wildcard ./*.cpp)
COMP_FLAGS:=$(FLAGS) $(SANITIZER)
all: lib
	$(CC) $(COMP_FLAGS) -o chat.out $(FILES) Telemetry/libtelemetry.a $(SHARED_LIB)

lib:
	cd Telemetry && $(MAKE) client
