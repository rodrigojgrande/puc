void main(int argc, char argv) {
    int token,i=1;	
	yyin = fopen(argv[1],"r");
	token = yylex();
	while(token) {
		printf("%d) %d %s\n", i, token, yytext);
		token = yylex();
	}
	imprime();
}
