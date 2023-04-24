	.file	"project1.c"
	.text
	.globl	binHex
	.section .rdata,"dr"
	.align 32
binHex:
	.ascii "0000\0"
	.ascii "0001\0"
	.ascii "0010\0"
	.ascii "0011\0"
	.ascii "0100\0"
	.ascii "0101\0"
	.ascii "0110\0"
	.ascii "0111\0"
	.ascii "1000\0"
	.ascii "1001\0"
	.ascii "1010\0"
	.ascii "1011\0"
	.ascii "1100\0"
	.ascii "1101\0"
	.ascii "1110\0"
	.ascii "1111\0"
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	call	__main
	cmpl	$1, 16(%rbp)
	jg	.L2
	call	getUserInput
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	call	printResults
	jmp	.L3
.L2:
	movq	24(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	strtol
	movl	%eax, %ecx
	call	printResults
.L3:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "Enter a decimal value \0"
.LC1:
	.ascii "%d\0"
	.text
	.globl	getUserInput
	.def	getUserInput;	.scl	2;	.type	32;	.endef
	.seh_proc	getUserInput
getUserInput:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	.LC0(%rip), %rcx
	call	puts
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	movl	-4(%rbp), %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC2:
	.ascii "The value of %d in Hex is %s \12\0"
	.align 8
.LC3:
	.ascii "The value of %d in Octal is %s \12\0"
	.align 8
.LC4:
	.ascii "The value of %d in Binary is %s \12\0"
	.text
	.globl	printResults
	.def	printResults;	.scl	2;	.type	32;	.endef
	.seh_proc	printResults
printResults:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %ecx
	call	decimalToHex
	movq	%rax, -8(%rbp)
	movl	16(%rbp), %ecx
	call	decimalToOctal
	movq	%rax, -16(%rbp)
	movl	16(%rbp), %ecx
	call	decimalToBinary
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %r8
	movl	16(%rbp), %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	movq	-16(%rbp), %rax
	movq	%rax, %r8
	movl	16(%rbp), %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	movq	-24(%rbp), %rax
	movq	%rax, %r8
	movl	16(%rbp), %edx
	leaq	.LC4(%rip), %rcx
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	nop
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC6:
	.ascii "%x\0"
	.text
	.globl	decimalToHex
	.def	decimalToHex;	.scl	2;	.type	32;	.endef
	.seh_proc	decimalToHex
decimalToHex:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cvtsi2sdl	16(%rbp), %xmm0
	call	log10
	movsd	.LC5(%rip), %xmm1
	divsd	%xmm1, %xmm0
	cvttsd2sil	%xmm0, %eax
	cltq
	addq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	16(%rbp), %r8d
	leaq	.LC6(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC8:
	.ascii "%o\0"
	.text
	.globl	decimalToOctal
	.def	decimalToOctal;	.scl	2;	.type	32;	.endef
	.seh_proc	decimalToOctal
decimalToOctal:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	cvtsi2sdl	16(%rbp), %xmm0
	call	log10
	movsd	.LC7(%rip), %xmm1
	divsd	%xmm1, %xmm0
	cvttsd2sil	%xmm0, %eax
	cltq
	addq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	16(%rbp), %r8d
	leaq	.LC8(%rip), %rdx
	movq	%rax, %rcx
	call	sprintf
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	decimalToBinary
	.def	decimalToBinary;	.scl	2;	.type	32;	.endef
	.seh_proc	decimalToBinary
decimalToBinary:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %ecx
	call	decimalToHex
	movq	%rax, -8(%rbp)
	cvtsi2sdl	16(%rbp), %xmm0
	call	log
	movsd	.LC9(%rip), %xmm1
	divsd	%xmm1, %xmm0
	cvttsd2sil	%xmm0, %eax
	addl	$6, %eax
	movl	%eax, -12(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movl	%eax, -16(%rbp)
	movl	-12(%rbp), %eax
	cltq
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -24(%rbp)
	movl	-16(%rbp), %ecx
	movq	-8(%rbp), %rdx
	movq	-24(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	hexToBinary
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-24(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	hexToBinary
	.def	hexToBinary;	.scl	2;	.type	32;	.endef
	.seh_proc	hexToBinary
hexToBinary:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movl	%eax, -4(%rbp)
	movq	24(%rbp), %rdx
	movl	-4(%rbp), %eax
	movq	%rdx, %r8
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	loopHelper
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	hexToDecimal
	.def	hexToDecimal;	.scl	2;	.type	32;	.endef
	.seh_proc	hexToDecimal
hexToDecimal:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	cmpb	$47, 16(%rbp)
	jle	.L16
	cmpb	$96, 16(%rbp)
	jle	.L17
	cmpb	$64, 16(%rbp)
	jle	.L18
	movsbl	16(%rbp), %eax
	subl	$55, %eax
	jmp	.L19
.L18:
	movsbl	16(%rbp), %eax
	subl	$87, %eax
	jmp	.L19
.L17:
	movsbl	16(%rbp), %eax
	subl	$48, %eax
	jmp	.L19
.L16:
	movl	$0, %eax
.L19:
	popq	%rbp
	ret
	.seh_endproc
	.globl	loopHelper
	.def	loopHelper;	.scl	2;	.type	32;	.endef
	.seh_proc	loopHelper
loopHelper:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	32(%rbp), %rdx
	movl	24(%rbp), %eax
	movq	%rdx, %r9
	movl	$0, %r8d
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	actualLoop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	actualLoop
	.def	actualLoop;	.scl	2;	.type	32;	.endef
	.seh_proc	actualLoop
actualLoop:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -64(%rbp)
	movl	%edx, -56(%rbp)
	movl	%r8d, -48(%rbp)
	movq	%r9, -40(%rbp)
	movl	-48(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jne	.L23
	movq	-64(%rbp), %rax
	jmp	.L24
.L23:
	movl	-48(%rbp), %eax
	leal	1(%rax), %ebx
	movl	-48(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	call	hexToDecimal
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	binHex(%rip), %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	movq	-64(%rbp), %rcx
	call	strcat
	movq	%rax, %rcx
	movq	-40(%rbp), %rdx
	movl	-56(%rbp), %eax
	movq	%rdx, %r9
	movl	%ebx, %r8d
	movl	%eax, %edx
	call	actualLoop
.L24:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC5:
	.long	1352628735
	.long	1072907283
	.align 8
.LC7:
	.long	-118540546
	.long	1072490012
	.align 8
.LC9:
	.long	-17155601
	.long	1072049730
	.ident	"GCC: (Rev2, Built by MSYS2 project) 9.2.0"
	.def	strtol;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	log10;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	sprintf;	.scl	2;	.type	32;	.endef
	.def	log;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	strcat;	.scl	2;	.type	32;	.endef
