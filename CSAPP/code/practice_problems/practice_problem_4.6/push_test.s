	.file	"push_test.c"
	.section	.rodata
.LC0:
	.string	"result = %d\n"
.LC1:
	.string	"m = %d\n"
	.text
	.globl	push_test
	.type	push_test, @function
push_test:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$10, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
#APP
# 11 "push_test.c" 1
	movl %esp, %edx # Move the stack pointer to a register 
	push %esp  # Push the value in esp to the top of this stack manually. 
	popl %eax 
	
# 0 "" 2
#NO_APP
	movl	%edx, 8(%ebp)
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	subl	%eax, 8(%ebp)
	movl	8(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	push_test, .-push_test
	.section	.rodata
.LC2:
	.string	"Result = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$12, (%esp)
	call	push_test
	movl	%eax, 28(%esp)
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
