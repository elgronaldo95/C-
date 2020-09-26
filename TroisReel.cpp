#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Tab{
    int capa;
    int *cases =new int[capa]  ;
};

void RemplireCasesTab (Tab &tab1){
    for (int i=0;i<=tab1.capa;i++){
        cout<<"entrez valeur de la cases "<< endl;
        cin>>tab1.cases[i];
    }
}

void AfficherTAB (Tab tab1){
    cout<<"taille du tableau "<<endl;
    cout << tab1.capa <<endl;

     for (int i=0;i<=tab1.capa;i++){

         cout<<tab1.cases[i]<<endl;

      
     }


}

void InverserValeurTAB(Tab &tab1,int i,int j){
int temp;

temp =tab1.cases[i];
tab1.cases[i]=tab1.cases[j];
tab1.cases[j]=temp;


}

void ModifierTAB(Tab &tab1){

    cout<<"entrer la cases à modifier "<<endl;
    int i;
    cin>>i;

    cout<<"entrez la nouvelle valeur à mettre "<< endl;
    int x;
    cin>>x;

    tab1.cases[i]=x;
}



int main (int argc, char *argv[]){

Tab desreel;
cout<<"taille du tableau "<<endl;
cin>> desreel.capa;

RemplireCasesTab (desreel);
cout<<"au depart "<<endl;
AfficherTAB (desreel);
ModifierTAB(desreel);
cout<<"apres modification "<<endl;
AfficherTAB (desreel);
InverserValeurTAB(desreel,0,1);
cout<<"apres inversion "<<endl;
AfficherTAB (desreel);
}