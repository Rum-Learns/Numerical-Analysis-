#include<iostream>

#define error 0.001

using namespace std;

double func(double x){
    return x*x*x - x*x +2;
}

double funcDeriv(double x){
    return 3*x*x - 2*x;
}

void newtonRaphson(double x){

    int n=0;
    
    double h=func(x)/funcDeriv(x);    
    while(abs(h)>= error){
        h=func(x)/funcDeriv(x);    
        x=x-h;
        n++;
    }
    cout<<"The value of the root is: "<<x<<"\t n= "<<n;
}

int main(){
    double x0=-20;
    newtonRaphson(x0);
    return 0;
    
}