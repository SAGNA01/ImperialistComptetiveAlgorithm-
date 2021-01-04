#ifndef EMPIRE_H
#define EMPIRE_H
#include "Country.h"
#include<vector>
#include <ctime>
using namespace std;
class Empire
{
public:
    Empire();
    double calculateCost();
    void replaceColony(int index,Country* colony);
    void deleteColony( int index);
    double getCost();
    void addColony(Country* colony);
    void removeColony(int index);
    int getNumberOfColonies();
    Country* getColony(int index);
    Country* bestSolution();
    Country* weakesSolution();
    int weakestColonyIndex();
    int bestColonyIndex();
    virtual ~Empire();


protected:

private:
    vector<Country*> _colonies;
    double cost;
};

#endif // EMPIRE_H
