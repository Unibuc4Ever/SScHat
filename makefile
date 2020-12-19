CC=g++
FLAGS=-O0 -g -std=c++2a
SHARED_LIB:=-lcurses -lpthread
SANITIZER:=-fsanitize=address,undefined,signed-integer-overflow
WARNINGS:=-Wall -Wextra
FILES:=$(wildcard ./*.cpp)

all: lib
	$(CC) $(COMP_FLAGS) $(SANITIZER) -o chat.out $(FILES) Telemetry/libtelemetry.a $(SHARED_LIB) 
	# gcc -c Telemetry/Client/telemetry.c -I Telemetry/Shared -o telemetry.o
	# gcc -c Telemetry/Shared/fifo_parser.c -o fifo_parser.o
	# gcc -c Telemetry/Shared/standard.c -o standard.o
	# gcc -c Telemetry/Shared/treap.c -o treap.o
	# g++ -c chat.cpp -o chat.o
	# g++ -c networking.cpp -o networking.o -l Telemetry/Client
	# g++ -c screens.cpp -o screens.o
	# g++ fifo_parser.o standard.o treap.o telemetry.o chat.o networking.o screens.o -l curses -l pthread -o chat.out


lib:
	cd Telemetry && $(MAKE) client



# CC=gcc
# FLAGS=-O0 -g
# DAEMON_CFILES:=$(wildcard ./Daemon/*.c)
# CLIENT_CFILES:=$(wildcard ./Client/*.c)
# SHARED_CFILES:=$(wildcard ./Shared/*.c)
# SHARED_LIB:=-IShared -IClient -pthread
# SANITIZER:=-fsanitize=address,undefined,signed-integer-overflow
# WARNINGS:=-Wall -Wextra

# CLIENT_O_FILES:=$(patsubst %.c, %.o, $(CLIENT_CFILES) $(SHARED_CFILES))

# COMP_FLAGS:=$(FLAGS) $(SANITIZER) $(WARNINGS) $(SHARED_LIB)

# all: client daemon demo

# daemon: $(DAEMON_CFILES) $(SHARED_CFILES)
# 	$(CC) $(FLAGS) $(SANITIZER) $(WARNINGS) $(SHARED_LIB) $(SHARED_CFILES) $(DAEMON_CFILES) -o daemon.out

# client: $(SHARED_CFILES) $(CLIENT_CFILES)
# 	$(CC) -c $(FLAGS) $(SANITIZER) $(WARNINGS) $(SHARED_LIB) $(SHARED_CFILES) $(CLIENT_CFILES)
# 	ar rc libtelemetry.a fifo_parser.o  standard.o  telemetry.o  treap.o 

# demo: client
# 	$(CC) -c $(COMP_FLAGS) ./Demo/main.c -o main.o
# 	$(CC) $(COMP_FLAGS) -o main.out Demo/main.c libtelemetry.a