# Target Tool Specification Makefile (target_tools.mk)
#
# - To create a PIL implementation for your own processor, you
#   can modify this makefile to specify the appropriate
#   embedded tools and options.
# - This file is included by ec_target.tmf. 
#
# Copyright 2009-2011 The MathWorks, Inc.

# From tool_paths.mk
TI_INSTALL    = $(CCSROOTDIR)
TARGET_SOURCE = $(EXAMPLEPILF28335DIR)\F28335SerialRtiostream

# Helpers
TI_TOOLS     = $(TI_INSTALL)\TOOLS\COMPILER\C2000\BIN
TI_INCLUDE   = $(TI_INSTALL)\TOOLS\COMPILER\C2000\INCLUDE
TI_LIB       = $(TI_INSTALL)\TOOLS\COMPILER\C2000\LIB
F28_HEADERS  = $(TIF28XXXSYSSWDIR)\~SupportFiles\DSP2833x_headers

# Compiler command and options
CC     = "$(TI_TOOLS)\cl2000"
CFLAGS = --compile_only \
         --float_support=fpu32 \
         --large_memory_model --silicon_version=28 --opt_level=2 \
         --define="_DEBUG" --define="LARGE_MODEL"\
         -i"$(TARGET_SOURCE)" \
         -i"$(F28_HEADERS)" \
         -i"$(F28_HEADERS)\include" \
         -i"$(TI_INCLUDE)" -os 

CFLAGS += $(OPTS)
CDEBUG = -g
CCOUTPUTFLAG = --output_file=

CXX      =
CXXFLAGS =
CXXDEBUG =

# Linker command and options
LD      = "$(TI_TOOLS)\cl2000"
LDFLAGS = -z \
          --stack_size=0x380 --warn_sections \
          --reread_libs --rom_model \
          "$(TARGET_SOURCE)\F28335SerialRtiostream_RAM.cmd" \
          "$(F28_HEADERS)\cmd\DSP2833x_Headers_nonBIOS.cmd" \
          -m"$(MODEL).map" \
          -l"$(TI_LIB)\rts2800_fpu32.lib" \
          -os
LDDEBUG = -g
LDOUTPUTFLAG = --output_file=

# Archiver command and options
AR      = "$(TI_TOOLS)\ar2000"
ARFLAGS = -r

# Binary file format converter command and options
OBJCOPY      = 
OBJCOPYFLAGS = 

# Specify the output extension from compiler
OBJ_EXT = .o

# Specify extension from linker
PROGRAM_FILE_EXT = .out 

# Specify extension for final product at end of build
EXE_FILE_EXT     = $(PROGRAM_FILE_EXT)



