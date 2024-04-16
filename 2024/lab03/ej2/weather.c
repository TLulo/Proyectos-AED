/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

Weather weather_from_file(FILE* file)
{
    Weather weather;

    int k_average = __INT_MAX__;
    int k_max_temp = __INT_MAX__;
    int k_min_temp = __INT_MAX__;
    unsigned int k_pressure = 0u;
    unsigned int k_moisture = 0u;
    unsigned int k_rainfall = 0u;

    int res = fscanf(file, EXPECTED_WEATHER_FILE_FORMAT,&k_average,&k_max_temp,&k_min_temp,&k_pressure,&k_moisture,&k_rainfall);
    if (res != AMOUNT_OF_WEATHER_VARS){
      fprintf(stderr, "Invalid array6.\n");
      exit(EXIT_FAILURE);
    }
    weather._average_temp = k_average;
    weather._max_temp = k_max_temp;
    weather._min_temp = k_min_temp;
    weather._pressure = k_pressure;
    weather._moisture = k_moisture;
    weather._rainfall = k_rainfall;

    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
