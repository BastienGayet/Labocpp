#include "Garage.h"

/***********************************************************************************************************/
/************Constructeur et destructeur*******************************************************************/
/***********************************************************************************************************/

Garage::Garage()// cons defaut
{
	#ifdef DEBUG
    cout<<"Constrcuteur par defaut de Garage"<<endl;
    #endif


}

Garage::~Garage()
{

	#ifdef DEBUG
    cout<<"Destructeur de Garage"<<endl;
    #endif
}

/*METHODE PUBLIC*************************/


void Garage::ajouteModele(const Modele & m)
{
	modeles.insere( m );
}

		
void Garage::afficheModelesDisponibles() const
{
	modeles.Affiche();
}
Modele Garage::getModele(int indice)
{
	return modeles[indice];
}
		

void Garage::ajouteOption(const Option & o)
{
	options.insere(o);
}
void Garage::afficheOptionsDisponibles() const
{
	options.Affiche();
}
Option Garage::getOption(int indice)
{
	return options[indice];
}
		
void Garage::ajouteClient(string nom,string prenom,string gsm)
{
	Client c ;
	c.setNom(nom);
	c.setPrenom(prenom);
	c.setGsm(gsm);
	c.setNumero(c.numCourant);
	
	clients.insere(c);
	c.numCourant++;
	

}
void Garage::afficheClients() const
{
	clients.Affiche();
}
void Garage::supprimeClientParIndice(int ind)
{
	clients.retire(ind);
}
void Garage::supprimeClientParNumero(int num)
{
	 int i = 0;
    Iterateur<Client> it(clients);
    it.reset();
    while(!it.end() && num != clients[i].getNumero())
    {
        i++;
        it++;
    }
    if(!it.end())
        clients.retire(i);
	
}
		
		
		
void Garage::ajouteEmploye(string nom,string prenom,string login,string fonction)
{
	Employe e;
	e.setNom(nom);
	e.setPrenom(nom);
	e.setLogin(login);
	e.setFonction(fonction);
	e.setNumero(e.numCourant);

	employes.insere(e);
	e.numCourant++;
}
void Garage::afficheEmployes() const
{
	employes.Affiche();
}
void Garage::supprimeEmployeParIndice(int ind)
{
	employes.retire(ind);
}
void Garage::supprimeEmployeParNumero(int num)
{
	int i = 0;
    Iterateur<Employe> it(employes);
    it.reset();
    while(!it.end() && num != employes[i].getNumero())
    {
        i++;
        it++;
    }
    if(!it.end())
        employes.retire(i);
	
}


Garage& Garage::getInstance()
{
	return instance;
} 
Garage Garage::instance = Garage();

Voiture& Garage::getProjetEnCours()
{
	return projetEnCours;

}
Voiture Garage::projetEnCours = Voiture();

void Garage::resetProjetEnCours()
{

	projetEnCours=Voiture();

}