CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -pg -I../include
OBJS = util.o vector.o list.o map.o

all: benchmark benchmarkoptimized

benchmark: benchmark.cpp $(OBJS)
	$(CC) $(CFLAGS) benchmark.cpp $(OBJS) -o benchmark

benchmarkoptimized: benchmark.cpp $(OBJS)
	$(CC) $(CFLAGS) -O3 benchmark.cpp $(OBJS) -o benchmarkoptimized

map_test: map_test.c $(OBJS)
	$(CC) $(CFLAGS) map_test.c $(OBJS) -o map_test

util.o: ../src/util.c ../include/util.h
	$(CC) $(CFLAGS) -c ../src/util.c

vector.o: ../src/vector.c ../include/vector.h
	$(CC) $(CFLAGS) -c ../src/vector.c

list.o: ../src/list.c ../include/list.h
	$(CC) $(CFLAGS) -c ../src/list.c

map.o: ../src/map.c ../include/map.h
	$(CC) $(CFLAGS) -c ../src/map.c

clean:
	rm -f *.o test
