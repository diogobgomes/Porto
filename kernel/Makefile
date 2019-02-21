# Makefile - kernel directory
# ---------------------------------------------------------------------------
#
# Run this makefile to build the kernel (only kernel)
# Run 'make help' for a list of targets
#

# TODO
# add help target
# check local build directories
# IMPORTANT: target crtbegin and crtend need revamp - no OBJ=...

override SHELL:=/bin/sh

ifeq (${MAKELEVEL},0)

# Prepare to run as top makefile (not default)

include ../config/make/make.config

# Build directories (local)

PREFIX?=/usr/local
EXEC_PREFIX?=$(PREFIX)
BOOTDIR?=$(EXEC_PREFIX)/boot
INCLUDEDIR?=$(PREFIX)/include

endif

include ${ROOT_SRC_DIR}/config/make/make.output

DESTDIR?=${SYSROOT}

# Default compiler flags

CFLAGS:=$(CFLAGS)
CKFLAGS:= -D__is_kernel -Iinclude
CXXFLAGS:=$(CXXFLAGS)
CXXKFLAGS:=
LDFLAGS:=$(LDFLAGS)
LIBS:=$(LIBS) -nostdlib -lk -lgcc

ARCHDIR=arch/$(TARGETARCH)

include $(ARCHDIR)/make.config

CFLAGS:=$(CFLAGS) $(KERNEL_ARCH_CFLAGS)
CXXFLAGS:=$(CXXFLAGS) $(KERNEL_ARCH_CXXFLAGS)
LDFLAGS:=$(LDFLAGS) $(KERNEL_ARCH_LDFLAGS)
LIBS:=$(LIBS) $(KERNEL_ARCH_LIBS)

KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
kernel/kernel.o \

OBJS=\
$(ARCHDIR)/crti.o \
$(ARCHDIR)/crtbegin.o \
$(KERNEL_OBJS) \
$(ARCHDIR)/crtend.o \
$(ARCHDIR)/crtn.o \

LINK_LIST=\
$(LDFLAGS) \
$(ARCHDIR)/crti.o \
$(ARCHDIR)/crtbegin.o \
$(KERNEL_OBJS) \
$(LIBS) \
$(ARCHDIR)/crtend.o \
$(ARCHDIR)/crtn.o \

.PHONY: all clean install install-headers install-kernel
.SUFFIXES: .o .c .S

all: ${PROJECT_NAME}.kernel

${PROJECT_NAME}.kernel: $(OBJS) $(ARCHDIR)/linker.ld
	$(call cmd,ld)
	$(Q)$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot ${PROJECT_NAME}.kernel

$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o:
	OBJ=`$(CC) $(CFLAGS) $(LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@

%.o: %.c
	$(call cmd,cc)
	$(Q)$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS) $(CKFLAGS)

%.o: %.S
	$(call cmd,as)
	$(Q)$(CC) -MD -c $< -o $@ $(CFLAGS) $(CKFLAGS)

clean:
	-$(Q)rm -f ${PROJECT_NAME}.kernel
	-$(Q)rm -f $(OBJS) *.o */*.o */*/*.o
	-$(Q)rm -f $(OBJS:.o=.d) *.d */*.d */*/*.d
	@echo '   Clean done!'

install: install-headers install-kernel

install-headers:
	@echo '   Installing headers to $(DESTDIR)$(INCLUDEDIR)'
	$(Q)mkdir -p $(DESTDIR)$(INCLUDEDIR)
	$(Q)cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-kernel: ${PROJECT_NAME}.kernel
	@echo '   Installing kernel to $(DESTDIR)$(BOOTDIR)'
	$(Q)mkdir -p $(DESTDIR)$(BOOTDIR)
	$(Q)cp ${PROJECT_NAME}.kernel $(DESTDIR)$(BOOTDIR)

-include $(OBJS:.o=.d)
