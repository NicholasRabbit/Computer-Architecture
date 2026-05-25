
silly.o:     file format elf32-i386


Disassembly of section .text:

00000000 <silly>:
   0:	8b 44 24 04          	mov    0x4(%esp),%eax
   4:	85 c0                	test   %eax,%eax
   6:	79 07                	jns    f <silly+0xf>
   8:	eb 0b                	jmp    15 <silly+0x15>
   a:	f7 d8                	neg    %eax
   c:	8d 04 40             	lea    (%eax,%eax,2),%eax
   f:	85 c0                	test   %eax,%eax
  11:	79 f7                	jns    a <silly+0xa>
  13:	f3 c3                	repz ret 
  15:	b8 00 00 00 00       	mov    $0x0,%eax
  1a:	c3                   	ret    

0000001b <main>:
  1b:	83 ec 04             	sub    $0x4,%esp
  1e:	c7 04 24 24 00 00 00 	movl   $0x24,(%esp)
  25:	e8 fc ff ff ff       	call   26 <main+0xb>
  2a:	b8 00 00 00 00       	mov    $0x0,%eax
  2f:	83 c4 04             	add    $0x4,%esp
  32:	c3                   	ret    
