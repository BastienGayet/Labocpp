#ifndef PERSONNE_H
#define PERSONNE_H

/*CLASSE MERE - Personne */

class  Personne
{	
	friend ostream& operator<<(ostream&, const Personne&);
	friend istream& operator>>(istream&, Personne&);

	protected:

		string nom;
		string prenom;

	public:
		  Personne();// cons defaut
		  Personne( string ,  string); // initialisation // const uniquement si pointeur ou reference 
		  Personne(const Personne& ); // copie
		  ~ Personne(); // cons dest


		//setter
		void setNom(string);
		void setPrenom( string);

		//getter
		string getNom() const ;
		string getPrenom() const;


		//Affichage
		void Affiche() const;

		/*SURCHAGE DES OPERATEURS*/

		Personne& operator=(const Personne&);


	
};

#endif