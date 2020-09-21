#include<math.h>
#include<stdio.h>

double constanteCrammer(double (*f) (double x), double x0, double x1, double x2) {
    double detAc = ( pow(f(x0),2) * f(x1) * x2 ) +
                   ( f(x0) * x1 * pow(f(x2),2) ) +
                   ( x0 * pow(f(x1),2) * f(x2) ) -
                   ( x0 * f(x1) * pow(f(x2), 2)) -
                   ( pow(f(x0),2) * x1 * f(x2) ) - 
                   ( f(x0) * pow(f(x1),2) * x2 ) ;
    double detA  = ( pow(f(x0),2) * f(x1) * 1 ) +
                   ( f(x0) * 1 * pow(f(x2),2) ) +
                   ( 1 * pow(f(x1),2) * f(x2) ) -
                   ( 1 * f(x1) * pow(f(x2), 2)) -
                   ( pow(f(x0),2) * 1 * f(x2) ) - 
                   ( f(x0) * pow(f(x1),2) * 1 ) ;
    return detAc / detA ;
}

int IQI (double x0, double x1, int p, double (*f) (double x), double* r) {
    double x2 = (x0 + x1) / 2;
    double iteracoes = 0;

    double c = constanteCrammer(f,x0,x1,x2);
    while ( fabs(f(c)) > 0.5 * pow(10, -14) && iteracoes < 50 ) {
        x0 = x1;
        x1 = x2;
        x2 = c;
        c = constanteCrammer(f,x0,x1,x2);
        iteracoes++;
    }
    *r = c;
    return iteracoes;
}

int bissecao (double a, double b, int p, double (*f) (double x), double * r) {

    double maxerror = 0.5 * pow(10, -p);
    double c = 0;
    double iteracoes = 0;
    while ( (b - a)/2 > maxerror ) {
        c = (a + b) / 2;
        if( fabs(f(c)) < 0.5 * pow(10, -16)) {
            break;
        }
        if ( f(a)*f(c) < 0 ) {
            b = c;
        } else {
            a = c;
        }
        iteracoes ++;
    }
    *r = (a + b)/2 ;
    return iteracoes;

}