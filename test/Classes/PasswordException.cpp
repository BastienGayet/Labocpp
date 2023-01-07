#include <iostream>  
#include <string.h> 
using namespace std;

#include "PasswordException.h"
#include <string>


/***MEMBRE STATIC***/

const int PasswordException::INVALID_LENGTH=1;
const int PasswordException::ALPHA_MISSING= 2;
const int PasswordException::DIGIT_MISSING= 3;
const int PasswordException::NO_PASSWORD=   4;


/*CONSTRUCTEUR*******/

PasswordException::PasswordException():Exception()
{
	#ifdef DEBUG
    cout<<"Constructeur par defaut de PasswordException"<<endl;
    #endif

    code=0;
}

PasswordException::PasswordException(string nvMessage, int nvCode): Exception(nvMessage)
{
	#ifdef DEBUG
    cout<<"Constructeur par init de PasswordException "<<endl;
    #endif

    setCode(nvCode);
}
PasswordException::PasswordException(const PasswordException& source ): Exception(source.getMessage())
{
	#ifdef DEBUG
    cout<<"Constructeur de copie  de PasswordException "<<endl;
    #endif

    setCode(source.getCode());
}
PasswordException::~PasswordException()
{
	#ifdef DEBUG
    cout<<"Destrcuteur de copie de PasswordException "<<endl;
    #endif


}

/***SETTEUR***********/

void PasswordException::setCode(int nvCode) 
{
	code=nvCode;
}

/***GETTEUR**********/


int  PasswordException::getCode()const 
{
	return code;
}



