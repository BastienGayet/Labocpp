#include "Exception.h"



/*****CONSTRUCTEUR****************/

Exception::Exception()
{
	#ifdef DEBUG
    cout<<"Constructeur par defaut de Exception "<<endl;
    #endif

    message="Pas de message";
}
Exception::Exception( string nvMessage)
{
	#ifdef DEBUG
    cout<<"Constructeur par Init de Exception "<<endl;
    #endif

    setMessage(nvMessage);
}
Exception::Exception(const Exception& source)
{
	#ifdef DEBUG
    cout<<"Constructeur de copie de Exception "<<endl;
    #endif

    setMessage(source.getMessage());
}

Exception::~Exception()
{
	#ifdef DEBUG
    cout<<"Destructeur de copie de Exception "<<endl;
    #endif

}


/**********SETTEUR**********************/
void Exception::setMessage( string nvMessage)
{
	message=nvMessage;
}

/**********GETTEUR***********************/ 

string Exception::getMessage() const
{
	return message;
}


/********SURCHAGE OPERATEUR*******************
Exception& Exception::operator=(const Exception& source)
{
	setMessage(source.getMessage());

	return *this;
}*/