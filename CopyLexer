%{
  #include <iostream>
  using namespace std;
  extern "C" int yylex();
%}

%%
[\ \n] ;

array { cout << "<ARRAY , " << yytext << " >" << endl;}
return {cout << "RET, " << yytext << " >" << endl;}
break {cout << "BRK, " << yytext << " >" << endl;}
import { cout << "<IMPORT , " << yytext << " >" << endl;}
if { cout << "<IF , " << yytext << " >" << endl;}
elif { cout << "<ELF , " << yytext << " >" << endl;}
else { cout << "<ELSE , " << yytext << " >" << endl;}

for { cout << "<FOR , " << yytext << " >" << endl;}

while { cout << "<WHILE , " << yytext << " >" << endl;}

def { cout << "<DEF , " << yytext << " >" << endl;}

[\+\-\*/%] {cout << "<ARITOP , " << yytext << " >" << endl;}
(and|or|not) { cout << "<BOOLOP , " << yytext << " >" << endl;}
(<=|>=|!=|>|<) {cout << "<RELOP , " << yytext << " >" << endl;}
[=] {cout << "<ASGN , " << yytext << " >" << endl;}
; {cout << "<SCOMMA , " << yytext << " >" << endl;}
, {cout << "<COMM , " << yytext << " >" << endl;}

(int|uint|char|bool) { cout << "<VARTYPE , " << yytext << " >" << endl;}
(true|false) {cout << "<BOOL , " << yytext << " >" << endl;}

\{ {cout << "<OF , " << yytext << " >" << endl;}
\} { cout << "<CF , " << yytext << " >" << endl;}
\( {cout << "<OC , " << yytext << " >" << endl;}
\) { cout << "<CC , " << yytext << " >" << endl;}
\[  { cout << "<CC , " << yytext << " >" << endl;}
\]  { cout << "<CC , " << yytext << " >" << endl;}
[a-zA-Z][a-zA-Z0-9]* {cout << "<ID , " << yytext << " >" << endl;}

'..+' {cout << "<STR , " << yytext << " >" << endl;}
'.' {cout << "<CHAR , " << yytext << " >" << endl;}
[0-9][0-9]* {cout << "<INTL , " << yytext << " >" << endl;}
%%

int main(int argc, char** argv) {
  // lex through the input
  FILE *myfile = fopen(argv[1], "r");
    // Make sure it is valid:
    if (!myfile) {
      cout << "I can't open a.snazzle.file!" << endl;
      return -1;
    }
   yyin = myfile;
   while (yylex());
}
