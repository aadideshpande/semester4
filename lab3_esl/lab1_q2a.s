;transfer block of ten 32 bit numbers
; without over-lapping
	area RESET, DATA, readonly
	export __Vectors
__Vectors
	dcd 0x10001000
	dcd Reset_Handler
	
	area mydata, DATA, readwrite
dst dcd 0
	area mycode, CODE, readonly
	export Reset_Handler
	ENTRY
src dcd 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A
	
Reset_Handler
	ldr r0,=src
	ldr r2,=dst
	mov r10,#10	;set the counter
	
loop
		ldr r1,[r0]
		str r1, [r2]
		add r0,#4
		subs r10, #1
		bne loop
stop
		b stop
		end