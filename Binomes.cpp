#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Etu{
    string prenom;
    Etu *binome;
    Etu *suivant;   
};

struct Liste{
    Etu *Premier;
};

Liste *initialisation(){

    Liste *l1=new Liste();
    Etu *e1=new Etu();

    cout<<"entrez le nom du premier étudiant "<<endl;
    cin>>(e1->prenom);

    e1->suivant=nullptr;
    e1->binome=nullptr;


    l1->Premier=e1;

    return l1;

}

void ajouterDebut(Liste *l1,Etu e1){

    Etu *nouveau=new Etu(e1);

    nouveau->suivant=l1->Premier;
    l1->Premier=nouveau;

}

void ajouterFin(Liste *l1,Etu e1){
    Etu *nouveau=new Etu(e1);
    Etu *ptr=new Etu();

    ptr=l1->Premier;

    while(ptr->suivant!=nullptr){
        ptr=ptr->suivant;
    }
    ptr->suivant=nouveau;
    nouveau->suivant=nullptr;
}

void supprimerDebut(Liste *l1){
    Etu *aSuprimer=new Etu();
    aSuprimer=l1->Premier;
    l1->Premier=aSuprimer->suivant;
    aSuprimer=nullptr;
    delete(aSuprimer);
}

void supprimerFin(Liste *l1){

    Etu *aSuprimer=new Etu();
    Etu *avant=new Etu();

    avant=l1->Premier;
    aSuprimer=avant->suivant;

    while(aSuprimer->suivant!=nullptr){
        avant=aSuprimer;
        aSuprimer=avant->suivant;
    }

    avant->suivant=nullptr;
    aSuprimer=nullptr;
    delete(aSuprimer);

}

bool rechercheEtu(Liste *l1,Etu*e1){

    Etu *actuel=new Etu();

    actuel=l1->Premier;

    while (actuel->suivant != nullptr && actuel!=e1){

        actuel=actuel->suivant;
    }

    return(actuel==e1);
}
bool estEnBinome(Etu *e1){

    return (e1->binome!=nullptr && e1->binome!=e1 );
}

void Association(Etu *e1,Etu *e2){

   if(estEnBinome(e1)){
       cout<<"l'édudiant à déja un binome "<<endl;
   }
   else{
       e1->binome=e2;
   }
}



void affichageEtuBinome(Liste *l1){

    Etu *actuel=new Etu();

    actuel=l1->Premier;

    while(actuel->suivant!=nullptr){
        
        if(estEnBinome(actuel)){

            cout<<" -> "<<actuel->prenom<<" est avec : "<<actuel->binome->prenom<<endl;
            
        }else{
            cout<<" -> "<<actuel->prenom<<" est tout seul "<<endl;
        }
        actuel=actuel->suivant;
    }

}

void destructionBinome(Etu *e1){

    if(estEnBinome(e1)){

        e1->binome=nullptr;
        delete(e1->binome);
    }

}

void detruireToutBinome(Liste *l1){

    Etu *actuel=new Etu();

    actuel=l1->Premier;

    while (actuel->suivant!=nullptr){

       destructionBinome(actuel);

        actuel=actuel->suivant;

    }

}



/*void AssociationV2 (Liste *l1,Etu *e1,Etu *e2){

    destructionBinome(e2);

     Etu *actuel=new Etu();

    actuel=rechercheEtu(l1,e1);



    if(actuel!=nullptr){

        destructionBinome(actuel);

        actuel->binome=new Etu();

        actuel->binome=e2;
    }

    
   


}*/











