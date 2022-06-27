
func:
		PUSH	%14
		MOV 	%15,%14
@func_body:
		MULS	8(%14), 8(%14), %0
		MOV 	%0,%13
		JMP 	@func_exit

@func_exit:
		MOV 	%14,%15
		POP 	%14
		RET

main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		PUSH	$11
		CALL	func
		ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET
