%{
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>
	#include "defs.h"
	#include "symtab.h"
	#include "codegen.h"
  
	int yylex(void);
	int yyparse(void);
	int yyerror(const char *);
	extern int yylineno;
	int error_count = 0;
	unsigned scope = 0;
	
	int out_lin = 0;
	
	int labNumStates[64];
	int lab_num_count = -1;
	int max_lab_num = -1;
	
	int nextLabNumStates[64];
	int next_lab_num_count = -1;

  	FILE *output;
  
	char char_buffer[CHAR_BUFFER_LENGTH];


	// Kod definisanja funkcije parametri bez definisane vrednosti ne smeju da se nalaze posle param sa def vrednostima
	bool valuedParamDef = false;

	// Za funkcije
	int funcInds[32]; 
	int currFuncInd = -1; 	
	int defParamNum = 0;
	int nonDefParamNum = 0;
	bool hasReturn = false;
	int argsNum = 0;
	int funcCallInd = -1;

	// Za varijable
	int varNumsInds[64] = {0}; 
	int var_num_ind = 0;

	// Za parametre
	int paramNumsInds[64] = {0}; 
	int param_num_ind = 0;

	// Kod komparacije
	int currRelOp = -1;
	int cmpCounter = 0;

	// While petlja
	int regToClear = -1;
	int whileLabNums[64];
	// Broji u koliko se ugnjezdenih petlja nalazi pa na osnovu toga dozvoljava ( >0 ) odnosno ne dozvoljava ( ==0) 'break' ili 'continue'
	int loopCounter = -1;
	
	// Za multi assign
	int mAssignVarsCounter = 0;
	int mAssignValuesCounter = 0;
	int mAssignCurrVal = 0;
	int mAssignVarInds[64];
	
  
%}

%union {
  int i;
  char *s;
}

%token _NEW_LINE _INDENT _DEDENT 

%token _AND
%token _BREAK
%token _CONTINUE
%token _DEF
%token _ELIF _ELSE _EXCEPT
%token _FINALLY _FOR
%token _IF _IN
%token _NOT
%token _OR
%token _PASS
%token _RETURN
%token _TRY
%token _WHILE

%token _COMMA _COLON

%token _LPAREN _RPAREN
%token _ASSIGN

%token <i> _ADD_SUB_OP _MUL_DIV_OP _LOP _RELOP

%token <s> _ID
%token <s> _NUM_BOOL _STRING _NONE


%type <i> num_exp exp function_call literal while_part


%define parse.error verbose


%nonassoc VAR_ID 
%nonassoc _LPAREN

%left _LOP
%right _NOT
%left _RELOP
%left _ADD_SUB_OP
%left _MUL_DIV_OP 

%%

file
	: /* empty */ 
	| statement_list
	| new_line statement_list
	;

statement_list
	: statement {code("\n");}
	| statement_list statement {code("\n");}
	;

statement
	: simple_statement new_line
	| compound_statement
	;

simple_statement
	: assign_statement
	| multi_assign_statement
	| return_statement	{ hasReturn = true; }
	| function_call
	| _BREAK
		{
			if (loopCounter == 0)
				err("'break' must be inside while statement!");
				
			code("\n\t\tJMP \t@while_end%d", whileLabNums[loopCounter]);
		}
	| _CONTINUE
		{
			if (loopCounter == 0)
				err("'continue' must be inside while statement!");
				
			code("\n\t\tJMP \t@while_start%d", whileLabNums[loopCounter]);
		}
	| _PASS
	;

compound_statement
	: function_def
	| if_statement
	| while_statement
	| try_except_statement
	;
	
assign_statement
	: _ID _ASSIGN num_exp
		{
			int index = lookup_symbol_all_kinds($1);

			if(index == NO_INDEX || get_kind(index) == FUN) {
				index = insert_symbol($1, VAR, get_type($3), ++varNumsInds[var_num_ind], NO_ATR, scope);
				code("\n\t\tSUBS\t%%15,$%d,%%15", 4);
			}
			else 
				set_type(index, get_type($3));
			gen_mov($3, index);
		}
	; 

