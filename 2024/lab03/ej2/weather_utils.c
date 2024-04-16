#include "weather_utils.h"



int temp_min(WeatherTable a){
    int min = __INT_MAX__;
    int tmp = __INT_MAX__;
    for (unsigned int year = 0; year < YEARS; year++)
    {
        for (unsigned int month = 0; month < MONTHS; month++)
        {
            for (unsigned int day = 0; day < DAYS; day++)
            {
                tmp = a[year][month][day]._min_temp;
                min = (min <= tmp) ? min : tmp;
            }
            
        }
        
    }

    return min;
}


void procedimiento(WeatherTable a, int output[YEARS]){
    int tmp = __INT_MAX__;

    for (unsigned int year = 0; year < YEARS; year++){
        for (unsigned int month = 0; month < MONTHS; month++)
        {
            for (unsigned int day = 0; day < DAYS; day++)
            {
                tmp = a[year][month][day]._max_temp;
                output[year] = (tmp >= output[year]) ? tmp : output[year];
            }
            
        }
        
    }
}


void month_mrainfall(WeatherTable a, month_t output[YEARS]){
    unsigned int tmp = __INT_MAX__;
    unsigned int max_rainfall = 0u;

    for (unsigned int year = 0; year < YEARS; year++){
        max_rainfall = 0u;
        tmp = __INT_MAX__;
        output[year] = january;
        month_t month_rainfall;
        month_rainfall = january;
        for (unsigned int month = 0; month < MONTHS; month++)
        {
            for (unsigned int day = 0; day < DAYS; day++)
            {
                tmp = a[year][month][day]._rainfall;
                if (tmp >= max_rainfall)
                {
                    max_rainfall = tmp;
                    month_rainfall = month;
                }
                output[year] = (month_rainfall != output[year]) ? month : output[year];
            }
            
        }
        
    }
}

void dump_utils(int temp, int max_temp[YEARS], month_t mes_mayrainf[YEARS]){
    printf("\nLa temperatura minima de todos los anos fue: %d", temp);
    for (unsigned int year = 0u; year < YEARS; year++)
    {
        printf("\nLa mayor temperatura del ano %u es: %d",(year+1980), max_temp[year]);
        printf("\nEl mes con mayor precipitacion del ano %u es: %d",(year+1980), mes_mayrainf[year]+1);
    }
    
}