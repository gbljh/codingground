#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
 
int main()
{
    int i,j;
    char fio[100], fios[1000], *pch;
    setlocale(LC_ALL, "rus");
    char buff[100];
    ifstream fin("bd.txt");
    for(i=0;i<7;++i){
        fin >> buff;
    }
    for(j=0;j<10;++j){
        int sum = 0;
        for(i=0;i<7;++i){
           fin >> buff;
            if(i==1){
                *fio = 0;
                strcat(fio,buff);
           }
           if(i>3){
             sum+=atoi(buff);
          }
        }
     if(sum>=225){
            strcat(fios,fio);
            strcat(fios,"\n");
     }
     }
    fin.close();
    FILE *f;
    f = fopen("1.txt", "wt");
    ofstream fout ("1.txt");
    fout << fios;
    return 0;
}