multi_assign_statement
	: multi_assign_vars 
		{
			code("\n\t\tSUBS\t%%15,$%d,%%15", 4*mAssignVarsCounter);
		}
	  multi_assign_values 
		{
			if (mAssignVarsCounter != mAssignValuesCounter)
				err("You must assign equal number of values to number of identifiers in multi assign statement!");
			mAssignVarsCounter = 0;
			mAssignValuesCounter = 0;
		}
	;

multi_assign_vars
	: _ID _COMMA _ID 
		{ 
			int index = lookup_symbol_all_kinds($1);
			if(index == NO_INDEX || get_kind(index) == FUN)
				mAssignVarInds[mAssignVarsCounter++] = insert_symbol($1, VAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			else
				mAssignVarInds[mAssignVarsCounter++] = index;

			index = lookup_symbol_all_kinds($3);
			if(index == NO_INDEX || get_kind(index) == FUN)
				mAssignVarInds[mAssignVarsCounter++] = insert_symbol($3, VAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			else
				mAssignVarInds[mAssignVarsCounter++] = index;
		}
	| multi_assign_vars _COMMA _ID 
		{ 
			int index = lookup_symbol_all_kinds($3);
			if(index == NO_INDEX || get_kind(index) == FUN)
				mAssignVarInds[mAssignVarsCounter++] = insert_symbol($3, VAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
			else
				mAssignVarInds[mAssignVarsCounter++] = index;		
		}
	;
	
multi_assign_values
	: _ASSIGN num_exp _COMMA num_exp 
		{ 	
			int index = mAssignVarInds[mAssignValuesCounter++];
			set_type(index, get_type($2));
			gen_mov($2, index);

			index = mAssignVarInds[mAssignValuesCounter++];
			set_type(index, get_type($4));
			gen_mov($4, index);
		}
	| multi_assign_values _COMMA num_exp 
		{
			int index = mAssignVarInds[mAssignValuesCounter++];
			set_type(index, get_type($3));
			gen_mov($3, index);
		}
	;

return_statement
	: _RETURN
		{
			if (currFuncInd < 0)
				err("'return' must be inside a function definition!");
			
			int funcInd = funcInds[currFuncInd];
			if(hasReturn && get_type(funcInd) != NONE)
				set_type(funcInd, UNKNOWN);

        	code("\n\t\tJMP \t@%s_exit", get_name(funcInds[currFuncInd]));	
		}
	| _RETURN num_exp
		{
			if (currFuncInd < 0)
				err("'return' must be inside a function definition!");
			
			int funcInd = funcInds[currFuncInd];
			if(hasReturn && get_type(funcInd) != $2)
				set_type(funcInd, UNKNOWN);
			else if(!hasReturn)
				set_type(funcInd, $2);
				
	        gen_mov($2, FUN_REG);
	        code("\n\t\tJMP \t@%s_exit", get_name(funcInds[currFuncInd]));	

		}
	;

function_call
	: _ID _LPAREN arguments _RPAREN
      {
        funcCallInd = lookup_symbol_all_kinds($1);
        if (funcCallInd == NO_INDEX || get_kind(funcCallInd) != FUN)
           err("There is no defined function of name %s", $1);
          
        int nonDefParams = get_atr1(funcCallInd);
        int defParams = get_atr2(funcCallInd);

        if (argsNum > nonDefParams+defParams)
        	err("Function given more arguments than the definition has parameters!");
        else if (argsNum < nonDefParams)
        	err("Function given less arguments than the definition has non default parameters!");

        code("\n\t\tCALL\t%s", get_name(funcCallInd));

        if(argsNum > 0)
          code("\n\t\tADDS\t%%15,$%d,%%15", argsNum * 4);
         
        argsNum = 0;
        set_type(FUN_REG, UNKNOWN);
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
      }
	;
	
arguments
	: /* no arguments */
	| arguments args
	;
	
args
	: num_exp
		{
			free_if_reg($1);
			code("\n\t\tPUSH\t");
			gen_sym_name($1);
			argsNum++;
		}
	| args _COMMA num_exp
		{
			code("\n\t\tPUSH\t");
			gen_sym_name($3);	
			free_if_reg($3);
			argsNum++;
		}
	;

function_def
	: _DEF _ID 
		{
			paramNumsInds[param_num_ind+1] = paramNumsInds[param_num_ind];
			param_num_ind++;

		    currFuncInd++;
			funcInds[currFuncInd] = insert_symbol($2, FUN, NONE, NO_ATR, NO_ATR, scope);
	  		scope++;
      	
		    code("\n%s:", $2);
		    code("\n\t\tPUSH\t%%14");
		    code("\n\t\tMOV \t%%15,%%14");
		}
	  _LPAREN parameters _RPAREN _COLON new_line 
		{
			set_atr1(funcInds[currFuncInd], nonDefParamNum);
			set_atr2(funcInds[currFuncInd], defParamNum);
	    	nonDefParamNum = 0;
	    	defParamNum = 0;
			code("\n@%s_body:", get_name(funcInds[currFuncInd]));
		}	
	  body 
	  	{
		    clear_symbols(funcInds[currFuncInd] + 1);
		    currFuncInd--;
			param_num_ind--;
		    scope--;
		    hasReturn = false;
	  	
	  	    code("\n@%s_exit:", $2);
		    code("\n\t\tMOV \t%%14,%%15");
		    code("\n\t\tPOP \t%%14");
		    code("\n\t\tRET");
		}
	;

parameters 
	: /* no params */
	| _ID  						
		{ 
			insert_symbol($1, PAR, UNKNOWN, ++paramNumsInds[param_num_ind], NO_ATR, scope);
			nonDefParamNum++; 
		}
	| param_with_default_val
	| parameters _COMMA _ID		
		{
			if (valuedParamDef)
				err("Parameters without default values cannot be defined after parameter with set default value.");

			insert_symbol($3, PAR, UNKNOWN, ++paramNumsInds[param_num_ind], NO_ATR, scope);
			nonDefParamNum++; 
		}
	| parameters _COMMA param_with_default_val
	;
	
param_with_default_val
	: _ID _ASSIGN num_exp
		{
			insert_symbol($1, PAR, UNKNOWN, ++paramNumsInds[param_num_ind], NO_ATR, scope);
			valuedParamDef = true;
			defParamNum++;
		}
	;

if_statement
	: if_part elif_part else_part 
		{ 
			code("\n@if_end%d:", labNumStates[lab_num_count]);
			lab_num_count--;
			next_lab_num_count--;
		}
	;

if_part
	: _IF 
		{
			labNumStates[++lab_num_count] = ++max_lab_num;
			nextLabNumStates[++next_lab_num_count] = 0;
			
			code("\n@if_start%d:", labNumStates[lab_num_count]);		
		}
	  num_exp _COLON new_line
		{
			$<i>$ = get_last_element()+1; 
			scope++;
			
			free_if_reg($3);
	        code("\n\t\t%s\t@next%d_%d", opp_jumps[currRelOp], labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]);	
			code("\n@if_body%d:", labNumStates[lab_num_count]);	
		}	
	 body
		{
			clear_symbols($<i>6);
			scope--;
			
			code("\n\t\tJMP \t@if_end%d", labNumStates[lab_num_count]);	
			code("\n@next%d_%d:", labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]++);
		}
	;
	
elif_part
	: /* no elif part*/
	| elif_part _ELIF num_exp _COLON new_line
		{
			$<i>$ = get_last_element()+1; 
			scope++;
			
			free_if_reg($3);

		    code("\n\t\t%s\t@next%d_%d", opp_jumps[currRelOp], labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]);	
		}
	 body
		{
			clear_symbols($<i>6);	
			scope--;
			
			code("\n@next%d_%d:", labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]++);
		}

	;

