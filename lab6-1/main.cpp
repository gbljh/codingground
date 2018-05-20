#include <iostream>
#include <cmath>
#include <fstream>
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
    float integr1, integr2, step = 0.2, xmin = -1.0, xmax = 1.0;
    int i, n =((abs(xmin)+(xmax))/step)+1;
    float x1[n], x2[n], y1[n], y2[n];
    x1[0] = xmin;
    x2[0] = xmin;
    y1[0] = f1(x1[0]);
    y2[0] = f2(x2[0]);
    float y1max = y1[0], y2max = y2[0];
    integr1 = y1[0]*step;
    integr2 = y2[0]*step;
    for(i = 1;i<n;++i){
        x1[i] = x1[i-1]+step;
        x2[i] = x2[i-1]+step;
        y1[i] = f1(x1[i]);
        y2[i] = f2(x2[i]);
        integr1 += y1[i]*step;
        integr2 += y2[i]*step;
        if(y1[i]>y1max){
            y1max = y1[i];
        }
        if(y2[i]>y2max){
            y2max = y2[i];
        }
    }
   FILE *f;
    f = fopen("1.txt", "wt");
    ofstream fout ("1.txt");
    fout << "Функція x*5^x\nx       y\n";
    for(i = 0;i<n;++i){
    fout << round(x1[i]*100000)/100000;
    fout << "       ";
    fout << round(y1[i]*100000)/100000;
    fout << "\n";
    }
    fout << "max = ",y1max;
    fout << y1max;
    fout << "\n";
    fout << "Integral[";
    fout << xmin;
    fout << ",";
    fout << xmax;
    fout << "] = ";
    fout << integr1;
    fout << "\nФункція 3-|x-pow(3-x,1/3)| при x<=1, pow(x,1/3) при 1<x<=4, pow(2-x,1/3) при x>4\nx       y\n";
    for(i = 0;i<n;++i){
    fout << round(x2[i]*100000)/100000;
    fout << "       ";
    fout << round(y2[i]*100000)/100000;
    fout << "\n";
    }
    fout << "max = ",y2max;
    fout << y2max;
    fout << "\n";
    fout << "Integral[";
    fout << xmin;
    fout << ",";
    fout << xmax;
    fout << "] = ";
    fout << integr2;
   return 0;
}