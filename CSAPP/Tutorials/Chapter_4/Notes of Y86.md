### Note

N.B. I have downloaded Y86 simulator of the CSApp 2e and installed it successfully. The following notes are all about it. 

### 1, What is TTY?

TTY is short for teletypewriter. When Y86 simulator is run in TTY mode, it prints all information about its run-time behaviour on the terminal. 

### 2, How to use Y86 simulator?

(1) After installing all the tools, see "Errors When Installing Simulators", we can execute some example object files from `y86-code` as follows. See 3.1 of the "simguide" of CSAPP-2e.

```shell
# Note that excute the follwing command in the directory of '/y86-code'.
Unix > ../seq/ssim -t < asum.yo
```

(2) GUI mode is invoked by adding `-g`  in following a command. As an illustration, 

```shell
Unix > ../pipe/psim -t -g asum.yo # Note that there is no "<" for I/O redirection.  
```

