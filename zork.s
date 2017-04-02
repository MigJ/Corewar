.name "zork"
.comment "lol"
l2:
sti r1,%:live,%1
and r1,%0,r1
and 34,%34,r6	
live: live %1
zjmp %:live
sti r3,%34,%34
