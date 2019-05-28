# CTYPE LIST OF OBJECT FILES - v0.1
#
# A list of all the ctype object files. Should be included in libc's top-level
# makefile.
#
#
# 2019 Diogo Gomes

# libk's objects
FREEOBJS:=$(FREEOBJS) \
ctype/istype.o \

# libc's objects
HOSTEDOBJS=$(HOSTEDOBJS)\