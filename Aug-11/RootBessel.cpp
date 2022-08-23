#include <iostream>
#include <cmath>

using Bessptr = double(double, double); //Puntero a Bessel 
double f(double alpha, double x, double t);
double IntSimpson(double a, double b, int n);
double Bessel(double alpha, double x);
double Zerobisection(double xl, double xu, double eps, Bessptr f, double alpha);
int main(){
    
    double a = 2.0;
    double b = 4.0;
    double const ErrMax = 1e-7;
    double Orden_n = 0.0;


    std::cout << "La raíz es " << Zerobisection(a, b, ErrMax, Bessel, Orden_n) << std::endl;
        return 0;
}

double f(double alpha, double x, double t){
    double arg = alpha*t - x*std::sin(t);
    return std::cos(arg);
}
double IntSimpson(double a, double b, int n, double alpha, double x){
    n*=2;
    double h = (b-a)/n; //Para intervalos pares
    double sum = 0.0;
    for(int ii = 0; ii <=n; ii++){ //Contador entero
        double tt = a + ii*h; //Para Bessel, t variable de integración
        if(ii == 0 || ii == n)
            sum += f(alpha,x,tt);
        else if(ii%2 == 0)
            sum += 2.0*f(alpha,x,tt);
        else
            sum += 4.0*f(alpha,x,tt);
    }
    
    return h/3.0*sum;
}
double Bessel(double alpha, double x){
    double a = 0.0;
    double b = M_PI;
    double n = 50;
    return 1.0/M_PI*IntSimpson(a, b, n, alpha, x);
}
double Zerobisection(double xl, double xu, double eps, Bessptr f, double alpha){
    double m, fm;
    double fxl = f(alpha, xl);
    while(xu-xl >= eps){
        m = (xu+xl)/2.0;
        fm = f(alpha, m);
        if(fxl*fm > 0.0){
            xl = m;
            fxl = fm;
        }
        else
            xu = m; 
    }
    return  (xl+xu)/2.0;
}
