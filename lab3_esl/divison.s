;divison of two numbers using repeated subtraction
	area reset, data, readonly
	export __Vectors
__Vectors
	dcd 0x10001000
	dcd Reset_Handler
	
	area mydata, data,readwrite
dst dcd 0
	area mycode, code,readonly
	export Reset_Handler
n1 dcd 24
n2 dcd 04
	ENTRY
Reset_Handler
	ldr r0,=n1
	ldr r1,=n2
	mov r2,#0	;store the quotient
	ldr r3, [r0] ;will store remainder
	ldr r4, [r1]
loop
	cmp r3, r4
	bcs skip
	mov r5,r3
	b stop

skip
	sub r3,r3,r4
	add r2, #1
	b loop
stop 
	b stop
	end
	
	
	