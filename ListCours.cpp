#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;


struct Article {
    string nom;
    float prix;
    string description;
};


void AfficherArticle (Article a1){
    cout<<"le nom "<<endl;
    cout<< a1.nom<<endl;
    cout<<"le prix "<<endl;
    cout<< a1.prix<<endl;;
    cout<<"la description "<<endl;
    cout<<a1.description<<endl;
}

void AfficherList(vector <Article> list){
    for (int i=0;i<=list.size();i++){
        int j=0;
        cout<< "article numero " << j <<endl;
        AfficherArticle (list[i]);
        j+=1;
    }
}

void AjouterArticle (vector <Article>& list,Article a1){
   
   list.push_back(a1);

}

void RetirerArticle  (vector <Article>& list,string nomRecherche){
    int i=0;
    while (i<=list.size()){
        if(list[i].nom==nomRecherche){
          for (int j=i;i<=list.size();i++){
               if(j+1<=list.size()){
                    list[j]=list[j+1];
               }
               
           }
           list.pop_back();

        }
        i+=1;
    }

}




int main (int argc, char *argv[]){
    Article a1,a2,a3;

    a1={"a",0,"aa"};
    a2={"b",0,"bb"};
    a3={"c",0,"cc"};

    
    vector<Article> list;

    AjouterArticle(list,a1);
    AjouterArticle(list,a2);
    AjouterArticle(list,a2);
    AfficherList(list);
    RetirerArticle (list,"c");
    AfficherList(list);





    
}
