CC:=gcc
LIB:=liblogger.so
SRC:=$(wildcard *.c)
OBJS:=$(SRC:.c=.o)
LDFLAGS := -shared
CFLAGS:= -fPIC -Wall -Wextra
PREFIX ?=/usr

.PHONY: all, clean, install uninstall

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

install:
	install -d $(PREFIX)/lib
	install -d $(PREFIX)/include
	install -m 644 $(LIB) $(PREFIX)/lib/$(LIB)
	install -m 644 logger.h $(PREFIX)/include/logger.h

uninstall: 
	$(RM) $(PREFIX)/lib/$(LIB)
	$(RM) $(PREFIX)/include/logger.h
	
clean:
	$(RM) $(LIB) $(OBJS)