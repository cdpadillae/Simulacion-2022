#include <iostream>
#include <cmath>

using fptr = double(double); //retorna(recibe)
using bisptr = double(double, double, double, fptr);
double sinxx(double x);
double bisection(double xl, double xu, double eps, fptr f);

int main(int argc, char **argv){

    double a = 2.0;
    double b = 4.0;
    double const ErrMax = 1e-7;

    std::cout << bisection(a, b, ErrMax, sinxx) << std::endl;

    return 0;
}

double sinxx(double x){    
    return std::sin(x)/x;
}
double bisection(double xl, double xu, double eps, fptr f){
    double m, fm;
        double fxl = f(xl);
        while(xu-xl > eps){
        m = (xu+xl)/2.0;
        fm = f(m);
        if(fxl*fm > 0.0){
            xl = m;
            fxl = fm;
        }
        else
            xu = m; 
    }
    return  m;
}
