	.file	"tmult_ok_1.c"
	.text
	.globl	tmult_ok_1
	.type	tmult_ok_1, @function
tmult_ok_1:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
#APP
# 8 "tmult_ok_1.c" 1
	setae %al
# 0 "" 2
#NO_APP
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	tmult_ok_1, .-tmult_ok_1
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
