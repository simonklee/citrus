# Makefile Used to install a citrus as shared library
# Prerequisite mkdir /opt/lib and add /opt/lib to /etc/ld.so.conf

PRJNAME=citrus

# Project sourcefiles
PRJSRC=citrus.c\
	citrus.h\

# Project testfiles
TESTSRC=test-citrus.c\

# Lib install folder
LIBDIR=/opt/lib

# Header install folder
HEADDIR=/usr/local/include

# Compiler
CC=gcc

# utils
REMOVE=rm -R

# Target
TRG=lib$(PRJNAME)

# C flags
CFLAGS=-Wall #-fPIC

# Sourcefiles
CFILES=$(filter %.c, $(PRJSRC))
CTESTFILES=$(filter %.c, $(TESTSRC))

# Installedfiles
INSTFILES=$(LIBDIR)/$(TRG).so\
	$(LIBDIR)/$(TRG).so.1\
	$(LIBDIR)/$(TRG).so.1.0\
	$(HEADDIR)/$(CHEADERS)\


# Headerfiles
CHEADERS=$(filter %.h, $(PRJSRC))

# List all object files we need to create
OBJDEPS=$(CFILES:.c=.o)   

.SUFFIXES : .c .o .out .s  .h 
.PHONY: clean install uninstall test

# Targets
all: install

install: $(TRG)
	mv $(TRG).so.1.0 $(LIBDIR)
	ln -sf $(LIBDIR)/$(TRG).so.1.0 $(LIBDIR)/$(TRG).so
	ln -sf $(LIBDIR)/$(TRG).so.1.0 $(LIBDIR)/$(TRG).so.1
	cp $(CHEADERS) $(HEADDIR)
	ldconfig

uninstall: 
	$(REMOVE) $(INSTFILES)
	ldconfig

test: install
	$(CC) $(CFLAGS) -L$(LIBDIR) -l$(PRJNAME) $(CTESTFILES) -o $(PRJNAME).out

clean:
	$(REMOVE) $(OBJDEPS)

# Create shared library objects
$(TRG): $(OBJDEPS) 
	$(CC) -shared -Wl,-soname,$(TRG).so.1 -o $(TRG).so.1.0 $(OBJDEPS)

# object from C
.c.o: 
	$(CC) $(CFLAGS)-fPIC -c $< -o $@

