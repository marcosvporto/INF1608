#include"taylor.h"
#include<math.h>
#include<stdio.h>
int main() {
    
    double realcos = 0;
    double mycos = 0;
    double angulo = 0;
    int i;
    for (i = 0;i<100001; i++) {
        angulo = (Pi/2)*i/100000;
        realcos = cos(angulo);
        mycos = cos_taylor_90(angulo);
        double erro = fabs(realcos - mycos);
        if(erro > 0.005) {
            printf("Erro maior que o tolerável com angulo = %.6f\n",angulo);
            printf("Valor Esperado: %.6f\n",realcos );
            printf("Erro: %.6f\n",erro );
            return 0;
        }
    }
    printf("angulo = %.6f\n", angulo);
    for (i = 0;i<100001; i++) {
        angulo = (2*Pi)*i/100000;
        realcos = cos(angulo);
        mycos = cos_taylor(angulo);
        double erro = fabs(realcos - mycos);
        if(erro > 0.005) {
            printf("Erro maior que o tolerável com anguloh = %.6f\n",angulo);
            printf("Valor Esperado: %.6f\n",realcos );
            printf("Erro: %.6f\n",erro );
            return 0;
        }
    }
    printf("angulo = %.6f\n", angulo);
    for (i = 0;i<100001; i++) {
        angulo = -(2*Pi)*i/100000;
        realcos = cos(angulo);
        mycos = cos_taylor(angulo);
        double erro = fabs(realcos - mycos);
        if(erro > 0.005) {
            printf("Erro maior que o tolerável com anguloh = %.6f\n",angulo);
            printf("Valor Esperado: %.6f\n",realcos );
            printf("Erro: %.6f\n",erro );
            return 0;
        }
    }
    printf("angulo = %.6f\n", angulo);
    return 0;
}