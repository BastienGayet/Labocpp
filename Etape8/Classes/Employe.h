#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "Intervenant.h"


/*CLASSE FILLE Employe.h*/

class Employe : public Intervenant
{
	friend ostream& operator<<(ostream&, const Employe&);

	private:
		string login;
		string * motdepasse;
		string fonction;
	public:
		Employe();// init
		Employe( string,  string, int ,  string,  string);
		Employe(const Employe&);
		~Employe();

		static const string VENDEUR;
		static const string ADMINISTRATIF;

		/*SETTER ET GUETTER*/

		void setLogin( string);
		void setMotDePasse( string );
		void setFonction( string);


		string getLogin() const;
		string  getMotDePasse() const;
		string getFonction() const ; 


		/*SURCHAGE OPERATEUR ********/

		Employe& operator=(const Employe&);



		/*TUPLE ET TOSTRING*******/

	    string ToString() const;
		string Tuple() const ;

		/*******FONCTION PUBLIC**********/

		void ResetMotDePasse();
	
};

#endif