#include <iostream> //Entrada y salida de datos
#include <cmath>

double f(double x);

int main(int agrv, char **argc){

    double x;
    double xa = 2.0;
    double xb = 4.0;
    double const EPS = 1e-12;

    double xm = (xb+xa)/2.0;
     
    while(std::abs(f(xm))>EPS){
        xm = (xb+xa)/2.0;
        if(f(xm)*f(xb)<0)
            xa = xm;
        else
            xb = xm;
        
    }

    //std::cout << xm << std::endl; Solucion raiz
    for(x = 0.1;x<=10;x+=0.1){
        std::cout << x << "\t" << f(x) << std::endl;
    }
        
    return 0;
}

double f(double x){

    double y = std::sin(x)/x;
        
    return y;
}
