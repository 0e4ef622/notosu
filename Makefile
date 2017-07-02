BINARY  = notosu
CC      = g++
SHELL   = /bin/sh
CFLAGS  = -g -Wall
LDFLAGS = -lsfml-graphics -lsfml-system -lsfml-window
SRCDIR  = src
BINDIR  = bin

ALL_CFLAGS := -I$(SRCDIR) $(CFLAGS)
SOURCES    := $(shell find $(SRCDIR) -type f -name '*.cpp')
STRUCTURE  := $(sort $(subst $(SRCDIR),$(BINDIR),$(dir $(SOURCES))))
OBJECTS    := $(subst $(SRCDIR),$(BINDIR),$(SOURCES:%.cpp=%.o))

.PHONY: all outdirs clean

all: outdirs $(BINARY)

outdirs: $(STRUCTURE)

$(STRUCTURE):
	mkdir -p $(STRUCTURE)

$(BINARY): $(OBJECTS)
	$(CC) $(LDFLAGS) $(ALL_CFLAGS) -o $(BINARY) $(OBJECTS)

$(OBJECTS): $(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(LDFLAGS) $(ALL_CFLAGS) -o $@ -c $<

.depend: $(SOURCES)
	$(CC) -MM $(SOURCES) $(ALL_CFLAGS) | sed "s/\([A-Za-z0-9]\+\)\.o/bin\/\1.o/g" > ./.depend

include .depend

clean:
	-rm -rf bin/ .depend notosu
