#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <string.h>

void leDadosModoGrafico(int x1, int y1, int corFundo, int corBorda,
                        int corCaracteres, int quantidadeCaracteres,
                        char valorDigitado[]);

main()
{
      char entrada[20];

      initwindow(300,200,"Login",450,180);
      leDadosModoGrafico(20, 80, 15, 5, 0, 19, entrada);
      printf("Valor digitado = %s\n\n", entrada);

      system("pause");

      closegraph();
}

void leDadosModoGrafico(int x, int y, int corFundo, int corBorda,
                        int corCaracteres, int quantidadeCaracteres,
                        char valorDigitado[])
{
    int indice = 0, tecla;

    setfillstyle(1,corFundo);
    bar(x,y,x+(quantidadeCaracteres*14),y+30);
    setlinestyle(0,0,2);
    setcolor(corBorda);
    rectangle(x-3,y-3,x+(quantidadeCaracteres*14)+2,y+32);

    setcolor(corCaracteres);
    setbkcolor(corFundo);

    strcpy(valorDigitado, "");
    indice = 0;
    tecla = 0;
    do
    {
        tecla = getch();
        if (tecla >= 32 && tecla <= 127) // Teclas do teclado e existentes na Tabela ASCII
        {
            valorDigitado[indice] = (char) tecla;
            indice++;
            valorDigitado[indice] = '\0';
            setfillstyle(1,corFundo);
            bar(x,y,x+(quantidadeCaracteres*14),y+30);
            outtextxy(x+4,y+6,valorDigitado);
        }

        if (tecla == 8) //BackSpace
        {
            if (indice > 0)
            {
                indice--;
                valorDigitado[indice] = '\0';
                setfillstyle(1,corFundo);
                bar(x,y,x+(quantidadeCaracteres*14),y+30);
                outtextxy(x+4,y+6,valorDigitado);
            }
        }
    } while (tecla != 13 && indice < quantidadeCaracteres); // ENTER ou atingiu a quantidade de caracteres
}
