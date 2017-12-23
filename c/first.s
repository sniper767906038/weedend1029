	.file	"first.c"
	.section	.rodata
.LC0:
	.string	"num1:%d, num2:%d\n"
.LC1:
	.string	"m:%d, t:%d\n"
.LC3:
	.string	"i:%d, d:%lf, d2:%lf\n"
.LC4:
	.string	"the bytes of d is %ld\n"
.LC5:
	.string	"%d %d\n"
.LC6:
	.string	"n1:%d, n2:%d\n"
.LC7:
	.string	"float--->%ld\n"
.LC8:
	.string	"double--->%ld\n"
.LC9:
	.string	"long double--->%ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movb	$100, -53(%rbp)
	movzbl	-53(%rbp), %eax
	addl	$1, %eax
	movb	%al, -53(%rbp)
	movl	$10, -44(%rbp)
	movl	$50, -40(%rbp)
	movl	-40(%rbp), %eax
	xorl	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	xorl	%eax, -40(%rbp)
	movl	-40(%rbp), %eax
	xorl	%eax, -44(%rbp)
	movl	-40(%rbp), %edx
	movl	-44(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$10, -36(%rbp)
	movl	-36(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -36(%rbp)
	movl	%eax, -32(%rbp)
	movl	-36(%rbp), %edx
	movl	-32(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -36(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	-36(%rbp), %edx
	movl	-32(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	cvttsd2si	%xmm0, %eax
	movl	%eax, -52(%rbp)
	movl	-52(%rbp), %eax
	pxor	%xmm0, %xmm0
	cvtsi2sd	%eax, %xmm0
	addsd	-24(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	movl	-52(%rbp), %eax
	movsd	-16(%rbp), %xmm0
	movq	-24(%rbp), %rdx
	movapd	%xmm0, %xmm1
	movq	%rdx, -72(%rbp)
	movsd	-72(%rbp), %xmm0
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$2, %eax
	call	printf
	movl	$8, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$8, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	$8, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movl	-52(%rbp), %edx
	movl	-52(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$101, -48(%rbp)
	movl	-48(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	je	.L2
	movl	-48(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -48(%rbp)
	jmp	.L3
.L2:
	subl	$1, -48(%rbp)
	movl	-48(%rbp), %eax
.L3:
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %edx
	movl	-48(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$10, -48(%rbp)
	movl	$20, -28(%rbp)
	addl	$1, -48(%rbp)
	addl	$1, -28(%rbp)
	movl	-28(%rbp), %eax
	subl	%eax, -48(%rbp)
	movl	-28(%rbp), %edx
	movl	-48(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$4, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movl	$8, %esi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movl	$16, %esi
	movl	$.LC9, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	2233382994
	.long	1076220395
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
