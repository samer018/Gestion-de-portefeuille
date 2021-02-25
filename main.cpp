#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Bourse.h"
#include "Trader.h"
#include "Clienthumain.h"
#include "Date.h"
#include "Prix_journalier.h"
#include "Robotrader.h"
#include "Robotrader2.h"
#include "Titre.h"
#include "Transaction.h"
using namespace std;

int main()
{

    /*Date cejour(1,1,2016);
    Date hier(cejour.jour,cejour.mois,cejour.annee);
    hier.Decrementer();
    Date b (1,2,4);
    cout << hier.jour << endl;*/


   ifstream fichier("prices.csv");

   if(fichier)
   {

     Bourse b;
     string ligne;
     getline(fichier, ligne);
      while(getline(fichier, ligne))
      {
         Date d(atoi(ligne.substr(8,2).c_str()),atoi(ligne.substr(5,2).c_str()),atoi(ligne.substr(0,4).c_str() ));
         int pos1=ligne.find(",");
         int pos2=ligne.substr(pos1+1).find(",");
         string act=ligne.substr(pos1+1,pos2);
         float prix=atof(ligne.substr(pos1+pos2+2 ,  ligne.substr(pos1+pos2+2).find(",")).c_str() )   ;

         Prix_journalier pj (act,prix,d);
         b.AjouterPrixJournalier(pj);

      }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }
   Bourse::action.push_back("WLTW");
   for(int i=0; i<Bourse::vprix.size();i++)
   {
       bool test (false);
       for(int j=0;j<Bourse::action.size();j++)
       {
           if(Bourse::action[j]==Bourse::vprix[i].getAction())
            test=true;
       }
       if (!test)
           Bourse::action.push_back(Bourse::vprix[i].getAction());

   }





   int mode=0;






    cout << "Bienvenue dans notre bourse"  << endl<<endl;

    cout << "Inscrivez-vous s'il vous plait" << endl<<endl;
    string aa,bb,cc,dd;
    float e=0;
    int n=0;
    cout << "Entrez votre nom"  <<endl;
    cin >> aa ;
    cout << "Entrez votre prenom"  <<endl;
    cin >> bb   ;
    cout << "Entrez votre login"  <<endl;
    cin >> cc  ;
    cout << "Entrez votre mot de passe"  <<endl;
    cin >> dd  ;
    while(e<50000)
    {
        cout << "Entrez votre budget (>=50000)"  <<endl;
        cin >> e  ;
    }



    cout << "Pour travailler en mode client humain, entrez 1." <<endl;
    cout << "Pour travailler en mode Robotrader, entrez 2." <<endl;
    cout << "Pour travailler en mode Robotrader2, entrez 3." <<endl;
    cin >> mode;

    if (mode==1){

                 TypeTransaction tt;
                 string act,s;
                 int q;
                 Clienthumain cl(aa,bb,cc,dd,e);
                 Date cejour(1,1,2010);
                 cejour=Clienthumain::choisirDate();
                 while (tt !=deconnecter){

                         tt=cl.operation(cejour);
                 }
                 cout<<"Voila votre benefice"<<endl;

                 cout << cl.Benefice(cejour) << endl;

    }
    if (mode==2){

                 bool connecte(true);

                 Robotrader R(aa,bb,cc,dd,e);
                 Date cejour(1,1,2010);
                 cejour=Robotrader::choisirDate();

                  while(connecte==true)
                 {
                     vector<Transaction> tr;
                     tr=R.Trans(cejour);

                     R.Appliquer(cejour,connecte,tr);
                     cejour.Incrementer(1);
                     bool b=false;
while (!b) {

for (int i=0;i<Bourse::vprix.size();i++){
if (Bourse::vprix[i].getDate()==cejour ) {
        b=true;
        break;
                                           }
        }
        if (!b) {
    cejour.Incrementer(1);
                                  }
}
cout << "Votre liquidite est estimee de "<< endl;
cout << R.getLiquidite()<< endl;
                 }
                 cout<<"Voila votre benefice"<<endl;

                 cout << R.Benefice(cejour) << endl;


    }
     if (mode==3){

                 bool connecte(true);


                 Robotrader R(aa,bb,cc,dd,e);
                 Date cejour(1,1,2010);
                 cejour=Robotrader::choisirDate();
                  while(connecte==true)
                 {
                     vector<Transaction> tr;
                     tr=R.Trans(cejour);
                     R.Appliquer(cejour,connecte,tr);
                     cejour.Incrementer(1);
                     bool b=false;
while (!b) {

for (int i=0;i<Bourse::vprix.size();i++){
if (Bourse::vprix[i].getDate()==cejour ) {
        b=true;
        break;
                                           }
        }
        if (!b) {
    cejour.Incrementer(1);
                                  }
}
cout << "Votre liquidite est estimee de "<< endl;
cout << R.getLiquidite()<< endl;


                 }
                 cout<< "Voila Votre benefice."<<endl;

                 cout << R.Benefice(cejour) << endl;


    }
    return 0;

}
