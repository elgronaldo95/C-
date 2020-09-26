#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Chapitre{

string titre;
string *contenu;
Chapitre *prec;
Chapitre *suiv;

};


//cree deux chapitre introduction et conclusion
//la liste les 2 chapitres ne doivent pas etre vide
Chapitre *nouveau(){

Chapitre *intro=new Chapitre();
Chapitre *conclu =new Chapitre();

if (intro==nullptr||conclu==nullptr){
    exit(EXIT_FAILURE);
}

conclu->titre="conclusion";
conclu->contenu=new string();
(*conclu->contenu)="z";
conclu->prec=intro;
conclu->suiv=nullptr;

intro->titre="debut";
intro->contenu=new string();
(*intro->contenu)="a";
intro->suiv=conclu;
intro ->prec=nullptr;


return intro;
}

//nous donne le chapitre du debut (introduction)
// le chainage ne doit pas etre null
Chapitre *trouverIntro(Chapitre*c1){

    
    if(c1->prec==nullptr){

        Chapitre *actuel=new Chapitre();

        actuel=c1;

        return actuel;

    }

    else{

        trouverIntro(c1->prec);
       
    }



}

//nous donne le chapitre de fin (conclusion)
// le chainage ne doit pas etre null
Chapitre *trouverConvlusion(Chapitre*c1){

    if(c1->suiv==nullptr){

        Chapitre *actuel=new Chapitre();

        actuel=c1;
        return actuel;

    }


    else{

        trouverIntro(c1->suiv);
       
    }

}

//retourne la taille de la liste
int tailleList(Chapitre *c1){

    Chapitre *actuel =new Chapitre();
    actuel=trouverIntro(c1);
    int i=0;

    while(actuel != nullptr){
        actuel=actuel->suiv;
        i+=1;
    }

    return i;
}

//change le contenu d'un maillion de type chapitre
void changerContenu(Chapitre *c1){
    

    cout<<"entrez nouveau titre " <<endl;
    cin>>(c1->titre);

    cout<<"entrez description "<<endl;
    cin>>(*c1->contenu);

    
}

//affiche le contenu chainage de l'introduction à la conclusion
// le chainage ne doit pas etre null
void sommaire(Chapitre *c1){

    Chapitre *actuel=new Chapitre();

    actuel=trouverIntro(c1);

    while (actuel !=nullptr){
    
    printf("%d -> ",actuel,actuel->suiv);
    
    actuel=actuel->suiv;

    }

    printf("nullptr\n");

    

}

//affiche le contenu chainage de la conclusion à l'introduction
// le chainage ne doit pas etre null
void sommaireV2(Chapitre *c1){
    
    Chapitre *actuel=new Chapitre();
    actuel=trouverConvlusion(c1);
    printf("nullptr");
    while (actuel !=nullptr){
    
    printf("<- %d   ",actuel,actuel->prec);
    
    actuel=actuel->prec;

    }

    printf("\n");
    
}
//change le contenu chainage de l'introduction à la conclusion
// le chainage ne doit pas etre null
void metsContenu(Chapitre *c1){

    Chapitre *actuel=new Chapitre();

    actuel=trouverIntro(c1);

    while (actuel !=nullptr){

    changerContenu(actuel);
    actuel=actuel->suiv;
        
    }
    
    
}
//change le contenu chainage de la conclusion à l'introduction
// le chainage ne doit pas etre null
void metsContenuV2(Chapitre *c1){

    Chapitre *actuel=new Chapitre();
    actuel=trouverConvlusion(c1);

    while (actuel !=nullptr){

    changerContenu(actuel);
    actuel=actuel->prec;
        
    }
    
    
}

//ajoute un mailion de type Chapitre dans le contenu chainage de l'introduction à la conclusion
// le chainage ne doit pas etre null et chaque maillion doit etre remplis
void ajouterChapitre(Chapitre *c1,string mot,string description,int pos){

    Chapitre *avant=new Chapitre();
    avant=trouverIntro(c1);

    Chapitre *actuel=new Chapitre();
    actuel=avant->suiv;
    Chapitre *nouveau = new Chapitre();

    int i=0;

    while (i<pos && actuel!=nullptr){

    avant=actuel;
    actuel=actuel->suiv;
    i+=1;

    }

    if(avant!=nullptr){

    nouveau->titre=mot;
    nouveau->contenu=new string();
    (*nouveau->contenu)=description;
    avant->suiv=nouveau;
    actuel->prec=nouveau;
    nouveau->prec=avant;
    nouveau->suiv=actuel;
        

    }

    else{
     printf("non trouver");
    }
    
}

//ajoute un mailion de type Chapitre dans le contenu chainage de la conclusion à l'introduction
// le chainage ne doit pas etre null et chaque maillion doit etre remplis
void ajouterChapitreV2(Chapitre *c1,string mot,string description,int pos){

    Chapitre *avant=new Chapitre();
    avant=trouverConvlusion(c1);

    Chapitre *actuel=new Chapitre();
    actuel=avant->prec;
    Chapitre *nouveau = new Chapitre();

    int i=tailleList(c1);


    while (i>pos && actuel!=nullptr){

    avant=actuel;
    actuel=actuel->prec;
    i-=1;

    }

     if(avant!=nullptr){

        nouveau->titre=mot;
        nouveau->contenu=new string();
        (*nouveau->contenu)=description;
        avant->prec=nouveau;
        actuel->suiv=nouveau;
        nouveau->prec=actuel;
        nouveau->suiv=avant;
     }

     else{
     printf("non trouver");
    }


}

//supprime un mailion de type Chapitre dans le contenu chainage de l'introduction à la conclusion
// le chainage ne doit pas etre null et chaque maillion doit etre remplis
void supressionChapitre(Chapitre *c1,string mot){

    Chapitre *avant=new Chapitre();
    avant=trouverIntro(c1);

    Chapitre *actuel=new Chapitre();
    actuel=avant->suiv;

    Chapitre *apres=new Chapitre();
    apres=actuel->suiv;

    while (actuel->titre !=mot && apres!=nullptr){

        avant=actuel;
        actuel=apres;
        apres=apres->suiv;

    }

    if(actuel !=nullptr){
        avant->suiv=apres;
        apres->prec=avant;
        free(actuel);
    }

    else{
        printf("non trouver");
    }
 
}

//supprime un mailion de type Chapitre dans le contenu chainage de la conclusion à l'introduction
// le chainage ne doit pas etre null et chaque maillion doit etre remplis
void supressionChapitreV2(Chapitre *c1,string mot){

     Chapitre *avant=new Chapitre();
    avant=trouverConvlusion(c1);

    Chapitre *actuel=new Chapitre();
    actuel=avant->prec;

    Chapitre *apres=new Chapitre();
    apres=actuel->prec;

    while (actuel->titre !=mot && apres!=nullptr){

        avant=actuel;
        actuel=apres;
        apres=apres->prec;

    }

    if(actuel !=nullptr){
        avant->prec=apres;
        apres->suiv=avant;
        free(actuel);
    }

    else{
        printf("non trouver");
    }


}

int main (int argc, char *argv[]){

Chapitre *c1;
c1=nouveau();
sommaire(c1);
//sommaireV2(c1);
ajouterChapitre(c1,"b","bb",0);
//ajouterChapitreV2(c1,"c","cc",1);
sommaire(c1);
//sommaireV2(c1);
supressionChapitre(c1,"b");
sommaire(c1);
//sommaireV2(c1);
//supressionChapitreV2(c1,"c");
//sommaire(c1);
//sommaireV2(c1);
delete(c1);


}
