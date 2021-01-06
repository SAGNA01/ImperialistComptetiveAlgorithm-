#ifndef OPTIMIZATIONALGORITHM_H
#define OPTIMIZATIONALGORITHM_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <limits>
#include <ctime>
#include <chrono>
#include <fstream>

#include"SetUpParams.h"
#include"Problem.h"
#include"CountrySolution.h"
#include"Empire.h"

using namespace std;

class OptimizationAlgorithm
{
    public:
        OptimizationAlgorithm(const Problem& pbm, const SetUpParams& setup);

        virtual ~OptimizationAlgorithm();
        void removeEmpire(int index);
        void createCountries();
        void createEmpires();

        void assimilate();
        void revolution();
        void interEmpireWar();

        Empire* bestEmpire();
        void run ();

    protected:

    private:
     double bestSolution;
     vector<CountrySolution*>  _countries;
     vector<Empire*>  _empires;
     const SetUpParams& _setup;
     const Problem& _pbm;

};

#endif // OPTIMIZATIONALGORITHM_H
