#ifndef _WHEATER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"

void procedimiento(WeatherTable a, int output[YEARS]);
//Receives one array of Weather table(a) and one array(output) of int, the maximun temp max of the year is saves in the output[years]


int temp_min(WeatherTable a);
//Receives array of Weather table and return minor temp min of the array


void month_mrainfall(WeatherTable a, month_t output[YEARS]);
//Receives one array of Weather table(a) and one array(output) of int, the month with higher precipitation


void dump_utils(int temp, int max_temp[YEARS], month_t mes_mayrainf[YEARS]);
//Dump the utilities to weather_utils.c

#endif