parse: lexer.l parser.y
	bison -d parser.y
	flex lexer.l
	g++ parser.tab.c lex.yy.c -lfl -o Output
	./Output temo
	echo '----------------------'

clean:
	rm lex.yy.c parser.tab.c parser.tab.h
