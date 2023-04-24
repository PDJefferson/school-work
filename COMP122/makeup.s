	.file	"makeup.c"
	.text
	.globl	int_rightrect
	.def	int_rightrect;	.scl	2;	.type	32;	.endef
	.seh_proc	int_rightrect
int_rightrect:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movsd	%xmm2, 32(%rbp)
	movq	%r9, 40(%rbp)
	movsd	24(%rbp), %xmm0
	subsd	16(%rbp), %xmm0
	divsd	32(%rbp), %xmm0
	movsd	%xmm0, -24(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	16(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	jmp	.L2
.L3:
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	movq	40(%rbp), %rax
	call	*%rax
	movsd	-8(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
.L2:
	movsd	24(%rbp), %xmm0
	subsd	-24(%rbp), %xmm0
	comisd	-16(%rbp), %xmm0
	jnb	.L3
	movsd	-24(%rbp), %xmm0
	mulsd	-8(%rbp), %xmm0
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 9.2.0"
