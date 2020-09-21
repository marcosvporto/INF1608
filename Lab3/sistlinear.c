#include"sistlinear.h"
#include"matriz.h"
#include<stdio.h>
#include<math.h>

void gauss (int n, double** A, double* b, double* x) {

    for (int j = 0; j < n - 1; j ++) {
        // elimina coluna j
        int p = j;
        for (int w = j + 1; w < n; w ++) {
            if(fabs(A[w][j]) > fabs(A[p][j])) {
                p = w;
            }
        }
        // for(int w = j; w < n; w ++) {
        //     A[j][w] = A[p][w];
        // }
        A[j] = A[p];
        b[j] = b[p];
        for (int i = j + 1; i < n ; i++ ) {
            // elimina aij

            double f = A[i][j] / A[j][j] ;

            for (int k = j; k < n; k++) {
                A[i][k] = A[i][k] - (A[j][k] * f); 
            }
            b[i] = b[i] - (b[j]*f);
        }
    }
    for(int i = n - 1 ; i >= 0 ; i--) {
        double s = 0;
        for (int j = i ; j < n; j++) {
            s = s + (A[i][j]*x[j]);
        }
        x[i] = ( b[i] - s ) / A[i][i];
    }
}


void cholesky (int n, double** A) {
    
    for(int k = 0; k < n ; k ++) {
        A[k][k] = sqrt(A[k][k]);
        for(int i = k + 1 ; i < n ; i++) {
            A[i][k] = A[i][k] / A[k][k];
            
        }
        for(int i = k + 1 ; i < n ; i++) {
            for(int j = k + 1 ; j <= i ; j++) {
                A[i][j] = A[i][j] - (A[i][k]*A[j][k]);
            }
        }
    } 
}

void substituicoes (int n, double** A, double* b, double* x) {

    double *y = criavet(n);
    
    for(int i = 0; i< n; i++) {
        y[i] = 0;
    }

    for(int i = 0; i< n ;i++) {
        double s = 0;
        
        for(int j = i; j>=0; j--) {
            s = s + A[i][j] * y[j];
        }
        y[i] = (b[i] - s) / A[i][i];
    }
    
    for(int i = n - 1 ; i >= 0 ; i--) {
        double s = 0;
        for (int j = i ; j < n; j++) {
            s = s + (A[j][i]*x[j]);
            
        }
        x[i] = ( y[i] - s ) / A[i][i];
    }
}