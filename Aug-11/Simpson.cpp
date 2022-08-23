#include <iostream>
#include <cmath>

double f(double x);
double IntSimpson(double a, double b, int n);
int main(){
    double xa = 0.0;
    double xb = M_PI/2.0;
    int const N = 2;
    std::cout << IntSimpson(xa,xb,N) << std::endl;
    return 0;
}

double f(double x){
    return std::cos(x);
}
double IntSimpson(double a, double b, int n){
    n*=2;
    double h = (b-a)/n; //Para intervalos pares
    double sum = 0.0;
    for(int ii = 0; ii <=n; ii++){ //Contador entero
        double xx = a + ii*h;
        if(ii == 0 || ii == n)
            sum += f(xx);
        else if(ii%2 == 0)
            sum += 2.0*f(xx);
        else
            sum += 4.0*f(xx);
    }

    return h/3.0*sum;
}
