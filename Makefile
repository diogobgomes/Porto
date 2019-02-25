# Makefile - Top level Makefile
# ---------------------------------------------------------------------------
#
# Run this makefile to build the entire OS
# Run 'make help' for a list of targets
#

# TODO
# add help target
# confirm better way of handling install-headers
# add dependency header tracking
# add cleandep target
# add ./configure
export
override SHELL:=/bin/sh

ifeq ($(MAKELEVEL),0)
include config/make/make.config
endif

include config/make/make.output

# Build directories, defined here for global compilation
export PREFIX:=/usr
export EXEC_PREFIX:=$(PREFIX)
export BOOTDIR:=/boot
export LIBDIR:=$(EXEC_PREFIX)/lib
export INCLUDEDIR:=$(PREFIX)/include

# Subdirectories where we have to go with make
SUBDIRS:=libc kernel
HEADER_SUBDIR=include

# Final kernel iso
KERNEL_ISO := $(PROJECT_NAME)-$(VERSION).$(SUBVERSION)-$(RELEASE).iso

.PHONY: all clean install qemu install-headers help

all: $(SUBDIRS)

install-headers: $(SYSROOT) $(SYSROOT)$(INCLUDEDIR)

$(SYSROOT)$(INCLUDEDIR): $(HEADER_SUBDIR)
	@echo 'Installing headers to $(SYSROOT)$(INCLUDEDIR)'
	$(Q)mkdir -p $(SYSROOT)$(INCLUDEDIR)
	$(Q)cp -R --preserve=timestamp $(HEADER_SUBDIR)/. $(SYSROOT)$(INCLUDEDIR)

$(SUBDIRS): $(SYSROOT) install-headers
	@$(MAKE) -C $@ install

kernel: libc

$(SYSROOT):
	$(Q)mkdir -p $(SYSROOT)


install: all $(KERNEL_ISO)

$(KERNEL_ISO):
	@echo '   Installing OS to isodir/boot/grub'
	$(Q)mkdir -p isodir/boot/grub
	$(Q)cp sysroot/boot/$(PROJECT_NAME).kernel isodir/boot/$(PROJECT_NAME).kernel
	$(Q)echo "menuentry \"$(PROJECT_NAME)\" {\
		multiboot /boot/$(PROJECT_NAME).kernel\
	}" > isodir/boot/grub/grub.cfg
	@echo '   Creating bootloader image...'
	$(Q)$(ISOTOOL) -o $(KERNEL_ISO) isodir

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	-$(Q)rm -rf $(SYSROOT)
	-$(Q)rm -rf isodir
	-$(Q)rm -rf $(KERNEL_ISO)
	@echo '   Clean done!'

qemu: install
	@echo '   Starting qemu for $(TARGETARCH)'
	$(Q)qemu-system-$(TARGETARCH) -cdrom $(KERNEL_ISO)
