
sum_args:
		PUSH	%14
		MOV 	%15,%14
@sum_args_body:
		ADDS	8(%14), 12(%14), %0
		ADDS	%0, 16(%14), %0
		MOV 	%0,%13
		JMP 	@sum_args_exit

@sum_args_exit:
		MOV 	%14,%15
		POP 	%14
		RET

quad:
		PUSH	%14
		MOV 	%15,%14
@quad_body:
		MULS	8(%14), 8(%14), %0
		MOV 	%0,%13
		JMP 	@quad_exit

@quad_exit:
		MOV 	%14,%15
		POP 	%14
		RET

main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$12,%15
		PUSH	$0
		CALL	quad
		ADDS	%15,$4,%15
		MOV 	%13,%0
		PUSH	$2
		CALL	quad
		ADDS	%15,$4,%15
		MOV 	%13,%1
		MOV 	%0,-4(%14)
		MOV 	%1,-8(%14)
		PUSH	$3
		CALL	quad
		ADDS	%15,$4,%15
		MOV 	%13,%0
		MOV 	%0,-12(%14)

		MOV 	-4(%14),%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET
