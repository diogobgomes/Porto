#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/porto.kernel isodir/boot/porto.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "porto" {
	multiboot /boot/porto.kernel
}
EOF
grub-mkrescue -o porto.iso isodir
