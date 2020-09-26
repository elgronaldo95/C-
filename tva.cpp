#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>



using namespace std;

struct TVA {
    float reduit;
    float normal;
    float particulier;
};

struct Produit{
    string nomProduit;
    float prixHT;
    TVA *ptva;
};


float prixTTC(Produit p1,float tvaprod){
    float prixTTC;

    prixTTC = tvaprod * p1.prixHT;

    return prixTTC;
}



int main (int argc, char *argv[]){

Produit p1;
TVA t1;


t1={2,6,7};

p1={"pomme",4,nullptr};


p1.ptva=new(TVA);

*(p1.ptva) = t1;

float prix,tvaprod;

tvaprod=(*(p1.ptva)).reduit;

prix=prixTTC(p1,tvaprod);

cout<<"le prix du produit"<<endl;

cout<<prix<<endl;

free (p1.ptva);
}