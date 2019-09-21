parser: lexer.l
	flex lexer.l
	g++ lex.yy.c -lfl -o Output;
	echo '-------------------'
	./Output $(file)

clean:
	rm lex.yy.c Output
