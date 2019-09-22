%{
#include <stdio.h>
#include <iostream>
using namespace std;

extern int yylex();
extern int yyparse();
extern FILE *yyin;

void yyerror(const char *s);
%}

%token NL ARRAY RETURN BREAK IMPORT IF ELIF ELSE FOR WHILE DEF ARITOP BOOLOP
%token NOT RELOP ASGN SCOMMA COMMA VARTYPE BOOL
%token OF CF OC CC OS CS ID CHAR INTL
%%

File: Imports GlobalDecs Functions
	| GlobalDecs Functions
	| Functions
	;

Imports: Import NL
	| Import Imports NL
	;

Import: IMPORT ID;

GlobalDecs: GlobalDec NL
	| GlobalDecs GlobalDec NL
	;

GlobalDec: ARRAY VARTYPE ArrayName
	| VARTYPE ID AssignedOrEmpty
	;

AssignedOrEmpty: ASGN Expression
	| /*epsilon*/
	;

ArrayName: ID OS Expression CS
	| ID OS Expression CS OS Expression CS
	;

Functions: NL
	| Function NL Functions
	;

Function: DEF ID OC ArgList CC OF Codes CF;

Codes: /*epsilon*/
	| Codes Code
	;

ArgList: /*epsilon*/
	| Argument
 	| Argument COMMA ArgList
	;

Argument: VARTYPE ID ;

Code: Loop
	| IfDec
	| Vardec
	| MethodCall
	| ReturnBlock
	| MultipleAssignment
	;

Vardec: ARRAY VARTYPE ID
	| VARTYPE ID
	| VARTYPE ID ASGN Expression
	;

Loop: ForLoop | WhileLoop;

ForLoop: FOR OC Declaration CC SCOMMA Condition SCOMMA Change CC OF Codes CF;

WhileLoop: WHILE OC Condition CC OF Codes CF;

Declaration: Location '=' Expression;

Expression: Location
	| MethodCall
	| Literal
	| Expression BinaryOp Expression
	| TernaryOp
	| '-' Expression
	| NOT Expression
	| OC Expression CC
	;

Location: ID
	| ID Expression
	| ID OS  Expression CS
	| ID OS  Expression CS OS Expression CS
	;


Condition:
	| Expression
	;

IfDec: IfBlock ElifBlock ElseBlock;

IfBlock: IF OC Condition CC OF Codes CF;

ElifBlock: /*epsilon*/
	| ElifPiece ElifBlock
	;

ElifPiece : ELIF OC Condition CC OF Codes CF;

ElseBlock: /*epsilon*/
	| ELSE OF Codes CF
	;

MethodCall: ID OC ParamList CC;

ParamList:  Expression ',' ParamList
	| Expression
	| /*epsilon*/
	;

Literal: INTL
	| BOOL
	| CHAR
	;

BinaryOp: RELOP
	| ARITOP
	| BOOLOP
	;

TernaryOp: Condition '?' Expression ':' Expression;

ReturnBlock: RETURN ParamList;

MultipleAssignment: VarList ASGN MethodCall;

VarList:
	Location |
	Location COMMA VarList
	;

Change: Location ASGN Expression
	| /*epsilon*/
	;
%%

void yyerror(const char *s)
{
        fprintf(stderr, "error: %s\n", s);
}


main(int argc, char **argv)
{
        yyparse();
        printf("Parsing Over\n");
}
