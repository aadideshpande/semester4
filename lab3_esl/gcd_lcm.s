;gcd and lcm of numbers
	area reset, data, readonly
	export __Vectors
__Vectors
	dcd 0x10001000
	dcd Reset_Handler
	
	area mydata, data,readwrite
dst dcd 0
	area mycode, code,readonly
	export Reset_Handler
n1 dcd 35
n2 dcd 07
	ENTRY
Reset_Handler
	ldr r0,=n1
	ldr r1,=n2
	ldr r4, =dst
	ldr r2, [r0]
	ldr r3, [r1]
	mov r5,r2;	;temp value
	mov r6,r3;	;temp value
loop
	cmp r5,r6
	beq stop
	bhi sub1	; if r2 > r3 is true
	sub r6,r6,r5
sub1
	sub r5,r5,r6
	b loop

stop
	str r5, [r4]	;GCD is stored in r5

; now, we will find the LCM
	mul r6, r2,r3
	
loop2
	cmp r6, r5
	bcs skip
	mov r6,r5
	b stop2

skip
	sub r6,r6,r5
	add r10, #1		;r10 contains the quotient i.e. the LCM
	b loop2

stop2 
	b stop2
	end
	
	
	