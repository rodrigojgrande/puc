
/*
  Ref.:: https://www.clubedohardware.com.br/forums/topic/1557007-menus-e-submenus-com-ncurses/

  A logica no exemplo:
  . Criar uma janela com uma borda para facilitar a identificacao.
  . A janela tem o tamanho calculado para envolver as opcoes do menu.
  . A janela tem uma linha de titulo e uma linha em branco antes das opcoes.
  . A linha em branco em geral eh uma barra horizontal na linha 2.
  . Entao, o menu comeca na linha 3.

/------------\
|   titulo   |
|------------|
|   opcao 1  |
|   opcao 1  |
|   opcao 1  |
|   opcao X  |
\------------/

  A logica de desenvolvimento:
  . criar o menu
  . calcular e apresentar a janela.
  . apagar a janela e ... acoes.
  . retornar a opcao selecionada.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <menu.h>
#include <ncurses.h>

#define ENTER    '\n'
#define LOG      "./ncurses.log"

int main(void) {
    char *opcao_0[] = {"Cliente", "Funcionario", "Sair", NULL};
    char versao[20] = {0};				// para mostrar ncurses x.y
    int x, y;							// colunas e linhas da tela ao 
										// abrir o programa
 
	/* Abre o arquivo de registros (log) */
    FILE *log = fopen(LOG, "a+");		// append
    if (log == NULL) return -1;

    initscr();							// inicializacao
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);

    fprintf(log, "versao: %s\n", curses_version());
	getmaxyx(stdscr, y, x);
    fprintf(log, "(linhas) y = %d, (colunas) x = %d\n", y, x);

    if (has_colors())
        fprintf(
            log, "Sim, terminal tem cores: %d pares\n", COLOR_PAIRS);
    else
        fprintf(log, "nao, o terminal nao tem cores\n");

    fflush(log);
    clear();

    wattron(stdscr, COLOR_PAIR(1));
    mvwprintw(stdscr, 1, 3, "%s", strncpy(versao,curses_version(),11));
    wattroff(stdscr, COLOR_PAIR(1));
    refresh();

    /* Cria o vetor de opcoes */
    size_t n_opcao_0 = sizeof(opcao_0) / sizeof(opcao_0[0]);

	ITEM **item_0    = (ITEM **)calloc(n_opcao_0, sizeof(ITEM *));
    for (size_t i = 0; i < n_opcao_0; i += 1)
        item_0[i] = new_item(opcao_0[i], "");

    MENU *menu_0 = new_menu(item_0);	// o menu
    set_menu_mark(menu_0, " > ");

    /* Define opcoes para o nivel */
    Menu_Options opt_0 =
        ~O_ONEVALUE | ~O_SHOWDESC | O_IGNORECASE | O_NONCYCLIC;
    int n = set_menu_opts(menu_0, opt_0);

	if (n == E_OK)
        fprintf(log, "set_menu_opts() retornou OK\n");
    else
        fprintf(log, "set_menu_opts() retornou %d\n", n);
    fflush(log);

    int y_0 = 0, x_0 = 0;				// linhas e colunas para caber o menu

    scale_menu(menu_0, &y_0, &x_0);
    fprintf(log, "scale_menu() retornou %ux%u\n", y_0, x_0);
    fprintf(
        log, "%d itens reportados para esse menu\n",
        item_count(menu_0));
    fflush(log);

	/*
       Cria uma janela para o menu
       scale_menu() ja deu o tamanho minimo
       uma linha para opcao, mais as bordas e o titulo
       colunas - largura da maior opcao mais largura do menu_mark()
       mais as bordas
	 */
    WINDOW *Win_0 = newwin(
        (y_0 + 4), (x_0 + 2 + strlen(menu_mark(menu_0))), 10, 10);
    box(Win_0, 0, 0);
    wrefresh(Win_0);

    set_menu_win(menu_0, Win_0);	// associa o menu e a janela
    set_menu_sub(menu_0, derwin(Win_0, y_0, x_0, 3, 1));
    keypad(Win_0, TRUE);
    post_menu(menu_0);				// mostra o menu afinal
    wrefresh(Win_0);

    int c       = 0;
    int count_0 = item_count(menu_0);	// para usar no loop
    int dentro = 1;

    while (dentro) {
        int cmd = 0;				// comando para o menu
        c = wgetch(Win_0);
        n = item_index(current_item(menu_0));
        switch (c) {
            case KEY_DOWN:
              cmd = (n == count_0 - 1) ? REQ_FIRST_ITEM : REQ_DOWN_ITEM;
              menu_driver(menu_0, cmd);
              break;

            case KEY_UP:
              cmd = (n == 0) ? REQ_LAST_ITEM : REQ_UP_ITEM;
              menu_driver(menu_0, cmd);
              break;

            case ENTER:				// '\n'
                fprintf(log, "O menu retornou %d\n", n);
                fflush(log);
                unpost_menu(menu_0);
                free_menu(menu_0);
                dentro = 0;
                break;

            default:
                break;
        };							// switch()
        // wrefresh(Win_0);
    };  // while()

    /* Fechas as coisas */
    wclear(Win_0);
    wrefresh(Win_0);
    refresh();

    wattron(stdscr, COLOR_PAIR(1));
    mvwprintw(stdscr, 2, 3, "Menu nivel 0 retornou %d\n", n);
    mvwprintw(stdscr, 3, 3, "Tecle 'x' para encerrar\n");
    wattroff(stdscr, COLOR_PAIR(1));
    refresh();

    while ((c = wgetch(stdscr)) != 'x'); // loop

    fprintf(log, "Saindo com opcao %d\n", n);
    fflush(log);

    /* Libera os items */
    for (size_t i = 0; i < n_opcao_0; i += 1) free_item(item_0[i]);
    endwin();							// fecha tudo
    return 0;
}

/*
   Um codigo profissional usaria algo com
   toda a descricao do menu DENTRO da estrutura (encapsulamento).

typedef struct {
        size_t      id;
        ITEM**      item;     // items
        MENU*       menu;     // menu
        size_t      n_opt;    // quantas
        Menu_Options opt;     // opcoes especiais
        const char* tit;      // titulo
        WINDOW*     win;      // janela
} Menu_desc;

E pode escrever funcoes como

int o_menu(Menu_desc *menu);

que mostra o menu, espera a opcao, apaga a janela e 
retorna para o programa. Em C++ usaria uma classe.

E usar um array com todos os menus do programa:

    Menu_desc     meu-menu[20];       // 20 menus no programa
    Menu_desc   **todos_menus = NULL; // e constroi um vetor de menus

Para compilar:

    clang -o teste -Wall -std=c17 teste.c -lmenu -lncurses

*/


