#pragma once

#include <stdio.h>
#include "pch.h"
#include "File.h"

class ClasseUML
{
public : 
	// Définition de variables
	ElementCh1<string>* pPremier;
	ElementCh1<File<string>>* pDernier;

	ElementCh1<File<string>>* pFile;

	string nomClasse;
	File<File<string>> ListeAttributs;
	File<string> attribut;
	File<File<string>> ListeMethodes;
	File<string> methode;

	ClasseUML() 
	{
		pPremier = NULL;
		pDernier = NULL;
	}

	int AjoutNomClasse(string nomClasse) 
	{
		ElementCh1<string>* NouvElement = new ElementCh1(nomClasse);
		NouvElement->suivant = pPremier;
		pPremier = NouvElement;

		return 1;
	}

	int AjoutAttribut(string visibilite, string nomAttribut, string type) 
	{
		ElementCh1<string>* NouvElement1 = new ElementCh1(visibilite);
		NouvElement1->suivant = pPremier;
		pPremier = NouvElement1;
		return 1;

		ElementCh1<string>* NouvElement2 = new ElementCh1(nomAttribut);
		NouvElement2->suivant = pPremier;
		pPremier = NouvElement2;
		return 1;

		ElementCh1<string>* NouvElement3 = new ElementCh1(type);
		NouvElement3->suivant = pPremier;
		pPremier = NouvElement3;
		return 1;
		
	}

	int AjoutMethode(string visibilite, string nomMethode, File<string>typesEntree, string typeSortie) 
	{
		ElementCh1<string>* NouvElement1 = new ElementCh1(visibilite);
		NouvElement1->suivant = pPremier;
		pPremier = NouvElement1;
		return 1;

		ElementCh1<string>* NouvElement2 = new ElementCh1(nomMethode);
		NouvElement2->suivant = pPremier;
		pPremier = NouvElement2;
		return 1;

		ElementCh1<File<string>>* NouvElement3 = new ElementCh1<File<string>>(typesEntree);
		NouvElement3->suivant = pFile;
		pFile = NouvElement3;
		return 1;

		ElementCh1<string>* NouvElement4 = new ElementCh1(typeSortie);
		NouvElement4->suivant = pPremier;
		pPremier = NouvElement4;
		return 1;
	}

	string TraductionVisibilite(char visibilite) 
	{
		string visibiliteClasse;
		switch(visibilite) 
		{
			case ' + ' :
				visibiliteClasse = "public";
			case ' - ':
				visibiliteClasse = "private";
			case ' # ':
				visibiliteClasse = "protected";
		}

		return visibiliteClasse;
	}

};

