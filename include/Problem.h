#ifndef PROBLEM_H
#define PROBLEM_H


class Problem
{
    public:
        Problem();
        virtual ~Problem();
        int dimension() const;

    private:
        int _dimension;
		double LowerLimit, UpperLimit;
		int numfunction;
};

#endif // PROBLEM_H
