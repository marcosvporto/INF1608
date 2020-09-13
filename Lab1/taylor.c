#include"taylor.h"
#include<stdio.h>

double pot(double x, int n) {
    if(n == 1) {
        return x;
    } else {
        return x*pot(x,n-1);
    }
}
double fat(int n) {
    if(n == 0) {
        return 1;
    } else {
        return 1.0*(n*fat(n-1));
    }
}
// Usando x0 = 0
double cos_taylor_90 (double x) {
    if(x < 0 || x > Pi/2) {
        printf("Valor do ângulo não suportado 90: %.6f\n", x);
        return 0;
    }



    return  F0 +    ((F1*pot(x,1))/fat(1)) + ((F2*pot(x,2))/fat(2)) + 
                    ((F3*pot(x,3))/fat(3)) + ((F4*pot(x,4))/fat(4)) +
                    ((F5*pot(x,5))/fat(5)) + ((F6*pot(x,6))/fat(6)) + 
                    ((F7*pot(x,7))/fat(7));
                    
}

double cos_taylor (double x){
    if( x < -2*Pi || x > 2*Pi) {
        printf("Valor do ângulo não suportado\n");
        return 0;
    } else {
        if( x < 0 ) {
            x = x + 2*Pi;
            
        }
    }
    if(x <= Pi /2) { // Primeiro Quadrante
        //printf("Primeiro Quadrante\n");
        return cos_taylor_90(x);

    } else if(x <= Pi) { // Segundo Quadrante
        //printf("Segundo Quadrante\n");
        //printf("\n%.6f\n",x - (Pi/2));
        return - cos_taylor_90(Pi - x);
        
    } else if(x <= 3*Pi/2) { // Terceiro Quadrante 
        //printf("Terceiro Quadrante\n");
        return - cos_taylor_90(x - Pi);

    } else { // Quarto Quadrante
        //printf("Quarto Quadrante\n");
        return cos_taylor_90(2*Pi - x);

    }
}