#include<stdio.h>
#include<math.h>
#include"raiz.h"

static double f1 (double x) {
    
    return cos(x) - pow(x, 3) + x;
}

static double f2 (double x) {
    
    return exp(pow(sin(x),3)) + pow(x, 6) - pow(x, 4) + pow(x,3) - 1;
}
static double funcaoParaquedista(double m) {
    return ((9.8 * m / 15) * (1 - exp ( - 15 * 9 / m ))) - 35 ;
}

int main () {
    double r = 0;
    printf("Quantidade de iterações f1 bissecao =  %d \n", bissecao(0.0, 2.0, 7, &f1, &r));    
    printf("Valor da Raíz = %.7f\n", r);
    printf("Quantidade de iterações f1 IQI =  %d \n", IQI(0.0, 2.0, 7, &f1, &r));    
    printf("Valor da Raíz = %.7f\n", r);
    
    printf("Quantidade de iterações f2 bissecao -2 a -1 =  %d \n", bissecao(-2.0, -1.0, 7, &f2, &r));    
    printf("Valor da Raíz = %.7f\n", r);
    printf("Quantidade de iterações f2 IQI -2 a -1 =  %d \n", IQI(-2.0, -1.0, 7, &f2, &r));    
    printf("Valor da Raíz = %.7f\n", r);

    printf("Quantidade de iterações f2 bissecao -1 a 2=  %d \n", bissecao(-1.0, 2.0, 7, &f2, &r));    
    printf("Valor da Raíz = %.7f\n", r);
    printf("Quantidade de iterações f2 IQI -1 a 2 =  %d \n", IQI(-1.0, 2.0, 7, &f2, &r));    
    printf("Valor da Raíz = %.7f\n", r);

    printf("Quantidade de iterações paraquedista bissecao 0 a 200 =  %d \n", bissecao(0.0, 200.0, 7, &funcaoParaquedista, &r));    
    printf("Valor da Massa = %.7f\n", r);
    printf("Quantidade de iterações paraquedista IQI 0 a 200 =  %d \n", IQI(0.0, 200.0, 7, &funcaoParaquedista, &r));    
    printf("Valor da Massa = %.7f \n", r);

    return 0;
}