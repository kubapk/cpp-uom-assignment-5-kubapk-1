//Test of assignment 5

#include<iostream>
#include<vector>
#include <stdexcept>
#include "Lepton.h"
#include "FourMomentum.h"
using std::vector;


int main()
{
    try
    {
        //Create new lepton
        std::cout<<"\nCreating new lepton"<<std::endl;
        Lepton lepton_test{Lepton(FourMomentum(10, 2, 3, 1))};

        //Print out lepton info
        lepton_test.info();

        /*
        //Use Particle getters to print out properties
        std::cout<<"\nUsing particle getters"<<std::endl;
        std::cout<<" Get name: "<<electron_test.get_name()<<std::endl;
        std::cout<<" Get FourMomentum: "<<electron_test.get_four_momentum()<<std::endl;

        //Change momentum
        std::cout<<"\nChanging particle x momentum"<<std::endl;
        electron_test.get_four_momentum().set_px(5);
        std::cout<<electron_test<<std::endl;

        //Use FourMomentum getters to print out properties
        std::cout<<"\nUsing FourMomentum getters"<<std::endl;
        std::cout<<" Get Energy: "<<electron_test.get_four_momentum().get_E()<<std::endl;
        std::cout<<" Get x momentum: "<<electron_test.get_four_momentum().get_px()<<std::endl;
        std::cout<<" Get y momentum: "<<electron_test.get_four_momentum().get_py()<<std::endl;
        std::cout<<" Get z momentum: "<<electron_test.get_four_momentum().get_pz()<<std::endl;

        //Change particle name
        std::cout<<"\nSetting new particle name"<<std::endl;
        electron_test.set_name("muon");
        std::cout<<electron_test<<std::endl;

        //Change momentum
        std::cout<<"\nChanging four momentum using particle setter"<<std::endl;
        electron_test.set_four_momentum(FourMomentum(0, 1, 1, 1));
        std::cout<<electron_test<<std::endl;

        //Create a constant particle - we don't want to modify it
        //This is why we need get_four_momentum to be able to return const as well
        std::cout<<"\nCreating const particle p1"<<std::endl;
        const Particle p1{Particle("up", FourMomentum(20, 0, 1, 0))};
        std::cout<<" Get name: "<<p1.get_name()<<std::endl;
        std::cout<<" Get four momentum: "<<p1.get_four_momentum()<<std::endl;

        //Edit properties of const particle
        //p1.get_four_momentum().set_E(10) //does not update const particle

        //Create a const momentum
        std::cout<<"\nCreating const FourMomentum fm1"<<std::endl;
        const FourMomentum fm1{FourMomentum(5, 1, 1, 1)};
        std::cout<<"fm1: "<<fm1<<std::endl;
        std::cout<<" Get E: "<<fm1.get_E()<<std::endl;
        std::cout<<" Get px: "<<fm1.get_px()<<std::endl;
        std::cout<<" Get py: "<<fm1.get_py()<<std::endl;
        std::cout<<" Get pz: "<<fm1.get_pz()<<std::endl;

        //Edit properties of const FourMomentum
        //fm1.set_E(10); //does not update const FourMomentum

        //Create particle using default constructor
        std::cout<<"\nCreating particle using default constructor"<<std::endl;
        Particle p2;
        std::cout<<p2<<std::endl;
        */

    }
    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
        return 1;
    }

    return 0;
}