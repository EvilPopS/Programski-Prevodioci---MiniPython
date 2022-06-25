
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		CMPS 	$2,$3
		JLTS	@true0
@false0:
		MOV 	$0, %0
		JMP 	@cmp_end0
@true0:
		MOV 	$1, %0
@cmp_end0:
		SUBS	%15,$4,%15
		MOV 	%0,-4(%14)

		CMPS 	$3,$2
		JLTS	@true1
@false1:
		MOV 	$0, %0
		JMP 	@cmp_end1
@true1:
		MOV 	$1, %0
@cmp_end1:
		SUBS	%15,$4,%15
		MOV 	%0,-8(%14)

		CMPS 	-4(%14),-8(%14)
		JGTS	@true2
@false2:
		MOV 	$0, %0
		JMP 	@cmp_end2
@true2:
		MOV 	$1, %0
@cmp_end2:
		SUBS	%15,$4,%15
		MOV 	%0,-12(%14)

@if0:
		CMPS 	-4(%14),-8(%14)
		JLTS	@true3
@false3:
		MOV 	$0, %0
		JMP 	@cmp_end3
@true3:
		MOV 	$1, %0
@cmp_end3:
		JGES	@next0_0
		MOV 	$3,%13
		JMP 	@main_exit

@next0_0:
		CMPS 	-12(%14),$0
		JEQ 	@true4
@false4:
		MOV 	$0, %0
		JMP 	@cmp_end4
@true4:
		MOV 	$1, %0
@cmp_end4:
		JNE 	@next0_1
		MOV 	$7,%13
		JMP 	@main_exit

@next0_1:
		CMPS 	-12(%14),$1
		JEQ 	@true5
@false5:
		MOV 	$0, %0
		JMP 	@cmp_end5
@true5:
		MOV 	$1, %0
@cmp_end5:
		JNE 	@next0_2
		MOV 	$8,%13
		JMP 	@main_exit

@next0_2:
@exit_if0:
@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET