# STDLIB LIST OF OBJECT FILES - v0.1
#
# A list of all the stdlib object files. Should be included in libc's top-level
# makefile.
#
#
# 2019 Diogo Gomes

# libk's objects
FREEOBJS:=$(FREEOBJS) \
stdlib/abort.o \
stdlib/atoi.o \
stdlib/itoa.o \
stdlib/strtol.o \

# libc's objects
HOSTEDOBJS=$(HOSTEDOBJS)\