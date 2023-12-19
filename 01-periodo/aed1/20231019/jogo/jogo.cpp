#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <windows.h>

main()
{
    int x1, y1, x2, y2;

    initwindow(282,185,"Programando um Jogo",50,100);
    readimagefile("Cenario.jpg",0,0,282,185);

    x1 = 120;
    y1 = 185;
    x2 = 180;
    y2 = 185;

    do
    {
         y1 = y1 - 5;
         x1 = x1 + 5;
         setfillstyle(1,4);
         fillellipse(x1,y1,5,5);

         y2 = y2 - 5;
         x2 = x2 - 5;
         setfillstyle(1,2);
         fillellipse(x2,y2,5,5);

         Sleep(1000);
         readimagefile("cenario.jpg",0,0,282,185);
    } while (x1 != x2);

    setbkcolor(1);
    setcolor(14);
    outtextxy(100,10,"Booommm !!!");
    getchar();
    closegraph();
}
