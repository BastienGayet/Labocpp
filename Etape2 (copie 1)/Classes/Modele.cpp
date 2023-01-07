#include "Modele.h"
#include <string.h>

/***********************************************************************************************************/
/************Concstructeur et destructeur*******************************************************************/
/***********************************************************************************************************/
Modele::Modele()  // constrcuteur par defaut
{
  #ifdef DEBUG
  cout<<"Constrcuteur par defaut de Modele"<<endl;   // << pour afficher   // >> 
  #endif

  puissance=0;
  prixdeBase=0;
  moteur=Essence;

  //nom=NULL;

  // nom=new char[20]; // allocation dynamique de 20 caractere
  // strcpy(nom,"Modele sans nom");  // 2ieme methode
  nom=NULL; // pour eviter de faire planter le mrogramme , j'initialise nom a null 
  setNom("Modele sans nom");
}   

 Modele::Modele(const char*n,int p,Moteur m,float px)
 {
  #ifdef DEBUG
  cout<<"COnstructeur par initialisation de Modele "<<n<< " " << p<<" " << m << " " <<px<< " " <<endl;
  #endif
  setPuissance(p);
  setPrixDeBase(px);
  setMoteur(m);

  nom=NULL;
  setNom(n);
 }


 Modele::Modele(const Modele &source)
 {
  #ifdef DEBUG
 // cout<<"COnstructeur de copie"<<source.getNom<<" "<<source.getPuissance<<" "<<source.getMoteur<<" "<<source.getPrixDeBase<<endl;


   cout<<"COnstructeur de copie";
   source.Affiche();
  #endif

   setPuissance(source.getPuissance());
   setPrixDeBase(source.getPrixDeBase());
   setMoteur(source.getMoteur());
   nom =NULL;
   setNom(source.getNom());

 }


 Modele::~Modele()
 {
  #ifdef DEBUG
  cout<<"Destructeur de copie de Modele"<<endl;//<<nom<<" "<<puissance<<" "<<moteur<<" "<<prix<<endl;
  //this->Affiche();
  #endif

  if(nom)
      delete[]nom;
 }

/***********************************************************************************************************/
/************Getters et setters*****************************************************************************/
/***********************************************************************************************************/

const char * Modele::getNom()const
{
  return nom;

}
int Modele::getPuissance()const
{
  return puissance;

}
float Modele::getPrixDeBase()const
{
  return prixdeBase;
}
Moteur Modele::getMoteur()const
{
  return moteur;
}


 void Modele:: setNom(const char * n)
 {
    if(n)
    {
      if(nom) // si il y a un nom dans la variable je supprime avant
          delete [] nom ;

      nom=new char[strlen(n)+1];
      strcpy(nom,n);

    }
    
 }




    void Modele::setPuissance(int p)
    {
      if(p>=0)
        puissance=p;

    }
    void Modele::setPrixDeBase(float p)
    {
      if(p>=0)
        prixdeBase=p;
      

    }
    void Modele::setMoteur(Moteur m)
    {
      moteur = m;
    }

/***********************************************************************************************************/
/************Méthodes publiques********************************************************************* *******/
/***********************************************************************************************************/



 void Modele::Affiche()const
 {
  cout<< nom <<" Puissance "<< puissance <<" Prix: "<< prixdeBase << " Motorisation ";

  switch(moteur)
  {
    case Essence:
        cout<<"Essence"<<endl;
        break;

    case Diesel:
        cout<<"Diesel"<<endl;
        break;

    case Electrique:
        cout<<"Electrique"<<endl;
        break;

    case Hybride:
        cout<<"Hybride"<<endl;
        break;

  }

 }