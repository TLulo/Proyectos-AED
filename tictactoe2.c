#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define n 4
#define CELL_MAX (n * n - 1) //Define la posicion maxima que podemos elegir para poner una X u O 

void print_sep(int length) //Imprime separadores
{
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[n][n]) //Imprime el board
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
    bool hor_winner,vert_winner,diag_winner,diags_winner;
    int i,j;
    int temp_i,temp_j;
    char winner = '-';
    // Revisa horizontales
    for(i = 0; i < n; i++){
        hor_winner = true;
        for(int j = 0; j < n - 1; j++){
            if((board[i][j] == board[i][j+1]) && board[i][j] != '-'){
                    hor_winner = true && hor_winner;
            } else {
                    hor_winner = false && hor_winner;
                }
            }
        if (hor_winner){
            return board[i][i];
        }
    }
    // Revisa vertical 
    for(i = 0; i < n; i++){
        vert_winner = true;
        for(int j = 0; j < n - 1; j++){
            if((board[j][i] == board[j+1][i]) && board[j][i] != '-'){
                    vert_winner = true && vert_winner;
            } else {
                    vert_winner = false && vert_winner;
                }
            }
        if (vert_winner){
            return board[i][i];
        }
    }
    
    // Revisa diagonal principal
    diag_winner = true;
    for(i = 0; i < n-1; i++){
        if((board[i][i] == board[i+1][i+1]) && board[i][i] != '-'){
            diag_winner = true && diag_winner;
        } else {
            diag_winner = false && diag_winner;
        }
    } 
    if (diag_winner){
            return board[i][i];
    }
    // Revisa diagonal secundaria
    diags_winner = true;
    for((i = 0, j = n - 1); i < n-1;( i++ ,j--)){
        if((board[i][j] == board[i+1][j-1]) && board[i][j] != '-'){
            diags_winner = true && diags_winner;
        } else {
            diags_winner = false && diags_winner;
        }
    } 
    if (diags_winner){
            return board[0][n-1];
}
        return winner;
}

bool has_free_cell(char board[n][n])
{
    bool free_cell=false;
    // Anidado de bucles para reccorrer las posiciones del board
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n; j++)
            {
                if(board[i][j] == '-') //Si hay un lugar libre devuelve true
                    {free_cell = true || free_cell;} 
                else                   //Si no hay un lugar libre devuelve false
                    {free_cell = false || free_cell;}
            }    
    }
    return free_cell;
}


int main(void)
{
    printf("TicTacToe Completisimo :)\n"); //Importante para saber que funciona

    char board[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            board[i][j] = '-';
    }
    }

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) { // Ciclo que va a ejecutarse siempre que haya celdas libres y no haya ganador
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
