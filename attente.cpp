#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


//un objet en reparation qui est caracteriserpar don id
struct Repa{
    string idDossier;
    Repa *suiv;
};

//maillion de depart
struct List{
    Repa *premier;
};

//construit un nouveau chainage
//la list et notre premier element ne doivent pas etre vide
List *initialisation(){
 
    List *pList = new List();// (List*) malloc(sizeof(List));
     
    Repa *pRepa = new Repa(); // (Repa*) malloc(sizeof(Repa));
      

    if (pList==nullptr||pRepa==nullptr){
        exit(EXIT_FAILURE);
    }
    
    pRepa->idDossier="rouge";
   
    pRepa->suiv=nullptr;
     
    pList->premier=pRepa;
      

    return pList;
}

string TrouverIdD(List*l1){
return l1->premier->idDossier;
}

//afiche le contenue du chainage
//le chainage ne doit pas etre vide
void AffichageList (List *l1){

    if(l1 ==nullptr){
        exit(EXIT_FAILURE);
    }

    Repa *actuel=l1->premier;//question a poser

    while(actuel !=nullptr){
        printf("%d -> ", actuel->idDossier);//question a poser
        actuel=actuel->suiv;
    }

    printf("nullptr\n");//question à poser
}
//ajoute un element Repa au debut du chainage
//chainage ne doit pas etre vide
void AjouterTete (List *l1,string mot){
    Repa *nouveau = new Repa();//(Repa* )malloc(sizeof(*nouveau));

    if (l1==nullptr || nouveau==nullptr){
        exit(EXIT_FAILURE);
    }

    nouveau->idDossier=mot;
    nouveau->suiv=l1->premier;
    l1->premier=nouveau;
  
}
//supprime le premier element du chainage
//le chainage ne doit pas etre vide
void RetirerTete(List *l1){
    
    if(l1 ==nullptr){
        exit(EXIT_FAILURE);
    }
   
    if(l1->premier !=nullptr){
        Repa *aSuprimer=l1->premier;//question a poser
        l1->premier= l1->premier->suiv;
        free(aSuprimer);

    }
}

//ajoute un element Repa en fin de chainage
//le chainage ne doit pas etre vide
void AjouterQueu (List *l1,string mot){

    Repa *nouveau = new Repa(); //(Repa* ) malloc(sizeof(*nouveau));

    if(l1==nullptr || nouveau==nullptr){
        exit(EXIT_FAILURE);
    }
    nouveau->idDossier=mot;
    nouveau->suiv=nullptr;
    Repa *actuel=l1->premier;

    while(actuel !=nullptr){
        actuel=actuel->suiv;
    }

}

//ici en cherche a inserer par le nom du dernier maillion demandé 

void insertion (List *l1,string mot1,string mot2){
    Repa *nouveau =new Repa();
    Repa *ptr=nullptr;
    Repa *avant=nullptr;

    if(l1->premier->suiv !=nullptr && l1->premier->idDossier !=mot1){
        avant=l1->premier;
        ptr=avant->suiv;

        while (ptr->idDossier!=mot1 && ptr!=nullptr){
            avant=ptr;
            ptr=ptr->suiv;
        }

        if(ptr !=nullptr){
            nouveau->idDossier=mot2;
            avant->suiv=nouveau;
            nouveau->suiv=ptr;
        }

        else{
            printf("non trouvé");
        }
    }
    else{
        AjouterTete (l1,mot2);
    }

}
//insertion a une position
void insertionV2 (List *l1,string mot,int pos){
    Repa *nouveau =new Repa();
    Repa *ptr=nullptr;
    Repa *avant=nullptr;
    int i=0;

    if(l1->premier->suiv !=nullptr && i<pos){
        avant=l1->premier;
        ptr=avant->suiv;

        while (i<pos && ptr!=nullptr){
            avant=ptr;
            ptr=ptr->suiv;
            i+=1;
        }

        if(ptr !=nullptr){
            nouveau->idDossier=mot;
            avant->suiv=nouveau;
            nouveau->suiv=ptr;
        }

        else{
            printf("non trouvé");
        }
    }
    else{
        AjouterTete (l1,mot);
    }

}

//supprime un elements choisis par le mots
//le chainage ne doit pas etre vide
void Suprimer(List *l1,string mot){
    
    Repa *ptr=nullptr;
    Repa *avant=nullptr;

    if (l1->premier->suiv!=nullptr && l1->premier->idDossier != mot){
        avant=l1->premier;
        ptr=avant->suiv;

        while (ptr->idDossier!=mot && ptr!=nullptr){
        avant=ptr;
        ptr=ptr->suiv;
        }

        if(ptr!=nullptr){

            avant->suiv=ptr->suiv;
            free(ptr);
        }

        else{
            printf("element non trouvé");
        }

    }

    else{
        RetirerTete(l1);
    }
    
   
}

void retirerQueu(List *l1){
    Repa *ptr=nullptr;
    Repa *avant=nullptr;

    if(l1->premier->suiv!=nullptr){
        avant=l1->premier;
        ptr=avant->suiv;

        while(ptr->suiv=nullptr){
            avant=ptr;
            ptr=ptr->suiv; 
        }

        if(ptr !=nullptr){
            avant->suiv=avant->suiv->suiv;
            free(ptr);

        }
       


    }
}

void retarder(List *l1){
    
    Repa *aRetarder=new Repa();
    Repa *suivant=new Repa();
    Repa *temp=new Repa();

    aRetarder=l1->premier;
    suivant=aRetarder->suiv;

    temp=aRetarder;
    aRetarder=suivant;
    suivant=temp;
}



int main (int argc, char *argv[]){

List *l1;
//Repa r1,r2,r3;

l1=initialisation();
AjouterTete (l1,"rouge");
insertion (l1,"rouge","bleu");
insertionV2 (l1,"vert",1);
AffichageList (l1);
RetirerTete(l1);
AffichageList (l1);
string idDebut=TrouverIdD(l1);
cout<<"notre id au debut "<<endl;
cout<<idDebut<<endl;
retarder(l1,"rouge");
AffichageList (l1);
Suprimer(l1,"vert");
AffichageList (l1);
retirerQueu(l1);
AffichageList (l1);

free(l1);

}