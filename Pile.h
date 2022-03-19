#include <stdlib.h>
#include "SuiteCh1.h"

using namespace std;
template <class T> class Pile;
template <class T>

class Pile : public SuiteCh1<T> {

public:

    //Constructeur de la classe

    Pile()
    {
        pPremier = NULL;
        pDernier = NULL;
        NbreElements = 0;
    }

    int AjoutPile(const T & d); // Ajout dans la pile
    int SuppressionPile(); // Suppression dans la pile
    void afficherPile();
    void afficherSommetPile();
   
    int NbreElements; // Connaître la taille de la pile

public:
    ElementCh1<T>* pPremier;
    ElementCh1<T>* pDernier;

private:

    SuiteCh1<T> donnees;
    Pile(const Pile &);
    Pile & operator = (const Pile &);

};

template <class T>
int Pile<T>::AjoutPile(const T& d)
{
        ElementCh1<T> * NouvElement = new ElementCh1<T>(d);
		NouvElement->suivant = pPremier;
		pPremier = NouvElement;
		NbreElements++;

		if (pDernier == NULL) {
			pDernier = NouvElement;
		}
		
		return 1;
    
}

template <class T>
int Pile<T>::SuppressionPile()
{
    if (NbreElements > 0)
		{
			ElementCh1<T>* aEffacer = pPremier;
			pPremier = pPremier->suivant;
			delete aEffacer;
		}
    return 1;
}

template <class T>
void Pile <T> ::afficherPile()
{
    ElementCh1<T>* p = pPremier;
    while (p != NULL)
    {
        cout << p->donnee << endl;
        p = p->suivant;
    }
}

template <class T>
void Pile <T> ::afficherSommetPile() 
{
    if (pPremier != NULL) 
    {
        cout << "Pile non vide" << endl;
        cout << pPremier->donnee << endl;
    }
    else 
    {
        cout << "Pile vide !" << endl;
    }
}

