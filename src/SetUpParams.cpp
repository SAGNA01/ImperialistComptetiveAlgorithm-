#include "SetUpParams.h"

SetUpParams::SetUpParams():_independent_runs(1), _number_of_iterations((int)(2000)),
                           _number_of_countries(200), _number_of_empires(8)
{

}
SetUpParams::SetUpParams(unsigned int independent_runs, unsigned int number_of_iterations,unsigned int number_of_countries, unsigned int number_of_empires):_independent_runs(independent_runs), _number_of_iterations(number_of_iterations),
    _number_of_countries(number_of_countries), _number_of_empires(number_of_empires)
{

}

double SetUpParams::get_assimilation_rate() const
{
    return assimilation_rate;
}

double SetUpParams::get_revolution_rate() const
{
    return revolution_rate;
}

double SetUpParams::get_alpha_rate() const
{
    return alpha_rate;
}

double SetUpParams::get_revolution_probability() const
{
    return revolution_probability;
}

double SetUpParams::get_neighbourhood_radius() const
{
    return neighbourhood_radius;
}

double SetUpParams::get_constant_gravitation() const
{
    return  constant_gravitation;
}

unsigned int SetUpParams::get_independent_runs() const
{
    return _independent_runs;
}

unsigned int SetUpParams::get_number_of_iterations() const
{
    return _number_of_iterations;
}

unsigned int SetUpParams::get_number_of_countries() const
{
    return _number_of_countries;
}

unsigned int SetUpParams::get_number_of_empires() const
{
    return  _number_of_empires;
}

void SetUpParams::set_independent_runs(unsigned int independent_runs)
{
   _independent_runs=independent_runs;
}
void SetUpParams::set_number_of_iterations(unsigned int number_of_iterations)
{
    _number_of_iterations=number_of_iterations;
}
void SetUpParams::set_number_of_countries(unsigned int number_of_countries)
{
    _number_of_countries=number_of_countries;
}
void SetUpParams::set_number_of_empires(unsigned int number_of_empires)
{
    _number_of_empires=number_of_empires;
}
istream& operator>> (istream& ist, SetUpParams& setup)
{
    unsigned int runs, steps, country, empire;

    cout<<"\t\t\t The rapameters : \n\n";
    cout<<"\t\t\t Nombre d'execution : ";
	ist>>runs;
	cout<<"\t\t\t Nombre d'iteration : ";
	ist>>steps;
	cout<<"\t\t\t pays : ";
	ist>>country;
	cout<<"\t\t\t empire : ";
	ist>>empire;

	if (ist.good())
	{
		setup.set_independent_runs(runs);
		setup.set_number_of_iterations(steps);
		setup.set_number_of_countries(country);
		setup.set_number_of_empires(empire);
	}
	return ist;
}

SetUpParams::~SetUpParams()
{
    //dtor
}
