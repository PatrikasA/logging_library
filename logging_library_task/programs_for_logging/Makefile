BIN = program_that_logs
CC:=gcc
CFLAGS:=-Wall -Wextra
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
LDFLAGS := -L/usr/lib -llogger

PREFIX?=/usr

.PHONY: all install uninstall clean

all: $(BIN)

$(BIN): program_that_logs.o
	$(CC)  $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c 
	$(CC) -c $^

install: 
	install -d $(PREFIX)
	install -m 555 ./$(BIN) $(PREFIX)/bin/$(BIN)

uninstall:
	$(RM) $(PREFIX)/bin/$(BIN)

clean:
	$(RM) $(BIN) $(OBJS)