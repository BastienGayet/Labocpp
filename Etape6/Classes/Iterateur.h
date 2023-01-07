#ifndef ITERATEUR_H
#define ITERATEUR_H
#include <iostream>
using namespace std;
#include "Vecteur.h"
#include "Client.h"





template<class T> class Iterateur
{
	private:
		Vecteur <T> &p; // pointeur vers l'objet 
		T* pdata;

	public:
		
		Iterateur(Vecteur<T> &);
		~Iterateur(); // destructeur




	/***METHODEPUBLIC***/

		void reset();
		bool end() const;



	/*SURCHARGE DES OPERATEUR***/
		
	  bool operator++();
	  bool operator++(int);

	  operator T() ;


};





#endif