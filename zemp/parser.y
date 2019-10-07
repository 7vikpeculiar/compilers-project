%{
#include <cstdio>
#include <iostream>
using namespace std;

extern "C" int yylex();
extern int yyparse();
extern FILE **yyin;
void yyerror(const char *s);
%}

%token ADD DIV EQ GEQ GT LEQ LT MULT NEQ SUB ID
%%
Expression : Expression Op Expression | ID	;					

Op: ADD
	| SUB
	| MULT
	| DIV
	| LEQ
	| GEQ
	| GT
	| EQ
	| LT
	| NEQ
%%

int main(int argc, char **argv)
{
				/* FILE *fd;
			  if (argc == 2)
    		{
        	if (!(fd = fopen(argv[1], "r")))
        	{
            	perror("Error: ");
            	return (-1);
        	}
        yyset_in(fd);
        yylex();
        fclose(fd);
    		}
				else
			 printf("Usage: a.out filename\n"); */
 		 // Make sure it is valid:
			 /* if (!myfile) {
				 cout << "I can't open a.snazzle.file!" << endl;
				 return -1;
			 }
			 // Set Flex to read from it instead of defaulting to STDIN: */
			 /* yyin = myfile; */

			 // Parse through the input:
			 yyparse();
	 return (0);
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}
