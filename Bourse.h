#ifndef BOURSE_H_INCLUDED
#define BOURSE_H_INCLUDED
#include <vector>
#include<string>
#include "Date.h"
#include "Prix_journalier.h"
class Bourse
{
      public:
      Bourse();
      ~Bourse();
      void AjouterPrixJournalier(Prix_journalier p);
      static float TrouverPrix(std::string act,Date &d);
      static bool Etat(std::string action, Date d);//verifier que le prix d'aujourd'hui est supérieur à celui d'hier
      static std::vector <Prix_journalier> vprix;
      static std::vector <std::string> action;//vecteur comportant tous les noms des actions.


};

#endif