while_statement
	: while_part 
	  	{
			code("\n@while_else_start%d:", labNumStates[lab_num_count]);
			if (regToClear != -1) {
				free_if_reg(regToClear);
				regToClear = -1;
			}
	  	}
	  else_part 
		{ 
			code("\n@while_end%d:", labNumStates[lab_num_count]); 
			clear_symbols($1);	
			scope--;
			loopCounter--;
			
			lab_num_count--;
			next_lab_num_count--;
		}
	;

while_part
	: _WHILE 
		{			
			labNumStates[++lab_num_count] = ++max_lab_num;
			nextLabNumStates[++next_lab_num_count] = 0;
			
			whileLabNums[++loopCounter] = labNumStates[lab_num_count];

			$<i>$ = take_reg();
		    code("\n\t\tMOV \t$0,");
		    gen_sym_name($<i>$);
		    regToClear = $<i>$;
			code("\n@while_start%d:", labNumStates[lab_num_count]);
		}
	  num_exp _COLON new_line 
		{
			$<i>$ = get_last_element()+1; 
			scope++;
		
	        code("\n\t\t%s\t@while_body%d", jumps[currRelOp], labNumStates[lab_num_count]);	

			code("\n\t\tCMPS \t");
			gen_sym_name($<i>2);
			code(",$0");
            code("\n\t\t%s\t@while_else_start%d", jumps[4], labNumStates[lab_num_count]);
            code("\n\t\tJMP \t@while_end%d", labNumStates[lab_num_count]);

			code("\n@while_body%d:", labNumStates[lab_num_count]);
		    code("\n\t\tMOV \t$1,");
		    gen_sym_name($<i>2);
		}
	  body 
	  	{
	        code("\n\t\tJMP \t@while_start%d", labNumStates[lab_num_count]);
	        $$ = $<i>6;	  	
	  	}
	;

