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
