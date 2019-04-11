	.file	"strcat.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "what's your favorite flower\0"
LC1:
	.ascii "%u \12\0"
LC2:
	.ascii "%p \12\0"
LC3:
	.ascii "End of file encountered\0"
LC4:
	.ascii "bye\0"
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
	subl	$64, %esp
	call	___main
	movl	$1836261491, 31(%esp)
	movl	$543976549, 35(%esp)
	movl	$1701538156, 39(%esp)
	movl	$1684827936, 43(%esp)
	movl	$1869116192, 47(%esp)
	movw	$29541, 51(%esp)
	movb	$0, 53(%esp)
	movl	$LC0, (%esp)
	call	_puts
	movl	$10, 4(%esp)
	leal	54(%esp), %eax
	movl	%eax, (%esp)
	call	_s_gets
	testl	%eax, %eax
	je	L2
	movl	$10, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	54(%esp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	54(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	leal	31(%esp), %eax
	movl	%eax, 4(%esp)
	leal	54(%esp), %eax
	movl	%eax, (%esp)
	call	_strcat
	leal	54(%esp), %eax
	movl	%eax, (%esp)
	call	_puts
	movl	$10, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	54(%esp), %eax
	movl	%eax, (%esp)
	call	_strlen
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	leal	54(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	leal	31(%esp), %eax
	movl	%eax, (%esp)
	call	_puts
	jmp	L3
L2:
	movl	$LC3, (%esp)
	call	_puts
L3:
	movl	$LC4, (%esp)
	call	_puts
	call	_getchar
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.globl	_s_gets
	.def	_s_gets;	.scl	2;	.type	32;	.endef
_s_gets:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	movl	__imp___iob, %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_fgets
	movl	%eax, -16(%ebp)
	cmpl	$0, -16(%ebp)
	je	L6
	jmp	L7
L9:
	addl	$1, -12(%ebp)
L7:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$10, %al
	je	L8
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L9
L8:
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$10, %al
	jne	L11
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movb	$0, (%eax)
	jmp	L6
L12:
	nop
L11:
	call	_getchar
	cmpl	$10, %eax
	jne	L12
L6:
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_strlen;	.scl	2;	.type	32;	.endef
	.def	_strcat;	.scl	2;	.type	32;	.endef
	.def	_getchar;	.scl	2;	.type	32;	.endef
	.def	_fgets;	.scl	2;	.type	32;	.endef
