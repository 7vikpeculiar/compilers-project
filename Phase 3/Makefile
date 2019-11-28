# g++ parser.tab.c lex.yy.c ast.cpp -lfl -o Output
parse: lexer.l parser.y ast.h ast.cpp
	bison -vd parser.y
	flex -l lexer.l
	g++ -std=c++11 -Wno-deprecated-register -o  Output parser.tab.c lex.yy.c ast.cpp -ll `llvm-config --cppflags --ldflags --libs core --system-libs`

clean:
	rm lex.yy.c parser.tab.c parser.tab.h parser.output Output
