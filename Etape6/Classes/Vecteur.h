#ifndef VECTEUR_H
#define VECTEUR_H
#include <iostream>
using namespace std;
#include "Client.h"


template<class T > class Iterateur; 

template<class T > class Vecteur
{
	protected:
		T *v;
		int _sizeMax; // taille max du vecteur 
		int _size; // nombre d'element dans le vecteur

		

	public:
		Vecteur();// defaut
		Vecteur(int);//init
		Vecteur(const Vecteur& );
		~Vecteur();//des copie	
		


		/**METHODEPUBLIC****/

		void Affiche() const;

		int size()const;
		int sizeMax()const;
		void insere(const T& val);
		 T retire(int ind);


		/*SURCHAGE OPERATOR**/

		Vecteur<T>& operator=(const Vecteur&);
		const T & operator[](int) const ;




		friend class Iterateur<T>;



}; 










#endif