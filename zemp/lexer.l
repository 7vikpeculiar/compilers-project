%{
  /* #include <iostream> */
  #include <cstdio>
  #include <bits/stdc++.h>
  #include "parser.tab.h"
  #define YY_DECL extern "C" int yylex()
  using namespace std;

  /* ('..+'|"..+") {return STR;} */
%}

%%
[\ \n] {};
"+" {return ADD;}
"-"  {return SUB;}
"*"  {return MULT;}
"/"  {return DIV;}
"<=" {return LEQ;}
">=" {return GEQ;}
"==" {return EQ;}
"!=" {return NEQ;}
">"  {return GT;}
"<"  {return LT;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}

%%
