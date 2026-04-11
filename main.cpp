/*
_____________________________TITLE_____________________________
PHYS30762 Assignment 4 - Practising Overloading Special 
Functions/Operators in Classes
_______________________________________________________________
This C++ script creates a vector of 8 particles using Lepton and
FourMomentum classes. It prints them out and uses move and copy
semantics to move and copy some of these.

Created by Kuba Kane (ID: 11019699)
Created on Wed 25 Mar 2026
*/

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
        //Create empty vector of Lepton objects
        vector<Lepton> particles;
        particles.reserve(8); //prevent reallocations

        
        //Add particles to vector
        std::cout<<"\nAdding particles to vector\n"<<string(60, '-')<<std::endl;
        particles.emplace_back(Lepton("electron", FourMomentum(10, 2, 3, 1)));
        particles.emplace_back(Lepton("electron", FourMomentum(10, 0, 1, 1)));
        particles.emplace_back(Lepton("muon", FourMomentum(30, 1, 1, 1)));
        particles.emplace_back(Lepton("muon", FourMomentum(25, 1, 0, 1)));
        particles.emplace_back(Lepton("muon", FourMomentum(34, 1, 0, 1)));
        particles.emplace_back(Lepton("muon", FourMomentum(15, 0, 2, 1)));
        particles.emplace_back(Lepton("tau", FourMomentum(10, 1, 2, 1)));
        particles.emplace_back(Lepton("tau", FourMomentum(25, 2, 3, 1)));
        std::cout<<string(60, '-')<<"\n"<<std::endl;
        //emplace back used since it avoids unecessary copying which push back uses


        //Print out all vectors
        std::cout<<"\nPrint out vectors\n"<<string(60, '-')<<std::endl;
        for(size_t i{}; i<particles.size(); i++)
        {
            std::cout<<particles[i]<<"\n"<<std::endl;
        }
        std::cout<<string(60, '-')<<"\n"<<std::endl;


        //(1) Electron four momenta sum
        std::cout<<"\nSum of the four momenta of the 2 electrons\n"<<string(60, '-')<<std::endl;
        std::cout<<particles[0].get_four_momentum() + particles[1].get_four_momentum()<<std::endl;
        std::cout<<string(60, '-')<<"\n"<<std::endl;


        //(2) Muon dot product
        std::cout<<"\nDot product of first two muons\n"<<string(60, '-')<<std::endl;
        std::cout<<particles[2].get_four_momentum().dotProduct(particles[3].get_four_momentum())<<std::endl;
        std::cout<<string(60, '-')<<"\n"<<std::endl;


        //(3) Electron copy assignment operator
        //Assignmnent requires the new electron to already exist
        std::cout<<"\nCopy first electron to a new electron using copy assignment\n"<<string(60, '-')<<std::endl;
        std::cout<<"Initialising new electron"<<std::endl;
        Lepton new_electron("electron", FourMomentum()); //uses default FourMomentum

        std::cout<<"Assigning new electron"<<std::endl;
        new_electron = particles[0];

        std::cout<<"New electron: \n"<<new_electron<<"\n"<<std::endl;
        std::cout<<"First electron: \n"<<particles[0]<<std::endl;
        std::cout<<string(60, '-')<<"\n"<<std::endl;


        //(4) Muon copy constructor
        //Copy constructor declares new muon on same line as copy
        std::cout<<"\nCopy constructor of the first muon to a new muon\n"<<string(60, '-')<<std::endl;
        Lepton new_muon = particles[2];
        std::cout<<"New muon: \n" <<new_muon<<"\n"<<std::endl;
        std::cout<<"First muon: \n" <<particles[2]<<std::endl;
        std::cout<<string(60, '-')<<"\n"<<std::endl;


        //(5) Electron move constructor
        //Move constructor declares moved electron on same line as copy
        std::cout<<"\nMove first electron to new electron using move constructor\n"<<string(60, '-')<<std::endl;
        Lepton moved_electron = std::move(particles[0]);
        std::cout<<"New electron: \n"<<moved_electron<<std::endl;
        //Check if first electron moved: std::cout<<"First electron: \n"<<particles[0]<<std::endl;
        std::cout<<string(60, '-')<<"\n"<<std::endl;


        //(6) Muon move assignment operator
        //Assignment requires moved muon as input first
        std::cout<<"\nMove first muon to a new muon using move assignment\n"<<string(60, '-')<<std::endl;

        std::cout<<"Assigning new muon"<<std::endl;
        Lepton moved_muon("muon", FourMomentum());

        std::cout<<"Moving first muon to new muon"<<std::endl;
        moved_muon = std::move(particles[2]);
        std::cout<<"New muon: \n"<<moved_muon<<std::endl;
        //Check if first muon moved: std::cout<<"First muon: \n"<<particles[2]<<std::endl;
        std::cout<<string(60, '-')<<"\n"<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
        return 1;
    }

    return 0;
}