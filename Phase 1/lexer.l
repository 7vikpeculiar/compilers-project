%{
  #include <cstdio>
  #include <bits/stdc++.h>
  #include "parser.tab.h"
  #define YY_DECL extern "C" int yylex()
  using namespace std;
%}

%%
[\ \n]  {}
array  {return ARRAY;}
return {return RETURN;}
break  {return BREAK;}
import {return IMPORT;}

if {return IF;}
elif {return ELIF;}
else {return ELSE;}

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
"="  {return ASGN;}
"+=" {return PASGN;}
"-=" {return SASGN;}

"and"  {return AND;}
"or"   {return OR;}
"void" {return VOID;}
not {return NOT; /* [\+\-\*%] {return ARITOP;} (<=|>=|!=|>|<) {return RELOP;} */}
; {return SCOMMA;}
"," {return COMMA;}

"int"    {return TINT;}
"bool"   {return TBOOL;}
"char"   {return TCHAR;}
"uint"   {return TUINT;}
"True"   {return TRUE; }
"False"  {return FALSE;}

\. {return STOP;}
\{ {return OF ;}
\} {return CF ;}
\( {return OC ;}
\) {return CC ;}
\[ {return OS ;}
\] {return CS ;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}


('.'|".") {return CHAR;}

-?[0-9][0-9]* {return INTL;}

%%
