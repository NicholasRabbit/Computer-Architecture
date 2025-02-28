### Practice problem 1.1

A.  T(new) = 20h 

It is 1.2x

### **Practice 2.29**

![img](note-images/clip_image002.jpg)

 

### P2.34

![img](note-images/clip_image004.jpg)

### P2.35

I don’t understand problem 2.35 and find the solution later.

### P2.37

Aside  Security vulnerability in the XDR library  (after Practice problem 2.36, on Page 91)

$(2^{20}+1)*2^{12}= 2^{20}*2^{12} + 1*2^{12}=4,294,967,296 + 4,096$

Because $2^{20}$ is less than $2^{32}$(int: 4 bytes).

### P2.38

LEA instruction: $a<<k+b$ . LEA is abbreviated to "Load Effective Address".

As we know from the question,  $k \in {0,1,2,3}$ and `b` is 0 or `a`.

1. When b is 0, the computation is simply $a<<k$, which gives: 

   - For k = 0 : a << 0 = a

   - For k = 1 : a << 1= 2a

   - For k = 2 : a << 2 = 4a

   - For k = 3 : a << 3 = 8a

     Thus, when b=0b = 0b=0, we can compute the multiples: 1a,2a,4a,8a

2. When b is a, the computation becomes $a<<k+a$, which gives:

   - k = 0 : a << 0 + a = 2a
   - k = 1 : a << 1 + a = 3a
   - k = 2 : a<< 2 + a = 5a
   - k = 3 : a << 3 + a = 9a

​         Thus, when b=ab = ab=a, we can compute the multiples: 2a,3a,5a,9a.

​      In conclusion, the answer is `1a, 2a, 3a, 4a, 5a, 8a, 9a`.

###  Practice Problem 2.43 

As 

### Practice Problem 2.44 

Actually, some parts of the solution are incomprehensible. I will figure it out later.

### Practice Problem 2.45

| Fractional Value | Binary Representation | Decimal Representation |
| ---------------- | --------------------- | ---------------------- |
| $\frac{1}{8}$    | 0.001                 | 0.125                  |
| $\frac{3}{4}$    | 0.11                  | 0.75                   |
| $\frac{25}{16}$  | 1.1001                | 1.5625                 |
| $2\frac{11}{16}$ | 10.1011               | 2.6875                 |
| $1\frac{1}{8}$   | 1.001                 | 1.125                  |
| $5\frac{7}{8}$   | 101.111               | 5.875                  |
| $3\frac{3}{16}$  | 11.0011               | 3.1875                 |

### Practice Problem 2.46

1. The binary representation of $\frac{1}{10}$ is `0.0001 1001 1[0011]` in which the square brackets([]) means the repetition of specific bits. 

2. Elaboration of the answers of C and D.
   The answer is approximately $0.343$ seconds, which indicates that the clock or something to count time of  the Patriot Missile is about $0.343$  slower than the real time.  If the speed of an Iraqi missile is 
   $2000km$, $2000*0.343$  is 686 which is quite a big number and is definitely has disastrous effects.

### Practice Problem 2.47 

<img src="note-images/1735711837679.png" alt="1735711837679" style="zoom:67%;" />

### Practice Problem 2.48

<img src="note-images/1735711914139.png" alt="1735711914139" style="zoom: 67%;" />



### Practice Problem 3.10

```txt
Practice Problem 3.10
It is common to find assembly code lines of the form
xorl %edx,%edx
in code that was generated from C where no Exclusive-Or operations were
present.
A. Explain the effect of this particular Exclusive-Or instruction and what
useful operation it implements.
B. What would be the more straightforward way to express this operation in
assembly code?
C. Compare the number of bytes to encode these two different implementations of the same operation.
```

Why does `xorl %edx, %edx` only needs two bytes?

Here is my conclusion from the answer below: The operations such as `xor`, `add`, `sal` and so forth are also encoded in the CPU of IA32. So are the registers. They all have address or numbers in CPU, too. One byte (255) is enough to represent them all.  

In order to verify the solution disassembling assembly code `xorl %edx, %edx` and `movl $0, %edx` is necessary. 
First of all, we write a assembly code named `p3.10_xor_mov_compare.s`.

```assembly
# Instructions are omitted before the operations.
_start:
xorl %edx, %edx
movl $0, %edx
```

