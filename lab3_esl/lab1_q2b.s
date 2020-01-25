;transfer ten 32 bit numbers
; with overlapping
	area RESET, data, readonly
	export __Vectors
__Vectors
	dcd 0x10001000
	dcd Reset_Handler

	area mydata, data, readwrite
dst dcd 0x1000001C
src dcd 0x10000000	
	area mycode, code, readonly
	export Reset_Handler
size equ 10
ol equ 2
	ENTRY
Reset_Handler
	ldr r0, =src
	ldr r1, =dst
	
	;this is the code to generate any source array
	; the source array is table of 5
	mov r2, #5
	mov r3, #10	;counter
	mov r4, #1
loop
	mul r10,r4, r2
	str r10, [r0],#4
	mov r10, #0
	add r4, #1
	subs r3, #1
	bne loop
	
	;let us begin the overlap transfer
	ldr r0, =src
	add r0, #(size-1)*4
	ldr r5,=size
	ldr r0,= src + (size-1)*4
	mov r1, r0
	sub r1, #(ol-1)*4
	add r1, #(size-1)*4
up
	ldr r2, [r0], #-4
	str r2, [r1], #-4
	subs r5, #1
	bne up
stop
	b stop
	end
	
	
	
	
	