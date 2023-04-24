	.file	"Comp222ProgrammingProject.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "Sort using quicksort: \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	movl	$1, -64(%rbp)
	movl	$23, -60(%rbp)
	movl	$45, -56(%rbp)
	movl	$10, -52(%rbp)
	movl	$8, -48(%rbp)
	movl	$99, -44(%rbp)
	movl	$32, -40(%rbp)
	movl	$17, -36(%rbp)
	movl	$54, -32(%rbp)
	movl	$73, -28(%rbp)
	movl	$3, -24(%rbp)
	movl	$89, -20(%rbp)
	movl	$12, -4(%rbp)
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	leaq	-64(%rbp), %rax
	movl	%edx, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	quickSort
	leaq	.LC0(%rip), %rcx
	call	puts
	movl	-4(%rbp), %edx
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	printAnswer
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "%d \0"
	.text
	.globl	printAnswer
	.def	printAnswer;	.scl	2;	.type	32;	.endef
	.seh_proc	printAnswer
printAnswer:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L5
	movl	$10, %ecx
	call	putchar
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	swap
	.def	swap;	.scl	2;	.type	32;	.endef
	.seh_proc	swap
swap:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	24(%rbp), %rax
	movl	(%rax), %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	movq	24(%rbp), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rax)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	partition
	.def	partition;	.scl	2;	.type	32;	.endef
	.seh_proc	partition
partition:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	32(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	movl	24(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -4(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L8
.L10:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -12(%rbp)
	jle	.L9
	addl	$1, -4(%rbp)
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movq	%rax, %rcx
	call	swap
.L9:
	addl	$1, -8(%rbp)
.L8:
	movl	32(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jg	.L10
	movl	32(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	cltq
	addq	$1, %rax
	leaq	0(,%rax,4), %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movq	%rax, %rcx
	call	swap
	movl	-4(%rbp), %eax
	addl	$1, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	quickSort
	.def	quickSort;	.scl	2;	.type	32;	.endef
	.seh_proc	quickSort
quickSort:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	24(%rbp), %eax
	cmpl	32(%rbp), %eax
	jge	.L14
	movl	32(%rbp), %edx
	movl	24(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	partition
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	movl	24(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	quickSort
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	32(%rbp), %edx
	movl	%edx, %r8d
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	quickSort
.L14:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 9.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
