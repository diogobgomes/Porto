#!/bin/sh
# CONFIGURE HELPER SCRIPT
#
# Returns our target arch
#
#
# 2019 Diogo Gomes

if echo "$1" | grep -Eq 'i[[:digit:]]86-'; then
	echo i386;
else
	echo "$1" | grep -Eo '^[[:alnum:]_]*';
fi