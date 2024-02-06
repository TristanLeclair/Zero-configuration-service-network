CC=gcc
CFLAGS=-I./include -Wall -Wextra -g
LDFLAGS=
BINDIR=./bin
SRCDIR=./src
LIBDIR=./lib
OBJDIR=$(LIBDIR)/obj

# Automatically find common source files
COMMON_SOURCES := $(wildcard $(SRCDIR)/common/*/*.c)
COMMON_OBJECTS := $(COMMON_SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# All targets
all: $(BINDIR)/app $(BINDIR)/service

# Compile app
$(BINDIR)/app: $(OBJDIR)/app/app.o $(COMMON_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

# Compile service
$(BINDIR)/service: $(OBJDIR)/service/service.o $(COMMON_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

# Generic rule for compiling source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(BINDIR)/*
	rm -rf $(LIBDIR)

.PHONY: all clean

