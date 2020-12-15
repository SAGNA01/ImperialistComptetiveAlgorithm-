#include "Problem.h"

//Problem::Problem() : _dimension{30}, _LowerLimit{-2.048}, _UpperLimit{2.048}, _numfunction{3}
//{}

Problem::Problem(int dimension, double LowerLimit, double UpperLimit, int numfunction) : _dimension{dimension},
                                                                                         _LowerLimit{LowerLimit},
                                                                                         _UpperLimit{UpperLimit},
                                                                                         _numfunction{numfunction}
{}

Problem::Problem(int dimension, int numfunction) : _dimension{dimension}, _numfunction{numfunction}
{
   switch (_numfunction)
	{
	case 1: // Rosenbrock
		_LowerLimit = -2.048;
		_UpperLimit = 2.048;
		break;
	case 2: // Rastrigin
		_LowerLimit = -5.12;
		_UpperLimit = 5.12;
		break;
	case 3: // Ackley
		_LowerLimit = -32.768;
		_UpperLimit = 32.768;
		break;
	case 4: // Schwefel
		_LowerLimit = -500;
		_UpperLimit = 500;
		break;
	case 5: // schaffer
		_LowerLimit = -100;
		_UpperLimit = 100;
		break;
	case 6: // Weierstrass
		_LowerLimit = -30;
		_UpperLimit = 30;
		break;
	}
}

int Problem::getDimension() const
{
    return _dimension;
}

int Problem::getNumerofunction() const
{
    return _numfunction;
}

double Problem::getLowerLimit() const
{
    return _LowerLimit;
}

double Problem::getUpperLimit() const
{
    return _UpperLimit;
}

void Problem::setLowerLimit(double valeur)
{
    _LowerLimit = valeur;
}
void Problem::setUpperLimit(double valeur)
{
    _UpperLimit = valeur;
}
void Problem::setNumerofunction(int num)
{
    _numfunction = num;
}
void Problem::afficherParametres(std::ostream& ost, const Problem& pbm)
{
    ost << "\t\t\t Function id : " << pbm.getNumerofunction()<<std::endl;
    ost << "\t\t\t LowerLimit : " << pbm.getLowerLimit()<<std::endl;
    ost << "\t\t\t UpperLimit : " << pbm.getUpperLimit()<<std::endl;
}

void Problem::saisirParametres(std::istream& ist, Problem pbm)
{
    std::cout<<"\t\t\t Function id : ";
    ist>>pbm._numfunction;
    switch (pbm._numfunction)
	{
	case 1: // Rosenbrock
	    std::cout<<"\t\t\t Rosenbrock function\n";
		pbm.getLowerLimit();
		pbm.getUpperLimit();
		break;
	case 2: // Rastrigin
	    std::cout<<"\t\t\t Rastrigin function\n";
		pbm.getLowerLimit();
		pbm.getUpperLimit();
		break;
	case 3: // Ackley
	    std::cout<<"\t\t\t Ackley function\n";
		pbm.getLowerLimit();
		pbm.getUpperLimit();
		break;
	case 4: // Schwefel
	    std::cout<<"\t\t\t Schwefel function\n";
		pbm.setLowerLimit(-500);
		pbm.setUpperLimit(500);
		break;
	case 5: // schaffer
	    std::cout<<"\t\t\t schaffer function\n";
		pbm.setLowerLimit(-100);
		pbm.setUpperLimit(100);
		break;
	case 6: // Weierstrass
	    std::cout<<"\t\t\t Weierstrass function\n";
		pbm.setLowerLimit(-30);
		pbm.setUpperLimit(30);
		break;
	}
}
