#pragma once
#include <stdlib.h>
#include "SuiteCh1.h"

using namespace std;
template <class T> class File;
template <class T>

class File : public SuiteCh1<T> {

public:

    //Constructeur de la classe

    File()
    {
        pPremier = NULL;
        pDernier = NULL;
        NbreElements = 0;
    }

    int AjoutFile(const T& element); // Ajout dans la File
    int SuppressionFile(); // Suppression dans la File
    void afficherFile();
    void afficherSommetFile();
    
    int NbreElements; // Connaître la taille de la File

public:
    ElementCh1<T>* pPremier;
    ElementCh1<T>* pDernier;

private:

    SuiteCh1<T> donnees;
    File(const File&);
    File& operator = (const File&);

};

template <class T>
int File<T>::AjoutFile(const T& d)
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
int File<T>::SuppressionFile()
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
void File <T> ::afficherFile()
{
    ElementCh1<T>* p = pPremier;
    while (p != NULL)
    {
        cout << p->donnee << endl;
        p = p->suivant;
    }
}

template <class T>
void File <T> ::afficherSommetFile()
{
    if (pPremier != NULL)
    {
        cout << pPremier->donnee << endl;
    }
    else
    {
        cout << "File vide !" << endl;
    }
}