try_except_statement
	: try_part except_part finally_or_else_part
	;

try_part
	: _TRY _COLON new_line 
		{
			$<i>$ = get_last_element()+1; 
			scope++;
			loopCounter++;
		}
	  body
		{
			clear_symbols($<i>4);	
			scope--;
			loopCounter--;
		} 
	;

except_part
	: /* no except block */
	| except_part _EXCEPT _ID
	  	{
  	      	int index = lookup_symbol_all_kinds($3);
		    if(index == NO_INDEX)
		       insert_symbol($3, VAR, UNKNOWN, ++varNumsInds[var_num_ind], NO_ATR, scope);
		    else 
		    	if (get_kind(index) == FUN)
		    		insert_symbol($3, VAR, UNKNOWN, +varNumsInds[var_num_ind], NO_ATR, scope);
	  	}
	  except_finally_body
	| except_part _EXCEPT except_finally_body
	;

except_finally_body
	: _COLON new_line
		{
			$<i>$ = get_last_element()+1; 
			scope++;
			loopCounter++;
		}
	  body
		{
			clear_symbols($<i>3);	
			scope--;
			loopCounter--;
		}
	;
finally_or_else_part
	: /* no else or finally part */
	| _FINALLY except_finally_body
	| _ELSE except_finally_body
	;

else_part
	: /* no else part*/
	|_ELSE _COLON new_line 
		{
			$<i>$ = get_last_element()+1; 
			scope++;			
		}
	 body
		{
			clear_symbols($<i>4);	
			scope--;
			code("\n@next%d_%d:", labNumStates[lab_num_count], nextLabNumStates[next_lab_num_count]);
		}
	;

body
	: _INDENT 
		{
			varNumsInds[var_num_ind+1] = varNumsInds[var_num_ind];
			var_num_ind++;
		}
	  statement_list _DEDENT 
	  	{
            var_num_ind--;
	  	}
	;
		

