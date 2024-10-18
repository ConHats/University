#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define cities 10
#define S 3

double CalculatingAverageallCities(double temper[cities][S]);
double CalculatingAverageCity(double temper[cities][S], int i);
double CalculatingmaxDeviation(int i,double temper[i][S]);


int main()
{
    double temper[cities][S];
    int i, j;


	for (i=0; i<cities; i++)
		for (j=0; j<S; j++)
        {
            printf("Temp of City %d During %d 8-hour period: ",i,j);
            temper[i][j]=GetReal();
        }

    printf("%3.1f\n", CalculatingAverageallCities(temper));
    for (i=0; i<cities; i++)
    {
        printf("City %d  %.1f  %.1f\n",i,CalculatingAverageCity(temper, i), CalculatingmaxDeviation(i,temper));
    }
    return 0;
}


double CalculatingAverageallCities(double temper[cities][S])
{
    double MO=0;
    int i, j;
    for (i=0; i<cities; i++)
      for (j=0; j<S; j++)
      {
          MO += temper[i][j];
      }
    return MO/(cities*S);
}




double CalculatingAverageCity(double temper[cities][S], int i)
{
    double average= 0;
    int j;
    for (j=0; j<S; j++)
    {
        average += temper[i][j];
    }
    return average/S;

}


double CalculatingmaxDeviation(int i,double temper[cities][S])
{
    double apoklisi[cities][S];
    int j;
    for (j=0; j<S; j++)
    {
        apoklisi[i][j] = fabs(CalculatingAverageallCities(temper)-temper[i][j]);
    }

    double maxapoklisi = apoklisi[i][0];
    for(j=1; j<S; j++)
    {
        if (maxapoklisi<apoklisi[i][j])
        {
            maxapoklisi= apoklisi[i][j];
        }
    }
    return maxapoklisi;
}
