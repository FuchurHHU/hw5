//Homework 5 , Lösen der DGL x'' + x = 0 mittels Euler forward und backward

//Umschreiben der DGL siehe Blatt Papier 

#include <cmath>
#include <iostream>
#include <complex>

using namespace std;

int main (){
  
  double pi = 3.1416;
  
  //Erstellen eines t-Vektors:
  double dt = pi/100;  // iteration step
  double tmin = 0; 
  double tmax = pi*20;
  int N = (tmax - tmin)/dt +1  ;
  double t[N];
  
 for (int i = 0; i < N ; i++){
    t[i] = tmin + dt*i;
   }
  
  
  //Euler methods (f = forward b =backwards) , Herleitung der Formel für backwards siehe Blatt
  
  double yf[2], yb[2]; //weil hier Vektor mit 2 Zeilen, y = (x , x')
  double ya;
  yf[0] = 1; //initial value of x
  yb[0] = yf[0];
  ya = yf[0];
 
  
  yf[1] = 0; //initial value of x'
  yb[1] = yf[1];
  
  
  cout << t[0] << "\t" << yf[0] << "\t" << yb[0] << "\t"<< ya<< endl; // Gibt Startwerte aus
  
  for (int i = 1; i < N; i++){
    //forward
    double yftemp = yf[0];
    yf[0] += dt*yf[1] ;
    yf[1] -= dt*yftemp;
    
    //backward
    double ybtemp = yb[0];
    yb[0] = 1/(1 + dt*dt) * (yb[0] - dt*yb[1]);
    yb[1] = 1/(1 + dt*dt) * (dt*ybtemp + yb[1]);
    
    //analytically
    ya = cos(t[i]);
 
    
     cout << t[i] << "\t" << yf[0] << "\t" << yb[0] <<"\t"<< ya <<endl; // Gibt Startwerte aus
  
    
    
    
  }
  
  
  return 0;
}