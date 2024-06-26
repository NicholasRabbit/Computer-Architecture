	.file	"negate_number.c"
	.section	.rodata
.LC0:
	.string	"s1 = %d: \t s1n = %d\n"
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
	movw	$10, -2(%rbp)
	movzwl	-2(%rbp), %eax
	negl	%eax
	movw	%ax, -4(%rbp)
	movw	$6, -6(%rbp)
	movzwl	-6(%rbp), %eax
	negl	%eax
	movw	%ax, -8(%rbp)
	movswl	-8(%rbp), %edx
	movswl	-6(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
