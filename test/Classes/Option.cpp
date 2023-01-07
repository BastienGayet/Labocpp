#include "Option.h"

#include <cstring>

/***********************************************************************************************************/
/************Constructeur et destructeur*******************************************************************/
/***********************************************************************************************************/
	Option::Option()
	{
		#ifdef DEBUG
    	cout<<"Constrcuteur par defaut de Option"<<endl;
    	#endif

    	Code="0000";

    	Intitule="Pas d'option";

    	Prix= 0.0;

	}


	Option::Option( string  code1,  string  description, float Prix)
	{
		#ifdef DEBUG
    	cout<<"Constrcuteur par initialisation de Option"<<endl;
    	
    	cout<<code1<<" "<<endl;
    	cout<<description<<" "<<endl;
    	cout<<Prix<<" "<<endl;
    	#endif


    	setCode(code1);
    	setIntitule(description);
    	setPrix(Prix);

	}

	Option::Option(const Option & source)
	{
		#ifdef DEBUG
    	cout<<"Constrcuteur de copie de Voiture"<<endl;
    	#endif

    	setCode(source.getCode());
    	setIntitule(source.getIntitule());
    	setPrix(source.getPrix());
	}


	Option::~Option()
	{
		#ifdef DEBUG
  		cout<<"Destructeur de copie de Option"<<endl;
  		//this->Affiche();
  		#endif
	}

/***********************************************************************************************************/
/************Getters et setters*****************************************************************************/
/***********************************************************************************************************/
	 string Option::getCode()const
	{
		return Code;
	}

	 string Option::getIntitule()const
	{
		return Intitule;
	}

	float Option::getPrix()const
	{
		return Prix;
	}

	
	
			void Option::setCode(string code1) 
		{
	
			int test=code1.size();

			if(test==4)
			{
				Code=code1;
				
			}
			else
			{
				throw OptionException("Le format du code est pas correct ");
			}
		


		}

		void Option::setIntitule(string description)
		{
			

			int test=description.size();

			if(test<1)
			{
				throw OptionException("Le format de Intitule est pas correct ");
			}
			else
			{

				Intitule=description;
			}
			
		}


		void Option::setPrix(float p)
    {
      if(p>=0)
        Prix=p;
      else
      	throw OptionException("Le prix doit etre positif ");

    }

	



/***********************************************************************************************************/
/************Méthodes publiques*****************************************************************************/
/***********************************************************************************************************/

	void Option::Affiche()const
	{
		cout<< "Code option : "<<Code<<endl;
		cout<< "Intitule : "<<Intitule<<endl;
		cout<< "Prix: "<<Prix<<endl;
	

		
	}

// DECREMENTATION -------------------------------------------------------------- 

	Option Option::operator--()
	{
		if(getPrix()<50)
		{
			throw OptionException("Le format de Intitule est pas correct ");
		}
		setPrix(getPrix()-50.0);

		return (*this);
	}

	Option Option::operator--(int)
	{
		Option copie(*this);

		setPrix(getPrix()-50.0); // decremente

		return copie; //renvoi l'ancienne valeur 
	}


/*******ENTREES ET SORTIES*********************************************/

	ostream& operator<<(ostream& flux , const Option& option) // sortie 
	{
		
		flux<<"Code option = " << option.getCode() << endl;
		
		
		flux<<"Intitule = " <<  option.getIntitule() << endl;
		

		flux<<"Prix option = " << option.getPrix() << endl;

		return flux;

	}

	istream& operator>>(istream& flux, Option& option)
	{
		string code;
		string intitule;
		string pr;
		float prix= 0.0;

		
		cout<< "Code option : " ;
		getline(flux,code, '\n');


		cout<< "Intitule : " ;
		getline(flux,intitule, '\n');


		cout<< "Prix option : : " ;
		getline(flux,pr, '\n');

		prix= stof(pr);


		option.setCode(code);
		option.setIntitule(intitule);
		option.setPrix(prix);

	  

			return flux;
	}

	  /*******FLUX BYTES ******************/

  // ECRITURE
  void Option::Save(ofstream & fichier ) const 
  {
  	int taille = getCode().size();

  	fichier.write((char *)&taille,sizeof(int));
  	fichier.write((char *)getCode().data(),taille*sizeof(char));

  	int taille1 = getIntitule().size();

  	fichier.write((char *)&taille1,sizeof(int));
  	fichier.write((char *)getIntitule().data(),taille1*sizeof(char));

  	float tempprix= getPrix();
  	fichier.write((char *)&tempprix, sizeof(float));



  }

  // LECTURE

  void Option::Load(ifstream &fichier)
  {

    int taille=Code.size();
  	
    fichier.read((char *)&taille,sizeof(int));
    Code.resize(taille);
    fichier.read((char*)Code.data(),taille*sizeof(char));
    setCode(Code);

    int taille2=Intitule.size();

    fichier.read((char*)&taille2,sizeof(int));
    Intitule.resize(taille2);
    fichier.read((char*)Intitule.data(),taille2*sizeof(char));
    setIntitule(Intitule);

    float tempPrix = 0;
    fichier.read((char *)&tempPrix,sizeof(float));
    setPrix(tempPrix);
   

  }