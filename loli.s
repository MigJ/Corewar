	.name "HULA"
	.comment "A voir"

lab1:
live %1
	ld 34,r3
	st r3,r2
	add r1,r3,r8
	sub r1,r3,r8
	and r2, r2,r3
	or r2,%0,r3
	xor r2,%0,r3
	zjmp %:lab1
	ldi 3,%4,r1
	sti r2,%4,%5
	fork %45
	lld 34,r3
	lldi 3,%4,r1
	lfork %45
	aff r3
