//Test of assignment 5

#include<iostream>
#include<vector>
#include <stdexcept>
#include "Electron.h"
using std::vector;


int main()
{
    try
    {
        //Cannot create a Lepton - it is an abstract class
        //Lepton lepton_test{Lepton(FourMomentum(10, 2, 3, 1))};

        //Create an electron
        std::cout<<"\nCreating new electron"<<std::endl;
        Electron electron_test{Electron(0.0, 0.0, 0.0, 0.0, 0.0)};

        //Print out lepton info
        electron_test.info();

    }
    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
        return 1;
    }

    return 0;
}