#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H
#include<iostream>
#include <cmath>
using namespace std;

class SetUpParams
{
public:
    SetUpParams();
    SetUpParams(unsigned int independent_runs, unsigned int number_of_iterations,unsigned int number_of_countries, unsigned int number_of_empires);
     double get_assimilation_rate()const;
     double get_revolution_rate ()const;
     double get_alpha_rate ()const;
     double get_revolution_probability ()const;
     double get_neighbourhood_radius ()const;
     double get_constant_gravitation()const;

     unsigned int get_independent_runs()const;
     unsigned int get_number_of_iterations()const;
     unsigned int get_number_of_countries()const;
     unsigned int get_number_of_empires()const;

     void set_independent_runs(unsigned int independent_runs);
     void set_number_of_iterations(unsigned int number_of_iterations);
     void set_number_of_countries(unsigned int number_of_countries);
     void set_number_of_empires(unsigned int number_of_empires);

     virtual ~SetUpParams();
     friend istream& operator >>(istream& ist, SetUpParams& setup);
protected:

private:

    double assimilation_rate = 1.0; // 2
    double revolution_rate = 0.7; // 0.3
    double alpha_rate = 0.8;
    double revolution_probability = 0.8;
    double neighbourhood_radius = 0.1;
    double constant_gravitation= 6.672;

    unsigned int _independent_runs;
    unsigned int _number_of_iterations;
    unsigned int _number_of_countries;
    unsigned int _number_of_empires ;
};

#endif // SETUPPARAMS_H
