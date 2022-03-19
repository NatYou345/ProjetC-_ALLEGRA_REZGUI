#include <Windows.h>

#include "pch.h"
#include "SuiteCh1.h"
#include "ElementCh1.h"
#include "Pile.h"
#include "File.h"
#include "Arbre.h"
#include "ClasseUML.h"





int main()
{
	/*
	//Partie Listes
	SuiteCh1<string>* liste = new SuiteCh1 <string>();
	liste->ajoutDebut("6.3");
	liste->ajoutFin("oui");
	liste->ajoutPosition("2", 2);
	liste->ajoutDebut("10");
	liste->ajoutFin("100");
	liste->afficherListe();



	// Partie Piles
	Pile<string>* pile = new Pile <string>();
	pile->AjoutPile("IP");
	pile->SuppressionPile();
	pile->AjoutPile("EL");
	pile->AjoutPile("mv1");
	pile->AjoutPile("LH44");
	pile->AjoutPile("KM7");
	pile->SuppressionPile();
	pile->afficherPile();



	// Partie Files
	File<string>* file = new File <string>();
	file->AjoutFile("ElementFile");
	file->AjoutFile("ElementFile2");
	file->AjoutFile("ElementFile3");
	file->SuppressionFile();
	file->afficherFile();


	// Partie Arbres
	Arbre <int> arbre;
	arbre.inserer(40);
	arbre.inserer(50);
	arbre.inserer(14);
	arbre.inserer(16);
	arbre.inserer(5);
	arbre.inserer(3);
	arbre.inserer(7);
	arbre.inserer(55);
	arbre.inserer(45);

	cout << '\n';
	cout << "Le parcours infixe de cet arbre est : "<< endl;
	arbre.infixe();
	cout << '\n';

	cout << '\n';
	cout << "Le parcours postfixe de cet arbre est : "<< endl;
	arbre.postfixe();
	cout << '\n';

	cout << '\n';
	cout << "Le parcours prefixe de cet arbre est : "<< endl;
	arbre.prefixe();
	cout << '\n';

	cout << '\n';


	arbre.supprimer(3);
	cout << '\n';
	cout << "Le parcours infixe de l'arbre apres la suppression de 3 devient : "<< endl;
	arbre.infixe();

	arbre.supprimer(40);
	cout << '\n';
	cout << "Le parcours infixe de l'arbre apres la suppression 40 devient : "<< endl;
	arbre.infixe();
	*/
	cout << "-----------------------------------------------------------------------------------------------------------------"<< endl;
	ClasseUML * classeTest = new ClasseUML();

	char visibiliteUML;
	int nbreAttributs;

	cout << "Ce programme permet de créer le squelette du code C++ à partir d'une création de classe UML." << endl;
	Sleep(2000);
	cout << "Pour cela, plusieurs informations sont nécessaires" << endl;
	Sleep(2000);
	cout << "Saisissez le nom de votre classe : "<< endl;
	cin >> visibiliteUML;
	cout << "Combien d'attributs souhaitez-vous dans votre classe ? " << endl;
	cin >> nbreAttributs;

}