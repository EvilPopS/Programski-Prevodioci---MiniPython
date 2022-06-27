
main:
		PUSH	%14
		MOV 	%15,%14
@main_body:
		SUBS	%15,$4,%15
		MOV 	$10,-4(%14)

		SUBS	%15,$4,%15
		MOV 	$5,-8(%14)

		SUBS	%15,$4,%15
		MOV 	$0,-12(%14)

@if_start0:
		MULS	-8(%14), $3, %0
		CMPS 	-4(%14),%0
		JLTS	@true0
@false0:
		MOV 	$0, %1
		JMP 	@cmp_end0
@true0:
		MOV 	$1, %1
@cmp_end0:
		JGES	@next0_0
@if_body0:
		MULS	-4(%14), -8(%14), %0
		MOV 	%0,-8(%14)

@if_start1:
		CMPS 	-8(%14),$30
		JGTS	@true1
@false1:
		MOV 	$0, %0
		JMP 	@cmp_end1
@true1:
		MOV 	$1, %0
@cmp_end1:
		JLES	@next1_0
@if_body1:
		MOV 	$100,-12(%14)

		JMP 	@if_end1
@next1_0:
		CMPS 	-8(%14),$20
		JLTS	@true2
@false2:
		MOV 	$0, %0
		JMP 	@cmp_end2
@true2:
		MOV 	$1, %0
@cmp_end2:
		JGES	@next1_1
		MOV 	$50,-12(%14)

@next1_1:
@if_start2:
		CMPS 	-4(%14),$3
		JGTS	@true3
@false3:
		MOV 	$0, %0
		JMP 	@cmp_end3
@true3:
		MOV 	$1, %0
@cmp_end3:
		JLES	@next2_0
@if_body2:
		MOV 	$2,%13
		JMP 	@main_exit

		JMP 	@if_end2
@next2_0:
		CMPS 	-8(%14),$2
		JLTS	@true4
@false4:
		MOV 	$0, %0
		JMP 	@cmp_end4
@true4:
		MOV 	$1, %0
@cmp_end4:
		JGES	@next2_1
		MOV 	$45,-12(%14)

@next2_1:
@if_end2:

@next1_2:
@if_end1:

		JMP 	@if_end0
@next0_0:
		DIVS	$100, $5, %0
		ADDS	-8(%14), %0, %0
		CMPS 	-4(%14),%0
		JGTS	@true5
@false5:
		MOV 	$0, %1
		JMP 	@cmp_end5
@true5:
		MOV 	$1, %1
@cmp_end5:
		JLES	@next0_1
		MOV 	$40,-12(%14)

@next0_1:
		MOV 	$38,%13
		JMP 	@main_exit

@next0_2:
@if_end0:

		MOV 	-12(%14),%13
		JMP 	@main_exit

@main_exit:
		MOV 	%14,%15
		POP 	%14
		RET
