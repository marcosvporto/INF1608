#include<stdio.h>
#include"sistlinear.h"
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

void imprimeMatrizTriangular(double ** M, int m) {
    for(int i = 0;i < m; i++) {
        printf("|");
        for(int j = 0; j < i + 1 ; j ++) {
            if(j==i){
                printf("%.1f", *(*(M+i)+j));    
            } else {
                printf("%.1f  ", *(*(M+i)+j));
            }
        }
        printf("| \n");
    }
    printf("\n");
}

int main () {

    double ** A = criamat(3, 3);
    double ** C = criamat(6, 6);
    double ** Atr = criamattri(3);
    double ** Ctr = criamattri(6);
    double * b = criavet(3);
    double * x = criavet(3);
    double * xCho = criavet(3);

    double * d = criavet(6);
    double * y = criavet(6);
    double * yCho = criavet(6);
    
    double vb[] = {0,2,3};
    double A0[] = { 1  , -1 , 0}; 
    double A1[] = { -1 , 2 , 1}; 
    double A2[] = { 0  , 1 , 2};

    double A0tri[] = { 1 }; 
    double A1tri[] = { -1 , 2 }; 
    double A2tri[] = { 0  , 1 , 2};

    double vd[] = {2.5  , 1.5   , 1     , 1     , 1.5   , 2.5};

    double C0[] = {3    , -1    , 0     , 0     , 0     , 0.5}; 
    double C1[] = {-1   , 3     , -1    , 0     , 0.5   , 0}; 
    double C2[] = {0    , -1    , 3     , -1    , 0     , 0}; 
    double C3[] = {0    , 0     , -1    , 3     , -1    , 0}; 
    double C4[] = {0    , 0.5   , 0     , -1    , 3     , -1}; 
    double C5[] = {0.5  , 0     , 0     , 0     , -1    , 3}; 
    
    double C0tri[] = {3 }; 
    double C1tri[] = {-1   , 3 }; 
    double C2tri[] = {0    , -1    , 3 }; 
    double C3tri[] = {0    , 0     , -1    , 3 }; 
    double C4tri[] = {0    , 0.5   , 0     , -1    , 3 }; 
    double C5tri[] = {0.5  , 0     , 0     , 0     , -1    , 3}; 
    
    A[0] = A0;
    A[1] = A1;
    A[2] = A2;
    b = vb;

    C[0] = C0;
    C[1] = C1;
    C[2] = C2;
    C[3] = C3;
    C[4] = C4;
    C[5] = C5;
    d = vd;

    Atr[0] = A0tri;
    Atr[1] = A1tri;
    Atr[2] = A2tri;

    Ctr[0] = C0tri;
    Ctr[1] = C1tri;
    Ctr[2] = C2tri;
    Ctr[3] = C3tri;
    Ctr[4] = C4tri;
    Ctr[5] = C5tri;
    
    imprimeMatriz(A,3,3);
    imprimeVetor(b,3);
    gauss (3,A,b,x);
    imprimeMatriz(A,3,3);
    imprimeVetor(x,3);

    imprimeMatriz(C,6,6);
    imprimeVetor(d,6);
    gauss (6,C,d,y);
    imprimeMatriz(C,6,6);
    imprimeVetor(y,6);

    imprimeMatrizTriangular(Atr,3);
    cholesky (3,Atr);
    imprimeMatrizTriangular(Atr,3);
    b[0] = 0;
    b[1] = 2;
    b[2] = 3;
    imprimeVetor(b,3);
    substituicoes (3, Atr, b, xCho);
    imprimeVetor(xCho,3);
    
    imprimeMatrizTriangular(Ctr,6);
    cholesky (6,Ctr);
    imprimeMatrizTriangular(Ctr,6);
    d[0]= 2.5;
    d[1]= 1.5;
    d[2]= 1;
    d[3]= 1;
    d[4]= 1.5;
    d[5]= 2.5;
    substituicoes (6, Ctr, d, yCho);
    imprimeVetor(yCho,6);


    return 0;
}