CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -I../include
OBJS = util.o vector.o list.o map.o

all: vector_test list_test map_test

vector_test: vector_test.c $(OBJS)
	$(CC) $(CFLAGS) vector_test.c $(OBJS) -o vector_test

list_test: list_test.c $(OBJS)
	$(CC) $(CFLAGS) list_test.c $(OBJS) -o list_test

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
