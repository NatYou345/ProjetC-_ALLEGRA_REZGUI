#pragma once
#pragma once
#ifndef Arbre_h
#define Arbre_h
#include"pch.h"
#include <iostream>

using namespace std;

// D�finition du noeud en tant que struct
template <typename T>
struct Noeud
{
    T donnees;
    Noeud <T>* gauche;
    Noeud <T>* droit;
};

// D�finition de la classe Liste
template <class T>
class Arbre
{
private:
    Noeud <T>* racine;
    int compteur;
    Noeud <T>* CreerNoeud(const T& valeur);
    void detruire(Noeud <T>* ptr); // Fonction d'aide
    void inserer(const T& value, Noeud <T>*& ptr); // Fonction d'aide
    void infixe(Noeud <T>* ptr) const; // Fonction d'aide
    void prefixe(Noeud <T>* ptr) const; // Fonction d'aide
    void postfixe(Noeud <T>* ptr) const; // Fonction d'aide
    Noeud <T>* successeur(Noeud <T>* ptr, Noeud <T>*& parent) const; // Fonction d'aide
    Noeud <T>* predecesseur(Noeud <T>* ptr, Noeud <T>*& parent) const; // Fonction d'aide
    void supprimer(Noeud <T>* ptr, Noeud <T>* parent); // Fonction d'aide
    Noeud <T>* recherche(const T& value, Noeud <T>* ptr, Noeud <T>*& parent) const; // Fonction d'aide

public:
    Arbre();
    ~Arbre();
    void inserer(const T& value);
    void detruire();
    void supprimer(const T& value);
    Noeud <T>* recherche(const T& value) const;
    void infixe() const;
    void prefixe() const;
    void postfixe() const;
    int taille() const;
    bool estVide() const;
};

// Constructeur
template <class T>
Arbre <T> ::Arbre() :racine(0), compteur(0) {}

// Destructeur
template <class T>
Arbre <T> :: ~Arbre()
{
    detruire(racine);
}

template <class T>
Noeud <T>* Arbre <T> ::CreerNoeud(const T& valeur) {
    Noeud <T>* temp = new Noeud <T>;
    temp->donnees = valeur;
    temp->gauche = NULL;
    temp->droit = NULL;
    return temp;
}

// Inserer un noeud
template <class T>
void Arbre <T> ::inserer(const T& valeur)
{
    inserer(valeur, racine);
    compteur++;
}



// Parcours infixe
template <class T>
void Arbre <T> ::infixe() const
{
    infixe(racine);
}

// Parcours prefixe
template <class T>
void Arbre <T> ::prefixe() const
{
    prefixe(racine);
}

// Parcours postfixe
template <class T>
void Arbre <T> ::postfixe() const
{
    postfixe(racine);
}

// Nombre de noeud dans l'arbre
template <class T>
int Arbre <T> ::taille() const
{
    return compteur;
}

template <class T>
bool Arbre <T> ::estVide() const
{
    return (compteur == 0);
}

// La fonction d'aide (R�cursive) appel�e par le destructeur
template <class T>
void Arbre <T> ::detruire(Noeud <T>* ptr)
{
    if (!ptr) { return; }

    detruire(ptr->gauche); // d�truire le sous-arbre gauche
    detruire(ptr->droit); // d�truire le sous-arbre droit
    delete ptr; // d�truire la racine
}

// LA fonction d'aide (R�cursive) appel�e par la fonction membre inserer
template <class T>
void Arbre <T> ::inserer(const T& valeur, Noeud <T>*& ptr)
{
    // si l'arbre vide, inserer comme racine
    if (!ptr) {
        ptr = CreerNoeud(valeur);
        return;
    }
    // si la valeur est inf�rieure � la valeur de racine, 
    // ins�rer le noeud dans le sous-arber gauche
    else if (valeur < ptr->donnees) {
        inserer(valeur, ptr->gauche);
    }
    // Sinon, ins�rer le noeud dans le sous-arber droit
    else {
        inserer(valeur, ptr->droit);
    }
}

