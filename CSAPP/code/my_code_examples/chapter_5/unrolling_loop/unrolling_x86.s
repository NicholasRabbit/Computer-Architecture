
combine_test.o:     file format elf32-i386


Disassembly of section .text:

00000000 <new_vec>:
   0:	56                   	push   %esi
   1:	53                   	push   %ebx
   2:	83 ec 14             	sub    $0x14,%esp
   5:	8b 74 24 20          	mov    0x20(%esp),%esi
   9:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  10:	e8 fc ff ff ff       	call   11 <new_vec+0x11>
  15:	89 c3                	mov    %eax,%ebx
  17:	85 c0                	test   %eax,%eax
  19:	74 37                	je     52 <new_vec+0x52>
  1b:	89 30                	mov    %esi,(%eax)
  1d:	85 f6                	test   %esi,%esi
  1f:	7e 28                	jle    49 <new_vec+0x49>
  21:	c7 44 24 04 04 00 00 	movl   $0x4,0x4(%esp)
  28:	00 
  29:	89 34 24             	mov    %esi,(%esp)
  2c:	e8 fc ff ff ff       	call   2d <new_vec+0x2d>
  31:	85 c0                	test   %eax,%eax
  33:	75 0f                	jne    44 <new_vec+0x44>
  35:	89 1c 24             	mov    %ebx,(%esp)
  38:	e8 fc ff ff ff       	call   39 <new_vec+0x39>
  3d:	b8 00 00 00 00       	mov    $0x0,%eax
  42:	eb 13                	jmp    57 <new_vec+0x57>
  44:	89 43 04             	mov    %eax,0x4(%ebx)
  47:	eb 05                	jmp    4e <new_vec+0x4e>
  49:	bb 00 00 00 00       	mov    $0x0,%ebx
  4e:	89 d8                	mov    %ebx,%eax
  50:	eb 05                	jmp    57 <new_vec+0x57>
  52:	b8 00 00 00 00       	mov    $0x0,%eax
  57:	83 c4 14             	add    $0x14,%esp
  5a:	5b                   	pop    %ebx
  5b:	5e                   	pop    %esi
  5c:	c3                   	ret    

0000005d <vec_length>:
  5d:	8b 44 24 04          	mov    0x4(%esp),%eax
  61:	8b 00                	mov    (%eax),%eax
  63:	c3                   	ret    

00000064 <get_vec_start>:
  64:	8b 44 24 04          	mov    0x4(%esp),%eax
  68:	8b 40 04             	mov    0x4(%eax),%eax
  6b:	c3                   	ret    

