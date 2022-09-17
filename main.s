	.file	"main.c"
	.text
	.globl	obj1
	.data
	.align 16
	.type	obj1, @object
	.size	obj1, 16
obj1:
	.byte	65
	.zero	3
	.long	1
	.long	1078523331
	.value	23
	.zero	2
	.comm	obj2,16,16
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
	movq	obj1(%rip), %rax
	movq	obj1+8(%rip), %rdx
	movq	%rax, obj2(%rip)
	movq	%rdx, obj2+8(%rip)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 9.3.1 20200408 (Red Hat 9.3.1-2)"
	.section	.note.GNU-stack,"",@progbits
