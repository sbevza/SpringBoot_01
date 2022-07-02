#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

const int WIDTH = 30;
const int HEIGHT = 30;
const int TRUE = 1;
const int FALSE = 0;

void makingboundarylines (int board[HEIGHT][WIDTH]){
    int cols, rows;
    for (cols =0; cols <WIDTH; cols++)
    {
        board[0][cols] = '_';
        board[HEIGHT -1][cols]= '_';
    }
    for (rows =1; rows <HEIGHT; rows++)
    {
        board[rows][0] = '|';
        board[rows][WIDTH -1] = '|';
    }
}

void fillarray(int board[HEIGHT][WIDTH]){
    int i,j;
    for(i =1; i <HEIGHT-1; i++)
        for(j=1; j <WIDTH-1; j++)
            board[i][j] = ' ';
}

void fillarrayrandomly(int board[HEIGHT][WIDTH]){
    int i, j, num;
    srand((unsigned)time(NULL));
    for(i =1; i <HEIGHT -1; i++)
        for(j=1; j <WIDTH -1;j++)
        { 
            num = rand()%11;
            if (num == 1)
                board[i][j] = 'O';
            else board[i][j] = ' ';
        }
}

void display2Darray(int board[HEIGHT][WIDTH]){
int rows;
int cols;
    for (rows = 0; rows <HEIGHT; rows++)
    {
        for(cols =0; cols <WIDTH; cols++)
            printf ("%3c", board[rows][cols]);
        printf ("\n");
    }
}

void countneighbors (int board[HEIGHT][WIDTH]){
    int neighbors;
    int rows;
    int cols;
    int a, b;
    for (rows =1; rows <HEIGHT; rows++)
    {
        for (cols = 1; cols <WIDTH; cols ++)
        {
            neighbors = 0;
            if (board[rows][cols] == 'O')
            {
                for (a = -1; a <2; a++)
                {
                    for (b = -1; b <2; b++)
                        if ((board[rows +a][cols +b] == 'O') ||(board[rows +a][cols +b] == 1) || (board[rows +a][cols +b] == 0))
                            neighbors++;
                }
                
                if ((neighbors == 2) || (neighbors == 3))
                    board[rows][cols] = 1; /*live*/<
                else if ((neighbors < 2) || (neighbors >= 4))
                    board[rows][cols] = 0; /*die*/
            }
        }
    }
}

void checknewborns (int board[HEIGHT][WIDTH]){
    int neighbors;
    int rows;
    int cols;
    int a, b;
    for (rows =1; rows <HEIGHT -1; rows++)
    {
        for (cols = 1; cols <WIDTH -1; cols ++)
        {
            neighbors = 0;
            if (board[rows][cols] == ' ')
            {
                for (a = -1; a <2; a++)
                {
                    for (b = -1; b <2; b++)
                        if ((board[rows +a][cols +b] == 'O') || (board[rows +a][cols +b] == 1) || (board[rows +a][cols +b] == 0))
                            neighbors++;
                }
                if (neighbors == 3)
                    board[rows][cols] = 2; /*newborn*/
            }
        }
    }
}

void anewgeneration (int board[HEIGHT][WIDTH]){
    int rows;
    int cols;
    for (rows =1; rows <HEIGHT -1; rows++)
    {
        for (cols = 1; cols <WIDTH -1; cols ++)
        {
            if (board[rows][cols] == 1)
                board[rows][cols] = 'O';
            else if (board[rows][cols] == 2)
                board[rows][cols] = 'O';
            else if (board[rows][cols] == 0)
                board[rows][cols] = ' ';
        }
    }
}

int checkforexistence (int board[HEIGHT][WIDTH]){
    int rows;
    int cols;
    int creatures =0;
    for (rows =1; rows <HEIGHT -1; rows++)
    {
        for (cols = 1; cols <WIDTH -1; cols ++)
        {
            if (board[rows][cols] == 'O')
                creatures++;
        }  
    }
    if (creatures == 0)
        return TRUE; /*all creatures died*/
    else return FALSE; /*there are still living creatures*/
}

void playgame (int board[HEIGHT][WIDTH], int numgeneration){
    int i, c, check;
    for (i = 1; (i <= numgeneration) && (c != 32); i++)
    {
        system("cls");
        countneighbors(board);
        checknewborns(board);
        anewgeneration(board);
        printf ("Generation: %i\n", i);
        printf ("Hit enter to move to the next generation\n");
        display2Darray(board);
        if(kbhit())
        {
            c = getch();
            if(c == 32)
                break;
        }
        check = checkforexistence(board);
        if ((check= checkforexistence(board)) ==TRUE)
        {
            printf ("\nALL CREATURES HAVE DIED: GAME OVER");
            c = 32;
        }
    }
}

void automaticmode(int board[HEIGHT][WIDTH]){
    int generation;
    fillarrayrandomly(board);
    display2Darray(board);
    printf ("\nPlease select a number of generation: ");
    scanf ("%i", &generation);

    playgame(board, generation);
}

int main () {
    int board[HEIGHT][WIDTH];
    
 //   while (1){
    makingboundarylines(board);
    fillarray(board);

    printf ("CONWAY'S GAME OF LIFE\n\n");
    printf ("Please hit space to terminate the program, hit enter to move to the next generation\n");

    automaticmode(board);
//    }
    return 0;
}
