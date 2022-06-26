
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$8,%15
		ADDS	$1, $3, %0
		MOV 	$1,-4(%14)
		MOV 	%0,-8(%14)

		SUBS	%15,$12,%15
		MOV 	$1,-4(%14)
		MOV 	$1,-12(%14)
		MOV 	$1,-16(%14)

		ADDS	-4(%14), -8(%14), %0
		ADDS	%0, -12(%14), %0
		ADDS	%0, -16(%14), %0
		MOV 	%0,%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET
