//----Print Fahrenheit-Celsius table for f = 0, 20, ...., 300.
//-------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-------------------------------------------------------------------------------------------------
int main(void) {

    int Lower,Upper;
    int Step;
    float Fahrenheit,Celsius;

    Lower = 0;  //----Lower limit of temp table
    Upper = 300;//----Upper limit
    Step = 20;  //----Step size

    Fahrenheit = Lower;
    while (Fahrenheit <= Upper) {
        Celsius = (5.0/9.0) * (Fahrenheit-32);
        printf("%4.0f %6.1f\n",Fahrenheit,Celsius);
        Fahrenheit = Fahrenheit+Step;
    }

    return(EXIT_SUCCESS);
}
//-------------------------------------------------------------------------------------------------
