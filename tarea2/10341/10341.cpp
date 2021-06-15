#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstring>
#include <cmath>
using namespace std;

int p,q,r,s,t,u;

//FUNCIÓN PARA CALCULAR SUS RAICES
double func_calc(double x){
    return ((p*exp(-x))+(q*sin(x))+(r*cos(x))+(s*tan(x))+(t*pow(x,2))+u);
}

//ESTA FUNCIÓN DE BISECCIÓN PARA CALCULAR RAICES LA COPIE DE OTRO CÓDIGO
double biseccion(){
    double a=0;
    double b=1;
    while(a+(1e-7) < b){
        double x = (a+b)/2;
        if(func_calc(a) * func_calc(x) <= 0){
            b=x;
        }
        else{
            a=x;
        }
    }
    return (a+b)/2;
}

int main(){
    //ENTRADA Y SALIDA
    while (scanf("%d %d %d %d %d %d", &p,&q,&r,&s,&t,&u) != EOF){
        if (func_calc(0) * func_calc(1) > 0){
            printf("No solution\n");
        }
        else{
            printf("%.4f\n", biseccion());
        }
    }
    return 0;
}
