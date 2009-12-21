
# Simon's Makefile :))
# Use as you wish. GPL whatever.

PROJECTNAME=citrus

# Project sourcefiles
PRJSRC=

# Compiler
CC=gcc

# utils
REMOVE=rm -Rf

# Target
TRG=$(PROJECTNAME).out
DUMPTRG=$(PROJECTNAME).s
OBJDUMP=objdump

# C flags
CFLAGS=-I ../libs/

# Sourcefiles
CFILES=$(filter %.c, $(PRJSRC))

# List all object files we need to create
OBJDEPS=$(CFILES:.c=.o)   

# Assembler 
GENASMFILES=$(filter %.s, $(OBJDEPS:.o=.s)) 

.SUFFIXES : .c .o .out .s  .h 
.PHONY: clean

# Targets
all: $(TRG)

asm: $(DUMPTRG)

$(TRG): $(OBJDEPS) 
	$(CC) $(CFLAGS) -o $(TRG) $(OBJDEPS)

$(DUMPTRG): $(TRG) 
	$(OBJDUMP) -S  $< > $@

# Assembler from C
%.s: %.c
	$(CC) -S $< -o $@

# object from C
.c.o: 
	$(CC) -c $< -o $@

# Clean the house.
clean:
	$(REMOVE) $(OBJDEPS)
	$(REMOVE) $(DUMPTRG)