num_exp
	: exp	{ $$ = $1; }
	| _NOT num_exp  
		{ 
			currRelOp = 4;
			$$ = take_reg();
			set_type($$, NUM_BOOL);
			
			code("\n\t\tCMPS \t");
			gen_sym_name($2);
			code(",$0");
			
            code("\n\t\t%s\t@true%d", jumps[4], cmpCounter);
            code("\n@false%d:", cmpCounter);

		    code("\n\t\tMOV \t$0, ");
		    gen_sym_name($$);

            code("\n\t\tJMP \t@cmp_end%d", cmpCounter);
            code("\n@true%d:", cmpCounter);

		    code("\n\t\tMOV \t$1, ");
		    gen_sym_name($$);		    

            code("\n@cmp_end%d:", cmpCounter++);
		}
	| num_exp _ADD_SUB_OP num_exp
		{
			int lt = get_type($1);
			int rt = get_type($3);
			int newType = UNKNOWN;
			
			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if (lt == STRING && rt == STRING) {
					if ($2 == SUB)
						err("Invalid operator '-' for operands of type 'string' and 'string'!");
					newType = STRING;
				}
				else if (lt == NUM_BOOL && rt == NUM_BOOL)
					newType = NUM_BOOL;
				else
					err("Invalid operator '+'/'-' for operands of type 'number'/'boolean' and 'string'!");
			}
			
			// Code gen part
		    code("\n\t\t%s\t", ar_instructions[$2]);
		    gen_sym_name($1);
		    code(", ");
		    gen_sym_name($3);
		    code(", ");
		    free_if_reg($3);
		    free_if_reg($1);
		    $$ = take_reg();
		    gen_sym_name($$);
		    set_type($$, newType);
		}
	| num_exp _MUL_DIV_OP num_exp
		{
			int lt = get_type($1);
			int rt = get_type($3);
			int newType = UNKNOWN;
			
			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if (lt == STRING && rt == STRING)
					err("Invalid operator for operands of type 'string' and 'string'!");
				else if ((lt == NUM_BOOL && rt == STRING) || (lt == STRING && rt == NUM_BOOL)) {
					if ($2 == DIV)
						err("Invalid operator for operands of type 'string' and 'number'/'boolean'!");
					newType = STRING;
				}
				else
					newType = NUM_BOOL;
			}
			
			// Code gen part
		    code("\n\t\t%s\t", ar_instructions[$2]);
		    gen_sym_name($1);
		    code(", ");
		    gen_sym_name($3);
		    code(", ");
		    free_if_reg($3);
		    free_if_reg($1);
		    $$ = take_reg();
		    gen_sym_name($$);
		    set_type($$, newType);
		}	
	| num_exp _LOP num_exp
		{
			int lt = get_type($1);
			int rt = get_type($3);

			if ($2 == AND)
				return rt;
			else 
				return lt;			
		}
	| num_exp _RELOP num_exp
		{
			int lt = get_type($1);
			int rt = get_type($3);
			int newType = UNKNOWN;
			
			if (lt != UNKNOWN && rt != UNKNOWN) {
				if (lt == NONE || rt == NONE)
					err("Invalid operator for operands of type 'None'!");
				else if ((lt == NUM_BOOL && rt == STRING) || (lt == STRING && rt == NUM_BOOL))
					err("Invalid operator for operands of type 'number'/'boolean' and 'string'!");
				else
					newType = NUM_BOOL;
			}
				
			currRelOp = $2;
		    $$ = take_reg();
		    set_type($$, newType);

			gen_cmp($1, $3);
            code("\n\t\t%s\t@true%d", jumps[currRelOp], cmpCounter);
            code("\n@false%d:", cmpCounter);

		    code("\n\t\tMOV \t$0, ");
		    gen_sym_name($$);

            code("\n\t\tJMP \t@cmp_end%d", cmpCounter);
            code("\n@true%d:", cmpCounter);

		    code("\n\t\tMOV \t$1, ");
		    gen_sym_name($$);		    

            code("\n@cmp_end%d:", cmpCounter++);
		}
	;
	
exp
	: literal	 { $$ = $1; }
	| _ID %prec VAR_ID
		{
			int idInd = lookup_symbol_var_par($1);
			if (idInd == NO_INDEX)
				err("Variable '%s' does not exist!", $1);
			$$ = idInd; 
		}
	| function_call		{ $$ = $1; }
	| _LPAREN num_exp _RPAREN	{ $$ = $2; }
	;
	
literal
	: _NUM_BOOL	{ $$ = insert_literal($1, NUM_BOOL, scope); }
	| _STRING	{ $$ = insert_literal($1, STRING, scope); }
	| _NONE		{ $$ = insert_literal($1, NONE, scope); }
	;

new_line
	: _NEW_LINE
	| new_line _NEW_LINE
	;
	
%%

int main() {
	int synerr;
	init_symtab();

	output = fopen("output.asm", "w+");
	synerr = yyparse();

	clear_symtab();
	fclose(output);
		
	if(synerr)
		return -1;  //syntax error
	else if(error_count)
		return error_count & 127; //semantic errors
	else
		return 0; //OK 
}
int yyerror(const char *s) {
  fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
  error_count++;
  return 0;
}
