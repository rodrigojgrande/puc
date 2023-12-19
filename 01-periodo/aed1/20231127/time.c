#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

time_t getTimeSystem();
char*  getCurrentTime();

main ()
{
  time_t inicio,fim;
  double diferencaTempo;
  char   *horario;

  inicio = getTimeSystem();
  horario = getCurrentTime();
  printf("Iniciando a execucao 'as %s...\n\n", horario);

  srand(time(NULL));
  Sleep(rand()%10001);

  fim = getTimeSystem();
  diferencaTempo = difftime(fim,inicio);

  printf ("Agora sao %s...\n\n", getCurrentTime());
  printf ("A execucao durou %5.2lf segundos...\n\n", diferencaTempo);
}

// Função que captura a hora corrente do sistema operacional e retorna uma estrutura time_t,
// que contém os atributos da hora obtida
time_t getTimeSystem()
{
     time_t tempoCorrente, retorno;
     struct tm *infoTempo;
     char   buffer[80];

     time(&tempoCorrente);
     infoTempo = localtime(&tempoCorrente);
     retorno = mktime(infoTempo);

     return retorno;
}

// Função que retorna uma string contendo o horario corrente no formato HH:MM:SS
char* getCurrentTime()
{
  time_t tempoCorrente;
  struct tm *infoTempo;
  char   *buffer;

  time(&tempoCorrente);
  infoTempo = localtime(&tempoCorrente);
  buffer = (char*) malloc(10*sizeof(char));
  strftime(buffer,80,"%H:%M:%S",infoTempo);

  return buffer;
}
