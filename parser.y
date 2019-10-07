%{
	#include <cstdio>
	#include <iostream>
	using namespace std;

	extern "C" int yylex();
	extern int yyparse();
	extern FILE **yyin;
	void yyerror(const char *s);
%}

%token ARRAY RETURN BREAK IMPORT IF ELIF ELSE FOR WHILE DEF ARITOP BOOLOP
%token NOT RELOP SCOMMA COMMA BOOL VOID
%token OF CF OC CC OS CS ID CHAR INTL NL QUEST COLON
%token ADD DIV EQ GEQ GT LEQ LT MULT NEQ SUB AND OR TRUE FALSE
%token TINT TUINT TCHAR TBOOL STOP
%token ASGN PASGN SASGN

%left ADD SUB
%left MULT DIV
%left EQ GEQ LEQ LT GT NEQ
%left AND OR
%right NOT
%right UMINUS
%%

File : ImportList ListOfStatem ListofFunctions   {cout << "Imports + GlobalDecs + Funcs" << endl;}
		 | ListOfStatem ListofFunctions							 {cout << "GlobalDecs + Functions" << endl;}
		 | ListofFunctions							 	 					 {cout << "Funcs" << endl;}
		 | ImportList ListofFunctions			 					 {cout << "Imports + Funcs" << endl;}
		 ;

Return : RETURN VOID STOP
			 | RETURN ListOfExpr STOP

Break:  BREAK STOP					{cout << "Break" << endl;}

ImportList : Import				 {cout << "Import" << endl;}
					 | ImportList Import  {cout << "List Of Imports" << endl;}
					 ;

Import : IMPORT ID STOP ;

ListofFunctions: Function								{cout << "Single Function" << endl;}
							| ListofFunctions Function {cout << "List of Functions" << endl;}

Function : DEF ID OC VoidableArgList CC OF ListOfCode CF {cout << "Function" << endl;}

VoidableArgList: VOID
							 | ArgList
							 ;

ArgList : Vartype ID        														{cout << "TYPE ID" << endl;}
				| ArgList COMMA Vartype ID 											{cout << "List of Vartype ID" << endl;}
				;

ListOfCode: Code
		 | Code ListOfCode
		 ;

Code : ListOfStatem {cout << "Code" << endl;}
		 | Conditional  {cout << "If-Else" << endl;}
		 | Loop 				{cout << "Loop" << endl;}
		 | Return				{cout << "Return" << endl;}
		 | Break				{cout << "Break" << endl;}
		 ;

Loop : ForLoop      {cout << "For" << endl;}
		| WhileLoop			{cout << "While" << endl;}
		;


ForLoop : FOR OC Voidable SCOMMA Expression SCOMMA Voidable CC OF ListOfCode CF

WhileLoop : WHILE OC VoidableSingleStatement CC OF ListOfCode CF

VoidableSingleStatement: VOID
				| Statement
				;

Voidable: VOID      {cout << "VOID" << endl;}
				| ListOfStatem {cout << "Voidable -> ListOfCode" << endl;}
				;

Conditional: IF OC Expression CC OF ListOfCode CF {cout << "If{*}" << endl;}
		| IF OC Expression CC OF ListOfCode CF Else_Block {cout << "If-El*" << endl;}
		;

Else_Block: ELSE OF ListOfCode CF {cout << "Else" << endl;}
		| ELIF OC Expression CC OF ListOfCode CF {cout << "Elif" << endl;}
		| ELIF OC Expression CC OF ListOfCode CF Else_Block {cout << "Elif*" << endl;}
		;
/*Non empty expressions for condition and code*/

ListOfStatem : ListOfStatem STOP Statement {cout << "S |n S" << endl;}
						 | Statement {cout << "Statement" << endl;}

Statement  : Expression                  {cout << "S->Expression" << endl;}
					 | Location AsignOp Expression    {cout << "Loc = Expr" << endl;}
					 | Vartype ID AsignOp Expression {cout << "Type Id = Expr" << endl;}
					 | Initialization                {cout << "INIT" << endl;}
					 ;

Initialization: Vartype ID
 					|  ARRAY Vartype ID OS Expression CS       {cout << "1d array init" << endl;}
					|  ARRAY Vartype ID OS Expression COMMA Expression CS {cout << "2d array init" << endl;}
					;

AsignOp : ASGN	{cout << "=" << endl;}
				| PASGN {cout << "+=" << endl;}
				| SASGN {cout << "-=" << endl;}

Expression : Location 								   {cout << "Location" << endl;}
					 | Literal                     {cout << "Literal" << endl;}
					 | Expression ADD Expression   {cout << "Expr + Expr"<< endl;}
					 | Expression SUB Expression   {cout << "Expr - Expr"<< endl;}
					 | Expression MULT Expression  {cout << "Expr * Expr"<< endl;}
					 | Expression DIV Expression   {cout << "Expr / Expr" << endl;}
					 | Expression LEQ Expression   {cout << "Expr <= Expr" << endl;}
					 | Expression GEQ Expression   {cout << "Expr >= Expr" << endl;}
					 | Expression GT Expression    {cout << "Expr > Expr" << endl;}
					 | Expression EQ Expression    {cout << "Expr == Expr" << endl;}
					 | Expression LT Expression    {cout << "Expr < Expr" << endl;}
					 | Expression NEQ Expression   {cout << "Expr != Expr" << endl;}
					 | Expression AND Expression   {cout << "Expr and Expr" << endl;}
					 | Expression OR Expression    {cout << "Expr or Expr" << endl;}
					 | OC Expression CC            {cout << "(Expr)" << endl;}
					 | NOT Expression              {cout << "not Expr" << endl;}
					 | SUB Expression %prec UMINUS     {cout << "- Expr" << endl;}
					 | MethodCall 								 {cout << "MethodCall" << endl;}
					 ;

Location : ID {cout << "ID" << endl;}
				 | ID OS Expression CS {cout << "1D Access" << endl;}
				 | ID OS Expression COMMA  Expression CS {cout << "2D Access" << endl;}
				 ;

Literal : INTL {cout << "INTL" << endl;}
				| TRUE {cout << "TRUE" << endl;}
				| FALSE {cout << "FALSE" << endl;}
				| CHAR {cout << "CHAR" << endl;}
				;

Vartype: TINT   {cout << "int" << endl;}
				| TUINT {cout << "uint" << endl;}
				| TBOOL {cout << "bool" << endl;}
				| TCHAR {cout << "char" << endl;}

MethodCall: ID OC CC
				| ID OC ListOfExpr CC
				;

ListOfExpr: Expression {cout << "ListOfExpr" << endl;}
				| Expression COMMA Expression {cout << "ListOfExpr" << endl;}
				;

%%

int main(int argc, char **argv)
{
			/*

				FILE *myfile = fopen(argv[1],"r");
				fileno(myfile);
				if (!myfile) {
					cout << "Cant open " << argv[1] << endl;
					return -1;
				}
				yyin = myfile;
        yyparse();
        printf("Parsing Over\n"); */
		yyparse();
		return (0);
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}
