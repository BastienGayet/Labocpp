#include <iostream>  
#include <string.h> 
using namespace std; 
#include "Personne.h"


//Constructeur par défaut
Personne::Personne()
{
	#ifdef DEBUG
    cout<<"Constrcuteur par defaut de Personne"<<endl;
    #endif
	nom="Pas de nom";
	
	prenom="Pas de prenom";

	

}

//	Constructeur d'initi

Personne::Personne( string nvNom,  string nvPrenom)
{
	#ifdef DEBUG
    cout<<"Constructeur par initialisation de Personne"<<endl;
    #endif


	setNom(nvNom);
	setPrenom(nvPrenom);
}

// constructeur de copie
Personne::Personne(const Personne& source)
{
	#ifdef DEBUG
    cout<<"Constructeur par copie de Personne"<<endl;
    #endif

    setNom(source.getNom());
    setPrenom(source.getPrenom());

}

Personne::~Personne()
{
	#ifdef DEBUG
    cout<<"Destructeur de Personne"<<endl;
    #endif
}

/*********SETTEUR*************************************************/

void Personne::setNom( string nvNom)
{
	nom=nvNom;
}

void Personne::setPrenom( string nvPrenom)
{
	prenom=nvPrenom;
}

/********GETTEURS******************************/

string Personne::getNom() const
{
	return nom;
}

string Personne::getPrenom() const
{
	return prenom;
}



/***********AFFICHAGE*************************/
/*
void Personne::Affiche() const
{
		cout<< "nom : "<<nom<<endl;
			cout<< "prenom : "<<prenom<<endl;
}
*/
/********SURCHAGE OPERATEUR*******************/
Personne& Personne::operator=(const Personne& source)
{
	setNom(source.getNom());
	setPrenom(source.getPrenom());

	return *this;
}

/*********ENTREE/SORTIE***********************/

// SORTIE

ostream& operator<<(ostream& flux, const Personne& personne)
{
	flux<<"Nom : "<<personne.getNom()<< endl;
	flux<<"Prenom : "<<personne.getPrenom()<<endl;

	return flux;
}


// ENTRE
istream& operator>>(istream& flux, Personne& personne)
{
	string nom;
	string prenom;

	cout<< "Nom : " ;
	getline(flux,nom, '\n');


	cout<< "Prenom  : " ;
	getline(flux,prenom, '\n');

	personne.setNom(nom);
	personne.setPrenom(prenom);

	return flux;
}

