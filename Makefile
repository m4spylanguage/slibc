# 🕷️ slibc - Spider OS Standard C Library
# Copyright (c) 2026 Spider OS Contributors. Licensed under MIT License.

CC ?= musl-gcc
CFLAGS ?= -O2 -Wall -Wextra -fPIC -Iinclude -std=c99
LDFLAGS ?= -shared -Wl,-soname,libslibc.so.1

SRCS = src/c23.c src/chk.c src/dl.c src/gnu_compat.c src/fts.c
OBJS = $(SRCS:.c=.o)
TARGET = libslibc.so.1

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
	ln -sf $(TARGET) libslibc.so

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) libslibc.so

install: $(TARGET)
	install -d /usr/local/lib
	install -m 755 $(TARGET) /usr/local/lib/
	ln -sf $(TARGET) /usr/local/lib/libslibc.so

.PHONY: all clean install
