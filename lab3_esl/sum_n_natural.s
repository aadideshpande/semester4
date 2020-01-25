; get the sum of n natural numbers
	area reset, data, readonly
	export __Vectors
__Vectors
	dcd 0x10001000
	dcd Reset_Handler

	area mydata, data, readwrite
dst dcd 0
	area mycode, code, readonly
	export Reset_Handler
src dcd 10
	ENTRY
Reset_Handler	
	ldr r0, =src
	ldr r3, =dst
	ldr r1, [r0]
	mov r5, #0	; r5 will store the sum
	mla r5,r1,r1,r1
	
	lsr r5, #1
	str r5,[r3]
	end