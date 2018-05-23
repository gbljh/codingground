#include <fstream>
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    int i, id, mat, phis, prog, group;
    string buff, fio, fios, tel;
    setlocale(LC_ALL, "rus");
    ifstream fin("bd.txt");
    getline(fin,buff);
    for(i=0;i<10;++i){
        fin >> id >> fio >> tel >> group >> mat >> phis >> prog;
        if(mat+phis+prog>=225){
            fios += fio+"\n";
     }
     }
    fin.close();
    ofstream fout ("1.txt");
    fout << fios;
    fin.close();
    return 0;
}