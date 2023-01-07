#ifndef VOITURE_H
#define VOITURE_H

#include <iostream>
#include <string>
#include <string.h>

#include "Modele.h" // on include que dans le .h
#include "Option.h"

using namespace std;


class Voiture
{
	private:

		string nomVoiture;
		Modele modele;
		Option * option[5];

	public:

		Voiture();// constructeur par defaut
		Voiture( string,const Modele &); // constructeur initalisation et on appel la classe 
		Voiture(const Voiture &); // vu que voiture a deja un variable Modele pas besoin de le rapeller // Cons Copie
		~Voiture(); // destructeur de copie



		 string getNom() const;
		 Modele getModele() const;

		float getPrix() const;

		void AjouteOption(const Option &);
		void RetireOption( string);
		

		
		void setNom( string);
		void setModele(const Modele &);


		void Affiche()const;

};

#endif