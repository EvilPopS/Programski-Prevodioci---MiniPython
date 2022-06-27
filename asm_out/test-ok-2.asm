
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$4,%15
		MOV 	$2,-4(%14)

		ADDS	-4(%14), $6, %0
		MOV 	%0,-4(%14)

		SUBS	%15,$4,%15
		MOV 	$1,-8(%14)

		ADDS	-4(%14), -8(%14), %0
		SUBS	%15,$4,%15
		MOV 	%0,-12(%14)

		MOV 	-12(%14),%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET
