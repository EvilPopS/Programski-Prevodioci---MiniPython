
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$4,%15
		MOV 	$2,-4(%14)
		SUBS	%15,$4,%15
		MOV 	$3,-8(%14)
		ADDS	-4(%14), -8(%14), %0
		SUBS	%15,$4,%15
		MOV 	%0,-12(%14)
		ADDS	-12(%14), $1, %0
		SUBS	%15,$4,%15
		MOV 	%0,-16(%14)
		MOV 	-16(%14),%13
		JMP 	@main_exit
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET