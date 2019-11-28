%{
	#include <cstdio>
	#include <iostream>
	using namespace std;
	#include <string>
	extern "C" int yylex();
	extern int yyparse();
	extern FILE **yyin;
	#include "ast.h"
	void yyerror(const char *s);
	/* map <string, symb_type> Symbol_table; */
%}

%token ARRAY RETURN BREAK IMPORT IF ELIF ELSE FOR WHILE DEF
%token NOT SCOMMA COMMA
%token OF CF OC CC OS CS QUEST COLON
%token ADD DIV EQ GEQ GT LEQ LT MULT NEQ SUB AND OR MOD

%token <node> INTL UINTL
%token <node> CHAR
%token <node> TRUE
%token <node> FALSE
%token <node> ID VOID
%token <value> TINT TUINT TCHAR TBOOL STOP
%token <value> ASGN PASGN SASGN
%type <node> Literal
%type <node> Location
%type <node> Expression MethodCall ListOfExpr Statement Initialization ListOfStatem Elif_Piece Else_Block Conditional Code
%type <node> Voidable VoidableSingleStatement ListOfCode Loop ForLoop WhileLoop Return Break TernaryOp
%type <node> VoidableArgList ArgList ImportList ListofFunctions File Function Import Else_Piece
%type <value> Vartype AsignOp

%left STATEMENT
%left LOCID
%left OC
%left EXPRESSIONVSEXPRESSION
%left EXPRESSIONVSLOCASGNEXP
%left EQ NEQ
%left GEQ LEQ LT GT 
%left ADD SUB
%left MULT DIV MOD
%left AND OR
%right NOT
%right UMINUS

%union
{
char* value;
class ASTnode *node;
}

%%
/*
Bile: File { $1->visit();}
*/

FinalNode : File	{
												cout << "-------AST------" << endl;
												$1->visit();
												cout << "------------------------" << endl;
												cout << "-------Interpreter------" << endl;
												cout << $1->interpret() << endl;
												cout << "------Symbol_table------" << endl;
												global_table.print();
												cout << "------------------------" << endl;
												cout << "------Function_Table------" << endl;
												method_table.print();
												cout << "------------------------" << endl;
												}

File : ImportList ListOfStatem ListofFunctions   { $$ = new FileNode($1, $2, $3); cout << "Imports + GlobalDecs + Funcs" << endl;}
		 | ListOfStatem ListofFunctions							 { $$ = new FileNode(NULL, $1, $2); cout << "GlobalDecs + Functions" << endl;}
		 | ListofFunctions							 	 					 { $$ = new FileNode(NULL, NULL, $1); cout << "Funcs" << endl;}
		 | ImportList ListofFunctions			 					 { $$ = new FileNode($1, NULL, $2); cout << "Imports + Funcs" << endl;}
		 ;

ImportList : Import				 { $$ = new ImportsListNode($1); cout << "Import" << endl;}
					 | ImportList Import  { $$->pb($2); cout << "List Of Imports" << endl;}
					 ;

Import : IMPORT ID STOP  {$$ = $2;}

ListofFunctions: Function								 {$$ = new FunctionListNode($1); cout << "Single Function" << endl;}
				| ListofFunctions Function {$$->pb($2); cout << "List of Functions" << endl;}

Function : DEF ID OC VoidableArgList CC OF ListOfCode CF {$$ = new FunctionNode($2,$4,$7); cout << "Function" << endl;}

ArgList : Vartype ID        					{$$ = new ArgListNode(new SingleInitNode($2,std::string($1))); cout << "TYPE ID" << endl;}
				| ArgList COMMA Vartype ID 		{$$->pb(new SingleInitNode($4,std::string($3))); cout << "List of Vartype ID" << endl;}
				;

VoidableArgList: VOID									{$$ = $1;}
							 | ArgList							{$$ = $1;}
							 ;

ListOfCode: Code													{cout << "LC -< C" << endl; $$ = new CodesNode($1);}
		 | ListOfCode Code										{$$->pb($2);}
		 ;

