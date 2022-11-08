TARGET=main
OBJ=Dnode.h DoubleLinkedList.h Deque.h Evaluator.h Evaluator.o main.o
CC=g++
CFLAGS=-c

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(OBJ)
