#include "Voiture.h"




/***********************************************************************************************************/
/************Constructeur et destructeur*******************************************************************/
/***********************************************************************************************************/


Voiture::Voiture()  // COnstructeur par defauts
{
	#ifdef DEBUG
    cout<<"Constrcuteur par defaut de Modele"<<endl;
    #endif

    nomVoiture="Voiture sans nom"; // vu que c'est un string je peux pas mettre à null 

    for(int i=0;i<5;i++)
	{
		if(option[i])
			option[i]=NULL;

	}



}
Voiture::Voiture( string nom, const Modele& modele_voiture)  // constructeur d'initialisation
{
	#ifdef DEBUG
    cout<<"Constrcuteur par initialisatiion de Voiture"<<endl;
    #endif
  
	setNom(nom);
	setModele(modele_voiture);

	for(int i=0;i<5;i++)
	{
		if(option[i])
			option[i]=NULL;

	}
}


Voiture::Voiture(const Voiture & source) // constructeur de copie 
{
	#ifdef DEBUG
    cout<<"Constrcuteur de copie de Voiture"<<endl;
    #endif
    
	setNom(source.getNom());
	setModele(source.getModele());

	for(int i=0;i<5;i++)
	{
		if(source.option[i])
		{
			option[i]=new Option(*source.option[i]);
		}
		else
			option[i]=NULL;

	}
	
	
}

Voiture::~Voiture() // desctructeur de copie
	{
		#ifdef DEBUG
  		cout<<"Destructeur de copie de Voiture"<<endl;
  		#endif

  		for(int i=0;i<5;i++)
  		{
  			if(option[i]!=NULL)
  			{
  				delete option[i];
  			}
  		}
  		
  		
		 
	}

/***********************************************************************************************************/
/************Getters et setters*****************************************************************************/
/***********************************************************************************************************/
 string Voiture::getNom() const  /// getter souvant avec const a la fin
{
	return nomVoiture;

}
 Modele Voiture::getModele() const // je return un objet de type constant 
{
	return modele;
}

 float Voiture::getPrix() const 
{
	float Prix_Finale=getModele().getPrixDeBase();
	for(int i=0;i<5;i++)
	{
		if(option[i])
		{
			Prix_Finale=Prix_Finale+option[i]->getPrix();

		}
	}

	return Prix_Finale;

}


void Voiture::setNom(string nom)
{
	nomVoiture=nom;

}

void Voiture::setModele(const Modele & modele_voiture )
{
	modele.setNom(modele_voiture.getNom()); // pas la meme adresse mais pointe sur la même chose
	modele.setPuissance(modele_voiture.getPuissance());
	modele.setMoteur(modele_voiture.getMoteur());
	modele.setPrixDeBase(modele_voiture.getPrixDeBase());

}


/***********************************************************************************************************/
/************Méthodes publiques********************************************************************* *******/
/***********************************************************************************************************/

void Voiture::Affiche()const
{
	cout<<nomVoiture<<" "<<endl;
	
	modele.Affiche();
	for(int i=0;i<5;i++)
	{
		if(option[i])  // si il  ya quelque chose dedans j'affiche 
			option[i]->Affiche(); // vu que c'est un pointeur je prend un fleche
		  
	}
	
}


void Voiture::AjouteOption(const Option & Option_Voiture)
{
	for(int i=0;i<5;i++)
	{

		if(option[i]==NULL) 
		{
			option[i] = new Option(Option_Voiture);
			return;
		}

	}

}

void Voiture::RetireOption( string code)
{
	for(int i=0;i<5;i++)
	{
		if(option[i]&& (option[i]->getCode()==code))
		{
			delete option[i];
			option[i]=NULL;

		}
			
	}



}