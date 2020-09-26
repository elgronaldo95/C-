#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Tab{
    int capa;
    int* cases = new int [capa] ;
};

void RemplireTableau(int &tab1[],int capa1){
    for (int i=0;i<=capa1;i++){
        cout<<"entrer valeur du tableau"<<endl;
        cin>>tab1[i];
    }
}

int main (int argc, char *argv[]){

    Tab desreel;
    int pos;
   

int capa1;
cout<<"entrez la la valeur du tableau tab1 "<<endl;
cin>>capa1;
int tab1[capa1];

 int* ptab=tab1;

 

desreel={0,nullptr};
desreel.cases=new (tab[capa1]);
desreel.capa=5;
(*(desreel.cases))[5]=3.14;
ptab=desreel.tab

for (int pos=2;pos<=3;pos++){
    (*(ptab))[pos]=(*(ptab))[7-pos]+1;
    (*(ptab))[6-pos]=(*(ptab))[pos]+2;
}

for (int pos=1 ; pos<= (desreel.capa)%2 ;pos++){
    cout<<(*(desreel.cases))[6-pos];
}

}

