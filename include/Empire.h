#ifndef EMPIRE_H
#define EMPIRE_H
#include "CountrySolution.h"
#include<vector>
#include <ctime>
using namespace std;
class Empire
{
public:
    Empire();
    double calculateCost();
    void replaceColony(int index,CountrySolution* colony);
    void deleteColony( int index);
    double getCost();
    void addColony(CountrySolution* colony);
    void removeColony(int index);
    int getNumberOfColonies();
    CountrySolution* getColony(int index);
    CountrySolution* bestSolution();
    CountrySolution* weakesSolution();
    int weakestColonyIndex();
    int bestColonyIndex();
    virtual ~Empire();

private:
    vector<CountrySolution*> _colonies;
    double cost;
};

#endif // EMPIRE_H
