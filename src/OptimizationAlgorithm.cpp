#include "OptimizationAlgorithm.h"


OptimizationAlgorithm::OptimizationAlgorithm(const Problem& pbm, const SetUpParams& setup) :_pbm{pbm}, _setup{setup}
{

}
OptimizationAlgorithm::~OptimizationAlgorithm()
{

}

void OptimizationAlgorithm::removeEmpire(int index)
{
    _empires[index] =_empires.back();
    _empires.pop_back();
}

void OptimizationAlgorithm::createCountries()
{
    _countries.clear();
    int number_of_countries = _setup.get_number_of_countries();
    for (int i = 0; i < number_of_countries; i++)
    {
        CountrySolution *c = new CountrySolution(_pbm);
        _countries.push_back(c);
    }
    for (int i = 0; i < number_of_countries; i++)
    {
        for (int j = 0; j < number_of_countries; j++)
        {
            if (_countries[i]->get_fitness() > _countries[j]->get_fitness() )
            {
                CountrySolution *temp =  _countries[i];
                _countries[i] =_countries[j];
                _countries[j] = temp;
            }
        }
    }
}

//Creation of initial empires
void OptimizationAlgorithm::createEmpires()
{
    _empires.clear();
    int number_of_empires = _setup.get_number_of_empires();

    for (int i = 0; i < number_of_empires; i++)
    {
        Empire *e = new Empire();

        e->addColony(_countries[i]);
        _empires.push_back(e) ;
    }

    double alpha_rate =_setup.get_alpha_rate();
    double max_cost=  _empires[number_of_empires-1]->getCost();

    vector<double> P;
    double sumP=0.0;
    for (int i = 0; i < _empires.size(); i++)
    {
        P.push_back(exp((-alpha_rate * _empires[i]->getCost())/max_cost));
        sumP += P[i];
    }
    for (unsigned int i = 0; i < P.size(); i++)
    {
        P[i]=P[i]/sumP;
        if (i>0)
        {
            P[i]= P[i]+ P[i-1];
        }
    }

    srand(time(0));
    for ( unsigned int i = _empires.size(); i < _countries.size(); i++)
    {

        double r = ((double) rand()  / (RAND_MAX));

        int k = 0;
        while (P[k]<r && k<number_of_empires)
        {
            k++;
        }
        _empires[k]->addColony(_countries[i]);
    }
}

//Assimilation;  Movement of colonies toward imperialists
void OptimizationAlgorithm::assimilate()
{
    unsigned int number_of_empires =  _empires.size();
    double assimilation_rate = _setup.get_assimilation_rate();
    if (number_of_empires!=0)
    {
        for (unsigned int i = 0; i < number_of_empires; i++)
        {
            CountrySolution* empire_representation = _empires[i]->bestSolution();
            int numberOfColonies = _empires[i]->getNumberOfColonies();
            if (numberOfColonies!= 0)
            {
                for ( int j = 0; j < numberOfColonies; j++)
                {
                    CountrySolution*  colony_representation =  _empires[i]->getColony(j);
                    int colony_size =(int)colony_representation->getCountry().size();
                    int number_of_tasks = (int)(colony_size*assimilation_rate);
                    vector<double> colony =  colony_representation->getCountry();
                    srand(time(0));
                    for ( int  k = 0; k < number_of_tasks; k++)
                    {
                        int index = rand() % colony_size;
                        colony[index]=empire_representation->getCountry()[index];
                    }
                    colony_representation->setCountry(colony);
                    _empires[i]->replaceColony(j,colony_representation);

                    }
            }
            else
            {

                removeEmpire(i);
            }
        }
    }
}

void OptimizationAlgorithm::revolution()
{
    double revolution_probability = _setup.get_revolution_probability();
    double revolution_rate = _setup.get_revolution_rate();
    vector<int> exchange_temp;
    vector<int> exchange;
    vector<int> exchange_candidates;
    vector<int> candidates;
    for (unsigned int i = 0; i < _empires.size(); ++i)
    {

        int numberOfColonies = _empires[i]->getNumberOfColonies();

        srand(time(0));
        for ( int j = 0; j < numberOfColonies; j++)
        {
            double r = ((double) rand() / (RAND_MAX));
            if (r <= revolution_probability && j !=_empires[i]->bestColonyIndex() )
            {

                exchange_temp.clear();
                exchange.clear();
                exchange_candidates.clear();
                candidates.clear();
                CountrySolution*  colony_representation =  _empires[i]->getColony(j);
                srand(time(0));
                double oldCost = colony_representation->get_fitness();
                int colony_size =(int)colony_representation->getCountry().size();
                int number_of_tasks = (int)(colony_size*revolution_rate);

                int index ;
                for ( int  k = 0; k < number_of_tasks; k++)
                {
                    index = rand() % colony_size;
                    if (std::count(candidates.begin(), candidates.end(), index))
                        k--;
                    else
                        candidates.push_back(index);
                }
                for ( int  k = 0; k < number_of_tasks; k++)
                {
                    index = rand() % colony_size;
                    if (std::count(exchange_temp.begin(), exchange_temp.end(), index))
                        k--;
                    else
                        exchange_temp.push_back(index);
                }

                for ( int l = 0; l <(int) exchange_temp.size() ; l++)
                {
                    if (l !=exchange_temp[l] )
                    {
                        exchange.push_back(l);
                    }
                }

                for ( int  k = 0; k < (int)exchange.size(); k++)
                {
                    index = rand()%(int)exchange.size();

                    if (std::count(exchange_candidates.begin(), exchange_candidates.end(), index))
                        k--;
                    else
                        exchange_candidates.push_back(index);
                }

                CountrySolution*  new_colony_representation = colony_representation;
                vector<double>& new_colony_representation_= new_colony_representation->getCountry();
                vector<double>& colony_representation_= colony_representation ->getCountry();

                for (int  k = 0; k < number_of_tasks; k++)
                {
                    if (exchange_candidates[k] <  new_colony_representation_.size()  && candidates[k]<  new_colony_representation_.size())
                    {
                        new_colony_representation_[exchange_candidates[k]] =colony_representation_[candidates[k]];
                        new_colony_representation_[candidates[k]]= colony_representation_[exchange_candidates[k]];
                    }
                }

                new_colony_representation->setCountry(new_colony_representation_);

                if (new_colony_representation->get_fitness() < oldCost)
                {
                    _empires[i]->replaceColony(j,new_colony_representation);
                }
            }
        }
    }
}

