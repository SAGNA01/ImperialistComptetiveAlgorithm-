#include <iostream>
#include "CountrySolution.h"
#include "Empire.h"
#include "Problem.h"
#include "SetUpParams.h"
#include "OptimizationAlgorithm.h"

using namespace std;

int menu()
{
    int input;
    do
    {
        cout<<"1 - Excecuter \n2 - Changer la fonction benchmark\n3 - Quitter"<<std::endl;
        cin>>input;
    } while(input<1 && input>3);
    return input;
}

void title()
{
    cout<<endl << endl << "\t\t\t ***** Imperialist competitive algorithm *****"<<endl;
    cout<< "\t\t\t _____________________________________________\n";
}

void line()
{
    cout<<endl;
}

void selectFunction()
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
    SetUpParams setup ;


    line();
    selectFunction();
    line();
    Problem pbm;
    cin >> pbm;
    cout << pbm;

    int choice = menu();
    while(choice != 1)
    {
        switch(choice)
        {
            default:
                break;
            case 2:
                selectFunction();
                cin >> pbm;
                break;
            case 3:
                std::exit;
        }
        choice=menu();
    }
    line();
    OptimizationAlgorithm algo = OptimizationAlgorithm{pbm, setup};
    algo.run();
    system("pause");
    return 0;
}
