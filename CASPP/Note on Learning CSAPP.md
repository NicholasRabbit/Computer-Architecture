### Chapter 1 ints and bits

#### 1, Shifting bits

In the low level of the computer system shifting bits is quite faster than multiplication. If the former costs one clock cycle, the latter will normally cost 13 to 17 clock cycles.  Nowadays the speed of multiplication has  increased dramatically but it still costs 4 clock cycles. While 4 is bigger than one anyway.

- What will happen if shifting 8 bits for a byte ?

#### 2, Signed and Unsigned

1. What will happed when a signed number is calculated with an unsigned number?
   The signed number will cast to a unsigned number.
2. 

#### 3, Truncate a number

Truncating a number is like a module operation.

```txt
# 4 bits overflow so the most significant number is truncated.
1 1101 : 27
  1101 : 11   #27 % 16 = 11
```



