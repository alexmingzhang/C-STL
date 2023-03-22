CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Wpedantic -pg -I../include
OBJS = util.o vector.o list.o map.o

all: benchmark benchmarkO3 benchmarkOfast

benchmark: benchmark.cpp $(OBJS)
	$(CC) $(CFLAGS) -O0 benchmark.cpp $(OBJS) -o benchmark

benchmarkO3: benchmark.cpp $(OBJS)
	$(CC) $(CFLAGS) -O3 benchmark.cpp $(OBJS) -o benchmarkO3

benchmarkOfast: benchmark.cpp $(OBJS)
	$(CC) $(CFLAGS) -Ofast benchmark.cpp $(OBJS) -o benchmarkOfast

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
