#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//retourne la valeur de la suite Un
//notre n de doit pas etre negatif
int trouverU(int n){

    int Un;
    if(n==0){

        Un=1;
    }

    else{
        Un=3*trouverU(n-1)-1;
    }
}

//met en sous chaine allant de d'une valeur de depart fixé à une valeur d'arrivé fixé
string sousChaine(string mot,int db,int nb){


    if(nb==0){
        return "" ;
    }

    else{

        return mot[db]+sousChaine(mot,db+1,nb-1);

    }

}

//inverse le sens d'un mot
//le mots doit au moins faire 3 lettres
string inverseMot(string mot,int db,int nb){

    if(db>mot.length()){
        return "";
    }

    else{

        return mot[nb]+inverseMot(mot,db+1,nb-1);
    }


}

//verifie si un mot est un palindrome
//verifie si un mot est un palindrome
bool palindromAux(string mot,int db,int nb){

   if(db>nb||mot.length()<=0){
     return true;
     }
   else if(mot[db]!=mot[nb]){
     return false;
     }
   else{
     return palindromAux(mot,db+1,nb-1);

     }
}
bool palindrom(string mot){
   return palindromAux(mot, 0, mot.length()-1);
}

//verifie si un mot est un palindrome
//le mots doit au moins faire 3 lettres
/*bool palindromV2(string mot){

    string mot2=inverseMot(mot,0,mot.length());

    return (mot.compare(mot2));


}*/





/*string miroire(string mot,int n){
    return inverseMot(mot,mot.length());
}*/

int main (){

    /*int n=4;
    string mot="anticonstitutionellement";

    cout<<"suite Un : "<<trouverU(n)<<endl;
    cout<<"sous chaine : "<<sousChaine(mot,0,6)<<endl;
    cout<<"inverse : "<<inverseMot(mot,0,mot.length())<<endl;*/


    //string mot2="kayak";

    //cout<<"est il un palindrome :"<<palindromV2(mot2)<<endl;

    string mot3= "lune";

   cout<<"est il un palindrome :"<<palindrom(mot3)<<endl;

}
