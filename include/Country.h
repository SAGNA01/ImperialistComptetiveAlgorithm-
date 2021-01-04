#ifndef COUNTRY_H
#define COUNTRY_H
#include <cmath>
#include"Problem.h"
#include<vector>
#include <ctime>

class Country
{
    public:
        Country(const Problem& pbm);
        Country(const Country& sol);
        virtual ~Country();
        const Problem& pbm() const;
		Country& operator=  (const Country& sol);


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

#endif // COUNTRY_H
