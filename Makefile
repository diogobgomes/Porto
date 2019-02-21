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

export ROOT_SRC_DIR := $(shell pwd)

include ${ROOT_SRC_DIR}/config/make/make.config
include ${ROOT_SRC_DIR}/config/make/make.output

# Build directories, defined here for global compilation
export PREFIX:=/usr
export EXEC_PREFIX:=$(PREFIX)
export BOOTDIR:=/boot
export LIBDIR:=${EXEC_PREFIX}/lib
export INCLUDEDIR:=$(PREFIX)/include

# Subdirectories where we have to go with make
SUBDIRS:=libc kernel
HEADER_SUBDIRS=${SUBDIRS}

# Final kernel iso
KERNEL_ISO := ${PROJECT_NAME}-${VERSION}.${SUBVERSION}-${RELEASE}.iso

.PHONY: all clean header-subdirs install-headers ${HEADER_SUBDIRS} #sysroot help install-headers ${SUBDIRS} subdirs install 

all: ${SUBDIRS}

install-headers: ${SYSROOT} #header-subdirs
	@echo '##########install-headers##############'
	@for dir in ${SUBDIRS}; do \
		${MAKE} -C $$dir install-headers; \
	done

#${SUBDIRS}/include: ${SYSROOT} #header-subdirs
#	@echo '##########install-headers##############'
#	@for dir in ${SUBDIRS}; do \
#		${MAKE} -C $$dir install-headers; \
#	done

#header-subdirs: ${HEADER_SUBDIRS}

#${HEADER_SUBDIRS}:
#	${MAKE} -C $@ install-headers;

#subdirs: ${SUBDIRS}
#	@echo '#########subdirs##############3'

${SUBDIRS}: ${SYSROOT}
	@# We must intall-headers first because for successfull install we must garantee all headers are installed
	@for dir in ${SUBDIRS}; do \
		${MAKE} -C $$dir install-headers; \
	done
	@${MAKE} -C $@ install

kernel: libc

${SYSROOT}:
	$(Q)mkdir -p ${SYSROOT}


install: all
	@echo '   Installing OS to isodir/boot/grub'
	$(Q)mkdir -p isodir/boot/grub
	$(Q)cp sysroot/boot/${PROJECT_NAME}.kernel isodir/boot/${PROJECT_NAME}.kernel
	$(Q)echo "menuentry \"${PROJECT_NAME}\" {\
		multiboot /boot/${PROJECT_NAME}.kernel\
	}" > isodir/boot/grub/grub.cfg
	@echo '   Creating bootloader image...'
	$(Q)grub-mkrescue -o ${KERNEL_ISO} isodir

clean:
	@for dir in ${SUBDIRS}; do \
		@${MAKE} -C $$dir clean; \
	done
	-$(Q)rm -rf ${SYSROOT}
	-$(Q)rm -rf isodir
	-$(Q)rm -rf ${KERNEL_ISO}
	@echo '   Clean done!'

qemu: install
	@echo '   Starting qemu for ${TARGETARCH}'
	$(Q)qemu-system-${TARGETARCH} -cdrom ${KERNEL_ISO}
