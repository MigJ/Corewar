	.name "zork"
	.comment "just	a basic living prog"
l2:
	and r1,%0,r3
	and 34,%34,r6
live:	live %1
	zjmp %:live
	sti r3,%34,%34
