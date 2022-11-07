BIN = log_reader
CC:=gcc
CFLAGS:=-Wall -Wextra
SRC = $(wildcard *.c)
OBJS = $(SRC: .c=.o)
LDFLAGS := -L/usr/lib -lloger

PREFIX?=/usr

all: $(BIN)
	$(CC) -o $@ $^ 

%.o:%.c
	$(CC)  $(CFLAGS) -c -o$@ $^ $(LDFLAGS)

install: 
	install -d $(PREFIX)
	install -m 555 ./$(BIN) $(PREFIX)/bin/$(BIN)

uninstall:
	$(RM) $(PREFIX)/bin/$(BIN)

clean:
	$(RM) $(BIN) $(OBJS)
