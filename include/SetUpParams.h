#ifndef SETUPPARAMS_H
#define SETUPPARAMS_H
#include<iostream>


class SetUpParams
{

    unsigned int _independent_runs;         //number of independent runs
	unsigned int _nb_evolution_steps;      // number of iterations per run
	unsigned int _population_size;		  // number of solutions in the population
	unsigned int _solution_size;	     // size of each particle

    public:
        // Constructeurs des paramaètres
        SetUpParams();
        SetUpParams(unsigned int ind_runs, unsigned int nbEvolu_steps, unsigned int population_size, unsigned int solution_size);
        // Accesseurs des paramètres
        const unsigned int getIndependent_runs() const;
		const unsigned int getNb_evolution_steps() const;
		const unsigned int getPopulation_size() const;
		const unsigned int getSolution_size() const;
		// Modificateurs des paramètres
		void setIndependent_runs(const unsigned int val);
		void setNb_evolution_steps(const unsigned int val);
		void setPopulation_size(const unsigned int val);
		void setSolution_size(const unsigned int val);
        ~SetUpParams(); // Destructeur

        friend std::ostream& operator <<(std::ostream& ist, SetUpParams& setup);
        friend std::istream& operator >>(std::istream& ist, SetUpParams setup);

};

#endif // SETUPPARAMS_H
