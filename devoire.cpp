#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Moteur{
    string carburant;
    string code;
    double puissance;
};

struct Tracteur{
    int code;
    Moteur *pmoteur;
    string chasis;
};

struct Usine{

    vector <Tracteur> list;
};



void afficherUsine (Usine site,int nb){
    for(int i=0;i<=nb;i++){

        cout <<"moteur "<<endl;
        cout<<site.list[i].chasis<<endl;
        cout<<site.list[i].code<<endl;
        cout<<(*site.list[i].pmoteur).code<<endl;
    }
}

bool estUtil(Usine site ,int nb ,string id){
    int i=0;
    bool trouve=false;
    while (i<=site.list.size()){

        
        if( (*site.list[i].pmoteur).code==id){
            trouve=true;
    
        }else{
            i+=1;
        }
    }
return trouve; 
    
}

void Ajouter (Usine &site,Tracteur t1){
    site.list.push_back(t1);
}



void AjouterNouveau(Usine &site,Tracteur &t1,string c1,string cod1,double puiss){
    
    Moteur m1={c1,cod1,puiss};

    t1.pmoteur=new(Moteur);
    *(t1.pmoteur)=m1;
    Ajouter (site,t1);

}

void ajouterPareil(Usine &site,int nb,Tracteur &t1){
    t1.pmoteur=new(Moteur);
    *(t1.pmoteur)=*(site.list[nb].pmoteur);

}

void supprDoffice(Usine &site,int nb,int rang){
    for(int i=rang;i<=site.list.size();i++){
        site.list[rang]=site.list[rang+1];
       
    }
     site.list.pop_back();
}

void suppr(Usine &site,int nb,string id,int rang){

    if (estUtil(site,nb,(*(site.list[rang]).pmoteur).code)==false){
        supprDoffice(site,nb,rang);
    }
}