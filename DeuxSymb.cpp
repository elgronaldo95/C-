#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>



using namespace std;


struct deuxSymb{
    char symb;
   char *pchar;
};



  void RemplireDeuxsymb(deuxSymb &s1){//l'utilisateur rempli les les attributs de deuxsymb

    cout<<" saissisez symb";

    cin>>s1.symb;

    cout<<" saisissez la valeur du pointeur ";
    s1.pchar=new(char);
    cin>>*(s1.pchar);

}

void Permutation(deuxSymb &s1){//echange le conteneu de deuxSymb 
char temp;

temp=s1.symb;

s1.symb=*(s1.pchar);

*(s1.pchar)= temp;
}

void AfiicherDeuxsymb(deuxSymb s1){

  cout<<s1.symb<<endl;

  cout<<*(s1.pchar)<<endl;
}

 deuxSymb CopieDeuxsymb(deuxSymb s1){//copie les attribut d'un deuxsymb sur un autre deuxsymb

    deuxSymb s2;

    s2.symb=s1.symb;
  s2.pchar=new(char);
  *(s2.pchar)=*(s1.pchar);

return s2;

}

int main (int argc, char *argv[]){

deuxSymb s1,s2;

s1= {'\0',nullptr};
s2= {'\0',nullptr};

RemplireDeuxsymb(s1);
cout<<" s1"<<endl;
AfiicherDeuxsymb(s1);

Permutation(s1);
cout<<" s1 apres permutation "<<endl;
AfiicherDeuxsymb(s1);

s2=CopieDeuxsymb(s1);
cout<<"s2"<<endl;
AfiicherDeuxsymb(s2);

free (s1.pchar);
}