// Fonction d'aide (R�cursive) appeler par la fonction infixe
template <class T>
void Arbre <T> ::infixe(Noeud <T>* ptr) const
{
    if (!ptr) { return; }

    infixe(ptr->gauche);
    cout << ptr->donnees << '\t';
    infixe(ptr->droit);
}

// Fonction d'aide (R�cursive) appeler par la fonction prefixe
template <class T>
void Arbre <T> ::prefixe(Noeud <T>* ptr) const
{
    if (!ptr) { return; }

    cout << ptr->donnees << '\t';
    prefixe(ptr->gauche);
    prefixe(ptr->droit);
}

// Fonction d'aide (R�cursive) appeler par la fonction postfixe
template <class T>
void Arbre <T> ::postfixe(Noeud <T>* ptr) const
{
    if (!ptr) { return; }

    postfixe(ptr->gauche);
    postfixe(ptr->droit);
    cout << ptr->donnees << '\t';
}

// Fonction d'aide (R�cursive) appeler par la fonction membre recherche
template <class T>
Noeud <T>* Arbre <T> ::recherche(const T& valeur, Noeud <T>* ptr, Noeud <T>*& parent) const
{
    if (!ptr) {
        //Arbre est vide
        return NULL;
    }
    else if ((ptr->donnees) == valeur) {
        // la valeur recherch�e est stock�e dans la racine
        return ptr;
    }
    else if (valeur < (ptr->donnees)) {
        parent = ptr;
        // la valeur recherch�e est dans le sous-arbre gauche
        return recherche(valeur, ptr->gauche, parent);
    }
    else {
        parent = ptr;
        // sinon, la valeur recherch�e est dans le sous-arbre droit
        return recherche(valeur, ptr->droit, parent);
    }
}

template <class T>
Noeud <T>* Arbre <T> ::successeur(Noeud <T>* ptr, Noeud <T>*& parent) const {
    if (!ptr) { return NULL; }

    Noeud <T>* courant = ptr;
    while (courant->gauche != 0) {
        parent = courant;
        courant = courant->gauche;

    }
    return courant;
}

template <class T>
Noeud <T>* Arbre <T> ::predecesseur(Noeud <T>* ptr, Noeud <T>*& parent) const {
    if (!ptr) { return NULL; }

    Noeud <T>* courant = ptr;
    while (courant->droit != 0) {
        parent = courant;
        courant = courant->droit;
    }
    return courant;
}


template <class T>
void Arbre <T> ::supprimer(const T& valeur)
{
    Noeud <T>* parent = 0;
    Noeud <T>* del = recherche(valeur, racine, parent);
    if (del == 0) {
        cout << "Le noeud n'appartient pas a l'arbre" << endl;
    }
    else {
        supprimer(del, parent);
    }
}


// Fonction d'aide (R�cursive) appeler par la fonction membre supprimer
template <class T>
void Arbre <T> ::supprimer(Noeud <T>* ptr, Noeud <T>* parent) {

    if (ptr->gauche == 0 && ptr->droit == 0)
    {
        cout << ptr->donnees << parent->donnees << endl;
        if (ptr != racine)
        {
            if (parent->gauche == ptr)
                parent->gauche = NULL;
            else
                parent->droit = NULL;
        }
        else
            racine = NULL;

        delete ptr;
    }
    else if (ptr->gauche && ptr->droit)
    {
        Noeud <T>* pere = ptr;
        // ici vous pouvez utiliser le pr�d�cesseur aussi  
        Noeud <T>* succ = successeur(ptr->droit, pere);
        int val = succ->donnees;
        supprimer(succ, pere);
        ptr->donnees = val;
    }
    else
    {
        Noeud <T>* enfant = (ptr->gauche) ? ptr->gauche : ptr->droit;
        if (ptr != racine)
        {
            if (ptr == parent->gauche)
                parent->gauche = enfant;
            else
                parent->droit = enfant;
        }

        else
            racine = enfant;

        delete ptr;
    }
}
#endif

