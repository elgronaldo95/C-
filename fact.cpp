/* fact - Chantal Enguehard et Christophe Jermann
DATE : 8 février 2018
ROLE : Calcul et affichage de la factorielle d'un nombre saisi par l'utilisateur.
*/

#include <iostream>
#include <cassert>

using namespace std;

//---------------------------------------------
// Rôle : retourne nb!
unsigned int factorielle(unsigned int nb) // nb et nb! entiers positifs --> unsigned int
{
    // lexique
    unsigned int i, fact;
    // début
    fact = 1;
    for (i=2; i <= nb; i++)
    {
        fact = fact*i;
    }
    return fact;
    // fin
}

//---------------------------------------------------------
// Programme principal
int main()
{
    // lexique
    int nombre;
    // début
    cout << "Donner un nombre entier entre 1 et 11 : ";
    cin >> nombre;
    assert(1 <= nombre and nombre <= 11); // validation de la saisie
    cout << nombre << "! = " << factorielle(nombre) << endl;
    return 0;
	// fin
}
