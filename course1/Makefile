#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Makefile for c1m2 project. 
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      .i -> make main.i, just run the preprocessor and leave a .i file.
#      .o -> make main.o, just run compile and leave a .o file.
#      .asm -> make main.asm, assembly language output file .asm, no link or compile.
#      compile-all ->  compile all source, do not link output file.
#      build -> compile all source, link output file. DEFAULT target.
#      all -> equivalent to 'build' target.
#      clean -> Remove all intermediate, assembler, map, and object code files.
#
# Platform Overrides:
#      make [TARGET] -> default Platform -> MSP432 (ELF 32-bit LSB executable, ARM, EABI5)
#      make [TARGET] PLATFORM=HOST -> Build for host (ELF 64-bit LSB shared object, x86-64)
#      make [TARGET] PLATFORM=MSP432 -> MSP432 (ELF 32-bit LSB executable, ARM, EABI5)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

BASENAME = c1m2
TARGET = $(BASENAME).out

OBJS = $(SOURCES:.c=.o)
INTERMEDIATE = $(SOURCES:.c=.i)
ASMFILES = $(SOURCES:.c=.asm)
DEPFILES = $(SOURCES:.c=.d)

.PHONY: build
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) $(DFLAGS) -o $@
	size $(TARGET)

%.i : %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -E $< -o $@ $(DFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(DFLAGS)

%.asm : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -S $< -o $@ $(DFLAGS)

compile-all : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(OBJS) $(DFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(INTERMEDIATE) $(ASMFILES) $(DEPFILES) $(TARGET) $(BASENAME).map

