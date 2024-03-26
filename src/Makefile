CC=gcc
CFLAGS=-Wall -Wextra -std=c11
GTKFLAGS=`pkg-config --cflags --libs gtk+-3.0`
TARGET=mon_terminal

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.c terminal_ui.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c terminal_ui.c $(GTKFLAGS)

run: $(target)
	./mon_terminal

clean:
	rm -f $(TARGET)