Code : ListOfStatem {$$ = $1; cout << "Code" << endl;}
		 | Conditional  {$$ = $1; cout << "If-Else" << endl;}
		 | Loop 				{$$ = $1; cout << "Loop" << endl;}
		 | Return				{$$ = $1; cout << "Return" << endl;}
		 | Break				{$$ = $1; cout << "Break" << endl;}
		 | TernaryOp    {$$ = $1; cout << "Ternary Op" << endl;}
		 ;

Loop : ForLoop      {$$ = $1; cout << "For" << endl;}
		| WhileLoop			{$$ = $1; cout << "While" << endl;}
		;

TernaryOp: 	Statement QUEST Statement COLON Statement STOP {$$ = new TernaryNode($1, $3, $5); cout << "Tern Expr" << endl;}

ForLoop : FOR OC Voidable SCOMMA Expression SCOMMA Voidable CC OF ListOfCode CF {$$ = new ForNode($3,$5,$7,$10);}

WhileLoop : WHILE OC VoidableSingleStatement CC OF ListOfCode CF {$$ = new WhileNode($3,$6);}

Return : RETURN VOID STOP												 {$$ = new ReturnNode($2);}
			 | RETURN Expression STOP									 {$$ = new ReturnNode($2);}

Break:  BREAK STOP					{ $$ = new BreakNode(); cout << "Break" << endl;}

VoidableSingleStatement: VOID {$$ = $1;}
				| Statement {$$ = $1;}
				;

Voidable: VOID      {$$ = $1; cout << "VOID" << endl;}
				| ListOfStatem {$$ = $1; cout << "Voidable -> ListOfCode" << endl;}
				;

Conditional: IF OC Expression CC OF ListOfCode CF { $$ = new ConditionNode($3,$6); cout << "If{*}" << endl;}
		| IF OC Expression CC OF ListOfCode CF Else_Block {$$ = new ConditionNode($3, $6, $8); cout << "If-El*" << endl;}
		;

Else_Block: Else_Piece { $$ = new ElseBlockNode($1);}
		| Elif_Piece { $$ = new ElseBlockNode(); $$->pb($1);}
		| Elif_Piece Else_Block { $$ = $2; $$->pb($1); cout << "Elif*" << endl;}
		;

Elif_Piece: ELIF OC Expression CC OF ListOfCode CF {$$ = new ElseIfNode($3, $6);}

Else_Piece: ELSE OF ListOfCode CF {$$ = new ElseNode($3);}

ListOfStatem : ListOfStatem STOP Statement { $$->pb($3); cout << "S |n S" << endl;}
						 | Statement {$$ = new StatementsNode($1); cout << "Statement" << endl;}

Statement  : Expression                 	 %prec EXPRESSIONVSEXPRESSION {$$ = $1; cout << "S->Expression" << endl;}
					 | Location AsignOp Expression   %prec EXPRESSIONVSLOCASGNEXP {$$ = new AssignmentNode($1,std::string($2),$3); cout << "Loc = Expr" << endl;}
					 | Vartype ID AsignOp Expression %prec STATEMENT{$$ = new InitAssignmentNode($2,std::string($3),$4,std::string($1)); cout << "Type Id = Expr" << endl;}
					 | Initialization                {$$ = $1; cout << "INIT" << endl;}
					 ;

Initialization: Vartype ID													 {$$ = new SingleInitNode($2,std::string($1));}
 					|  ARRAY Vartype ID OS Expression CS       { $$ = new OneDInitNode($3,$5,std::string($2)) ;cout << "1d array init" << endl;}
					|  ARRAY Vartype ID OS Expression COMMA Expression CS {$$ = new TwoDInitNode($3,$5,$7,std::string($2)); cout << "2d array init" << endl;}
					;

AsignOp : ASGN	{$$ = $1; cout << "=" << endl;}
				| PASGN {$$ = $1; cout << "+=" << endl;}
				| SASGN {$$ = $1; cout << "-=" << endl;}


