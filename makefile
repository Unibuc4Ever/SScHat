CC=g++
FLAGS=-O0 -g -std=c++2a
SHARED_LIB:=-lcurses
SANITIZER:=-fsanitize=address,undefined,signed-integer-overflow
WARNINGS:=-Wall -Wextra
FILES:=chat.cpp screens.cpp networking.cpp

all:
	gcc -c Telemetry/Client/telemetry.c -I Telemetry/Shared -o telemetry.o
	gcc -c Telemetry/Shared/fifo_parser.c -o fifo_parser.o
	gcc -c Telemetry/Shared/standard.c -o standard.o
	gcc -c Telemetry/Shared/treap.c -o treap.o
	g++ -c chat.cpp -o chat.o
	g++ -c networking.cpp -o networking.o -l Telemetry/Client
	g++ -c screens.cpp -o screens.o
	g++ fifo_parser.o standard.o treap.o telemetry.o chat.o networking.o screens.o -l curses -l pthread -o chat.out
