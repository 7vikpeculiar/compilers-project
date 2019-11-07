parse: lexer.l parser.y ast.h ast.cpp
	bison -vd parser.y
	flex -l lexer.l
	g++ parser.tab.c lex.yy.c ast.cpp -lfl -o Output

clean:
	rm lex.yy.c parser.tab.c parser.tab.h parser.output Output
