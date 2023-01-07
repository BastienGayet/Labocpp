#include <iostream>  
#include <string.h> 
using namespace std;

#include "OptionException.h"
#include <string>


/******CONSTRUCTEUR**************/

OptionException::OptionException():Exception()
{
	#ifdef DEBUG
    cout<<"Constructeur par defaut de OptionException "<<endl;
    #endif
}

OptionException::OptionException( string nvMessage):Exception(nvMessage)
{
	#ifdef DEBUG
    cout<<"Constructeur par Init de OptionException "<<endl;
    #endif
}

OptionException::OptionException(const OptionException& source): Exception(source.getMessage())
{
	#ifdef DEBUG
    cout<<"Constructeur de copie de OptionException "<<endl;
    #endif
}
OptionException::~OptionException()
{
	#ifdef DEBUG
    cout<<"Destructeur de copie  de OptionException "<<endl;
    #endif
}