Expression : Location 							     { $$ = $1; cout << "Location" << endl;}
					 | Literal                     { $$ = $1; cout << "Literal" << endl;}
					 | Expression ADD Expression   { $$ = new BiExprNode($1, $3, "add");  cout << "Expr + Expr"<< endl;}
					 | Expression SUB Expression   { $$ = new BiExprNode($1, $3, "sub");  cout << "Expr - Expr"<< endl;}
					 | Expression MULT Expression  { $$ = new BiExprNode($1, $3, "mult"); cout << "Expr * Expr"<< endl;}
					 | Expression DIV Expression   { $$ = new BiExprNode($1, $3, "div");  cout << "Expr / Expr" << endl;}
					 | Expression MOD Expression   { $$ = new BiExprNode($1, $3, "mod");  cout << "Expr %% Expr" << endl;}
					 | Expression LEQ Expression   { $$ = new BiExprNode($1, $3, "leq");  cout << "Expr <= Expr" << endl;}
					 | Expression GEQ Expression   { $$ = new BiExprNode($1, $3, "geq");  cout << "Expr >= Expr" << endl;}
					 | Expression GT Expression    { $$ = new BiExprNode($1, $3, "gt");   cout << "Expr > Expr" << endl;}
					 | Expression EQ Expression    { $$ = new BiExprNode($1, $3, "eq");   cout << "Expr == Expr" << endl;}
					 | Expression LT Expression    { $$ = new BiExprNode($1, $3, "lt");   cout << "Expr < Expr" << endl;}
					 | Expression NEQ Expression   { $$ = new BiExprNode($1, $3, "neq");  cout << "Expr != Expr" << endl;}
					 | Expression AND Expression   { $$ = new BiExprNode($1, $3, "and");  cout << "Expr and Expr" << endl;}
					 | Expression OR Expression    { $$ = new BiExprNode($1, $3, "or");   cout << "Expr or Expr" << endl;}
					 | OC Expression  CC           { $$ = $2; cout << "(Expr)" << endl;}
					 | NOT Expression              { $$ = new UniExprNode($2,"not"); cout << "not Expr" << endl;}
					 | SUB Expression %prec UMINUS { $$ = new UniExprNode($2, "uminus"); cout << "- Expr" << endl;}
					 | MethodCall 								 { $$ = $1; cout << "MethodCall" << endl;}
					 ;

Location : ID  %prec LOCID { $$ = $1;   cout << "ID" << endl;}
				 | ID OS Expression CS { $$ = new OneDArray($1, $3) ;  cout << "1D Access" << endl;}
				 | ID OS Expression COMMA  Expression CS {$$ = new TwoDArray($1,$3,$5); cout << "2D Access" << endl;}
				 ;

Literal : INTL  {$$ = $1; cout << "INTL" << endl; }
				| TRUE  {$$ = $1; cout << "TRUE" << endl; }
				| FALSE {$$ = $1; cout << "FALSE" << endl;}
				| CHAR  {$$ = $1; cout << "CHAR" << endl; }
				| UINTL  {$$ = $1; cout << "UINT" << endl; }
				;

Vartype:  TINT  {$$ = $1; cout << "int" << endl;}
				| TUINT {$$ = $1; cout << "uint" << endl;}
				| TBOOL {$$ = $1; cout << "bool" << endl;}
				| TCHAR {$$ = $1; cout << "char" << endl;}

MethodCall: ID OC CC   { $$ = new MethodCallNode($1); }
				| ID OC ListOfExpr CC  { $$ = new MethodCallNode($1, $3); }
				;

ListOfExpr: Expression { $$ = new ListExprsNode($1); cout << "ListOfExpr" << endl;}
				| ListOfExpr COMMA Expression {$$->pb($3); cout << "ListOfExpr" << endl;}
				;

%%

int main(int argc, char **argv)
{
		yyparse();
		cout << "Parsing Over" << endl;
		return (0);
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}
