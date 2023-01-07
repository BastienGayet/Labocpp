#ifndef PASSWORDEXCEPTION_H
#define PASSWORDEXCEPTION_H

#include "Exception.h"

class PasswordException : public Exception
{
	private:
		int code;
	public:
		PasswordException();// init
		PasswordException(string,int);// defaut
		PasswordException(const PasswordException&);
		~PasswordException();//destructeur

		/*SETTEUR*/

		void setCode(int);


		/*GETTER*/

		int getCode() const;


		static const int INVALID_LENGTH;
		static const int ALPHA_MISSING;
		static const int DIGIT_MISSING;
		static const int NO_PASSWORD;


	
};

#endif
