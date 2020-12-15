#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include"SetUpParams.h"

class Problem
{
    public:
        //Constructeur du problème
        //Problem();
        Problem(int dimension, double LowerLimit, double UpperLimit, int numfunction);
        Problem(int dimension, int numfunction);
        // Accesseurs de paramètres
        int getDimension() const;
        int getNumerofunction() const;
        double getLowerLimit() const;
        double getUpperLimit() const;

        // Les mutateurs
        void setLowerLimit(double valeur);
        void setUpperLimit(double valeur);
        void setNumerofunction(int num);


        void afficherParametres(std::ostream& ost, const Problem& pbm);
        void saisirParametres(std::istream& ist, const Problem pbm);

        int _numfunction;
    private:
        int _dimension;
		double _LowerLimit;
		double _UpperLimit;

};

#endif // PROBLEM_H
