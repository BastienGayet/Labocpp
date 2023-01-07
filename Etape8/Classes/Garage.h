#ifndef GARAGE_H
#define GARAGE_H

#include <iostream>
#include "Modele.h" // on include que dans le .h
#include "Option.h"
#include "Client.h"
#include "Employe.h"
#include "Vecteur.h"
#include "Iterateur.h"
#include "Voiture.h"


using namespace std;

class Garage
{	
	private:
		Vecteur<Employe> employes;
		Vecteur<Client> clients;
		Vecteur<Modele> modeles;
		Vecteur<Option> options;

		static Garage instance; // singleton 
		Garage();// defaut

		Garage(const Garage& g);
		Garage operator=(const Garage& g);
		~Garage();

		static Voiture projetEnCours;

	public:
		
		static Garage& getInstance();
		static Voiture& getProjetEnCours();
		static void resetProjetEnCours();


		void ajouteModele(const Modele & m);
		void afficheModelesDisponibles() const;
		Modele getModele(int indice);
		void ajouteOption(const Option & o);
		void afficheOptionsDisponibles() const;
		Option getOption(int indice);
		
		void ajouteClient(string nom,string prenom,string gsm);
		void afficheClients() const;
		void supprimeClientParIndice(int ind);
		void supprimeClientParNumero(int num);
		
		
		
		void ajouteEmploye(string nom,string prenom,string login,string fonction);
		void afficheEmployes() const;
		void supprimeEmployeParIndice(int ind);
		void supprimeEmployeParNumero(int num);
				 
	
};


#endif