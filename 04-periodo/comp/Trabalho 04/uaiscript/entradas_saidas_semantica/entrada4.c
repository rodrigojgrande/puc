void main(int argc, char argv) {
    int j=1, i, k = 2;	
	yyin = fopen(argv[1],"r");
	token = yylex();
	while(token) {
		printf("%d) %d %s\n", i, token, yytext);
		token = yylex();
	}
	imprime();
}

vazio_so main(interin argc, letrin argv) {
	interin j fica_sendo 1, i, k fica_sendo 2;
	yyin fica_sendo fopen(argv[1], "r");
	token fica_sendo yylex();
	vai_ino(token) {
		printf("%d) %d %s\n", i, token, yytext);
		token fica_sendo yylex();
	}
	imprime();
}
