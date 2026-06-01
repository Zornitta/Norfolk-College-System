
TARGET = programa

SRCS = main.c $(wildcard src/*.c)

OBJS = $(patsubst %.c, obj/%.o, $(notdir $(SRCS)))

CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)


obj/main.o: main.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p obj

clean:
	rm -rf obj $(TARGET)

.PHONY: all clean
