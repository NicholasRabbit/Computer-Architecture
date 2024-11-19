### 1, Errors 

Running `make btest` on a machine of 64-bit representation of integers may cause an error(`fatal error gnu/stubs-32.h no such file or directory `).  The solution is given as follows.

Solution:

```shell
# You need install the glibc-devle.i386 package because the labs need machine of 32-bit 
# representations of integers.
yum -y install glibc-devel.i386   # Centos 6/7
```

### 2, How to do the lab?

In the root directory of `datalab-handout` , run the following commands if you complete the code.

Step 1:  Read `bits.c` and modify it.

Step 2:  Run  ` ./dlc -e bits.c ` to check the legality of your solutions.

```shell
 # or
 ./dlc bits.c  # if your solution is legal, there is nothing output.
```

Step 3: Run `make clean`  and `make btest`  to compile the source code.

Step 4: Run `./btest`  test harness to check your functions for correctness.

Step 5: Run `./driver.pl` to grade your work automatically.

[datalab: Page 4 and 5.](./labs/L1_Data_Lab/datalab.pdf)

### 3, Elaboration of questions and answers

[Answers](https://blog.csdn.net/qq_45677541/article/details/123955438)

##### 1, tMin(void)

```shell
/* 
 * tmin - return minimum two's complement integer  
 * In two's complement the bits representation of a negative number begins with 1, 
 * return it.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
```

### 7, conditional

1, `x ? y : z`  equals $F =xy + \overline xz$. 

In the equation $xy$ is  Boolean  operation yields the same result as of $x\&y$ and the plus $+$ means $OR(|)$. 

​       