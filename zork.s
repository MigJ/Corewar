.name "zork"
.comment "just a basic living prog"
l2:
	sti r1,%:live,%1
	ld 34,r2
lfork %22
and r1,1,r1
	and 34,%1,r6
	and 3,3,r3
	and r2,r3,r4
live: live %1
zjmp %:live
sti r3,34,%34
	lld 34,r4
	lldi 3,%23,r5
