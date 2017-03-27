	.name "lol"
	.comment "argh"

l1:
	ld 1,r1
	live %1
	zjmp %:l1
	st r1, 2
