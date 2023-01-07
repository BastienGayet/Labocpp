#include <iostream> 
#include <climits> 
#include <string.h> 
using namespace std; 

#include "Intervenant.h"


/***CONSTRUCTEUR***************************/

Intervenant::Intervenant() : Personne()
{
	#ifdef DEBUG
    cout<<"Constrcuteur par defaut de Intervenant "<<endl;
    #endif


	numero=0; 

}
Intervenant::Intervenant( string nvNom,  string nvPrenom,  int nvNumero): Personne(nvNom, nvPrenom)
{
	#ifdef DEBUG
    cout<<"Constrcuteur Initia de Intervenant"<<endl;
    #endif

    setNumero(nvNumero);

}
Intervenant::Intervenant(const Intervenant& source) : Personne(source.getNom(),source.getPrenom())
{
	#ifdef DEBUG
    cout<<"Constrcuteur de copie de Intervenant"<<endl;
    #endif

	setNumero(source.getNumero());
}

Intervenant::~Intervenant()
{

	#ifdef DEBUG
    cout<<"Destructeur de Intervenant"<<endl;
    #endif
}


/******SETTER ET GUETTER*************************/

void Intervenant::setNumero( int nvNumero)
{
	numero=nvNumero;
}

int Intervenant::getNumero()const
{
	return numero;
}




/*******SURCHARGE DES OPERATEURS****************/

Intervenant& Intervenant::operator=(const Intervenant& source)
{
	Personne::operator=(source);

	setNumero(source.getNumero());

	return *this;
}



