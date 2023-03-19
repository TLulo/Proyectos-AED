#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1) //Define la posicion maxima que podemos elegir para poner una X u O 

void print_sep(int length) //Imprime separadores
{
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3]) //Imprime el board
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3])
{   
    int i;
    // Revisa horizontales
    for(i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    // Revisa verticales
    for(i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }
    
    // Revisa diagonales
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            return board[0][0];
    }
    if(board[0][2] == board[1][2] && board[0][2] == board[2][0]){
            return board[0][2];
    }
    
    return '-';
}

bool has_free_cell(char board[3][3])
{
    bool free_cell=false;
    // Anidado de bucles para reccorrer las posiciones del board
    for (int i = 0; i < 3 ; i++)
    {
        for (int j = 0; j < 3; j++)
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

    char board[3][3] = { // Definimos el board y le asignamos lugares vacios en todas las posiciones
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

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