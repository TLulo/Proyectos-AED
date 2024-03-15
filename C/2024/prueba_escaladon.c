#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */
#define n 19
#define CELL_MAX (n * n - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[n][n])
{
    int cell = 0;

    print_sep(n);
    for (int row = 0; row < n; ++row) {
        for (int column = 0; column < n; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(n);
    }
}

char get_winner(char board[n][n])
{
    char winner = '-';
    //
    //horizontal
    for(unsigned int row = 0; row<n;row++){
        bool ganah = false;
        for(unsigned int column = 1; column<n;column++){
              ganah = board[row][0] == board[row][column];
        }
        if (ganah){
                winner = board[row][0];
        }    
    }//fin horizontales
    //Verticales
    for(unsigned int column = 0; column<n;column++){
        bool ganav = false;
        for(unsigned int row = 1; row<n;row++){
              ganav = board[0][column] == board[row][column];
        }
        if (ganav){
                winner = board[0][column];
        }    
    }//fin vertical
    //Diagonal principal
    bool wpd= false;
    bool wsd = false;
    for (unsigned int i = 0; i < n-1;i++){
        wpd = board[i][i] == board[i+1][i+1];
    }
    if (wpd){
                winner = board[0][0];
        }
    int j = 2;
    for (unsigned int i = 0; i<n;i++){
        wsd = board[0][n-1] == board[i][j];
        j --;
    }
    if (wsd){
                winner = board[0][n-1];
        }
    //Diagonal secundaria
    
    //Fin diagonales
    //
    return winner;
}

bool has_free_cell(char board[n][n])
{
    bool free_cell=false;
    //
    for(unsigned int fila = 0;fila < n;fila++){
        for(unsigned columna = 0;columna < n;columna++){
                free_cell = free_cell || board[fila][columna] == '-'; 
        } 
    }
    //
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");
    printf("Inserte que tan grande desea el tictactoe: ");
    scanf("%d",&n);
    char board[n][n];
    for(unsigned int row = 0;row<n ; row++){
        for (unsigned int column = 0; column < n; column++){
                board[row][column]='-';
        }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
