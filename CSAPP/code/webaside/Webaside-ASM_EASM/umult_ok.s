	.file	"umult_ok.c"
	.text
	.globl	umult_ok
	.type	umult_ok, @function
umult_ok:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rsi
	movq	-24(%rbp), %rcx
	movq	-32(%rbp), %rdi
#APP
# 8 "umult_ok.c" 1
	movq %rcx, %rax  # Get x 
	mulq %rdi	# Unsigned long multiply by y 
	movq %rax, (%rsi)	# Store lower 8 bytes at 'dest' 
	setae %cl		# Set b_result
# 0 "" 2
#NO_APP
	movb	%cl, -1(%rbp)
	movzbl	-1(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	umult_ok, .-umult_ok
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
