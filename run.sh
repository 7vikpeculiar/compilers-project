#!/bin/bash
flex lexer.l;
g++ lex.yy.c -lfl -o Output;
(exec "./Output" "$1")
