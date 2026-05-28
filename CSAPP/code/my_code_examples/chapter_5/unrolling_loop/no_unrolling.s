
combine_test.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <new_vec>:
   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 08          	sub    $0x8,%rsp
   6:	48 89 fd             	mov    %rdi,%rbp
   9:	bf 10 00 00 00       	mov    $0x10,%edi
   e:	e8 00 00 00 00       	callq  13 <new_vec+0x13>
  13:	48 89 c3             	mov    %rax,%rbx
  16:	48 85 c0             	test   %rax,%rax
  19:	74 37                	je     52 <new_vec+0x52>
  1b:	48 89 28             	mov    %rbp,(%rax)
  1e:	b8 00 00 00 00       	mov    $0x0,%eax
  23:	48 85 ed             	test   %rbp,%rbp
  26:	7e 2f                	jle    57 <new_vec+0x57>
  28:	be 04 00 00 00       	mov    $0x4,%esi
  2d:	48 89 ef             	mov    %rbp,%rdi
  30:	e8 00 00 00 00       	callq  35 <new_vec+0x35>
  35:	48 85 c0             	test   %rax,%rax
  38:	75 0f                	jne    49 <new_vec+0x49>
  3a:	48 89 df             	mov    %rbx,%rdi
  3d:	e8 00 00 00 00       	callq  42 <new_vec+0x42>
  42:	b8 00 00 00 00       	mov    $0x0,%eax
  47:	eb 0e                	jmp    57 <new_vec+0x57>
  49:	48 89 43 08          	mov    %rax,0x8(%rbx)
  4d:	48 89 d8             	mov    %rbx,%rax
  50:	eb 05                	jmp    57 <new_vec+0x57>
  52:	b8 00 00 00 00       	mov    $0x0,%eax
  57:	48 83 c4 08          	add    $0x8,%rsp
  5b:	5b                   	pop    %rbx
  5c:	5d                   	pop    %rbp
  5d:	c3                   	retq   

000000000000005e <vec_length>:
  5e:	48 8b 07             	mov    (%rdi),%rax
  61:	c3                   	retq   

0000000000000062 <get_vec_start>:
  62:	48 8b 47 08          	mov    0x8(%rdi),%rax
  66:	c3                   	retq   

0000000000000067 <combine4>:
  67:	48 8b 17             	mov    (%rdi),%rdx
  6a:	48 8b 4f 08          	mov    0x8(%rdi),%rcx
  6e:	48 85 d2             	test   %rdx,%rdx
  71:	7e 1e                	jle    91 <combine4+0x2a>
  73:	48 89 c8             	mov    %rcx,%rax
  76:	48 8d 14 91          	lea    (%rcx,%rdx,4),%rdx
  7a:	f3 0f 10 05 00 00 00 	movss  0x0(%rip),%xmm0        # 82 <combine4+0x1b>
  81:	00 
  82:	f3 0f 59 00          	mulss  (%rax),%xmm0
  86:	48 83 c0 04          	add    $0x4,%rax
  8a:	48 39 d0             	cmp    %rdx,%rax
  8d:	75 f3                	jne    82 <combine4+0x1b>
  8f:	eb 08                	jmp    99 <combine4+0x32>
  91:	f3 0f 10 05 00 00 00 	movss  0x0(%rip),%xmm0        # 99 <combine4+0x32>
  98:	00 
  99:	f3 0f 11 06          	movss  %xmm0,(%rsi)
  9d:	c3                   	retq   

000000000000009e <main>:
  9e:	48 83 ec 38          	sub    $0x38,%rsp
  a2:	c7 44 24 20 00 00 00 	movl   $0x40000000,0x20(%rsp)
  a9:	40 
  aa:	c7 44 24 24 00 00 40 	movl   $0x40400000,0x24(%rsp)
  b1:	40 
  b2:	c7 44 24 28 00 00 a0 	movl   $0x40a00000,0x28(%rsp)
  b9:	40 
  ba:	48 c7 04 24 03 00 00 	movq   $0x3,(%rsp)
  c1:	00 
  c2:	48 8d 44 24 20       	lea    0x20(%rsp),%rax
  c7:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  cc:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  d1:	48 89 e7             	mov    %rsp,%rdi
  d4:	b8 00 00 00 00       	mov    $0x0,%eax
  d9:	e8 00 00 00 00       	callq  de <main+0x40>
  de:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  e3:	48 89 e7             	mov    %rsp,%rdi
  e6:	e8 00 00 00 00       	callq  eb <main+0x4d>
  eb:	b8 00 00 00 00       	mov    $0x0,%eax
  f0:	48 83 c4 38          	add    $0x38,%rsp
  f4:	c3                   	retq   
