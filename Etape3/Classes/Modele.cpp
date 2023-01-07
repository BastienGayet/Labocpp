#include "Modele.h"
#include <string.h>
#include <iostream> 
#include <fstream> 
#include <climits> 
#include <string>

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

 void Modele::operator=(const Modele& modele)
 {

   /*if(nom)
      delete[] nom;*/

   //nom= new char [50];

   //strcpy(nom,modele.nom);

    setNom(modele.getNom());

   puissance=modele.getPuissance();
   prixdeBase=modele.getPrixDeBase();
   moteur=modele.getMoteur();
  
 }

/*******ENTREES ET SORTIES*********************************************/

 ostream& operator<<(ostream& flux , const Modele& m) // sortie 
  {
    
    flux<<"Nom modele = " << m.getNom() << endl;

    flux<<"Puissance modele = " << m.getPuissance() << endl;

    flux<<"Prix de base = " << m.getPrixDeBase() << endl;


    flux<< "Moteur du modele = "<<m.getMoteur() << endl;
    
    
    return flux;

  }

  istream& operator>>(istream& flux, Modele& m)
  {
    string nom;
    string puis;
    int puissance=0; // stoi
    string pr;
    float prix= 0.0;
    string chmoteur;
    int choixmoteur;
    
    cout<< " Nom modele : " ;
    getline(flux,nom);
    //m.setNom(nom.data()): 
    size_t size= nom.size() +1;
    char n[size];
    strncpy(n,nom.c_str(), size);
  
    m.setNom(n);

    
    cout<< "Puissance : " ;
    getline(flux,pr);
    puissance=stoi(pr);


    m.setPuissance(puissance);

   
    cout<< "Prix de base : " ;
    getline(flux,pr);

    prix=stof(pr);
    m.setPrixDeBase(prix);

    

    cout<<"Type de moteur du modele, 1 pour Essence , 2 pour Diesel, 3 pour Electrique , 4 pour Hybride";
    cin>>choixmoteur;
    switch(choixmoteur)
    {
      case 1:
           cout<<"Essence"<<endl;
           m.setMoteur(Essence);
          break;

      case 2:
          cout<<"Diesel"<<endl;
          m.setMoteur(Diesel);
          break;

      case 3:
          cout<<"Electrique"<<endl;
          m.setMoteur(Electrique);
          break;

      case 4:
          cout<<"Hybride"<<endl;
          m.setMoteur(Hybride);
          break;

    }


    

    return flux;

  }