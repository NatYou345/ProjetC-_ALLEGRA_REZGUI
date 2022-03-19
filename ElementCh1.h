#pragma once

template <class T> class SuiteCh1;
template <class T>

class ElementCh1
{
	friend class SuiteCh1<T>;
	
public :
	T donnee;
	ElementCh1<T> * suivant;

	ElementCh1(const T & d) //Constructeur 1
	{
		donnee = d;
		suivant = NULL;
	}

	ElementCh1(const T & d, ElementCh1<T> * s) // Constructeur 2
	{
		donnee = d;
		suivant = s;
	}

};