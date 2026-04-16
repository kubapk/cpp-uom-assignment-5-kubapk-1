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
        //Lepton lepton_test{Lepton(10, 1, 0, 0, 0)};

        //Create an electron
        std::cout<<"\nCreating new electron"<<std::endl;
        Electron electron_test{Electron(10, 10, 10)};

        //Print out electron info
        electron_test.info();

        //Getters
        std::cout<<"\nGetters of electron"<<std::endl;
        std::cout<<"Mass: "<<electron_test.get_mass()<<std::endl;
        std::cout<<"Charge: "<<electron_test.get_charge()<<std::endl;
        std::cout<<"Four momentum: "<<electron_test.get_four_momentum()<<std::endl;

        //Four momentum getters
        std::cout<<"\nGetters of four momentum of electron"<<std::endl;
        //std::cout<<"Energy: "<<electron_test.momentum_ptr->get_E()<<std::endl;
        std::cout<<"Energy: "<<electron_test.get_four_momentum().get_E()<<std::endl;
        std::cout<<"X momentum: "<<electron_test.get_four_momentum().get_px()<<std::endl;
        std::cout<<"Y momentum: "<<electron_test.get_four_momentum().get_py()<<std::endl;
        std::cout<<"Y momentum: "<<electron_test.get_four_momentum().get_pz()<<std::endl;

        //Setters
        std::cout<<"\nChange px"<<std::endl;
        electron_test.set_px(100);
        electron_test.info();

        std::cout<<"\nChange py"<<std::endl;
        electron_test.set_py(-10);
        electron_test.info();

        std::cout<<"\nChange pz"<<std::endl;
        electron_test.set_pz(0.1);
        electron_test.info();

        //Cannot set anything through FourMomentum object
        //electron_test.get_four_momentum().set_px();

        //Create an electron through default constructor
        std::cout<<"\nCreating electron 2"<<std::endl;
        Electron electron_2{Electron()};
        electron_2.info();

        //Create a positron
        std::cout<<"\nCreate positron"<<std::endl;
        Electron positron_1{Electron(0.0, 0.0, 0.0, true)};
        positron_1.info();

    }
    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
        return 1;
    }

    return 0;
}