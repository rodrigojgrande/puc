#include <stdio.h>
#include <graphics.h>
#include <time.h>

time_t getTimeSystem();
char*  getCurrentTime();

main()
{
    time_t inicio,fim;
    double diferencaTempo;
    char   *horario;

    inicio = getTimeSystem();
    initwindow(300,80,"Relógio",0,0);

    while (!kbhit())
    {
        horario = getCurrentTime();
        setcolor(14);
        outtextxy(230,10,horario);
    }

    fim = getTimeSystem();
    diferencaTempo = difftime(fim,inicio);
    sprintf(horario, "Tempo de Execução = %5.2lf segundos", diferencaTempo);
    setcolor(10);
    outtextxy(20,50,horario);

    system("pause");

    closegraph();
}

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
