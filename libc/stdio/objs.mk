# STDIO LIST OF OBJECT FILES - v0.1
#
# A list of all the stdio object files. Should be included in libc's top-level
# makefile.
#
#
# 2019 Diogo Gomes

# libk's objects
FREEOBJS:=$(FREEOBJS) \
stdio/printf.o \
stdio/putchar.o \
stdio/puts.o \

# libc's objects
HOSTEDOBJS=$(HOSTEDOBJS)\