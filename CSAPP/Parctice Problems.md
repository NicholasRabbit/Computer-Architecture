**Partise problem 1.1** 

A.  T(new) = 20h 

It is 1.2x

**Practice 2.29**

![img](note-images/clip_image002.jpg)

 

#### P2.34

![img](note-images/clip_image004.jpg)

#### P2.35

I don’t understand problem 2.35 and find the solution later.

#### P2.37

Aside  Security vulnerability in the XDR library  (after Practice problem 2.36, on Page 91)

$(2^{20}+1)*2^{12}= 2^{20}*2^{12} + 1*2^{12}=4,294,967,296 + 4,096$

Because $2^{20}$ is less than $2^{32}$(int: 4 bytes).

#### P2.38

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

####  Practice Problem 2.43 

As 

#### Practice Problem 2.44 

Actually, some parts of the solution are incomprehensible. I will figure it out later.

#### Practice Problem 2.45

| Fractional Value | Binary Representation | Decimal Representation |
| ---------------- | --------------------- | ---------------------- |
| $\frac{1}{8}$    | 0.001                 | 0.125                  |
| $\frac{3}{4}$    | 0.11                  | 0.75                   |
| $\frac{25}{16}$  | 1.1001                | 1.5625                 |
| $2\frac{11}{16}$ | 10.1011               | 2.6875                 |
| $1\frac{1}{8}$   | 1.001                 | 1.125                  |
| $5\frac{7}{8}$   | 101.111               | 5.875                  |
| $3\frac{3}{16}$  | 11.0011               | 3.1875                 |

#### Practice Problem 2.46

1. The binary representation of $\frac{1}{10}$ is `0.0001 1001 1[0011]` in which the square brackets([]) means the repetition of specific bits. 

2. Elaboration of the answers of C and D.
   The answer is approximately $0.343$ seconds, which indicates that the clock or something to count time of  the Patriot Missile is about $0.343$  slower than the real time.  If the speed of an Iraqi missile is 
   $2000km$, $2000*0.343$  is 686 which is quite a big number and is definitely has disastrous effects.


