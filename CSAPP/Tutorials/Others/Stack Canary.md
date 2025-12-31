*From Gemini:* 

Here is a simple example showing how a C compiler (like GCC) adds the stack canary protection to a function that uses a local buffer.

### 1. The C Code

We’ll use a function that has a small local array. This is exactly the kind of setup where a compiler decides a "guard" is necessary.

C

```
#include <string.h>

void my_function(char *input) {
    char buffer[16];
    strcpy(buffer, input); // Potential overflow here
}
```

------

### 2. The Resulting Assembly (x86-64)

When compiled with stack protection enabled (`-fstack-protector`), the assembly looks like this. I've highlighted the specific canary instructions.

Code snippet

```
my_function:
    pushq   %rbp
    movq    %rsp, %rbp
    subq    $48, %rsp            # Reserve space on stack
    movq    %rdi, -40(%rbp)      # Save 'input' pointer

    # --- CANARY SETUP (Prologue) ---
    movq    %fs:40, %rax         # 1. Load random value from TLS (%fs:0x28)
    movq    %rax, -8(%rbp)       # 2. Place it on the stack just below return addr
    xorl    %eax, %eax           # 3. Clear %rax so the value isn't left lying around

    # ... (Rest of the function logic, e.g., strcpy) ...

    # --- CANARY CHECK (Epilogue) ---
    movq    -8(%rbp), %rax       # 1. Load the value back from the stack
    xorq    %fs:40, %rax         # 2. Compare it to the original value in %fs:0x28
    jne     .Lstack_fail         # 3. If NOT equal (result not zero), jump to failure
    
    leave
    ret                          # Safe to return

.Lstack_fail:
    call    __stack_chk_fail     # Terminate the program
```

------

### 3. Visualizing the Stack Layout

To understand why it's placed there, look at how the memory is organized. The canary acts as a "tripwire" between your local data and the critical control data (the Saved Base Pointer and Return Address).

| **Stack Component**           | **Memory Address** |
| ----------------------------- | ------------------ |
| **Return Address**            | High Address       |
| **Saved RBP**                 |                    |
| **Stack Canary (Guard)**      | **Located here**   |
| **Local Buffer (`char[16]`)** |                    |
| **Other Local Variables**     | Low Address        |

### Why this works

If an attacker provides an `input` string longer than 16 bytes, the `strcpy` function will start writing past the end of the `buffer`. To reach and overwrite the **Return Address** (to take control of the program), the attacker **must** write over the **Stack Canary** first.

Because the canary is a random value that changes every time the program runs, the attacker cannot guess it. When the function reaches the `xorq` instruction in the epilogue, the mismatch is detected instantly, and the program shuts down before the corrupted return address can be used.

Would you like to know how to intentionally disable this for debugging purposes, or perhaps how an attacker might try to "leak" the canary value?