Secondly, compile it and disassemble the object file.

```assembly
# as -s p3.10_xor_mov_compare.s -o test_3_10.o
# objdump -d test_3_10.o
=========== disassebling result
test_3_10.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_start>:
   0:   31 d2                   xor    %edx,%edx  # 2 bytes
   2:   ba 00 00 00 00          mov    $0x0,%edx  # 5 bytes ('00 00 00 00' is $0)
   7:   cd 80                   int    $0x80
# Both '31' and 'ba' are operating code of CPU to represent 'xor' and 'mov', respectively. They are all hexadecimal numbers.
```



*The following answer is from ChatGPT.*

The instruction `xorl %edx, %edx` is compact because it takes advantage of **register-to-register encoding** in x86 assembly, which is optimized to use minimal bytes for operations that only involve registers. Here's a breakdown of why it requires only two bytes:

------

##### **1. Instruction Encoding Overview**

In x86 assembly, instructions are encoded using:

- **Opcode**: Specifies the operation (e.g., `XOR`).
- **ModR/M Byte**: Indicates the registers involved in the operation.

The `xorl %edx, %edx` instruction works like this:

- **Opcode**: For XOR between two 32-bit registers, the opcode is **`0x31`**.

- ModR/M Byte

  : Specifies both source and destination registers: 

  - The ModR/M byte consists of: 
    - **Mod**: Specifies the addressing mode (here, both operands are registers, so `Mod=11`).
    - **Reg/Opcode**: Specifies the first register (`%edx` → `010`).
    - **R/M**: Specifies the second register (`%edx` → `010`).

When the source and destination registers are the same, this compact encoding allows the operation to be represented in **just two bytes**.

------

##### **2. Exact Encoding for `xorl %edx, %edx`**

- **Opcode**: `0x31` (indicates XOR for two 32-bit registers).

- ModR/M Byte

  : Encoded as 

  ```
  0xD2
  ```

  : 

  - **Mod**: `11` (register-to-register mode).
  - **Reg**: `010` (indicating `%edx`).
  - **R/M**: `010` (indicating `%edx`).

Thus, the entire instruction is:

```
31 D2
```

This is exactly **two bytes** long.

------

##### **3. Why Only Two Bytes?**

1. **Efficient Encoding**: The x86 instruction set uses compact encoding for operations that involve only registers. This avoids the need to include additional bytes for immediate values or memory addresses.
2. **Redundancy Optimization**: Since both operands are the same register, the ModR/M byte can fully specify the operation without needing extra data.

------

##### **Comparison with `movl $0, %edx`**

For `movl $0, %edx`, the instruction must include:

- The opcode (`0xC7`) for moving an immediate value.
- The ModR/M byte to indicate the destination register.
- A 4-byte immediate value (`0`).

This results in a **5-byte instruction**:

```
C7 C2 00 00 00 00
```

In contrast, `xorl %edx, %edx` avoids the need for the immediate value and uses the register encoding directly, saving 3 bytes.

------

##### **Key Takeaways**

- **Encoding Efficiency**: The compact encoding of `xorl %edx, %edx` results in only two bytes (`31 D2`).
- **Optimization**: This is why compilers favour such instructions to zero out registers—it minimizes memory usage and instruction size, improving performance in tight loops or embedded systems.

### Practice Problem 3.17

![1735712093104](note-images/1735712093104.png)

### Practice Problem 3.20

<img src="note-images/1735712124725.png" alt="1735712124725" style="zoom:67%;" />![1735712199778](note-images/1735712199778.png)

### Practice Problem 3.21

<img src="note-images/1735712199778.png" alt="1735712199778" style="zoom:80%;" />

### Practice Problem 3.22

<img src="note-images/1735712284399.png" alt="1735712284399" style="zoom:67%;" />

<img src="note-images/1735712304508.png" alt="1735712304508" style="zoom:67%;" />

### Practice Problem 3.27

<img src="note-images/1739318597317.png" alt="1739318597317" style="zoom:50%;" />

<img src="note-images/1739318649755.png" alt="1739318649755" style="zoom:50%;" />

Practice Problem 3.29

<img src="note-images/1740721377003.png" alt="1740721377003" style="zoom:67%;" />