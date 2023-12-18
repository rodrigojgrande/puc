/*
    PARTICIPANTES DO GRUPO: Enrico Souza Melo de Araujo;
                            Julia Romao;
                            Nicole Castro;
                            Rodrigo Grande;

    ASSUNTO: Projeto Final LAED 1, Hub com 4 jogos.
    PUC MINAS - Ciencia da Computacao 1 periodo
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define SZ 3

//variaveis universais
char player1[40], player2[40], game[SZ][SZ];
int portaAberta = 0, itemsCozinha = 0, espelho = 0, quadro = 0, itemsQuarto = 0, flagVelha = 0, flagForca = 0, flagEscape = 0, flagBatalha = 0;

//prototipos funcoes

//ENRICO
void cozinha();
void banheiro();
void quarto();
void porta();
int escape(void);
void jogoAcorrentado();

//JULIA
void forca(void);

//NICOLE
void startMatrix();
int isValid(char carac);
int spotIsValid(int li, int co);
int emptySpot(int li, int co);
int lineWinner();
int columnWinner();
int mainDiagonalWinner();
int secDiagonalWinner();
void visualMatrix();
void play();
int velha(void);

//RODRIGO
void limparTela();
void iniciarTabuleiro(int tabuleiro[][5]);
void iniciarValidarTiro(int tabuleiroValidarTiro[][5]);
void mostrarTabuleiro(int tabuleiro[][5]);
void iniciarNavios(int navios[][2]);
void darTiro(int tiro[2], int tabuleiroValidarTiro[5][5]);
int acertarNavio(int tiro[2], int navios[][2], int naviosAtingidos[][2]);
void palpite(int tiro[2], int navios[][2], int tentativas);
void alterarTabuleiro(int tiro[2], int navios[][2], int naviosAtingidos[][2], int tabuleiro[][5]);
void debugMatriz(int tabuleiroValidarTiro[5][5]);
int batalha(void);

// Funcao principal, exibe os jogos disponiveis e chama as funcoes para o usuario poder jogar
int main(void)
{
    int opcao;
    do
    {

        printf ("\nDigite um valor de 1 a 5: \n");
        printf ("\n[1] Escape Room\n");
        printf ("[2] Forca\n");
        printf ("[3] Jogo da Velha\n");
        printf ("[4] Batalha Naval\n");
        printf ("[5] Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            do
            {
                // Codigo Enrico
                printf("Codigo Enrico\n");
                escape();
            }
            while (flagEscape == 0);
            break;

        case 2:
            do
            {
                printf ("Codigo Julia\n");
                forca();
            }
            while (flagForca == 0);
            break;

        case 3:
            do
            {
                printf ("Codigo Nicole\n\n");
                velha();
            }
            while (flagVelha == 0);
            break;

        case 4:
            do
            {
                printf ("Codigo Rodrigo\n");
                batalha();
            }
            while (flagBatalha == 0);
            break;

        case 5 :
            printf("Saindo...\n");
            break;

        default :
            printf ("Opcao invalida!\n");
        }
    }
    while(opcao!=5);


    return 0;
}


int escape(void) // Funcao para confirmar a intencao de jogar
{
    char escolha = 'N';

    printf("Deseja jogar 'Acorrentado'? [S/N] = ");
    escolha = toupper(getchar());
    getchar();

    if (escolha == 'S')
    {
        jogoAcorrentado();
    }
    flagEscape = 1;
    return 0;
}

//Comeco das funcoes
void jogoAcorrentado() // Funcao principal do jogo, coordena os comodos do jogo
{
    char escolha = 'N';
    char opcao = 'P';

    printf("\033[H\033[J");
    printf("\nSeja bem vindo ao jogo 'Acorrentado'\n\n");
    printf("Para este jogo, digite apenas 1 (um) caractere nas respostas\n");
    printf("\nPronto? [S/N] = ");
    scanf("%1c", &escolha);
    getchar();
    escolha = toupper(escolha);

    if(escolha == 'S')
    {
        printf("\033[H\033[J");
        //Comeco
        printf("\nVoce acorda num apartamento estranho, sem lembrancas de como chegou neste lugar.\nA primeira"
               " coisa que chama sua atencao e a porta da frente, com diversos\ncadeados.\n");
        printf("\nAo lado direito da porta, ha uma cozinha; na esquerda, ha um banheiro;\n"
               "atras, voce ve uma porta aberta que leva ao quarto.\n");

        //Laco do jogo
        do
        {
            opcao = 'P';
            printf("\nPra onde voce quer ir?\n\n");
            printf("[P] Porta    [P]\n");
            printf("[C] Cozinha  [C]\n");
            printf("[B] Banheiro [B]\n");
            printf("[Q] Quarto   [Q]\n");
            scanf("%1c", &opcao);
            getchar();
            opcao = toupper(opcao);

            // Menu de opcoes e salas
            switch(opcao)
            {
            case 'C':
                cozinha();
                break;
            case 'B':
                banheiro();
                break;
            case 'Q':
                quarto();
                break;
            case 'P':
                porta();
                break;
            default:
                opcao = 'P';
                printf("\033[H\033[J");
                printf("\nOpcao invalida, digite uma das opcoes do menu...\n");
            }
        }

        while (portaAberta == 0);
        printf("\n\nParabens, voce conseguiu escapar!\n\n");
        return;
        flagEscape = 1;
    }
    else
    {
        flagEscape = 1;
        return;
    }

}

void cozinha() // Funcao da cozinha, area com itens necessarios para destravar dicas e pegar chaves finais
{
    char escolha = 'N';

    printf("\033[H\033[J");
    printf("\nVoce esta na cozinha\n");
    if(itemsCozinha == 0)
    {
        printf("\nNa cozinha, voce procura por algo que possa te ajudar. A geladeira parece nao\nser aberta ha meses. "
               "As gavetas possuem poucos talheres empoeirados e pratos \nsujos, mas debaixo da pia...\n"
               "\nVoce encontra uma tesoura e uma chave de fenda em uma delas.\n\nPegar? [S/N] = ");
        scanf("%1c", &escolha);
        getchar();
        escolha = toupper(escolha);
        if(escolha == 'S')
        {
            printf("\nVoce pegou os items.\n");
            itemsCozinha = 1;
            return;
        }
        else
        {
            return;
        }
    }
    if(itemsCozinha == 1)
    {
        printf("\nVoce ja pegou tudo que havia aqui\n");

    }

    return;
}

void banheiro() // Funcao do banheiro, area com dica necessaria para pegar as chaves finais e ganhar o jogo
{
    char escolha = 'N';

    printf("\033[H\033[J");
    printf("\nVoce esta no banheiro\n");
    if(espelho == 0)
    {
        printf("\nTudo parece em ordem, mas o espelho na frente da pia parece quebrado.\n"
               "Parece haver algo escrito atras dos cacos, mas nao parece seguro tirar\ncom as maos.\n");
        if(itemsCozinha == 1)
        {
            printf("\n\nUsar chave de fenda para tirar os cacos? [S/N] = ");
            scanf("%1c", &escolha);
            getchar();
            escolha = toupper(escolha);
            if(escolha == 'S')
            {
                printf("\nA frase 'Perdido, no fundo do mar' estava atras dos cacos.\n");
                espelho = 1;
                return;
            }
        }
    }
    else
    {
        printf("\nA frase 'Perdido, no fundo do mar' estava atras dos cacos .\n");
    }
}

void quarto() // Funcao do quarto, area com as chaves finais para abrir a porta e ganhar o jogo
{
    char escolha = 'N';

    printf("\033[H\033[J");
    printf("\nVoce esta no quarto\n");
    if(quadro == 0)
    {
        printf("\nO quarto esta completamente desarrumado, roupas jogadas pra todo lado\n"
               "as janelas estao fechadas e nao da para ver nada fora. O que mais chama\n"
               "sua atencao eh um quadro de um navio no meio do mar em uma das paredes.\n");
        if(espelho == 1)
        {
            printf("\nQuer mexer no quadro? [S/N] = ");
            scanf("%1c", &escolha);
            getchar();
            escolha = toupper(escolha);
            if(escolha == 'S')
            {
                printf("\nO quadro parece preso na parede, escondendo algo atras, talvez seja possivel\ncorta-lo.\n");
                if(itemsCozinha == 1)
                {
                    printf("\nQuer usar a tesoura para cortar o quadro? [S/N] = ");
                    scanf("%1c", &escolha);
                    getchar();
                    escolha = toupper(escolha);
                    if(escolha == 'S')
                    {
                        quadro = 1;
                        printf("\nVoce corta o quadro, revelando um alicate e um molho de chaves. Pegar? [S/N] = ");
                        scanf("%1c", &escolha);
                        getchar();
                        escolha = toupper(escolha);
                        if(escolha == 'S')
                        {
                            printf("\nVoce pega as chaves e o alicate. Provavelmente, voce ja consegue abrir a porta.");
                            itemsQuarto = 1;
                        }
                        else
                        {
                            return;
                        }
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    printf("\nVoce nao tem como abrir o quadro.\n");
                    return;
                }
                return;
            }

        }

    }
    if(quadro == 1)
    {
        if(itemsQuarto == 0)
        {
            printf("\nVoce cortou o quadro, revelando um alicate e um molho de chaves. Pegar? [S/N] = ");
            scanf("%1c", &escolha);
            getchar();
            escolha = toupper(escolha);
            if(escolha == 'S')
            {
                printf("\nVoce pega as chaves e o alicate. Provavelmente, voce ja consegue abrir a porta.");
                itemsQuarto = 1;
            }
        }
        else
        {
            return;
        }

    }
    if(itemsQuarto == 1)
    {
        printf("\nVoce ja pegou tudo que podia no quarto, fuja!\n");
    }
}

void porta() // Funcao da porta, com flags ativadas ao se interagir com as outras salas. Ganha o jogo
{
    char escolha = 'N';

    printf("\033[H\033[J");
    printf("\nVoce esta na frente da porta...");
    printf("\nTentar abrir? [S/N]  ");
    scanf("%1c", &escolha);
    getchar();
    escolha = toupper(escolha);
    if(escolha == 'S')
    {
        if(itemsQuarto == 1)
        {
            printf("\nVoce usa as chaves e o alicate para abrir os cadeados e cortar as correntes");
            portaAberta = 1;
        }
        else
        {
            printf("\nA porta esta trancada\n");
        }
    }
}
//</ENRICO>

//<JULIA>
void forca (void)
{
//    char s, v[13], e[21],
    char s, v[13],
         palavra [20][13] = {"lichia", "acerola", "pitaya", "cupuacu", "groselha", //palavras que podem ser sorteadas
                             "polenta", "risoto", "brownie", "lasanha", "ravioli",
                             "gaivota", "ornitorrinco", "marmota", "avestruz", "harpia",
                             "holanda", "russia", "coreia", "angola", "panama"
                            };

    int i, r, opcao = 1, resultado = 0, vitoria = 0, contador = 0, vida = 7;
    do
    {
        srand(time(NULL));  //escolhe uma palavra aleatoria
        r = rand() % 20;

        //printf("%s\n", palavra[r]);
        for (i = 0; i < strlen(palavra[r]); i++) //inicializa o vetor v utilizando '_' em cada indice
        {
            v[i] = '_';
        }
        /*
        for (i = 0; i < 21 ; i++)
        {
           e[i] = '\0';
        }
        */
        do
        {
            printf("Dica: ");

            if(r < 5)      //Diz qual a categoria da palavra a ser descoberta
            {
                printf("Fruta\n");
            }

            if(r > 4 && r < 10)
            {
                printf("Comida\n");
            }

            if(r > 9 && r < 15)
            {
                printf("Animal\n");
            }

            if(r >= 15)
            {
                printf("Pais\n");
            }




            printf("A palavra possui %ld letras", strlen(palavra[r]));
            printf("\n");


            scanf("%c", &s);    //Escaneia a letra que adivinhou
            getchar();
            printf("\n");


            for (i = 0; i < strlen(palavra[r]); i++)  //analisa o valor digitado e substitui no vetor, verificando cada indice
            {
                if(s == palavra[r][i])
                {
                    v[i] = s;
                }
                else                    //caso o valor nao seja encontrado na palavra eh somado +1 ao contador
                {
                    contador++;
                }

                if(contador == strlen(palavra[r])) //se o valor do contador for igual ao tamanho da palavra, uma vida sera descontada
                {
                    vida--;

                }
                if(v[i] != '_')         //Quando todos os valores do vetor forem diferentes de um espaco em branco, o jogo eh vencido
                {
                    vitoria ++;
                }

                printf("%c", v[i]);  //exibe cada indice do vetor

            }
            //Quando todos os indices forem analisados o contador volta para 0


            printf("\n");
            printf("\nVidas restantes:%d\n\n", vida);

            if(vitoria == strlen(palavra[r]))
            {
                printf("\nVoce venceu!!!\n\t=D");
                resultado = 1;
                printf("\nDigite 1 para jogar novamente ou digite 2 para encerrar o jogo\n");
                scanf("%d", &opcao);
                getchar();
            }
            if(vida == 0)
            {
                printf("Voce perdeu!\n\t=(");
                resultado = 1;
                printf("\nDigite 1 para jogar novamente ou digite 2 para encerrar o jogo\n");
                scanf("%d", &opcao);
                getchar();
            }
            vitoria = 0;
            contador = 0;

        }

        while(resultado == 0);
        vida = 7;
        resultado = 0;
    }

    while(opcao == 1);
    flagForca = 1;
}
//</JULIA>

