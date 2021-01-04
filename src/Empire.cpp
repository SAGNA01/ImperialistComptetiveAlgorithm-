#include "Empire.h"

Empire::Empire() :cost{0.0}
{

}
Empire::~Empire()
{

}

double Empire::calculateCost()
{
    cost = 0.0;

if (_colonies.size()>0){
        for( unsigned int i=0; i <_colonies.size(); i++ )
        {
            cost = cost+ _colonies.at(i)->get_fitness();
        }
}
    return cost;
}

void Empire::replaceColony(int index, Country* colony)
{
    _colonies[index]=colony;
    calculateCost();
}

void Empire::deleteColony(int index)
{
    _colonies[index]=_colonies.back();
    _colonies.pop_back();
    calculateCost();

}

double Empire::getCost()
{
    return cost;
}

void Empire::addColony( Country* colony)
{
    _colonies.push_back(colony);
   calculateCost();
}

void Empire::removeColony(int index)
{

    _colonies[index]=_colonies.back();
    _colonies.pop_back();
    calculateCost();
}

int Empire::getNumberOfColonies()
{
    return   _colonies.size();
}

Country* Empire::getColony(int index)
{
    return  _colonies[index];
}
Country* Empire::bestSolution()
{
    if (_colonies.size()>0)
    {
        Country* best =  _colonies[0];
        for (unsigned int i = 1; i < _colonies.size(); i++)
        {
            if (_colonies[i]->get_fitness() < best->get_fitness() )
            {
                best=_colonies[i];
            }
        }
        return best;
    }
    else
    {
        return NULL ;
    }
}

Country* Empire::weakesSolution()
{
    Country* weakes =  _colonies[0];
    if ( _colonies.size()>0)
    {
        for (unsigned int i = 1; i < _colonies.size(); i++)
        {
            if (_colonies[i]->get_fitness() > weakes->get_fitness() )
            {
                weakes=_colonies[i];
            }
        }
    }
    return weakes;

}
int Empire::weakestColonyIndex()
{
    int weakesIndex = 0;
    if ( _colonies.size()>0)
    {
        for (unsigned int i = 1; i < _colonies.size(); i++)
        {
            if (_colonies[i]->get_fitness() > _colonies[weakesIndex]->get_fitness() )
            {
                weakesIndex=i;
            }
        }
    }
    return weakesIndex;

}
int Empire::bestColonyIndex()
{
    if (_colonies.size()>0)
    {
        int best =  0;
        for (unsigned int i = 1; i < _colonies.size(); i++)
        {
            if (_colonies[i]->get_fitness() < _colonies[best]->get_fitness() )
            {
                best=i;
            }
        }
        return best;
    }
    else
    {
        return NULL ;
    }

}


