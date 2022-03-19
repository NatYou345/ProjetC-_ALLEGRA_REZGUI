#pragma once
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "ElementCh1.h"

using namespace std;
template <class T> class SuiteCh1;
template <class T>

class SuiteCh1
{ 

public: 

	  SuiteCh1();
	  int ajoutDebut(const T & d);
	  int ajoutFin(const T & d);
	  int ajoutPosition(const T & d, int pos);
	  void supprimerDebut();
	  void supprimerFin();
	  void supprimerPosition(int pos);
	  void afficherListe();
	  


	  int NbreElements = 0;

	  SuiteCh1 operator = (const SuiteCh1&);
public :	
	ElementCh1<T> * pPremier;
	ElementCh1<T> * pDernier;
};

	template <class T>
	SuiteCh1<T> :: SuiteCh1()
	{
		pPremier = NULL;
		pDernier = NULL;
		NbreElements = 0;
	}

	template <class T>
	int SuiteCh1 <T> :: ajoutDebut(const T & d)
	{
		//cout << "Ajout début" << endl;
		ElementCh1<T> * NouvElement = new ElementCh1<T>(d);
		NouvElement->suivant = pPremier;
		pPremier = NouvElement;
		NbreElements++;

		if (pDernier == NULL) {
			pDernier = NouvElement;
		}
		//cout << pPremier->donnee << endl;
		return 1;
	}

	template <class T>
	int SuiteCh1 <T> :: ajoutFin(const T & d)
	{
		ElementCh1<T>* NouvElement = new ElementCh1<T>(d);
		NbreElements++;
		if (pDernier != NULL) 
		{
			pDernier->suivant = NouvElement;
			pDernier = NouvElement;
		}
		else 
		{
			pPremier = NouvElement;
			pDernier = NouvElement;
		}
		return 1;
	}

	template <class T>
	int SuiteCh1 <T> :: ajoutPosition(const T & d, int pos)
	{
		if (pos > NbreElements) 
		{
			ajoutFin(d);
		}
		else if (pos <= 1) 
		{
			ajoutDebut(d);
		}
		else 
		{
			int i;
			ElementCh1<T>* p = pPremier;
			ElementCh1<T>* NouvElement = new ElementCh1<T>(d);
			for (i = 1; i < pos-1; i++) 
			{
				p = p->suivant;
			}
			NouvElement->suivant = p->suivant;
			p->suivant = NouvElement;
			NbreElements++;
		}
		return 1;
	}

	
	template<class T>
	void SuiteCh1<T> ::supprimerDebut()
	{
		if (NbreElements > 0)
		{
			ElementCh1<T>* aEffacer = pPremier;
			pPremier = pPremier->suivant;
			delete aEffacer;
		}
	}

	template<class T>
	void SuiteCh1<T> ::supprimerFin()
	{
		int i;
		if (NbreElements > 0)
		{
			if (NbreElements =  1) 
			{
				delete pPremier;
				pPremier = pDernier = NULL;
			}
			else 
			{
				ElementCh1<T>* pParcours = pPremier;
				for (i = 1; i < NbreElements - 1; i++)
				{
					pParcours = pParcours->suivant;
				}
				pParcours->suivant = NULL;
				delete pDernier;
				pDernier = pParcours;
			}
		}
	}

	template<class T>
	void SuiteCh1<T> ::supprimerPosition(int pos)
	{
		int i;
		if (pos > NbreElements) 
		{
			pos = NbreElements;
		}
			else if (pos <= 0)
			{
				pos = 1;
			}

		if (pos == 1) 
		{
			supprimerDebut();
		}

		if (NbreElements > 0)
		{
			ElementCh1<T>* pParcours = pPremier;
			for (i = 1; i < pos -1; i++)
			{
				pParcours = pParcours->suivant;
			}
			ElementCh1<T>* pcs = pParcours->suivant;
			pParcours->suivant = pcs->suivant;
			delete pcs;
		}
	}


	template <class T>
	void SuiteCh1 <T> :: afficherListe()
	{
		ElementCh1<T>* p = pPremier;
		while (p != NULL) 
		{
			cout << p->donnee << endl;
			p = p->suivant;
		}
	}


	template<class T>
	SuiteCh1<T> SuiteCh1<T> :: operator = (const SuiteCh1 & source)
	{
		if (this != &source) 
		{
		
			ElementCh1<T>* lecteur = source.pPremier;
			while (lecteur != NULL) 
			{
				assert(ajoutFin(lecteur->donnee));
				lecteur = lecteur->suivant;
			}
		}
		return *this;
	}
	