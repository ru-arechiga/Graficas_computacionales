//EJECUTAR EN TERMINAL:
//g++ challenge1.cpp -o main
//./main

#include <iostream>

using namespace std;

int main(){
  int x1, x2, y1, y2, dx, dy, x, y;
  
    cout<<"Introduce el valor X del PRIMER punto: ";
    cin>>x1;
    cout<<"Introduce el valor Y del PRIMER punto: ";
    cin>>y1;
    cout<<"Introduce el valor X del SEGUNDO punto: ";
    cin>>x2;
    cout<<"Introduce el valor Y del SEGUNDO punto: ";
    cin>>y2;

    dx = x2 - x1;
    dy = y2 - y1;

    for(x = x1; x < x2+1; x++){
        y = y1 + dy * (x - x1) / dx;
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }
  return 0;
}
