# Makefile - kernel directory
# ---------------------------------------------------------------------------
#
# Run this makefile to build the kernel (only kernel)
# Run 'make help' for a list of targets
#

# TODO
# add help target
# check local build directories
# check HOSTEDOBJS and ARCH_HOSTEDOBJS

override SHELL:=/bin/sh

ifeq (${MAKELEVEL},0)

# Prepare to run as top makefile (not default)

include ../config/make/make.config

# Build directories (local)

PREFIX?=/usr/local
EXEC_PREFIX?=${PREFIX}
INCLUDEDIR?=${PREFIX}/include
LIBDIR?=${EXEC_PREFIX}/lib

endif

include ${ROOT_SRC_DIR}/config/make/make.output

DESTDIR?=${SYSROOT}

# Default compiler flags

CFLAGS:=${CFLAGS}
CLFLAGS:= -D__is_libc -Iinclude
CXXFLAGS:=${CXXFLAGS}
LIBK_CFLAGS:=${CFLAGS}
LIBK_CLFLAGS:=${CFLAGS} -D__is_libk
LIBK_CXXFLAGS:=${CXXFLAGS}

ARCHDIR=arch/${TARGETARCH}

include ${ARCHDIR}/make.config

CFLAGS:=${CFLAGS} ${ARCH_CFLAGS}
CXXFLAGS:=${CXXFLAGS} ${ARCH_CXXFLAGS}
LIBK_CFLAGS:=${LIBK_CFLAGS} ${KERNEL_ARCH_CFLAGS}
LIBK_CXXFLAGS:=${LIBK_CXXFLAGS} ${KERNEL_ARCH_CXXFLAGS}

FREEOBJS=\
$(ARCH_FREEOBJS) \
stdio/printf.o \
stdio/putchar.o \
stdio/puts.o \
stdlib/abort.o \
string/memcmp.o \
string/memcpy.o \
string/memmove.o \
string/memset.o \
string/strlen.o \

HOSTEDOBJS=\
$(ARCH_HOSTEDOBJS) \

OBJS=\
$(FREEOBJS) \
$(HOSTEDOBJS) \

LIBK_OBJS=$(FREEOBJS:.o=.libk.o)

#BINARIES=libc.a libk.a # Not ready for libc yet.
BINARIES=libk.a

.PHONY: all clean install install-headers install-libs help

all: $(BINARIES)

libc.a: $(OBJS)
	$(call cmd,ar)
	$(Q)$(AR) rcs $@ $(OBJS)

libk.a: $(LIBK_OBJS)
	$(call cmd,ar)
	$(Q)$(AR) rcs $@ $(LIBK_OBJS)

%.o: %.c
	$(call cmd,cc)
	$(Q)$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CLFLAGS)

%.S: %.c
	$(call cmd,as)
	$(Q)$(CC) -MD -c $< -o $@ $(CFLAGS) $(CLFLAGS)

%.libk.o: %.c
	$(call cmd,cc)
	$(Q)$(CC) -MD -c $< -o $@ -std=gnu11 $(LIBK_CFLAGS) $(LIBK_CLFLAGS)

%.libk.o: %.S
	$(call cmd,as)
	$(Q)$(CC) -MD -c $< -o $@ $(LIBK_CFLAGS) $(LIBK_CLFLAGS)

clean:
	-$(Q)rm -f $(BINARIES) *.a
	-$(Q)rm -f $(OBJS) $(LIBK_OBJS) *.o */*.o */*/*.o
	-$(Q)rm -f $(OBJS:.o=.d) $(LIBK_OBJS:.o=.d) *.d */*.d */*/*.d
	@echo '   Clean done!'

install: install-headers install-libs

install-headers:
	@echo '   Installing headers to $(DESTDIR)$(INCLUDEDIR)'
	$(Q)mkdir -p $(DESTDIR)$(INCLUDEDIR)
	$(Q)cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-libs: $(BINARIES)
	@echo '   Installing libraries to $(DESTDIR)$(LIBDIR)'
	$(Q)mkdir -p $(DESTDIR)$(LIBDIR)
	$(Q)cp $(BINARIES) $(DESTDIR)$(LIBDIR)

-include $(OBJS:.o=.d)
-include $(LIBK_OBJS:.o=.d)
