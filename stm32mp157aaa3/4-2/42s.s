bl main
.global mymul
mymul:
	mul r2,r0,r1
	mov r0,r2
	bx lr
.end
