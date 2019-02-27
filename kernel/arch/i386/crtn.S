# CRTN ASSEMBLY STUB
#
# Small assembly stub that gcc processes to include crtend.o
#
#
# 2019 Diogo Gomes

.section .init
	/* gcc will nicely put the contents of crtend.o's .init section here. */
	popl %ebp
	ret

.section .fini
	/* gcc will nicely put the contents of crtend.o's .fini section here. */
	popl %ebp
	ret
