; fibonaaci series
	area reset, data, readonly
	export __Vectors
__Vectors
	dcd 0x10001000
	dcd Reset_Handler
	
	area mydata, data,readwrite
dst dcd 0
	area mycode, code,readonly
	export Reset_Handler
n dcd 10	; no. of terms of the series to be printed
	
	ENTRY
Reset_Handler
	ldr r0,=n
	ldr r1,[r0]
	ldr r2,=dst
	
	mov r3, #0
	mov r4, #1
loop
	add r3,r3,r4
	str r3, [r2], #4
	sub r4,r3,r4
	subs r1, #1
	bne loop
		
stop 
	b stop
	end
	
	
	