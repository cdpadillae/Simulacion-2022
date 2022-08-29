#include <iostream>
#include <cmath>

//Declaracion
double df1(double t, double x1, double x2);
double df2(double t, double x1, double x2);
void UnPasoRungeKutta(double &t0, double &x10, double &x20, double dt);

const double omega = 3.0;

int main(){
    
    double t,x1,x2; //Condiciones iniciales
    double dt = 0.1; //Paso Delta t
    
    for(t=0, x1=1, x2=0; t<7; ){
        std::cout << t << "\t" << x2 << std::endl;
        UnPasoRungeKutta(t,x1,x2,dt);
    }
    return 0;
}

//Implementacion
double df1(double t, double x1, double x2){
    return -omega*omega*x2;
}
double df2(double t, double x1, double x2){
    return x1;
}

void UnPasoRungeKutta(double &t0, double &x10, double &x20, double dt){
    
    double dx11, dx21, dx31, dx41;
    double dx12, dx22, dx32, dx42;
    //Primer delta
    dx11 = dt*df1(t0,x10,x20);
    dx12 = dt*df2(t0,x10,x20);
    //Segundo delta
    dx21 = dt*df1(t0+dt/2.0,x10+dx11/2.0,x20+dx12/2.0);
    dx22 = dt*df2(t0+dt/2.0,x10+dx11/2.0,x20+dx12/2.0);
    //Tercer delta
    dx31 = dt*df1(t0+dt/2.0,x10+dx21/2.0,x20+dx22/2.0);
    dx32 = dt*df2(t0+dt/2.0,x10+dx21/2.0,x20+dx22/2.0);
    //Cuarto delta
    dx41 = dt*df1(t0+dt,x10+dx31,x20+dx32);
    dx41 = dt*df2(t0+dt,x10+dx31,x20+dx32);
    //Deltas totales
    x10+=(dx11+2*(dx21+dx31)+dx41)/6.0;
    x20+=(dx12+2*(dx22+dx32)+dx42)/6.0;
    
    t0+=dt;
}
