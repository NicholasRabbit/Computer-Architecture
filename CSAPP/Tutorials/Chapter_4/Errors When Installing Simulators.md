### Errors of Installing Y86 Simulators

When run `make` in `../sim` in CentOS 7, there are some errors occurring. 

1) `/usr/bin/ld: cannot find -lfl`.

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



