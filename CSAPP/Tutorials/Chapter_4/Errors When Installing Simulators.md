### Errors of Installing Y86 Simulators

Note that the Linux distribution where the following errors occur is "CentOS 7.9.2009". The simulator is Y86 of CSAPP2e. 

#### General Errors

(1) When run `make` in `../sim` in CentOS 7, there are some errors occurring. 

1. **"/usr/bin/ld: cannot find -lfl"**

   1) Replace default mirrors with domestic ones in China. 

   First of all, if you are in China, replace the default mirrors with domestic ones. See the note of CentOS in my personal note to know how to accomplish it

   2) Then install `flex`.  

   ```shell
   # 1. Check if flex is installed.
   flex --version.
   # 2. If not, install it.
   yum install flex
   ```

   3) Install `libfl`

   ```shell
   yum install flex-devel
   ```

#### GUI Version

(1) After installing `flex`, when I was trying to run a command to invoke GUI mode in the directory of `y86-code` as it is written in "simguide", an errors occurs.

```shell
# Run this command in 'y86-code'
../seq/ssim  -t -g asum.yo
"Error in startup script: couldn't read file "seq.tcl": no such file or directory"
```

Whereas, there isn't any problem when it is running in `./sim/seq/` where the program `ssim` is.

```shell
# In ./sim/seq/
./ssim -t -g ../y86-code/asum.yo 
```

Note that GUI mode cannot be invoked in a SSH client, such as Putty. 

