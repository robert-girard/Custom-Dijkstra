OBJS	= main.o Point.o Graph.o Dijkstra.o
SOURCE	= main.cpp Point.cpp Graph.cpp Dijkstra.cpp
HEADER	= Dijkstra.h Point.h Graph.h
OUT	= main.exe
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

Point.o: Point.cpp
	$(CC) $(FLAGS) Point.cpp 

Graph.o: Graph.cpp
	$(CC) $(FLAGS) Graph.cpp 

Dijkstra.o: Dijkstra.cpp
	$(CC) $(FLAGS) Dijkstra.cpp 


clean:
	rm -f $(OBJS) $(OUT)