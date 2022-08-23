#include <iostream>
#include <cmath>

double f(double alpha, double x, double t);
double IntSimpson(double a, double b, int n);
double Bessel(double alpha, double x);
int main(){
    
    double Orden_n = 0.0;
    for(double xx = 0; xx<=10; xx+=0.01)
        std::cout << xx << " " << Bessel(Orden_n,xx) << std::endl;    
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
