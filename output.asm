
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$4,%15
		MOV 	$2,-4(%14)

@if_start0:
		CMPS 	-4(%14),$4
		JLTS	@true0
@false0:
		MOV 	$0, %0
		JMP 	@cmp_end0
@true0:
		MOV 	$1, %0
@cmp_end0:
		JGES	@next0_0
@if_body0:
		MOV 	$6,-4(%14)

@if_start1:
		CMPS 	-4(%14),$6
		JLTS	@true1
@false1:
		MOV 	$0, %0
		JMP 	@cmp_end1
@true1:
		MOV 	$1, %0
@cmp_end1:
		JGES	@next1_0
@if_body1:
		MOV 	$1,%13
		JMP 	@main_exit

@next1_0:
		CMPS 	$0,$0
		JEQ 	@true2
@false2:
		MOV 	$0, %0
		JMP 	@cmp_end2
@true2:
		MOV 	$1, %0
@cmp_end2:
		JNE 	@next1_1
@if_start2:
		CMPS 	$0,$0
		JEQ 	@true3
@false3:
		MOV 	$0, %0
		JMP 	@cmp_end3
@true3:
		MOV 	$1, %0
@cmp_end3:
		JNE 	@next2_0
@if_body2:
		MOV 	$1241,%13
		JMP 	@main_exit

@next2_0:
@if_end2:
@next1_1:
		MOV 	$2,%13
		JMP 	@main_exit

@next1_2:
@if_end1:
@next0_0:
		MOV 	$3,%13
		JMP 	@main_exit

@next0_1:
@if_end0:
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET