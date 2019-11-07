%{
  #include <cstdio>
  #include <bits/stdc++.h>
  #include <string>
  #include "parser.tab.h"
  #define YY_DECL extern "C" int yylex()
  using namespace std;
  #include "ast.h"

  int lineno  = 0;
%}

%%
[\ ]  {}
[\n]  {lineno++;}

array  {return ARRAY;}
return {return RETURN;}
break  {return BREAK;}
import {return IMPORT;}
"#".*  {}
if     {return IF;}
elif   {return ELIF;}
else   {return ELSE;}

for {return FOR;}

while {return WHILE;}

def {return DEF;}
"?" {return QUEST;}
":" {return COLON;}

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
"="  {yylval.value = strdup(yytext);  return ASGN;}
"+=" {yylval.value = strdup(yytext);  return PASGN;}
"-=" {yylval.value = strdup(yytext);  return SASGN;}

"and"  {return AND;}
"or"   {return OR;}
"void" {yylval.node = new VoidNode(); return VOID;}
not {return NOT; /* [\+\-\*%] {return ARITOP;} (<=|>=|!=|>|<) {return RELOP;} */}
; {return SCOMMA;}
"," {return COMMA;}

"int"    {yylval.value = strdup(yytext); return TINT;}
"bool"   {yylval.value = strdup(yytext); return TBOOL;}
"char"   {yylval.value = strdup(yytext); return TCHAR;}
"uint"   {yylval.value = strdup(yytext); return TUINT;}

"True"   {yylval.node = new BoolLiteral(yytext); return TRUE; }
"False"  {yylval.node = new BoolLiteral(yytext); return FALSE;}

\. {return STOP;}
\{ {return OF ;}
\} {return CF ;}
\( {return OC ;}
\) {return CC ;}
\[ {return OS ;}
\] {return CS ;}
[a-zA-Z][a-zA-Z0-9]* { yylval.node = new SingleId(yytext); return ID;}

\'.\'|\".\" {yylval.node = new CharLiteral(yytext[1]); return CHAR;}

[0-9][0-9]* {yylval.node = new IntLiteral(atoi(yytext)); return INTL;}

"0x"[0-9][0-9]* {yylval.node = new UintLiteral(yytext); return UINTL;}
%%
