#include "Achatrobot.h"

using namespace std;

vector<Transaction> Achatrobot(Date &cejour,Robotrader &h)
{
vector<Transaction> v;
Date hier(cejour.jour,cejour.mois,cejour.annee);
hier.Decrementer();
for(int i(0);i<h.porte.size();i++)
{
    if (Bourse::TrouverPrix(h.porte[i].getAction(),cejour)> Bourse::TrouverPrix(h.porte[i].getAction(),hier))
        {
            TypeTransaction a(achat);
            Transaction t(a,h.porte[i].getAction(),h.porte[i].getQuantite());
            v.push_back(t);

        }
    else
    {
        TypeTransaction a(rien);
        Transaction t(a,"",0);
        v.push_back(t);
    }

}
return(v);
}
