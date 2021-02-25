#ifndef ACHATROBOT_H_INCLUDED
#define ACHATROBOT_H_INCLUDED
#include <vector>
#include<string>
#include "Transaction.h"
#include "Date.h"
#include "Robotrader.h"

std::vector<Transaction> Achatrobot(Date &cejour,Robotrader &h);


#endif // ACHATROBOT_H_INCLUDED
