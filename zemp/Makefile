parse: lexer.l parser.y
	bison -vd parser.y
	flex -l lexer.l
	g++ parser.tab.c lex.yy.c -lfl -o Output
	./Output < temo

clean:
	rm lex.yy.c parser.tab.c parser.tab.h
