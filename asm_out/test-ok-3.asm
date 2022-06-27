
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$12,%15
		MULS	$3, $5, %0
		MOV 	$2,-4(%14)
		MOV 	%0,-8(%14)
		ADDS	$2, $4, %0
		MOV 	%0,-12(%14)

		ADDS	-4(%14), -8(%14), %0
		ADDS	%0, -12(%14), %0
		MOV 	%0,%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET
