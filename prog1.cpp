#include <iostream>   		// pour pouvoir utiliser cin, cout, endl
#include <cmath>
using namespace std;


double TrouverF(double x){

    double f;

    if(x<-1){

        f=pow(x,2)-1;
    }

    else if (x>1){

        f=sqrt(x-1);
    }

    else{
        f=0;
    }

    return f;

}

string sousChaine(string mot,int deb,int nb){

    string mot2;

    mot2="";

    for(int i=deb;i<=nb;i++){

        mot2 += mot[i];

    }

    return mot2;

}


void Scind(string mot,int gauche,int droite){

    string part1,part2,part3;

    part1="";
    part2="";
    part3="";

    for(int i=0;i<=gauche;i++){
    part1 +=mot[i];

    }

    cout<<"partie1 "<< part1<<endl;

    for(int i=gauche +1 ;i<=droite ;i++){
    part2 +=mot[i];

    }

    cout<<"partie2 "<< part2<<endl;

    for(int i=droite +1 ;i<=mot.length() ;i++){
    part3 +=mot[i];

    }

    cout<<"partie3 "<< part3<<endl;

}

double SuiteUn(double n){

    double Un;

    if (n<=0){
    Un=1;
    }
    else{
    Un =3*(n-1)-1;
    }


}


string Inverse(string mot){
    string mot2="";
    for(int i=mot.length()-1;i>=0;i--){

       mot2+=mot[i];

    }

    return mot2;

}



bool estPalindrome(string mot){
    string mot2;
    mot2=Inverse(mot);

return (mot.compare(mot2));



}

void Frequence (string mot){


char Cmax='\0';//le charactere qui revient le plus
int Imax=0;//represente le nombre de fois ou il apparait

int n=mot.length();

    for (int i=0;i<n;i=i+1){//on regarde chaque lettre du mot

    char c=mot[i];

    int j=0;

    int compteur =0;

    //on prend une lettre et ensuite on parcour tout le mot pour compter le nombre de fois quand cette letre reaparait

        while (j<= mot.length()){

        if(mot[j]==c){

        compteur+=1;

        }

        j+=1;



        }

        //on verifie si cette lettre apparait plus de fois que la lettre precedente si c'est le cas c'est elle qui devient la lettre la plus utilisé
        if(compteur >Imax){
        Imax=compteur;
        Cmax=c;
        }


    }

    cout<< "la lettre la plus frequent est : " <<Cmax<< " et il apparait : "<<Imax<< " fois" <<endl;



}





int main(){




string mot="anticonstitutionellement";
Frequence (mot);


/*double x;
cout<<"entrer x "<<endl;
cin>>x;

cout<< "F(x) = " << TrouverF(x)<<endl;
cout<< "Un = " << SuiteUn(x)<<endl;

string mot;
cout <<"entrer mot"<<endl;
cin>>mot;

int deb=0;
int fin=mot.length();


cout<<"en sous chaine " << sousChaine(mot,deb,fin)<<endl;
cout<<"en inverse " << Inverse(mot)<<endl;
cout<<estPalindrome(mot)<<endl;



int gauche=2;
int droite=4;

Scind(mot,gauche,droite);*/








}
