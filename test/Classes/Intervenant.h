#ifndef INTERVENANT_H
#define INTERVENANT_H

#include "Personne.h"

/*CLASSE fille Intervenant*/ // acceseurs = getteur et setteur 

class Intervenant : public Personne
{
	private:
		int numero;

	public:
		Intervenant(); // defaut
		Intervenant( string,  string ,  int); // init
		Intervenant(const Intervenant&);// copie
		 virtual ~Intervenant();// destructeur 
		static int numCourant;

		//setter
		void setNumero(int);

		//getter
		int getNumero()const;


		/*SURCHARGE OPERATEUR**********************/

		Intervenant& operator=(const Intervenant&);


		/***tupple et tostring********************/

		virtual string ToString()const =0;
		virtual string  Tuple() const =0;




	
};


#endif