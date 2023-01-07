#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

class Exception
{
	private:

		string message;


	public:
		Exception();// defaut
		Exception( string);
		Exception(const Exception&);
		~Exception();

		//setteur

		void setMessage( string);

		// Getteur
		string getMessage() const;



	
};

#endif 