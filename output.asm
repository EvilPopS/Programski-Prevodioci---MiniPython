
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
@if_start0:
		CMPS 	$0,$2
		JLTS	@true0
@false0:
		MOV 	$0, %0
		JMP 	@cmp_end0
@true0:
		MOV 	$1, %0
@cmp_end0:
		CMPS 	%0,$0
		JEQ 	@true1
@false1:
		MOV 	$0, %1
		JMP 	@cmp_end1
@true1:
		MOV 	$1, %1
@cmp_end1:
		JNE 	@next0_0
@if_body0:
		MOV 	$123,%13
		JMP 	@main_exit

@next0_0:
		MOV 	$9,%13
		JMP 	@main_exit

@next0_1:
@if_end0:
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET