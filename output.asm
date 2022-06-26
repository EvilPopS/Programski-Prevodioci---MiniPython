
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$4,%15
		MOV 	$2,-4(%14)

		MOV 	$0,%0
@while_start0:
		CMPS 	-4(%14),$5
		JGTS	@true0
@false0:
		MOV 	$0, %1
		JMP 	@cmp_end0
@true0:
		MOV 	$1, %1
@cmp_end0:
		JGTS	@while_body0
		CMPS 	%0,$0
		JEQ 	@while_else_start0
		JMP 	@while_end0
@while_body0:
		MOV 	$1,%0
		ADDS	-4(%14), $1, %2
		MOV 	%2,-4(%14)

		JMP 	@while_start0
@while_else_start0:
		MOV 	$123,%13
		JMP 	@main_exit

@next0_0:
@while_end0:
		MOV 	-4(%14),%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET