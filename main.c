/*
Diagrama de forças da centrífuga
|------> a
|\   |
| \  | alpha
|  \/
|   \
g    fg
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415
#define g 9.81
#define tolerancia 1e-8
#define iteracoes 500
int main(void)
{
float raio,rpm,fg,ang,omega,a;
    printf("------------------------------------------\n");
    printf("Programa para calculo do RPM da centrifuga\n\n");
    printf("|------> a\n");
    printf("|\\   |\n");
    printf("| \\  | alpha\n");
    printf("|  \\/\n");
    printf("|   \\ \n");
    printf("g    fg\n");
    printf("\nDigite a Fg desejada:");
    scanf("%f",&fg);
    printf("Digite o braco (raio) em [m]:");
    scanf("%f",&raio);
    a=1.0;
    float a_old;
    int i=0;
    do
    {
        a_old=a;
        a=fg*cos(atan(1/a));
        i++;
    } while (fabs(a-a_old)/a > tolerancia && i<iteracoes);
    rpm=(60*a*g)/(4*pow(pi,2)*raio);
    ang=180*asin(1/a)/pi;
    omega=rpm*2*pi/60;
    printf("\n\nRotacao do motor: \t%7.4f [rpm]\nOmega: \t\t\t%7.4f [rad/s]\nInclinacao do forno: \t%7.4f [graus]\nAceleracao centripeta: \t%7.4f [g]\n\n",rpm,omega,ang,a);
    printf("\n\nVersao 1.2\nDesenvolvido por Fumachi - SL19 - A(SL29)\nTECMAT - INPE/SJC\n\n\n");
    system("PAUSE");
    return 0;
}
