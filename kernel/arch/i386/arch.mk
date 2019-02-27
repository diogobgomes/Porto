# MAKEFILE CONFIGURE FILE
#
# Configure some architecture dependent make variables
#
#
# 2019 Diogo Gomes

KERNEL_ARCH_CFLAGS=
KERNEL_ARCH_CXXFLAGS=
KERNEL_ARCH_LDFLAGS=
KERNEL_ARCH_LIBS=

KERNEL_ARCH_OBJS=\
$(ARCHDIR)/boot.o \
$(ARCHDIR)/tty.o \
