#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */
#define n 5
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
// para verticales 
    for(int column = 0; column < n; column++){
        bool vw = true;
        for(int row = 0; row < n-1; row++){ 
            vw = (board[row][column] == board[row+1][column]) && vw && board[row][column] != '-';
      }
        if (vw){
            winner = board[column][column];
   }
}
    
// para horizontales 
    for(int row = 0; row < n; row++){
        bool hw = true;
        for(int column = 0; column < n-1; column++){ 
            hw = (board[row][column] == board[row][column+1]) && hw && board[row][column] != '-';
        }
        if (hw){
            winner = board[row][row];
    }
}
//diagonal principal 
    bool dpw = true;
    int i = 0;
    for( int i = 0 ; i < n-1; i++){
        dpw = (board[i][i] == board[i+1][i+1]) && dpw && board[i][i] != '-';
    }
    if (dpw){
        winner = board[i][i];
}
//diagonal secundaria 
    bool dsw = true;
    for(int i = 0, j = n-1; i < n-1; i++, j--){
        dsw = (board[i][j] == board[i+1][j-1]) && dsw && board[i][j] != '-';
    }
    if (dsw){
        winner = board[0][n-1];
}


    return winner;
}

bool has_free_cell(char board[n][n])
{
    bool free_cell = false;
       for (int row = 0; row < n; ++row) {
            for (int column = 0; column < n; ++column) {
                free_cell = free_cell || board[row][column] == '-';
                
        }
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");
    char board[n][n];
    for(int i = 0; i < n; i++){
        for (int j = 0 ; j < n;  j++){
            board[i][j] = '-';
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
            int row = cell / n;
            int colum = cell % n;
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
