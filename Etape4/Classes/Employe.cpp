#include <iostream>  
#include <string.h> 
using namespace std; 
#include "Employe.h"

Employe::Employe(): Intervenant()
{
	#ifdef DEBUG
    cout<<"Constructeur par defaut de Employer "<<endl;
    #endif

    login="Pas de login";

    motdepasse=NULL ;


    fonction="Pas de fonction ";
}
Employe::Employe( string nvNom,  string nvPrenom, int nvNumero,  string nvLogin,  string nvFonction): Intervenant(nvNom,nvPrenom,nvNumero)
{
	#ifdef DEBUG
    cout<<"Constructeur par init de Employer "<<endl;
    #endif

    setLogin(nvLogin);
    motdepasse=NULL;

    setFonction(nvFonction);


}

Employe::Employe(const Employe& source): Intervenant(source.getNom(), source.getPrenom(), source.getNumero())
{
	#ifdef DEBUG
    cout<<"Constrcuteur par copie de Employer "<<endl;
    #endif

    setLogin(source.getLogin());

    motdepasse=NULL;
    setMotDePasse(source.getMotDePasse());
    setFonction(source.getFonction());


}

Employe::~Employe()
{

    #ifdef DEBUG
    cout<<"Destructeur de Employe"<<endl;
    #endif

    if(motdepasse)
        delete motdepasse;
    motdepasse=NULL;
}



/****SETTEUR ET GETTER****************************/

void Employe::setLogin( string nvLogin)
{
	login=nvLogin;
}
void Employe::setMotDePasse( string  nvMotdepasse)
{
	if(motdepasse)
        delete motdepasse;

	motdepasse=new string;

	*motdepasse=nvMotdepasse;


	

}
void Employe::setFonction( string nvFonction)
{
	fonction=nvFonction;
}


string Employe::getLogin()const
{
	return login;
}
string Employe::getMotDePasse() const
{
	return *motdepasse; // je retourne ce que pointe mdp 
}

string Employe::getFonction() const
{
	return fonction;
}


// /********TOSTRING ET TUPLE**********************/
string Employe::ToString()const
    {

        string tmp;

        string num= to_string(getNumero());

        if(fonction=="VENDEUR")
        {
            tmp= "[V"  + num +"]" +getNom() +" " + getPrenom();
        }
        else
        {
            tmp= "[A"  + num +"]" +getNom() +" " + getPrenom();
        }




        return tmp;
    }

string Employe::Tuple()const
    {
        string tmp;
        string num= to_string(getNumero());
        tmp = num + ";" + getNom()+ getPrenom() + ";" + getFonction();
        return tmp;
    }

/*********SORTIE***********************************/

 ostream & operator<<(ostream& flux, const Employe& Employe)
 {
 	flux<<"Nom : "<<Employe.getNom()<< endl;
	flux<<"Prenom : "<<Employe.getPrenom()<<endl;
	flux<<"Numero : "<<Employe.getNumero()<<endl;
	flux<<"lOGIN : "<<Employe.getLogin()<< endl;
    if(Employe.motdepasse!=NULL)
	   flux<<"MDP : "<<Employe.getMotDePasse()<<endl;
    else
        flux<<"Pas de motdepasse"<<endl;

	flux<<"Fonction : "<<Employe.getFonction()<<endl;

	return flux;
 }

 /************SURCHAGE OPERATOR*************************/
 Employe& Employe::operator=(const Employe& source)
 {
 	Intervenant::operator=(source);

 	setLogin(source.getLogin());
 	setMotDePasse(source.getMotDePasse());
 	setFonction(source.getFonction());

 	return *this;

 }

 /******FONCTION PUBLIQUE*****************************/

 void Employe::ResetMotDePasse()
 {
    if(motdepasse)
        delete motdepasse;

        motdepasse=NULL;
 }

 const string Employe::ADMINISTRATIF= "ADMINISTRATIF";
 const string Employe::VENDEUR= "VENDEUR";