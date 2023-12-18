// https://cprogressive.blogspot.com/2012/12/Learn-how-to-make-a-Battleship-game-in-C-programming-language.html

#include <stdio.h>
#include <stdlib.h>

void startBoard(int board[][5])
{
    int line, column;
        for(line=0 ; line < 5 ; line++ )
            for(column=0 ; column < 5 ; column++ )
                board[line][column]=-1;
}

void showBoard(int board[][5])
{

    int line, column;

        printf("\t1 \t2 \t3 \t4 \t5");
        printf("\n");

        for(line=0 ; line < 5 ; line++ ){
            printf("%d",line+1);
            for(column=0 ; column < 5 ; column++ ){
                if(board[line][column]==-1){
                    printf("\t~");
                }else if(board[line][column]==0){
                    printf("\t*");
                }else if(board[line][column]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

    }

void startShips(int ships[][2]){
        srand(time(NULL));
        int ship, last;

        for(ship=0 ; ship < 3 ; ship++){
            ships[ship][0]= rand()%5;
            ships[ship][1]= rand()%5;

            //let's check if this shot was not tried
            //if it was, just get out of the 'do while' loop when draws a pair that was not tried
            for(last=0 ; last < ship ; last++){
                if( (ships[ship][0] == ships[last][0])&&(ships[ship][1] == ships[last][1]) )
                    do{
                        ships[ship][0]= rand()%5;
                        ships[ship][1]= rand()%5;
                    }while( (ships[ship][0] == ships[last][0])&&(ships[ship][1] == ships[last][1]) );
            }

        }
    }

void giveShot(int shot[2])
{

        printf("Line: ");
        scanf("%d",&shot[0]);
        shot[0]--;

        printf("Column: ");
        scanf("%d",&shot[1]);
        shot[1]--;

}

int hitship(int shot[2], int ships[][2])
{
    int ship;

        for(ship=0 ; ship < 3 ; ship++){
            if( shot[0]==ships[ship][0] && shot[1]==ships[ship][1]){
                printf("You hit a ship with the shot (%d,%d)\n",shot[0]+1,shot[1]+1);
                return 1;
            }
        }
        return 0;
    }

void tip(int shot[2], int ships[][2], int attempt)
{
        int line=0,
            column=0,
            row;

        //count how many ships there is line/column
        for(row=0 ; row < 3 ; row++){
            if(ships[row][0]==shot[0])
                line++;
            if(ships[row][1]==shot[1])
                column++;
        }

        printf("\nDica %d: \nline %d -> %d ships\ncolumn %d -> %d ships\n",attempt,shot[0]+1,line,shot[1]+1,column);
}

void changeBoard(int shot[2], int ships[][2], int board[][5]){
        if(hitship(shot,ships))
            board[shot[0]][shot[1]]=1;
        else
            board[shot[0]][shot[1]]=0;
    }

int main() {
        int board[5][5];
        int ships[3][2];
        int shot[2];
        int attempts=0,
            hits=0;

        startBoard(board);
        startShips(ships);

        printf("\n");

        do{
            showBoard(board);
            giveShot(shot);
            attempts++;

            if(hitship(shot,ships)){
                tip(shot,ships,attempts);
                hits++;
            }
            else
                tip(shot,ships,attempts);

            changeBoard(shot,ships,board);


        }while(hits!=3);

        printf("\n\n\nFinished game. You hit the three ships in %d attempts", attempts);
        showBoard(board);
    }
