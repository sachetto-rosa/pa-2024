#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1416

double calcHipotenusa(double cat1, double cat2)
{
    double h;
    
    h = sqrt(pow(cat1,2) + pow(cat2,2));

    return h;
}

void exiInfoTri(double cat1, double cat2, double hip)
{
    printf("O tri tem um cat = %lf \n", cat1);
    printf("O tri tem outro cat = %lf \n", cat2);
    printf("O tri tem uma hip = %lf \n", hip);
}

int main()
{
    //declarando variávies
    double a, b, h;
    // double a; //outra possibilidade
    // double b; //outra possibilidade
    
    printf("digite os dois catetos \
    separados por virgula: ");
    scanf("%lf,%lf", &a, &b);

    h = calcHipotenusa(a, b);
    
    exiInfoTri(a, b, h);

    //A ideia é usar esse conceito para criar
    //uma função que calcule o perímetro de 
    //uma circunferência.
    double per = 2*PI*10;

    return 0;
}