#ifndef COUNTRYSOLUTION_H
#define COUNTRYSOLUTION_H
#include <cmath>
#include"Problem.h"
#include<vector>
#include <ctime>

class CountrySolution
{
    public:
        CountrySolution(const Problem& pbm);
        CountrySolution(const CountrySolution& sol);
        virtual ~CountrySolution();
        const Problem& pbm() const;
		CountrySolution& operator =  (const CountrySolution& sol);

		void initialize();
		double fitness();
		double get_fitness();
		bool isColony() const;
        void setisColony() ;
        void setCountry(vector<double>& country);
		vector<double>& getCountry();

	private:
        vector<double> _Country;
        bool is_Colony = false;
        double _current_fitness;
		const Problem& _pbm;
};

#endif // COUNTRYSOLUTION_H
