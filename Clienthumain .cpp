#include "Clienthumain.h"
using namespace std;

Clienthumain::Clienthumain(string a,string b,string c,string d,float e):nom(a),prenom(b),login(c),psw(d),budget_init(e),liquidite(e){}

Clienthumain::~Clienthumain(){
                              }

 void Clienthumain::AjouterTitre(Titre t, Date d)
{
    float j;
    porte.push_back(t);
    j=Bourse::TrouverPrix(t.getAction(),d);
    liquidite-=t.getQuantite()*j;



}

void Clienthumain::AjouterBudget(float a) // a peut etre negatif
{
    liquidite+=a;
    budget_init+=a;
}

void Clienthumain::ModifierTitre(string action,int q, Date d)//q peut etre negatif
{
    float j;
    for(int i(0);i<porte.size();i++)
    {

        if (porte[i].getAction()==action)
        {
            porte[i].ModifierQuantite(q);

            j=Bourse::TrouverPrix(action,d);
            liquidite-=q*j;
        }
    }
}


string Clienthumain::getLogin()
{
    return(login);
}
string Clienthumain::getPsw()
{
    return(psw);
}
float Clienthumain::getLiquidite()
{
    return(liquidite);
}

float Clienthumain::Benefice(Date cejour)
{
    float b=0;
      for (int i=0;i<porte.size();i++){
          b+=porte[i].getQuantite()*Bourse::TrouverPrix(porte[i].getAction(),cejour);
          }
      b=b+liquidite-budget_init;
      return(b);

}


Date Clienthumain::choisirDate(){
                            Date d(1,1,2010);

                            cout<< " On va choisir la date de debut pour les transactions" << endl;
                            cout << "enter le jour" << endl;
                            cin >> d.jour;
                            cout << "enter le mois"<< endl;
                            cin >> d.mois;
                            cout << "enter l'annee"<< endl;
                            cin >> d.annee;
                            bool b=false;
                            while (!b) {

                                  for (int i=0;i<Bourse::vprix.size();i++){
                                        if (Bourse::vprix[i].getDate()==d ) {
                                           b=true;
                                           break;
                                           }
                                  }
                                  if (!b) {
                                      d.Incrementer(1);
                                  }
                            }
                            return(d);
}


TypeTransaction Clienthumain::operation(Date d){
                string s;
                TypeTransaction tt;
                bool v =false;
                       while (!v) {
                             cout << "'Entrer 'achat','vente','rien','ajouter' ou 'deconnecter'" << endl;
                             cin >> s;
                             if (s=="achat"){
                                       tt=achat;
                                       v=true;
                                     }
                             else if (s=="vente"){
                                       tt=vente;
                                       v=true;
                                     }
                             else if (s=="rien"){
                                       tt=rien;
                                       v=true;
                                     }
                             else if (s=="ajouter"){
                                       tt=ajouter;
                                       v=true;
                                     }
                             else if (s=="deconnecter"){
                                       tt= deconnecter;
                                       v=true;
                                     }
                       }
                       if (tt==rien){
                              bool b=false;
                              while (!b) {
                                    d.Incrementer(1);
                                    for (int i=0;i<Bourse::vprix.size();i++){
                                        if (Bourse::vprix[i].getDate()==d ) {
                                           b=true;
                                           break;
                                        }
                                    }
                                    if (d.annee==2017) {
                                        cout << "date limite depassé";
                                        tt=deconnecter;
                                        break;
                                    }

                              }

                       }

                       else if (tt==achat || tt==vente){
                            string act;
                            int q;
                            cout <<"entrez le nom de l'action à acheter/vendre" << endl;
                            cin >> act;
                            cout <<"entrez la quantite de l'action à acheter/vendre" << endl;
                            cin >> q;

                            if (tt==achat)  this->Acheter(act,q,d);

                            else  this->Vendre(act,q,d);
                       }
                       else if (tt==ajouter) {
                               cout << "entrer le montant à ajouter" << endl;
                               float b;
                               cin >> b;
                               this->AjouterBudget(b);
                       }
                       return(tt);
}
void Clienthumain::Acheter(string act,int q,Date d){
     bool existe=false;
     for (int i=0;i<porte.size();i++){
         if (porte[i].getAction()==act){
                          ModifierTitre(act,q,d);
                          existe=true;
                          break;
         }
     }
     if (!existe) {
                Titre t(act,q);
                AjouterTitre(t,d);


     }
}
void Clienthumain::Vendre(string act,int q,Date d){

     for (int i=0;i<porte.size();i++){
         if (porte[i].getAction()==act){
                          ModifierTitre(act,-q,d);
                          break;
         }

     }
}






