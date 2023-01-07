#include <iostream>  
#include <string.h> 
using namespace std; 
#include "Client.h"


Client::Client(): Intervenant()
{
	#ifdef DEBUG
    cout<<"Constructeur par defaut de Client "<<endl;
    #endif

    gsm="Pas de gsm ";
}

Client::Client( string nvNom,  string nvPrenom, int nvNumero,  string nvGSM): Intervenant(nvNom,nvPrenom,nvNumero)
{
	#ifdef DEBUG
    cout<<"Constrcuteur par init de Client "<<endl;
    #endif

    setGsm(nvGSM);
}
Client::Client(const Client& source): Intervenant(source.getNom(), source.getPrenom(), source.getNumero())
{
	#ifdef DEBUG
    cout<<"Constrcuteur par copie de Client "<<endl;
    #endif

    setGsm(source.getGsm());
}

Client::~Client()
{
	#ifdef DEBUG
    cout<<"Destructeur de Client"<<endl;
    #endif

    
}

/*****SETTER ET GETTEUR***************************/

void Client::setGsm( string nvGSM)
{
	gsm=nvGSM;
}


string Client::getGsm() const
{
	return gsm;
}


// /********TOSTRING ET TUPLE**********************/
string Client::ToString()const
    {
        string tmp;

        string num= to_string(getNumero()); 

        tmp="[C"+ num + "]" + getNom() + " " + getPrenom();

        return tmp;
    }

string Client::Tuple()const
    {
        string tmp;
        string num= to_string(getNumero());
        tmp = num + ";" + getNom()+ getPrenom() + ";" + getGsm();
        return tmp;
    }

/*********SORTIE***********************/

// SORTIE

ostream& operator<<(ostream& flux, const  Client& Client)
{
	flux<<"Nom : "<<Client.getNom()<< endl;
	flux<<"Prenom : "<<Client.getPrenom()<<endl;
	flux<<"Numero : "<<Client.getNumero()<<endl;
	flux<<"GSM : "<<Client.getGsm()<< endl;

	return flux;
}





/********SURCHAGE OPERATEUR*******************/
Client& Client::operator=(const Client& source)
{
	Intervenant::operator=(source);
	
	setGsm(source.getGsm());
	
	return *this;
}


