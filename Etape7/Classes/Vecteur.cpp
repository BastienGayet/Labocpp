#include <iostream>  
#include <string.h> 
using namespace std; 
#include "Vecteur.h"





/**CONSTRCUTEUR ET DESTRUCTEUR *****/


template <class T> Vecteur<T>::Vecteur()
{
	#ifdef DEBUG
    cout<<"Constructeur par defaut de Vecteur "<<endl;
    #endif

    v = new T[10];

    _sizeMax=10;
    
    
    _size=0;
}

template <class T> Vecteur<T>::Vecteur(int n)
{
	#ifdef DEBUG
    cout<<"Constructeur par init de Vecteur "<<endl;
    #endif


    _sizeMax=n;
   v=  new T[n];
    _size=0;

}

template <class T> Vecteur<T>::Vecteur(const Vecteur &source)
{

	#ifdef DEBUG
    cout<<"Constructeur de copie de Vecteur "<<endl;
    #endif


    _sizeMax=source._sizeMax;

    _size=source._size;

    v = new T[_sizeMax];

    for(int i=0;i<_size;i++)
    {
    	v[i]=source.v[i];
    }	



}
template <class T> Vecteur<T>::~Vecteur()
{

	#ifdef DEBUG
    cout<<"Destructeur de copie de Vecteur "<<endl;
    #endif

    if(v!=NULL)
		delete[] v ;

}



/****METHODE PUBLIC****************/



template <class T>  int Vecteur<T>::size()const
{
	return _size;
}


template <class T>  int Vecteur<T>::sizeMax()const
{
	return _sizeMax;
}


template <class T>  void Vecteur<T>::Affiche() const 
{

	for(int i=0; i<size();i++)
	{
		 cout<<v[i]<<";";
	}
}


template<class T> void Vecteur<T>::insere(const T& val)
{
		
		v[size()]=val;

		_size++;
	
}

template<class T> T Vecteur<T>::retire( int ind)
{
	T temp=v[ind];

	for(int i=ind;i<size()-1;i++)
	{
		v[i]=v[i+1];
	}

	_size--;

	return temp;
}

/**********SURCHARGE OPERATOR**************/

template <class T>  Vecteur<T>& Vecteur<T>::operator=(const Vecteur & source) 
{


	_sizeMax=source._sizeMax;
	_size=source._size;
	if(v)
		delete[] v;
	
	 v = new T[_sizeMax];

    for(int i=0;i<_size;i++)
    {
    	v[i]=source.v[i];
    }	


	return(*this);
	
}


template <class T>  const T & Vecteur<T>::operator[](int i) const
{
	return (v[i]); 

} 


template class Vecteur<int>;
template class Vecteur<Client>;