0000006c <combine4>:
  6c:	56                   	push   %esi
  6d:	53                   	push   %ebx
  6e:	83 ec 04             	sub    $0x4,%esp
  71:	8b 74 24 10          	mov    0x10(%esp),%esi
  75:	89 34 24             	mov    %esi,(%esp)
  78:	e8 fc ff ff ff       	call   79 <combine4+0xd>
  7d:	89 c3                	mov    %eax,%ebx
  7f:	89 34 24             	mov    %esi,(%esp)
  82:	e8 fc ff ff ff       	call   83 <combine4+0x17>
  87:	d9 e8                	fld1   
  89:	ba 00 00 00 00       	mov    $0x0,%edx
  8e:	89 d9                	mov    %ebx,%ecx
  90:	83 e1 07             	and    $0x7,%ecx
  93:	75 42                	jne    d7 <combine4+0x6b>
  95:	eb 30                	jmp    c7 <combine4+0x5b>
  97:	d8 0c 90             	fmuls  (%eax,%edx,4)
  9a:	83 c2 01             	add    $0x1,%edx
  9d:	d8 0c 90             	fmuls  (%eax,%edx,4)
  a0:	8d 72 01             	lea    0x1(%edx),%esi
  a3:	d8 0c b0             	fmuls  (%eax,%esi,4)
  a6:	8d 4a 02             	lea    0x2(%edx),%ecx
  a9:	d8 0c 88             	fmuls  (%eax,%ecx,4)
  ac:	8d 72 03             	lea    0x3(%edx),%esi
  af:	d8 0c b0             	fmuls  (%eax,%esi,4)
  b2:	8d 4a 04             	lea    0x4(%edx),%ecx
  b5:	d8 0c 88             	fmuls  (%eax,%ecx,4)
  b8:	8d 72 05             	lea    0x5(%edx),%esi
  bb:	d8 0c b0             	fmuls  (%eax,%esi,4)
  be:	8d 4a 06             	lea    0x6(%edx),%ecx
  c1:	d8 0c 88             	fmuls  (%eax,%ecx,4)
  c4:	83 c2 07             	add    $0x7,%edx
  c7:	39 da                	cmp    %ebx,%edx
  c9:	7c cc                	jl     97 <combine4+0x2b>
  cb:	8b 44 24 14          	mov    0x14(%esp),%eax
  cf:	d9 18                	fstps  (%eax)
  d1:	83 c4 04             	add    $0x4,%esp
  d4:	5b                   	pop    %ebx
  d5:	5e                   	pop    %esi
  d6:	c3                   	ret    
  d7:	39 da                	cmp    %ebx,%edx
  d9:	7d f0                	jge    cb <combine4+0x5f>
  db:	d8 0c 90             	fmuls  (%eax,%edx,4)
  de:	83 c2 01             	add    $0x1,%edx
  e1:	83 f9 01             	cmp    $0x1,%ecx
  e4:	74 e1                	je     c7 <combine4+0x5b>
  e6:	83 f9 02             	cmp    $0x2,%ecx
  e9:	74 32                	je     11d <combine4+0xb1>
  eb:	83 f9 03             	cmp    $0x3,%ecx
  ee:	74 27                	je     117 <combine4+0xab>
  f0:	83 f9 04             	cmp    $0x4,%ecx
  f3:	74 1c                	je     111 <combine4+0xa5>
  f5:	83 f9 05             	cmp    $0x5,%ecx
  f8:	74 11                	je     10b <combine4+0x9f>
  fa:	83 f9 06             	cmp    $0x6,%ecx
  fd:	74 06                	je     105 <combine4+0x99>
  ff:	d8 0c 90             	fmuls  (%eax,%edx,4)
 102:	83 c2 01             	add    $0x1,%edx
 105:	d8 0c 90             	fmuls  (%eax,%edx,4)
 108:	83 c2 01             	add    $0x1,%edx
 10b:	d8 0c 90             	fmuls  (%eax,%edx,4)
 10e:	83 c2 01             	add    $0x1,%edx
 111:	d8 0c 90             	fmuls  (%eax,%edx,4)
 114:	83 c2 01             	add    $0x1,%edx
 117:	d8 0c 90             	fmuls  (%eax,%edx,4)
 11a:	83 c2 01             	add    $0x1,%edx
 11d:	d8 0c 90             	fmuls  (%eax,%edx,4)
 120:	83 c2 01             	add    $0x1,%edx
 123:	eb a2                	jmp    c7 <combine4+0x5b>

00000125 <main>:
 125:	83 ec 28             	sub    $0x28,%esp
 128:	c7 44 24 1c 00 00 00 	movl   $0x40000000,0x1c(%esp)
 12f:	40 
 130:	c7 44 24 20 00 00 40 	movl   $0x40400000,0x20(%esp)
 137:	40 
 138:	c7 44 24 24 00 00 a0 	movl   $0x40a00000,0x24(%esp)
 13f:	40 
 140:	c7 44 24 08 03 00 00 	movl   $0x3,0x8(%esp)
 147:	00 
 148:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 14c:	89 44 24 0c          	mov    %eax,0xc(%esp)
 150:	8d 54 24 10          	lea    0x10(%esp),%edx
 154:	89 54 24 04          	mov    %edx,0x4(%esp)
 158:	8d 4c 24 08          	lea    0x8(%esp),%ecx
 15c:	89 0c 24             	mov    %ecx,(%esp)
 15f:	e8 fc ff ff ff       	call   160 <main+0x3b>
 164:	b8 00 00 00 00       	mov    $0x0,%eax
 169:	83 c4 28             	add    $0x28,%esp
 16c:	c3                   	ret    
