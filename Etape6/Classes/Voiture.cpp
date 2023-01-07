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
	for(int j=0;j<5;j++)
	{
		if(option[j] && (option[j]->getCode())==(Option_Voiture.getCode())) throw OptionException("L'option existe deja ");
		// la 2ieme c'est celle que je dois rajouter donc normale de pas avoir option[i]
	}


	for(int i=0;i<5;i++)
	{


		if(option[i]==NULL)
		{
			

			option[i] = new Option(Option_Voiture);
			
			return;
		}
	}

		throw OptionException("Le tableau d'Option est deja plein ");
			
}

void Voiture::RetireOption( string code)
{

	for(int i=0;i<5;i++)
	{
		if(option[i] && (option[i]->getCode()==code))
		{
			delete option[i];
			option[i]=NULL;
			return;

		}
			
	}

	throw  OptionException("L'option n'existe pas  ");


		



}

Voiture& Voiture::operator=(const Voiture &source)
{
	nomVoiture = source.getNom();
	modele = source.getModele();
	

for(int i=0;i<5;i++) 
	if (option[i]) 
	{
		delete option[i];
		option[i]=NULL;
	}

	for(int i=0;i<5;i++)
	{
		if(source.option[i]!=NULL)
		{
		  option[i]= new Option(*source.option[i]);
		}

	}

	return(*this);

}

Voiture Voiture::operator+(const Option& opt)const
{

	Voiture v(*this); 
	v.AjouteOption(opt);
	return v;
}

Voiture operator+(const Option& opt,const  Voiture& source)
{
	return  source+opt;
}

Voiture Voiture::operator-(string code)const
{
	Voiture v(*this);

	v.RetireOption(code);

	return v;
}
Voiture Voiture::operator-(const Option& opt)const
{
	Voiture v(*this);

	v.RetireOption(opt.getCode());

	return v;

}

int Voiture::operator<(const Voiture& v ) const
{
	return compV(v)==-1;
}
int Voiture::operator>(const Voiture& v ) const
{
	return compV(v)==1;
}

int Voiture::operator==(const Voiture& v ) const
{
	return compV(v)==0;
}
int Voiture::compV( const Voiture& v) const
{


	if(getPrix() < v.getPrix())
		return -1;

	if(getPrix() > v.getPrix())
		return 1;

	return 0;
}

Option* Voiture::operator[](int i) const 
{
	return(option[i]);
}

/*******ENTREES ET SORTIES*********************************************/

 ostream& operator<<(ostream& flux , const Voiture& v) // sortie 
  {
    
	flux << "Nom projet = " << v.getNom() << endl << v.getModele()  
	       << endl << "Prix avec options = " << v.getPrix();

    

    //Affiche les options 
    for(int i=0;i<5;i++)
    {
    	if(v.option[i]!=NULL)
    	{
    		flux<<*(v.option[i]) << endl;
    	}
    }
    
    return flux;

  }
    
    
