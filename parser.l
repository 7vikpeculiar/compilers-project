%{
  #include <iostream>
  using namespace std;
  extern int yylex();
%}

%option noyywrap
%%
[ \t\n]         ;
[0-9]+\.[0-9]+  { cout << "Found a floating-point number:" << yytext << endl; }
[0-9]+          { cout << "Found an integer:" << yytext << endl; }
[a-zA-Z0-9]+    { cout << "Found a string: " << yytext << endl; }


[f][o][r][\ \n]*[(][.]*[)][\ \n]*[{][.]*[}]  { cout << "<FOR " << yytext << ">" << endl;}

[w][h][i][l][e][\ \n]*[(][.]*[)][\ \n]*[{][.]*[}]  { cout << "<WHILE " << yytext << ">" << endl;}

[i][f][\ \n]*[(][.]*[)][\ \n]*[{][.]*[}]  { cout << "IF" << yytext << ">" << endl;}

[e][l][i][f][\ \n]*[(][.]*[)][\ \n]*[{][.]*[}]  { cout << "<ELIF " << yytext << ">" << endl;}

[e][l][s][e][\ \n]*[(][.]*[)][\ \n]*[{][.]*[}]  { cout << "<ELSE " << yytext << ">" << endl;}

[d][e][f][\ \n]*[a-zA-Z][a-ZA-Z0-9]*
%%

int main(int, char**) {
  // lex through the input:
  while (yylex());
}
