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

# Add your Source files to this variable
SOURCES_MSP432 = src/main.c \
	  src/memory.c \
	  src/data.c \
	  src/course1.c \
	  src/interrupts_msp432p401r_gcc.c \
	  src/startup_msp432p401r_gcc.c \
	  src/system_msp432p401r.c

SOURCES_HOST = src/main.c \
	       src/memory.c \
	       src/data.c \
	       src/course1.c

# Add your include paths to this variable
INCLUDES = -I include/CMSIS/ \
	   -I include/common/ \
	   -I include/msp432/


# Architectures Specific Flags
LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
FLOAT = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs

AFLAGS = -Wall \
	 -Werror \
	 -g \
	 -O0 \
	 -std=c99 \
	 -MD

ARMFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=$(FLOAT) -mfpu=$(FPU) --specs=$(SPECS)

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
  CC = gcc
  CFLAGS = $(AFLAGS)
  DFLAGS = -DHOST=true
  LD = ld
  LDFLAGS = -Wl,-Map=$(BASENAME).map
  SOURCES = $(SOURCES_HOST)
else
  CC = arm-none-eabi-gcc
  CFLAGS = $(AFLAGS) $(ARMFLAGS)
  DFLAGS = -DMSP432=true
  LD = arm-none-eabi-ld
  LDFLAGS = -Wl,-T $(LINKER_FILE) -Wl,-Map=$(BASENAME).map
  SOURCES = $(SOURCES_MSP432)
endif
CPPFLAGs = 

