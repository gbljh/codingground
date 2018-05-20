#include <iostream>
#include <cmath>
using namespace std;
float f1(float x){
    // Функція x*5^x
    return x*pow(5,x);
}
float f2(float x){
    // Функція 3-|x-pow(3-x,1/3)| при x<=1, pow(x,1/3) при 1<x<=4, pow(2-x,1/3) при x>4
    if(x<=1){
        return x*abs(x-pow(3-x,1/3));
    }
    else if(1<x && x<=4){
        return pow(x,1/3);
    }
    else{
        return pow(2-x,1/3);
    }
}
int main()
{
    float step = 0.2, xmin = -1.0, xmax = 1.0;
    int i, n =(abs(xmin)+(xmax))/step;
    float x1[n], x2[n], y1[n], y2[n];
    x1[0] = xmin;
    x2[0] = xmin;
    for(i = 0;i<n-1;++i){
        x1[i] = x1[i-1]+step;
        y1[i] = f1(x1[i]);
    }
   cout << "Hello World" << endl; 
   
   return 0;
}

