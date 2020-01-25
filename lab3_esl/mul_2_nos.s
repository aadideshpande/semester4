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
	ldr r2, [r0]
	ldr r3, [r1]
loop
	subs 
	bne loop
	end
	
	
	