//<NICOLE>
/*Na funcao velha, ocorre a entrada do nome dos dois jogadores. Tambem,
estao sendo chamada as funcoes que iniciam a matrix e o jogo,
alem da opcao de continuarou ou sair do jogo*/
int velha(void)
{
    int restart, cont =0, validRestInput = 0;

    printf("\nBem vindo(a) ao Jogo da Velha!\n");
    printf("_____________________________\n\n");

    printf("Digite o seu nome Jogador 1: ");
    scanf("%[^\n]%*c", player1);

    printf("Digite o seu nome Jogador 2: ");
    scanf("%[^\n]%*c", player2);

    do
    {
        startMatrix();
        play();
        printf("Deseja continuar jogando?\n1 - Sim \t2 - Nao\n");
        validRestInput = scanf("%d",&restart);
        while(validRestInput!=1)
        {
            printf("Por favor, digite o numero 1 para continuar ou 2 para sair: ");
            scanf("%*[^\n]");
            validRestInput = scanf("%d",&restart);
        }
        switch(restart)
        {
        case 1:
            printf("\nContinuando...\n");
            printf("\e[1;1H\e[2J");
            break;
        case 2:
            cont++;
            flagVelha = 1;
            printf("\nSaindo...\n");
        }
    }
    while(cont == 0);
    return 0;
}
//funcao que inicializa a matriz
void startMatrix()
{
    int line, column;

    for(line = 0; line < SZ; line++)
    {
        for(column = 0; column < SZ; column++)
        {
            game[line][column] = ' ';
        }
    }
}

