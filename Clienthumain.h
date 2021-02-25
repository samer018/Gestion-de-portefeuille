#ifndef CLIENTHUMAIN_H_INCLUDED
#define CLIENTHUMAIN_H_INCLUDED
#include <vector>
#include "Titre.h"
#include "Date.h"
#include "Bourse.h"
#include "Transaction.h"
#include<string>
#include<iostream>

class Clienthumain   {
      public:
    Clienthumain(std::string a,std::string b,std::string c,std::string d,float e);
    ~Clienthumain();
    void AjouterTitre(Titre t, Date d);
    void ModifierTitre(std::string action,int q, Date d);//si on a deja cette action
    void AjouterBudget(float a);
    std::string getLogin();
    std::string getPsw();
    float getLiquidite();
    float Benefice(Date cejour);
    TypeTransaction operation(Date d);
    void Acheter(std::string act,int q,Date d);
    void Vendre(std::string act,int q,Date d);
    static Date choisirDate();//choisir la date de début de treading

    std::vector<Titre>porte;//Les titres du client.


private:
    std::string nom;
    std::string prenom;
    std::string login;
    std::string psw;
    float budget_init;//Budget total
    float liquidite;//montant non encore investis


};








#endif // CLIENTHUMAIN_H_INCLUDED
