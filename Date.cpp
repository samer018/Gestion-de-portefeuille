#include "Date.h"

using namespace std;

Date::Date(int j, int m, int a): jour(j),mois(m),annee(a)
{

}
Date::~Date()
{

}

void Date::AfficherDate()
{
   cout << jour << "/" << mois << "/"<< annee<< endl;
}

void Date::Incrementer(int n)
{
    bool anneebissextile(false);

    if(annee % 4 == 0)
        anneebissextile=true;


    int nbreJourMois(0);

    switch(mois)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            nbreJourMois = 31;
    }
    switch(mois)
    {
        case 2:
            if(anneebissextile)
            {
                nbreJourMois = 29;
            }
            else
            {
                nbreJourMois = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            nbreJourMois = 30;
            break;
    }

while ((n + jour) > nbreJourMois)
    {
        n -= nbreJourMois;
        if (mois == 12)
        {
            mois = 0;
            annee++;
        }
        mois++;
    }
    jour += n;

}

void Date::Decrementer()
{
    bool anneebissextile(false);

    if(annee % 4 == 0)
        anneebissextile=true;


    int nbreJourMois(0);
    switch(mois)
    {
        case 2:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
        case 1:
            nbreJourMois = 31;
    }
    switch(mois)
    {
        case 3:
            if(anneebissextile)
            {
                nbreJourMois = 29;
            }
            else
            {
                nbreJourMois = 28;
            }
            break;
        case 5:
        case 7:
        case 10:
        case 12:
            nbreJourMois = 30;
            break;
    }

if(jour==1)
{
    if(mois==1)
    {
        jour=nbreJourMois;
        annee-=1;
        mois=12;
    }
    else
    {
        jour=nbreJourMois;
        mois-=1;
    }

}
else
{
    jour-=1;

}
}

bool operator==(Date const& a,Date const& b)
{
       if (a.jour == b.jour && a.mois == b.mois && a.annee == b.annee)
       {
           return(true);
       }

       else
       {
           return(false);
       }


}
