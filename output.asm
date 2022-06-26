
abc:
		PUSH	%14
		MOV 	%15,%14
@abc_body:
		ADDS	8(%14), 12(%14), %0
		ADDS	%0, 16(%14), %0
		MOV 	%0,%13
		JMP 	@abc_exit

@abc_exit:
		MOV 	%14,%15
		POP 	%14
		RET
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
			PUSH	$2
			PUSH	$0
			PUSH	$3
			CALL	abc
			ADDS	%15,$12,%15
		MOV 	%13,%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET