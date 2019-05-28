# STRING LIST OF OBJECT FILES - v0.1
#
# A list of all the string object files. Should be included in libc's top-level
# makefile.
#
#
# 2019 Diogo Gomes

# libk's objects
FREEOBJS:=$(FREEOBJS) \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memset.o \
string/strlen.o \

# libc's objects
HOSTEDOBJS=$(HOSTEDOBJS)\