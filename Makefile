parse: lexer.l parser.y
	bison -d parser.y
	flex lexer.l
	g++ -o parser lex.yy.c parser.tab.c -lfl
	echo '----------------------'

clean:
	rm lex.yy.c parser.tab.c parser.tab.h
