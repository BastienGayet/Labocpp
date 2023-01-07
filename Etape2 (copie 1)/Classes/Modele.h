#ifndef MODELE_H   /// dans un fichier .h il y aura tjrs ça 
#define MODELE_H
#include <iostream>
using namespace std;


enum Moteur {Essence, Diesel, Electrique, Hybride};

class Modele
{ 
  private: 
    char * nom;
    int puissance;
    Moteur moteur; // je declare une genre de structure  // moteur gauche variable moteur droite type 
    float prixdeBase;

  public:

    Modele();
    Modele(const char*,int,Moteur,float);
    Modele(const Modele &);  // const reference
    ~Modele(); // destructeur 

    const char * getNom()const;
    int getPuissance() const;
    float getPrixDeBase()const;
    Moteur getMoteur()const;

    void setNom(const char * nom);  // const car je vais pas modifier le nom
    void setPuissance(int);
    void setPrixDeBase(float);
    void setMoteur(Moteur);
   

    void Affiche()const;
};

#endif