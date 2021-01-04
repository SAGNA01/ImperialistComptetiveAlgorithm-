#include "Country.h"
#define M_PI 3.14159265
Country::Country(const Problem& pbm):_pbm {pbm},_current_fitness {0.0}
{
    initialize();
}

Country::Country(const Country& sol) : _current_fitness{sol._current_fitness}, _pbm{sol._pbm}
{

}

Country::~Country()
{

}

const Problem& Country::pbm() const
{
    return _pbm;
}


void Country::initialize()
{
    _Country.resize((unsigned long long int) _pbm.getDimension());
    srand(time(0));
    for (unsigned int i = 0; i < _Country.size(); ++i)
    {
        _Country[i] = (double) rand() / (double) RAND_MAX * (_pbm.getUpperLimit() - _pbm.getLowerLimit()) + _pbm.getLowerLimit();

    }
}
bool Country::isColony() const
{
    return is_Colony;

}
void Country::setisColony()
{
    is_Colony=!is_Colony;
}
void Country::setCountry(vector<double>& country)
{
    _Country=country;
}
double Country::fitness()
{
    vector<double> c =  _Country;
    double sum = 0.0;
    int dim =(int) _Country.size();
    int i;
    double currentfitness;
    int    numFunction = _pbm.getNumeroFonction();

    switch (numFunction)
    {
    case 1: // Rosenbrock
    {

        for ( i = 0; i < dim - 1; i++)
        {
            sum += 100 * (pow((c[i + 1] - pow(c[i], 2)), 2)) + pow( 1 - c[i], 2);
        }

        currentfitness = sum;
    }
    break;
    case 2: // Rastrigin
    {
        for ( i = 0; i < dim; i++)
        {
            sum += pow(c[i], 2) - (10 * cos(2 * M_PI * c[i]));
        }
        currentfitness = (10 * dim) + sum;
    }
    break;
    case 3: // Ackley
    {
        double sum1=0, sum2=0;
        for ( i = 0; i < dim; i++)
        {
            sum1 += pow(c[i], 2);
            sum2 += cos(2 * M_PI * c[i]);
        }
        sum = -20 * exp(-0.02*sqrt((1 / dim) * sum1)) - exp((1 / dim) * sum2) + 20 + exp(1);
        currentfitness = sum;
    }
    break;
    case 4: // Schwefel
    {
        for ( i = 0; i < dim; i++)
        {
            sum += c[i] * sin(sqrt(abs(c[i])));
        }
        currentfitness = 418.982887272434686131 * dim - sum;
    }
    break;
    case 5: // Schaffer
    {
        for ( i = 0; i < dim - 1; i++)
        {
            sum += (pow(sin(pow(c[i], 2) - pow(c[i + 1], 2)), 2) - 0.5) / (pow(1 + 0.001*(pow(c[i], 2) + pow(c[i + 1], 2)), 2));
        }
        currentfitness = 0.5 + sum;
    }
    break;
    case 6: // Weierstrass
    {
        double a, b;
        unsigned int k_max;
        a = 0.5;
        b = 3.0;
        k_max = 20;

        for ( int i = 0; i < dim; i++)
        {
            for (unsigned int t = 0; t <= k_max; t++)
            {
                sum = sum+pow(a, (double)t) * cos(2.0 * M_PI * pow(b, (double)t) * (c[i] + 0.5));
            }
        }
        currentfitness = sum;
    }
    break;
    }
    _current_fitness =currentfitness;
    return currentfitness;
}

double Country::get_fitness()
{
    fitness();
    return _current_fitness;
}

vector<double>& Country::getCountry()
{
    return _Country;
}
