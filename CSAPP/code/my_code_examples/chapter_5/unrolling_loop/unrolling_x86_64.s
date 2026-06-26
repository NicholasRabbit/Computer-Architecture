
test_unroll.o:     file format elf64-x86-64


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

0000000000000069 <combine4>:
  69:	41 54                	push   %r12
  6b:	55                   	push   %rbp
  6c:	53                   	push   %rbx
  6d:	49 89 fc             	mov    %rdi,%r12
  70:	48 89 f5             	mov    %rsi,%rbp
  73:	e8 00 00 00 00       	callq  78 <combine4+0xf>
  78:	48 89 c3             	mov    %rax,%rbx
  7b:	4c 89 e7             	mov    %r12,%rdi
  7e:	e8 00 00 00 00       	callq  83 <combine4+0x1a>
  83:	f3 0f 10 05 00 00 00 	movss  0x0(%rip),%xmm0        # 8b <combine4+0x22>
  8a:	00 
  8b:	ba 00 00 00 00       	mov    $0x0,%edx
  90:	48 89 d9             	mov    %rbx,%rcx
  93:	83 e1 07             	and    $0x7,%ecx
  96:	75 5d                	jne    f5 <combine4+0x8c>
  98:	eb 4c                	jmp    e6 <combine4+0x7d>
  9a:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
  9f:	48 83 c2 01          	add    $0x1,%rdx
  a3:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
  a8:	48 8d 72 01          	lea    0x1(%rdx),%rsi
  ac:	f3 0f 59 04 b0       	mulss  (%rax,%rsi,4),%xmm0
  b1:	48 8d 7a 02          	lea    0x2(%rdx),%rdi
  b5:	f3 0f 59 04 b8       	mulss  (%rax,%rdi,4),%xmm0
  ba:	4c 8d 42 03          	lea    0x3(%rdx),%r8
  be:	f3 42 0f 59 04 80    	mulss  (%rax,%r8,4),%xmm0
  c4:	4c 8d 4a 04          	lea    0x4(%rdx),%r9
  c8:	f3 42 0f 59 04 88    	mulss  (%rax,%r9,4),%xmm0
  ce:	4c 8d 52 05          	lea    0x5(%rdx),%r10
  d2:	f3 42 0f 59 04 90    	mulss  (%rax,%r10,4),%xmm0
  d8:	4c 8d 5a 06          	lea    0x6(%rdx),%r11
  dc:	f3 42 0f 59 04 98    	mulss  (%rax,%r11,4),%xmm0
  e2:	48 83 c2 07          	add    $0x7,%rdx
  e6:	48 39 da             	cmp    %rbx,%rdx
  e9:	7c af                	jl     9a <combine4+0x31>
  eb:	f3 0f 11 45 00       	movss  %xmm0,0x0(%rbp)
  f0:	5b                   	pop    %rbx
  f1:	5d                   	pop    %rbp
  f2:	41 5c                	pop    %r12
  f4:	c3                   	retq   
  f5:	48 39 da             	cmp    %rbx,%rdx
  f8:	7d f1                	jge    eb <combine4+0x82>
  fa:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
  ff:	48 83 c2 01          	add    $0x1,%rdx
 103:	48 83 f9 01          	cmp    $0x1,%rcx
 107:	74 dd                	je     e6 <combine4+0x7d>
 109:	48 83 f9 02          	cmp    $0x2,%rcx
 10d:	74 45                	je     154 <combine4+0xeb>
 10f:	48 83 f9 03          	cmp    $0x3,%rcx
 113:	74 36                	je     14b <combine4+0xe2>
 115:	48 83 f9 04          	cmp    $0x4,%rcx
 119:	74 27                	je     142 <combine4+0xd9>
 11b:	48 83 f9 05          	cmp    $0x5,%rcx
 11f:	74 18                	je     139 <combine4+0xd0>
 121:	48 83 f9 06          	cmp    $0x6,%rcx
 125:	74 09                	je     130 <combine4+0xc7>
 127:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
 12c:	48 83 c2 01          	add    $0x1,%rdx
 130:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
 135:	48 83 c2 01          	add    $0x1,%rdx
 139:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
 13e:	48 83 c2 01          	add    $0x1,%rdx
 142:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
 147:	48 83 c2 01          	add    $0x1,%rdx
 14b:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
 150:	48 83 c2 01          	add    $0x1,%rdx
 154:	f3 0f 59 04 90       	mulss  (%rax,%rdx,4),%xmm0
 159:	48 83 c2 01          	add    $0x1,%rdx
 15d:	eb 87                	jmp    e6 <combine4+0x7d>

000000000000015f <main>:
 15f:	48 83 ec 38          	sub    $0x38,%rsp
 163:	c7 44 24 20 00 00 00 	movl   $0x40000000,0x20(%rsp)
 16a:	40 
 16b:	c7 44 24 24 00 00 40 	movl   $0x40400000,0x24(%rsp)
 172:	40 
 173:	c7 44 24 28 00 00 a0 	movl   $0x40a00000,0x28(%rsp)
 17a:	40 
 17b:	48 c7 04 24 03 00 00 	movq   $0x3,(%rsp)
 182:	00 
 183:	48 8d 44 24 20       	lea    0x20(%rsp),%rax
 188:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
 18d:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
 192:	48 89 e7             	mov    %rsp,%rdi
 195:	b8 00 00 00 00       	mov    $0x0,%eax
 19a:	e8 00 00 00 00       	callq  19f <main+0x40>
 19f:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
 1a4:	48 89 e7             	mov    %rsp,%rdi
 1a7:	e8 00 00 00 00       	callq  1ac <main+0x4d>
 1ac:	b8 00 00 00 00       	mov    $0x0,%eax
 1b1:	48 83 c4 38          	add    $0x38,%rsp
 1b5:	c3                   	retq   
