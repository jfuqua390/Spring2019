	.file	"radius.c"
	.text
	.section	.rodata
.LC3:
	.string	"The area, %f, is too large. \n"
	.align 8
.LC4:
	.string	"The area, %f, is within limits. \n"
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
	subq	$16, %rsp
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	cvtss2sd	-8(%rbp), %xmm0
	movsd	.LC1(%rip), %xmm1
	mulsd	%xmm0, %xmm1
	cvtss2sd	-8(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -4(%rbp)
	movss	-4(%rbp), %xmm0
	ucomiss	.LC2(%rip), %xmm0
	jbe	.L7
	cvtss2sd	-4(%rbp), %xmm0
	leaq	.LC3(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	jmp	.L4
.L7:
	cvtss2sd	-4(%rbp), %xmm0
	leaq	.LC4(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
.L4:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1112014848
	.align 8
.LC1:
	.long	4028335726
	.long	1074340345
	.align 4
.LC2:
	.long	1120403456
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
