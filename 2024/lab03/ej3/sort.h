/*
  @file sort.h
  @brief Sort functions declarations
*/
#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "player.h"

/**
 * @brief Returns true if player 'x' goes before player 'y' in a sorted array of players.
 *
 * @param[in]  x Player 'x'
 * @param[in]  y Player 'y'
 *
 * @return true if player 'x' goes before player 'y' in a sorted array of players.
 */
bool goes_before(player_t x, player_t y);

/**
 * @brief    Checks if the array 'a' is in ascending order according
 *           to the goes_before function
 *
 * @param[in]  atp     The Player array
 * @param[in]  length  Length of player array
 *
 * @return True if array is sorted in ascendirng order according to goes_before function, false otherwise
 */
bool array_is_sorted(player_t atp[], unsigned int length);


/**
 * @brief Sort the array 'a' using any sorting algorithm. The resulting sort
 *        will be ascending according to the goes_before funtion.
 *        The array 'a' must have exactly 'length' elements.
 *
 * @param[in]      a       Players array
 * @param[in]      length  Length of players array
 */
void sort(player_t a[], unsigned int length);


/*
* swap position to two elements in array of player_t
*/
void swap(player_t a[], unsigned int i, unsigned int j);

/*
*Sort array in ranking with insertion sort
*Insertion sort have 0.03.... seconds delay
*/
void insert(player_t a[], unsigned int i);
void insertion_sort(player_t a[], unsigned int length);

/*
*Sort array in ranking with quick-sort
*Insertion sort have 0.0006.... seconds delay
*/
unsigned int partition(player_t a[], unsigned int izq, unsigned int der);
void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der);
void quick_sort(player_t a[], unsigned int length);

#endif
