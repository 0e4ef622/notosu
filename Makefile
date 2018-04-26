BINARY  = notosu
CXX    ?= g++
SHELL  ?= /bin/sh
CXXFLAGS  = -g -Wall
LDFLAGS = -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio
SRCDIR  = src
BINDIR  = bin

ALL_CXXFLAGS := -I$(SRCDIR) $(CXXFLAGS)
SOURCES    := $(shell find $(SRCDIR) -type f -name '*.cpp')
STRUCTURE  := $(sort $(subst $(SRCDIR),$(BINDIR),$(dir $(SOURCES))))
OBJECTS    := $(subst $(SRCDIR),$(BINDIR),$(SOURCES:%.cpp=%.o))

.PHONY: all outdirs clean

all: outdirs $(BINARY)

outdirs: $(STRUCTURE)

$(STRUCTURE):
	mkdir -p $(STRUCTURE)

$(BINARY): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(ALL_CXXFLAGS) -o $(BINARY) $(OBJECTS)

$(OBJECTS): $(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(LDFLAGS) $(ALL_CXXFLAGS) -o $@ -c $<

.depend: $(SOURCES)
	$(CXX) -MM $(SOURCES) $(ALL_CXXFLAGS) | sed "s/\([A-Za-z0-9]\+\)\.o/bin\/\1.o/g" > ./.depend

include .depend

clean:
	-rm -rf bin/ .depend notosu
