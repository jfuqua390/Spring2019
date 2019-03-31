	.file	"buildfile.c"
	.text
	.section	.rodata
.LC0:
	.string	"w"
.LC1:
	.string	"testfile"
.LC2:
	.string	"Error opening file. "
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -60(%rbp)
	movabsq	$8314057368361592916, %rax
	movabsq	$7234316338103214880, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movabsq	$2324737434182050336, %rax
	movabsq	$3345437242195669616, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movw	$2592, -16(%rbp)
	movb	$0, -14(%rbp)
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -56(%rbp)
	cmpq	$0, -56(%rbp)
	jne	.L3
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$1, %edi
	call	exit@PLT
.L4:
	movl	-60(%rbp), %eax
	cltq
	movzbl	-48(%rbp,%rax), %eax
	movsbl	%al, %eax
	movq	-56(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	fputc@PLT
	addl	$1, -60(%rbp)
.L3:
	cmpl	$32, -60(%rbp)
	jle	.L4
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L6
	call	__stack_chk_fail@PLT
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
