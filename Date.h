#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
class Date
{
public :
    Date(int jour, int mois, int annee);
    ~Date();
    void AfficherDate();
    void Incrementer(int n);
    void Decrementer();
    int jour ;
    int mois ;
    int annee ;




};

bool operator==(Date const& a,Date const& b);//Comparer entre deux dates

#endif // DATE_H_INCLUDED
