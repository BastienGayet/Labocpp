#ifndef MODELE_H   /// dans un fichier .h il y aura tjrs ça 
#define MODELE_H
#include <iostream>
using namespace std;
#include <fstream> 


enum Moteur {Essence, Diesel, Electrique, Hybride};

class Modele
{ 

    friend ostream& operator<<(ostream&, const Modele&);
    friend istream& operator>>(istream&, Modele&);
  private: 
    char * nom;
    int puissance;
    Moteur moteur; // je declare une genre de structure  // moteur gauche type moteur droite nom variable
    float prixdeBase;

    string image; 

  public:

    Modele();
    Modele(const char*,int,Moteur,float);
    Modele(const Modele &);  // const reference
    ~Modele(); // destructeur 

    Modele& operator=(const Modele& );

    const char * getNom()const;
    int getPuissance() const;
    float getPrixDeBase()const;
    Moteur getMoteur()const;

    string getImage()const;

    void setNom(const char * nom);  // const car je vais pas modifier le nom
    void setPuissance(int);
    void setPrixDeBase(float);
    void setMoteur(Moteur);

    void setImage(string);
   

    void Affiche()const;



    /******FLUX BYTES*****/

    void Save(ofstream & ) const;

    void Load(ifstream &) ;
};

#endif