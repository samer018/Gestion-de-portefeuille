#include "Bourse.h"

using namespace std;
vector <Prix_journalier> Bourse::vprix;
vector <string> Bourse::action;
Bourse::Bourse(){};

Bourse::~Bourse(){};

void Bourse::AjouterPrixJournalier(Prix_journalier p){
     vprix.push_back(p);
     }

float Bourse::TrouverPrix(string act,Date &d)
{
    bool test(false);
                for (int i=0;i<vprix.size();i++){
                    if (vprix[i].getDate()==d && vprix[i].getAction()==act) {
                                         test=true;
                                         return(vprix[i].getPrix());
                                         }
                    }
if(!test)
    return(0);

}
bool Bourse::Etat(string action, Date d)
{
    bool x(false);
Date hier(d.jour,d.mois,d.annee);
hier.Decrementer();

bool b=false;
while (!b) {

for (int i=0;i<Bourse::vprix.size();i++){
if (Bourse::vprix[i].getDate()==hier ) {
        b=true;
        break;
                                           }
        }
        if (!b) {
    hier.Decrementer();
                                  }
}

if(Bourse::TrouverPrix(action,d)>=Bourse::TrouverPrix(action,hier))
{
    x=true;
}
return(x);

}
