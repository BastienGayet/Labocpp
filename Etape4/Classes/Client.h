#ifndef CLIENT_H 
#define CLIENT_H 

#include "Intervenant.h" 


/*CLASSE FILLE - CLIENT */

class Client : public Intervenant
{
	friend ostream& operator<<(ostream&, const Client&);
	
	private:
		
		string gsm;

	public:
		Client();// defaut
		Client( string,  string ,  int,  string);// init
		Client(const Client&);// copie
		~Client(); // des 


		//setteur et getter

		void setGsm( string);


		string getGsm() const;



		/*TUPLE ET TOSTRING*******/

	    string ToString() const;
		string Tuple() const ;


		/*SURCHAGE DES OPERATEURS*/

		Client& operator=(const Client&);




};

#endif

