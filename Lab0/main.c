#include<stdio.h>
#include"matriz.h"

void imprimeVetor(double *v, int n){
    for(int i =0; i< n; i++) {
        printf("|%.2f|\n", *(v+i));
    }
    printf("\n");
}


void imprimeMatriz(double ** M, int m, int n) {
    for(int i = 0; i<m ; i++){
        printf("|");
        for(int j = 0; j< n ; j++){
            if(j==n-1){
                printf("%.1f", *(*(M+i)+j));    
            } else {
                printf("%.1f  ", *(*(M+i)+j));
            }
        }
        printf("| \n");
    }
    printf("\n");
}
int main(){

    /**
    * A =   |2 5 9|
    *       |3 6 8| 
    *       
    * B =   |2 7|
    *       |4 3|
    *       |5 2|
    *   
    * v =   |4| 
    *       |7| 
    *       |1|
    * 
    * w =   |2|
    *       |6|
    *       |7|    
    * 
    */ 
    double ** A = criamat(2, 3);
    double ** B = criamat(3, 2);
    double *  v = criavet(3);
    double *  w = criavet(3);
    double * Av = criavet(2);
    double ** AB = criamat(2, 2);
    
    A[0][0]=2;
    A[0][1]=5;
    A[0][2]=9;
    A[1][0]=3;
    A[1][1]=6;
    A[1][2]=8;

    printf("A \n");
    imprimeMatriz(A, 2, 3);
    transposta(2,3,A,B);
    printf("A Transposta \n");
    imprimeMatriz(B, 3, 2);
    transposta(3,2,B,A);
    printf("A = (A Transposta) Transposta \n");
    imprimeMatriz(A, 2, 3);
    printf("v \n");
    v[0] = 4.0;
    v[1] = 7.0;
    v[2] = 1.0;
    imprimeVetor(v,3);
    multmv(2, 3, A, v, Av);

    printf("A*v \n");
    imprimeVetor(Av, 2);

    B[0][0]=2;
    B[0][1]=7;
    B[1][0]=4;
    B[1][1]=3;
    B[2][0]=5;
    B[2][1]=2;
    
    printf("A \n");
    imprimeMatriz(A, 2, 3);
    printf("B \n");
    imprimeMatriz(B, 3, 2);

    multmm  (2, 3, 2, A, B, AB);

    printf("B*A \n");
    imprimeMatriz(AB, 2, 2);


    printf("v \n");
    imprimeVetor(v,3);

    printf("v*5 \n");
    multvs(3, v, 5, w);
    imprimeVetor(w,3);

    printf("w \n");
    w[0] = 2.0;
    w[1] = 6.0;
    w[2] = 7.0;
    imprimeVetor(w,3);

    printf("v*w = %.2f\n", prodescalar(3, v, w));
    
    printf("norma 2 de v = %.2f\n", norma2(3, v));
    


    liberamat(2, A);
    liberamat(3, B); 
    liberamat(2, AB);
    liberavet(v);
    liberavet(w);
    liberavet(Av);

    return 0;
}