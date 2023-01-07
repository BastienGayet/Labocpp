#include <iostream>  
#include <string.h> 
using namespace std; 
#include "Iterateur.h"
#include "Vecteur.h"




/*CONSTRUCTEUR ET DESTRUCTEUR*/




template <class T> Iterateur<T>::Iterateur( Vecteur<T>& source): p(source), pdata(source.v) 
{
	#ifdef DEBUG
    cout<<"Constructeur de copie de Iterateur "<<endl;
    #endif


};

template <class T> Iterateur<T>::~Iterateur()
{
	#ifdef DEBUG
    cout<<"Destructeur  de Iterateur "<<endl;
    #endif
};




/***METHODE PUBLIC*****/

template <class T> void Iterateur<T>::reset()
{
	pdata=p.v;
}


template <class T> bool Iterateur<T>::end() const
{
	if(pdata - p.v >= p.size())
		return true;
	else
		return false;
		
}


/***SURCHARGE DES OPERATEURS******/

template <class T>  bool Iterateur <T>::operator++()
{
	if(!end())
	{
		pdata ++;
		return true;

	}
	else
		return false;
}

template <class T>  bool Iterateur <T>::operator++(int)
{
	return operator++();
}


template <class T>   Iterateur <T>::operator T() 
{
	return *pdata;
}


template class Iterateur<int>;
template class Iterateur<Client>;
template class Iterateur<Employe>;