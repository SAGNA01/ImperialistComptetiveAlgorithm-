#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include<vector>
#include <ctime>


using namespace std;
class Problem
{
    public:
        //Constructeur du problème
        Problem();
        virtual ~Problem();
        Problem(int dimension, double LowerLimit, double UpperLimit, int numFonction);
        Problem(int dimension, int numFunction);
        // Accesseurs de paramètres
        int getDimension() const;
        int getNumeroFonction() const;
        double getLowerLimit() const;
        double getUpperLimit() const;

        //Les mutateurs
        void setLowerLimit(double valeur);
        void setUpperLimit(double valeur);
        void setNumeroFonction(int num);

        friend ostream& operator<<(ostream& ost, Problem& pbm);
        friend istream& operator>>(istream& ist, Problem& pbm);

        int _numFonction;
    private:
        int _dimension;
		double _LowerLimit;
		double _UpperLimit;
		double _imperialistCost;
	    double _totalCost;

};

#endif // PROBLEM_H
