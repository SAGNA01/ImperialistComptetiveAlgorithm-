#include "SetUpParams.h"

//#define _USE_MATH_DEFINES
#include <cmath>
SetUpParams::SetUpParams() : _independent_runs(30), _nb_evolution_steps((int)((2 * pow(10, 6)) / 200)),
                             _population_size(200), _solution_size(30)

{

}
SetUpParams::SetUpParams(unsigned int ind_runs, unsigned int nbEvolu_steps,
                         unsigned int population_size, unsigned int solution_size):

                         _independent_runs{ind_runs},
                         _nb_evolution_steps{(int)((2 * pow(10, 6) / _population_size))},
                         _population_size{population_size},
                         _solution_size{solution_size}
{}

const unsigned int SetUpParams::getIndependent_runs() const
{
    return _independent_runs;
}

const unsigned int SetUpParams::getNb_evolution_steps() const
{
    return _nb_evolution_steps;
}

const unsigned int SetUpParams::getPopulation_size() const
{
    return _population_size;
}

const unsigned int SetUpParams::getSolution_size() const
{
    return _solution_size;
}

void SetUpParams::setIndependent_runs(const unsigned int runs)
{
    _independent_runs = runs;
}
void SetUpParams::setNb_evolution_steps(const unsigned int steps)
{
    _nb_evolution_steps = steps;
}
void SetUpParams::setPopulation_size(const unsigned int pop)
{
    _population_size = pop;
}
void SetUpParams::setSolution_size(const unsigned int sol)
{
    _solution_size = sol;
}

SetUpParams::~SetUpParams()
{

}

std::istream& operator>> (std::istream& ist, SetUpParams setup)
{
    unsigned int runs, steps, population, solution;

    std::cout<<"\t\t\t The rapameters : \n\n";
    std::cout<<"\t\t\t Nombre d'execution : ";
	ist>>runs;
	std::cout<<"\t\t\t Nombre d'iteration : ";
	ist>>steps;
	std::cout<<"\t\t\t Population : ";
	ist>>population;
	std::cout<<"\t\t\t Solution : ";
	ist>>solution;

	if (ist.good())
	{
		setup.setIndependent_runs(runs);
		setup.setNb_evolution_steps(steps);
		setup.setPopulation_size(population);
		setup.setSolution_size(solution);
	}
	return ist;
}

std::ostream& operator<<(std::ostream& ost, SetUpParams& setup)
{
    ost<<setup.getIndependent_runs()<< std::endl;
    ost<<setup.getNb_evolution_steps()<< std::endl;
    ost<<setup.getPopulation_size()<< std::endl;
    ost<<setup.getSolution_size()<< std::endl;

    return ost;
}
