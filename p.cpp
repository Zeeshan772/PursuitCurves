#include <cmath>
#include <iostream>
#include "cpgplot.h"


float r(float t){
return (cos(t));
}
float s(float t){
return (sin(t));
}
// r't
float drdt(float t){
return (-sin(t));
}
//s't
float dsdt(float t){
return (cos(t));
}
float R(float t, float x, float y, float k){
return ((k)*(sqrt(drdt(t)*drdt(t) + dsdt(t)*dsdt(t))) / (sqrt((r(t)-x)*(r(t)-x) + (s(t)-y)*(s(t)-y))));
}
float dxdt(float t, float x, float y, float k){
return (R(t, x, y, k) * (r(t)-x));
}
float dydt(float t, float x, float y, float k){
return (R(t, x, y, k) * (s(t) - y));
}

int main(){
  int i,j,n;
  float tf, k;
  std::cout << " Enter Final Time: " << "\n";
  std::cin >> tf;
  std::cout << "Number of Intervals " << "\n";
  std::cin >> n;
  std::cout << "Speed of Fox " << "\n";
  std::cin >> k;
  float k1, k2, k3, k4;
  float l1, l2, l3, l4;
  float dt, h, a, b, o;
  float vx, vy;
  float rval[n]; float sval[n]; float x[n]; float y[n];
  float xp[n]; float yp[n]; float t[n];
 
  // Open a plot window
  if (!cpgopen("/XWINDOW")) return 1;
  // Set-up plot axes
  cpgenv(-5.,5.,-5.,5.,-1,0);
  // Label axes
  cpglab("x", "y", "Pursuit Curve");
  
  float t0 = 0.;
  y[0] = 0.;
  x[0] = 3.;
  dt = (tf - t0 )/n;
  t[0] = 0;

  h = 0.;
  for (j=0;j<n;j++){
    h += dt;
    t[j+1] = h;
    
  //std::cout << " " << t[j];
}



  std::cout << "We got to the beginning!\n";
  //rabit 
  for(i=0;i<n;i++){
    rval[i] = r(t[i]);
    sval[i] = s(t[i]);
}
 
  // Compute the function at the points
  for(i=0;i<(n);i++) {
    
    k1 = dxdt(t[i], x[i], y[i], k);
    l1 =  dydt(t[i], x[i], y[i], k);
    k2 = dxdt(t[i] + 0.5 * dt, x[i] + 0.5 *dt* k1, y[i] + (0.5*dt * l1), k);
    l2 =  dydt(t[i] + 0.5 * dt, x[i] + 0.5 *dt* k1, y[i] + (0.5 *dt* l1), k);
    k3 =  dxdt(t[i] + 0.5 * dt, x[i] + 0.5 *dt* k2, y[i] + (0.5 *dt* l2), k);
    l3 = dydt(t[i] + 0.5 * dt, x[i] + 0.5 *dt* k2, y[i] + (0.5 *dt* l2), k);
    k4 = dxdt((t[i] + dt), x[i] +  (dt*k3), y[i] +  (dt*l3), k);  
    l4 =  dydt((t[i] + dt), x[i] +  (dt*k3), y[i] +  (dt*l3), k); 
    

    // fox
    
    x[i+1] = x[i] + (dt/6)*(k1 + 2. * k2 + 2. * k3 + k4);
    y[i+1] = y[i] + (dt/6)*(l1 + 2. * l2 + 2. * l3 + l4);


  //std::cout << i << " " << x[i+1] << " " << y[i+1] ;//<< dxdt(0.01, 1.0);
}

  //std::cout <<rval[1000] << " " << sval[1000];

  // Plot the curve 
  cpgsci(2); //red
  cpgline(n, rval , sval);
  cpgsci(5); 
  cpgline(n, x, y);
  

  // Pause and then close plot window
  cpgclos();

  std::cout << "We got to the end!\n";
  return 0;
}
