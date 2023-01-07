#ifndef OPTIONEXCEPTION_H
#define OPTIONEXCEPTION_H
#include <string>
#include <string.h>
#include "Exception.h"
#include <iostream>



class OptionException: public Exception
{
	public:

		OptionException();// defaut
		OptionException(const string); // init
		OptionException(const OptionException&) ;// copie
		~OptionException();// des copie



		


};

#endif 