// funcoa que checa se o caractere e X ou 0
int isValid(char character)
{
    if(character == 'X' ||  character == '0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// funcao que checa se as coordenadas digitadas existem
int spotIsValid(int line, int column)
{
    if(line >= 0 && line < SZ)
    {
        if(column >= 0 && column < SZ)
        {
            return 1;
        }
    }
    return 0;
}

//funcao que checa se o espaco selecionado esta vazio
int emptySpot(int line, int column)
{
    if(game[line][column] != 'X' && game[line][column] != '0')
    {
        return 1;
    }
    return 0;
}

//funcao que checa se uma linha foi completada com caracteres iguais
int lineWinner()
{
    int line, column, cont=1;

    for(line = 0; line < SZ; line++)
    {
        for(column = 0; column < 2; column++)
        {
            if(isValid(game[line][column]) && game[line][column] == game[line][column+1])
            {
                cont++;
            }
        }
        if(cont == 3)
        {
            return 1;
        }
        cont = 1;
    }
    return 0;
}

// funcao que checa se uma coluna foi completada com caracteres iguai
int columnWinner()
{
    int line, column, cont=1;

    for(line = 0; line < SZ; line++)
    {
        for(column = 0; column < 2; column++)
        {
            if(isValid(game[column][line]) && game[column][line] == game[column+1][line])
            {
                cont++;
            }
        }
        if(cont == 3)
        {
            return 1;
        }
        cont = 1;
    }
    return 0;
}

// funcao que checa se a diagonal principal da matriz foi completada com caracteres iguais
int mainDiagonalWinner()
{
    int line, cont = 1;

    for(line = 0; line < 2; line++)
    {
        if(isValid(game[line][line]) && game[line][line] == game[line+1][line+1])
        {
            cont++;
        }
    }
    if(cont==3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//funcao que checa se a diagonal secundaria da matriz foi completada com caracteres iguais
int secDiagonalWinner()
{
    int line, cont = 1;

    for(line = 0; line < 2; line++)
    {
        if(isValid(game[line][3-line-1]) && game[line][3-line-1] == game[line+1][3-line-2])
        {
            cont++;
        }
    }
    if(cont==3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// funcao que estabelece o visual do jogo
void visualMatrix()
{
    int line, column;

    printf("\n\n\t   0   1   2\n");
    for(line = 0; line < SZ; line++)
    {
        printf("\t%d ", line);
        for(column = 0; column < SZ; column++)
        {
            if(isValid(game[line][column]))
            {
                if(column<2)
                {
                    printf(" %c |", game[line][column]);
                }
                else
                {
                    printf(" %c ", game[line][column]);
                }
            }
            else
            {
                if(column<2)
                {
                    printf("   |");
                }
                else
                {
                    printf("   ");
                }
            }
        }
        if(line < 2)
        {
            printf("\n\t   ---------\n");
        }
    }
}

/* funcao que recebe as coordenadas de jogada do usuario,
checa se sao validas, se o local esta vazio,
e qual jogador fez a escolha, e se as condicoes
forem verdadeiras adiciona um X para o jogador 1
ou 0 para o jogador 2. A funcao checa tambem se
o jogo foi ganhado por linha, coluna, ou diagonal
e caso tenha sido ganhado de alguma maneira,
exibe uma mensagem para o jogador,
caso nao tenha, exibe tambem uma mensagem*/
void play()
{
    int coordinate1, coordinate2, validMove, sequence = 1, winner = 0, movePlayed = 0, validCoordinateInput1=0, validCoordinateInput2=0;
    do
    {
        do
        {
            visualMatrix();
            printf("\n\n\n     Onde deseja jogar?:  \n");
            printf("\nLinha: ");
            validCoordinateInput1 = scanf("%d",&coordinate1);
            while(validCoordinateInput1!=1)
            {
                printf("Por favor, digite um numero de 0 a 2: ");
                scanf("%*[^\n]");
                validCoordinateInput1 = scanf("%d",&coordinate1);
            }
            printf("Coluna: ");
            validCoordinateInput2 = scanf("%d",&coordinate2);
            while(validCoordinateInput2!=1)
            {
                printf("Por favor, digite um numero de 0 a 2: ");
                scanf("%*[^\n]");
                validCoordinateInput2 = scanf("%d",&coordinate2);
            }
            validMove = spotIsValid(coordinate1, coordinate2);
            if(validMove == 1)
            {
                validMove = validMove + emptySpot(coordinate1, coordinate2);
            }
        }
        while(validMove != 2);
        if(sequence == 1)
        {
            game[coordinate1][coordinate2] = 'X';
        }
        else
        {
            game[coordinate1][coordinate2] = '0';
        }
        movePlayed++;
        sequence++;
        if(sequence == 3)
        {
            sequence = 1;
        }
        winner = winner + lineWinner();
        winner = winner + columnWinner();
        winner = winner + mainDiagonalWinner();
        winner = winner + secDiagonalWinner();
    }
    while(winner == 0 && movePlayed < 9);
    if(winner != 0)
    {
        if(sequence - 1 == 1)
        {
            printf("\n\nParabens, %s! Voce ganhou.\n\n", player1);
        }
        else
        {
            printf("\n\nParabens, %s! Voce ganhou.\n\n", player2);
        }

    }
    else
    {
        printf("\n\nDeu Velha! Nao ha vencedores.\n\n");
    }
}
//</NICOLE>

//<RODRIGO>
// Funcao para limpar a tela do jogo
void limparTela()
{
    printf("\e[1;1H\e[2J"); // Codigo Enrico
    // printf("\033[H\033[J"); // Codigo para limpar tela
    // printf("\n\n");
}


// Funcao para criar tabuleiro do jogo
// Tabuleiro de 5x5
// Todos os valores da Matriz recebem -1
void iniciarTabuleiro(int tabuleiro[][5])
{
    int linha, coluna;

    for(linha = 0 ; linha < 5 ; linha++ )
    {
        for(coluna=0 ; coluna < 5 ; coluna++ )
        {
            tabuleiro[linha][coluna] = -1;
        }
    }
}


// Funcao para criar tabuleiro de validacao
// Tabuleiro de 5x5
// Todos os valores da Matriz recebem -0
void iniciarValidarTiro(int tabuleiroValidarTiro[][5])
{
    int linha, coluna;

    for(linha = 0 ; linha < 5 ; linha++ )
    {
        for(coluna=0 ; coluna < 5 ; coluna++ )
        {
            tabuleiroValidarTiro[linha][coluna] = 0;
        }
    }
}


// Funcao para mostrar o tabuleiro na tala
void mostrarTabuleiro(int tabuleiro[][5])
{
    int linha, coluna;

    // Cria a marcacao das Colunas
    printf("\t1 \t2 \t3 \t4 \t5");
    printf("\n");

    for (linha = 0 ; linha < 5 ; linha++ )
    {
        // Cria a marcacao das linhas
        printf("%d",linha + 1);

        for (coluna = 0 ; coluna < 5 ; coluna++ )
        {

            // Se o valor for igual a -1, sera agua
            if(tabuleiro[linha][coluna] == -1)
            {
                printf("\t~");
            }

            // Se o valor for igual a 0, sera tiro na agua
            else if(tabuleiro[linha][coluna] == 0)
            {
                printf("\tO");
            }

            // Se o valor for igual a 1, sera acerto
            else if(tabuleiro[linha][coluna] == 1)
            {
                printf("\tX");
            }
        }
        printf("\n");
    }
}


// Funcao para sortear as posicoes dos navios e posiciona-los no tabuleiro
void iniciarNavios(int navios[][2])
{
    srand(time(NULL));
    int navio, ultimo;

    for(navio = 0 ; navio < 3 ; navio++)
    {
        navios[navio][0]= rand() % 5;
        navios[navio][1]= rand() % 5;

        // Laco para que os navios nao tenham valores repetidos
        for(ultimo = 0 ; ultimo < navio ; ultimo++)
        {
            if( (navios[navio][0] == navios[ultimo][0]) && (navios[navio][1] == navios[ultimo][1]) )
            {
                do
                {
                    navios[navio][0] = rand() % 5;
                    navios[navio][1] = rand() % 5;
                }
                while ( (navios[navio][0] == navios[ultimo][0]) && (navios[navio][1] == navios[ultimo][1]) );
            }
        }
    }
}


// Funcao para registrar o tiro que o usuario digitar
void darTiro(int tiro[2], int tabuleiroValidarTiro[5][5])
{
    int flag = 0;
    int valorPrimeiraCoordenada, valorSegundaCoordenada;

    do
    {

        printf("\n");
        printf("(Digite um numero de 1 a 5)\n\n");

        // Limitar o usuario para que digite um numero de 1 a 5 em Linha
        do
        {
            printf("Linha: ");
            scanf("%d", &tiro[0]);

            if (tiro[0] < 1 || tiro[0] > 5)
            {
                printf("(Numero fora do intervalo permitido. Tente novamente)\n");
            }

        }
        while (tiro[0] < 1 || tiro[0] > 5);

        valorPrimeiraCoordenada = tiro[0] - 1;

        // Limitar o usuario para que digite um numero de 1 a 5 em Coluna
        do
        {
            printf("Coluna: ");
            scanf("%d", &tiro[1]);

            if (tiro[1] < 1 || tiro[1] > 5)
            {
                printf("(Numero fora do intervalo permitido. Tente novamente)\n");
            }

        }
        while (tiro[1] < 1 || tiro[1] > 5);

        valorSegundaCoordenada = tiro[1] - 1;

        if (tabuleiroValidarTiro[valorPrimeiraCoordenada][valorSegundaCoordenada] == 7)
        {
            printf("Essa tentativa ja foi feita, escolha um valor nao tentado\n\n");
        }
        else
        {
            flag = 1;
            tabuleiroValidarTiro[valorPrimeiraCoordenada][valorSegundaCoordenada] = 7;

            // Altera o valor para 1
            tiro[0]--;
            tiro[1]--;
        }

    }
    while (flag == 0);
}


// Funcao para verificar se um tiro atingiu o navio
int acertarNavio(int tiro[2], int navios[][2], int naviosAtingidos[][2])
{
    int navio;

    for (navio = 0; navio < 3; navio++)
    {
        if (tiro[0] == navios[navio][0] && tiro[1] == navios[navio][1])
        {
            if (naviosAtingidos[navio][0] == -1)
            {
                printf("Voce acertou o navio com o tiro (%d,%d)\n", tiro[0] + 1, tiro[1] + 1);
                naviosAtingidos[navio][0] = tiro[0];
                naviosAtingidos[navio][1] = tiro[1];
                return 1; // Acertou um navio
            }
            else
            {
                return -1; // Navio ja foi atingido
            }
        }
    }
    return 0; // Nao acertou nenhum navio
}


// Funcao para retornar informacoes sobre a distribuicao dos navios com base nas coordenadas do ultimo tiro
void palpite(int tiro[2], int navios[][2], int tentativas)
{
    int linha = 0, coluna = 0, fileira;


    // Conta quantos navios tem na linha ou coluna
    for(fileira = 0 ; fileira < 3 ; fileira++)
    {
        if(navios[fileira][0] == tiro[0])
        {
            linha++;
        }

        if(navios[fileira][1] == tiro[1])
        {
            coluna++;
        }
    }
    printf("\nPalpite %d: \tDICA\nLinha %d -> %d Navios nessa Linha\nColuna %d -> %d Navios nessa Coluna\n\n",tentativas, tiro[0] +1, linha, tiro[1] + 1, coluna);
}


// Funcao para registrar o resultado de um tiro no tabuleiro, marcando a posicao como acerto (1) se o tiro atingir um navio ou como tiro na agua (0) caso contrario
void alterarTabuleiro(int tiro[2], int navios[][2], int naviosAtingidos[][2], int tabuleiro[][5])
{
    if(acertarNavio(tiro,navios, naviosAtingidos))
    {
        tabuleiro[tiro[0]][tiro[1]] = 1;
    }
    else
    {
        tabuleiro[tiro[0]][tiro[1]] = 0;
    }
}


// Funcao para fazer checagem do codigo
void debugMatriz(int tabuleiroValidarTiro[5][5])
{
    int i, j;
    printf("\n");
    printf("\n");
    printf("D E B U G    V A L I D A R   T I R O\n");
    printf("\t1 \t2 \t3 \t4 \t5");
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d",i + 1);
        for (j = 0; j < 5; j++)
        {
            printf("\t%d", tabuleiroValidarTiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}


// Funcao Principal
int batalha(void)
{
    do
    {


        int tabuleiro[5][5];
        int tabuleiroValidarTiro[5][5];
        int navios[3][2];
        int tiro[2];
        int naviosAtingidos[2][2];
        int tentativas = 0, acertos = 0;
        char continuarJogando = 'N';

        iniciarTabuleiro(tabuleiro);
        iniciarValidarTiro(tabuleiroValidarTiro);
        iniciarNavios(navios);

        printf("\n");

        do
        {
            mostrarTabuleiro(tabuleiro);
            darTiro(tiro, tabuleiroValidarTiro);
            tentativas++;
            limparTela();

            if(acertarNavio(tiro, navios, naviosAtingidos))
            {
                palpite(tiro,navios,tentativas);

                acertos++;
            }
            else
            {
                palpite(tiro,navios,tentativas);
            }

            alterarTabuleiro(tiro,navios,naviosAtingidos, tabuleiro);

        }
        while(acertos != 3);

        printf("\n\n\nJogo Finalizado. Voce acertou os 3 navios em %d tentavivas", tentativas);
        printf("\n\n");
        mostrarTabuleiro(tabuleiro);

        printf("\nDeseja Continuar Jogando? (Digite 1 para SIM e 2 para NAO)");
        scanf("%d", &continuarJogando);
        getchar();

        switch(continuarJogando)
        {
        case 1:
            printf("\nContinuando...\n");
            printf("\e[1;1H\e[2J");
            printf("%d", continuarJogando);
            acertos = 0;
            flagBatalha = 0;
            break;
        case 2:
            flagBatalha = 1;
            printf("\nSaindo...\n");
        }

    }
    while (flagBatalha == 0);
    return 0;

}
//</RODRIGO>
