CC = gcc
CFLAGS = -c -Wall
LDFLAGS =
BINDIR = bin
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(addprefix $(BINDIR)/, $(notdir $(SRC:.c=.o)))
HEADALL = $(SRCDIR)/structures.h $(SRCDIR)/defines.h
HEAD = $(filter-out $(HEADALL), $(wildcard $(SRCDIR)/*.h))
PROG = $(BINDIR)/ordonnanceur

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BINDIR)/main.o: $(SRCDIR)/main.c $(HEADALL) $(BINDIR)
	$(CC) $(CFLAGS) $< -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h $(HEADALL) $(BINDIR)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)

