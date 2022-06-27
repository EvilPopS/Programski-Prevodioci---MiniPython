
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$4,%15
		MOV 	$0,-4(%14)

		MOV 	$0,%0
@while_start0:
		CMPS 	-4(%14),$5
		JLES	@true0
@false0:
		MOV 	$0, %1
		JMP 	@cmp_end0
@true0:
		MOV 	$1, %1
@cmp_end0:
		JLES	@while_body0
		CMPS 	%0,$0
		JEQ 	@while_else_start0
		JMP 	@while_end0
@while_body0:
		MOV 	$1,%0
		SUBS	%15,$4,%15
		MOV 	$0,-8(%14)

		MOV 	$0,%2
@while_start1:
		CMPS 	-8(%14),$10
		JLTS	@true1
@false1:
		MOV 	$0, %3
		JMP 	@cmp_end1
@true1:
		MOV 	$1, %3
@cmp_end1:
		JLTS	@while_body1
		CMPS 	%2,$0
		JEQ 	@while_else_start1
		JMP 	@while_end1
@while_body1:
		MOV 	$1,%2
@if_start2:
		CMPS 	-8(%14),$5
		JEQ 	@true2
@false2:
		MOV 	$0, %4
		JMP 	@cmp_end2
@true2:
		MOV 	$1, %4
@cmp_end2:
		JNE 	@next2_0
@if_body2:
		JMP 	@while_end1

		JMP 	@if_end2
@next2_0:
		CMPS 	-8(%14),$3
		JLTS	@true3
@false3:
		MOV 	$0, %4
		JMP 	@cmp_end3
@true3:
		MOV 	$1, %4
@cmp_end3:
		JGES	@next2_1
		ADDS	-4(%14), -8(%14), %4
		MOV 	%4,-4(%14)

@next2_1:
		CMPS 	-8(%14),$6
		JGTS	@true4
@false4:
		MOV 	$0, %4
		JMP 	@cmp_end4
@true4:
		MOV 	$1, %4
@cmp_end4:
		JLES	@next2_2
		ADDS	-4(%14), -8(%14), %4
		MOV 	%4,-4(%14)

@next2_2:
@if_end2:

		ADDS	-8(%14), $1, %4
		MOV 	%4,-8(%14)

		JMP 	@while_start1
@while_else_start1:
@while_end1:

		ADDS	-4(%14), $1, %3
		MOV 	%3,-4(%14)

		JMP 	@while_start0
@while_else_start0:
@while_end0:

		MOV 	-4(%14),%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET
