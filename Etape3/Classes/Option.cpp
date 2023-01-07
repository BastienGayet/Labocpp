#include "Option.h"

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
		Code=code1;

	}

	void Option::setIntitule(string description)
	{
		Intitule=description;
	}


	void Option::setPrix(float p)
    {
      if(p>=0)
        Prix=p;
    }

/***********************************************************************************************************/
/************Méthodes publiques*****************************************************************************/
/***********************************************************************************************************/

	void Option::Affiche()const
	{
		cout<< "Code option : "<<Code<<endl;
		cout<< "Intitule : "<<Intitule<<endl;
		cout<< "Prix: "<<Prix<<endl;
	

		//Option.Affiche();
	}

// DECREMENTATION -------------------------------------------------------------- 

	Option Option::operator--()
	{
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