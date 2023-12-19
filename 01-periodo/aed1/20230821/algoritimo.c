#include <stdio.h>
#include <locale.h>

main(){
   char nome[30];
   int idade;
   float n1, n2, n3, n4, m;

setlocale(LC_ALL,"Portuguese");


printf("Calculo da Media das Notas\n");
printf("==========================\n\n");
printf("Digite o nome do(a) aluno(a) = ");
gets(nome);

// Pegue | s => String

printf("Digite a idade en anos = ");
scanf("%d", &idade);

// %d => Mascara

printf("Digite a primeira nota = ");
scanf("%f", &n1);
printf("Digite a segunda nota = ");
scanf("%f", &n2);
printf("Digite a terceira nota = ");
scanf("%f", &n3);
printf("Digite a quarta nota = ");
scanf("%f", &n4);

m = (n1+n2+n3+n4)/4;

printf("Exibindo os resultados\n");
printf("==========================\n\n");
printf("O (A) aluno(a) %s, com idade %d anos, obteve a media %5.2f\n\n", nome, idade, m);

}
