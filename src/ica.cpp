#include <iostream>
#include "Problem.h"
#include "SetUpParams.h"

using namespace std;


void title()
{
    cout<<endl << endl << "\t\t\t ***** Imperialist competitive algorithm *****"<<endl;
    cout<< "\t\t\t _____________________________________________\n";
}

void line()
{
    cout<<endl;
}

void SelectFunction()
{
    void line();
	cout<< "\t\t\t Select Benchmark function : " << endl;
	void line();
	cout<< "\t\t\t 1 - Rosenbrock" <<endl;
	cout<< "\t\t\t 2 - Rastragin" <<endl;
	cout<< "\t\t\t 3 - Ackley" <<endl;
	cout<< "\t\t\t 4 - Schwefel" <<endl;
	cout<< "\t\t\t 5 - schaffer" <<endl;
	cout<< "\t\t\t 6 - Weierstrass" <<endl;
}

int main()
{
    title();
    line();
    SetUpParams setup;
    cin>> setup;
    cout<< setup;
    line();
    SelectFunction();
    line();
    Problem pbm{30,2};
    pbm.saisirParametres(cin, pbm);
    pbm.afficherParametres(cout, pbm);
    line();
    system("pause");
    return 0;
}
