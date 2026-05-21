
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
  19:	74 39                	je     54 <new_vec+0x54>
  1b:	48 89 28             	mov    %rbp,(%rax)
  1e:	48 85 ed             	test   %rbp,%rbp
  21:	7e 27                	jle    4a <new_vec+0x4a>
  23:	be 04 00 00 00       	mov    $0x4,%esi
  28:	48 89 ef             	mov    %rbp,%rdi
  2b:	e8 00 00 00 00       	callq  30 <new_vec+0x30>
  30:	48 85 c0             	test   %rax,%rax
  33:	75 0f                	jne    44 <new_vec+0x44>
  35:	48 89 df             	mov    %rbx,%rdi
  38:	e8 00 00 00 00       	callq  3d <new_vec+0x3d>
  3d:	b8 00 00 00 00       	mov    $0x0,%eax
  42:	eb 15                	jmp    59 <new_vec+0x59>
  44:	48 89 43 08          	mov    %rax,0x8(%rbx)
  48:	eb 05                	jmp    4f <new_vec+0x4f>
  4a:	bb 00 00 00 00       	mov    $0x0,%ebx
  4f:	48 89 d8             	mov    %rbx,%rax
  52:	eb 05                	jmp    59 <new_vec+0x59>
  54:	b8 00 00 00 00       	mov    $0x0,%eax
  59:	48 83 c4 08          	add    $0x8,%rsp
  5d:	5b                   	pop    %rbx
  5e:	5d                   	pop    %rbp
  5f:	c3                   	retq   

0000000000000060 <vec_length>:
  60:	48 8b 07             	mov    (%rdi),%rax
  63:	c3                   	retq   

0000000000000064 <get_vec_start>:
  64:	48 8b 47 08          	mov    0x8(%rdi),%rax
  68:	c3                   	retq   

0000000000000069 <combine3>:
  69:	41 54                	push   %r12
  6b:	55                   	push   %rbp
  6c:	53                   	push   %rbx
  6d:	49 89 fc             	mov    %rdi,%r12
  70:	48 89 f3             	mov    %rsi,%rbx
  73:	e8 00 00 00 00       	callq  78 <combine3+0xf>
  78:	48 89 c5             	mov    %rax,%rbp
  7b:	4c 89 e7             	mov    %r12,%rdi
  7e:	e8 00 00 00 00       	callq  83 <combine3+0x1a>
  83:	c7 03 00 00 80 3f    	movl   $0x3f800000,(%rbx)
  89:	ba 00 00 00 00       	mov    $0x0,%edx
  8e:	eb 11                	jmp    a1 <combine3+0x38>
  90:	f3 0f 10 04 90       	movss  (%rax,%rdx,4),%xmm0
  95:	f3 0f 59 03          	mulss  (%rbx),%xmm0
  99:	f3 0f 11 03          	movss  %xmm0,(%rbx)
  9d:	48 83 c2 01          	add    $0x1,%rdx
  a1:	48 39 ea             	cmp    %rbp,%rdx
  a4:	7c ea                	jl     90 <combine3+0x27>
  a6:	5b                   	pop    %rbx
  a7:	5d                   	pop    %rbp
  a8:	41 5c                	pop    %r12
  aa:	c3                   	retq   

00000000000000ab <combine4>:
  ab:	41 54                	push   %r12
  ad:	55                   	push   %rbp
  ae:	53                   	push   %rbx
  af:	48 89 fd             	mov    %rdi,%rbp
  b2:	49 89 f4             	mov    %rsi,%r12
  b5:	e8 00 00 00 00       	callq  ba <combine4+0xf>
  ba:	48 89 c3             	mov    %rax,%rbx
  bd:	48 89 ef             	mov    %rbp,%rdi
  c0:	e8 00 00 00 00       	callq  c5 <combine4+0x1a>
  c5:	f3 0f 10 05 00 00 00 	movss  0x0(%rip),%xmm0        # cd <combine4+0x22>
  cc:	00 
  cd:	ba 00 00 00 00       	mov    $0x0,%edx
  d2:	eb 09                	jmp    dd <combine4+0x32>
  d4:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
  d9:	48 83 c2 01          	add    $0x1,%rdx
  dd:	48 39 da             	cmp    %rbx,%rdx
  e0:	7c f2                	jl     d4 <combine4+0x29>
  e2:	f3 41 0f 11 04 24    	movss  %xmm0,(%r12)
  e8:	5b                   	pop    %rbx
  e9:	5d                   	pop    %rbp
  ea:	41 5c                	pop    %r12
  ec:	c3                   	retq   

00000000000000ed <main>:
  ed:	48 83 ec 30          	sub    $0x30,%rsp
  f1:	c7 44 24 20 00 00 00 	movl   $0x40000000,0x20(%rsp)
  f8:	40 
  f9:	c7 44 24 24 00 00 40 	movl   $0x40400000,0x24(%rsp)
 100:	40 
 101:	c7 44 24 28 00 00 a0 	movl   $0x40a00000,0x28(%rsp)
 108:	40 
 109:	48 c7 04 24 03 00 00 	movq   $0x3,(%rsp)
 110:	00 
 111:	48 8d 44 24 20       	lea    0x20(%rsp),%rax
 116:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
 11b:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
 120:	48 89 e7             	mov    %rsp,%rdi
 123:	e8 00 00 00 00       	callq  128 <main+0x3b>
 128:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
 12d:	48 89 e7             	mov    %rsp,%rdi
 130:	e8 00 00 00 00       	callq  135 <main+0x48>
 135:	b8 00 00 00 00       	mov    $0x0,%eax
 13a:	48 83 c4 30          	add    $0x30,%rsp
 13e:	c3                   	retq   
