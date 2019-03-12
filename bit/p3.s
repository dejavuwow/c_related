	.file	"p3.c"
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%p %p %p\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$1, 28(%esp)
	movl	$3, 16(%esp)
	movzbl	20(%esp), %eax
	orl	$1, %eax
	movb	%al, 20(%esp)
	movzwl	20(%esp), %eax
	andw	$-2047, %ax
	orl	$46, %eax
		movw	%ax, 20(%esp)
	movzbl	24(%esp), %eax
	andl	$-16, %eax
	orl	$2, %eax
	movb	%al, 24(%esp)
	movzbl	24(%esp), %eax
	andl	$-17, %eax
	movb	%al, 24(%esp)
	leal	16(%esp), %eax
	movl	%eax, 12(%esp)
	leal	20(%esp), %eax
	movl	%eax, 8(%esp)
	leal	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	call	_getchar
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.ident	"GCC: (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_getchar;	.scl	2;	.type	32;	.endef