// Imperialistic competition
void OptimizationAlgorithm::interEmpireWar()
{

    if(_empires.size() >= 1)
    {
        int weakest_empire_index = 0;

        double weakest_empire_cost = _empires[weakest_empire_index]->getCost();

        for (unsigned int i = 0; i < _empires.size(); i++)
        {
            if (_empires[i]->getCost()> weakest_empire_cost)
            {
                weakest_empire_index = i ;
            }
        }

        double alpha_rate =_setup.get_alpha_rate();

        double max_cost=  _empires[weakest_empire_index]->getCost();
        vector<double> P;
        double sumP=0.0;

        for ( int i = 0; i <(int) _empires.size(); i++)
        {
            if (i==weakest_empire_index )
            {
                P.push_back(0.0);
            }
            else
            {
                P.push_back(exp((-alpha_rate * _empires[i]->getCost())/max_cost));
                sumP += P[i];
            }

        }
        for (unsigned int i = 0; i < P.size(); i++)
        {
            P[i]=P[i]/sumP;

        }

        srand(time(0));

        if (_empires[weakest_empire_index]->getNumberOfColonies() > 1 )
        {
            int  weakest_colony_index= _empires[weakest_empire_index]->weakestColonyIndex();


            int winning_empire_index = 0;
            double r = ((double) rand() / (RAND_MAX));
            while (P[winning_empire_index]<r && winning_empire_index<_empires.size()-1)
            {
                winning_empire_index++;
            }
            _empires.at(winning_empire_index)->addColony( _empires[weakest_empire_index]->getColony(weakest_colony_index));
            _empires.at(weakest_empire_index)->removeColony(weakest_colony_index);
        }
        srand(time(0));
        if (_empires[weakest_empire_index]->getNumberOfColonies() == 1)
        {
            CountrySolution* weakest_colony = _empires[weakest_empire_index]->getColony(0);
            int winning_empire_index = 0;

            double r = ((double) rand() / (RAND_MAX));
            while (P[winning_empire_index]<r && winning_empire_index<(int)_empires.size())
            {
                winning_empire_index++;
            }
            _empires[winning_empire_index]->addColony(weakest_colony);
            removeEmpire(weakest_empire_index);
        }
    }
}

Empire* OptimizationAlgorithm::bestEmpire()
{
    Empire* best =  _empires[0];
    for (unsigned int i = 1; i < _empires.size(); i++)
    {
        if (_empires[i]->getCost() < best->getCost() )
        {
            best=_empires[i];
        }
    }
    return best;
}
void OptimizationAlgorithm::run()
{
    unsigned int nbiter = _setup.get_number_of_iterations();
    unsigned int nbrun =_setup.get_independent_runs();
    char c = '0';

    for(unsigned int runs = 0; runs < nbrun; runs++)
    {
        createCountries();
        createEmpires();
        c += 1;
        string s = "run_";
        s += c;
        s += ".csv";
        bestSolution = (double) RAND_MAX ;
        ofstream MyFile(s);

        for(unsigned int iter = 0; iter < nbiter; iter++)
        {
            assimilate();
            revolution();
            interEmpireWar();
            if (bestSolution>bestEmpire()->bestSolution()->get_fitness())
            {
                bestSolution =bestEmpire()->bestSolution()->get_fitness();
            }
            MyFile << iter;
            MyFile << ";";
            MyFile <<bestSolution;
            MyFile << "\n";
            cout << "Best solution of  iteration : " <<  iter<<" "<< bestSolution << endl;
        }

        MyFile.close();
        cout<<"Execution run "<< runs+1  <<endl;
        cout << "Best solution :" << bestSolution << endl;
    }
}
