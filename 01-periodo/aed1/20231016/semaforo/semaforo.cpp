#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>

main()
{
    int semaforo;

    initwindow (180,300,"Controle de Semáforos",0,0);
    readimagefile("semaforovermelho.jpg",10,10,173,291);
    Sleep(2000);

    do
    {
        srand(time(NULL));
        semaforo = rand() % 3;

        printf("Semaforo aceso = %d\n", semaforo);

        if (semaforo == 0)
            readimagefile("semaforovermelho.jpg",10,10,173,291);
        if (semaforo == 1)
            readimagefile("semaforoamarelo.jpg",10,10,173,291);
        if (semaforo == 2)
            readimagefile("semaforoverde.jpg",10,10,173,291);

        Sleep(1000);
    } while (!kbhit());

    closegraph();
}
