#include <graphics.h>
#include <stdio.h>
#include <windows.h>
main()
{
    int x,y,tecla,cor=15;
    initwindow(640,480,"Janela",400,100);

    while(1)
    {
        x = mousex();
        y = mousey();
        //printf("X = %d Y = %d\n", x,y);

        if (kbhit())
        {
            tecla = getch();
            printf("Tecla pressionada = %d\n", tecla);

            if (tecla == 27)
                break;

            if (tecla == 59)
                printf("Tecla pressionado e o ponto e virgula...\n");
            else
            {
                tecla = getch();
                printf("Tecla pressionada = %d\n", tecla);
                if (tecla == 59)
                {
                    printf("Tecla F1 pressionada...\n");
                    cor--;
                    if (cor == 0)
                        cor = 15;
                }
                if (tecla == 80)
                    printf("Tecla Seta para Baixo pressionada...\n");
            }
        }

	    if (ismouseclick(WM_LBUTTONDOWN))
        {
            setlinestyle(1,1,4);
            setfillstyle(1,cor);
            bar(x,y,x+50,y+50);
            clearmouseclick(WM_LBUTTONDOWN);
        }
        if (ismouseclick(WM_RBUTTONDOWN))
        {
            setfillstyle(1,cor);
            setcolor(cor);
            fillellipse(x,y,25,25);
            clearmouseclick(WM_RBUTTONDOWN);
        }
    }
    // limpa o interior da janela gráfica, como se fosse um "clear screen"
    setfillstyle(1,0);
    bar(0,0,640,480);
    Sleep(3000);
    closegraph();
}
