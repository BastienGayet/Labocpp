#ifndef OPTION_H
#define OPTION_H


#include <iostream>
#include <string>
#include <string.h>
#include "OptionException.h"



using namespace std;

class Option
{
	friend ostream& operator<<(ostream&, const Option&);
	friend istream& operator>>(istream&, Option&);
	private:

		string Code;
		string Intitule;
		float Prix;

	public:
		Option(); // constructeur par defaut
		Option( string ,  string , float); // constructeur d'initialisation
		Option(const Option &);// constructeur de copie
		~Option(); // destructeurde copie  de option

		string getCode() const;
		string getIntitule() const;
		float getPrix() const;



		void setCode( string ); // si pas d'adresse ou refenrce pas besoin de string
		void setIntitule( string  );
		void setPrix(float);

		//pre decrementation , post decrementation 
		Option operator--(); // pref
		Option operator--(int);// post


		
	
		void Affiche()const;


};



#endif