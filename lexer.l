%{
  /* #include <iostream> */
  /* using namespace std; */
  #include <cstdio>
  #include "parser.tab.h"
  /* ('..+'|"..+") {return STR;} */
%}

%%
[\ ] ;
[\n] {return NL;}
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

[\+\-\*/%] {return ARITOP;}
(and|or) {return BOOLOP;}
not {return NOT;}
(<=|>=|!=|>|<) {return RELOP;}
[=] {return ASGN;}
; {return SCOMMA;}
, {return COMMA;}

(int|uint|char|bool) {return VARTYPE;}
(true|false) {return BOOL;}

\{ {return OF ;}
\} {return CF ;}
\( {return OC ;}
\) {return CF ;}
\[ {return OS ;}
\] {return CS ;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}

('.'|".") {return CHAR;}

-?[0-9][0-9]* {return INTL;}

%%
