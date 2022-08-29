#include <iostream>
#include <cmath>

double df(double t, double x); //Esta función me dice como es la derivada
void UnPasoEuler(double &t, double &x, double dt);

int main(){
    double t; //Condiciones iniciales
    double x; //Condiciones iniciales
    double dt = 0.01; //Paso Delta t
    for(t=0.0, x=1.0; t<2; ){
        std::cout << t << "\t" << x << "\t" << std::exp(t)  << std::endl;
        UnPasoEuler(t,x,dt);
    }
    return 0;
}
double df(double t, double x){
    return x; //Derivada, entonces la funcion es x2/2
}
void UnPasoEuler(double &t, double &x, double dt){
    double dx;
    dx = df(t,x)*dt;
    x+=dx; t+=dt;
}
