/*
_____________________________TITLE_____________________________
PHYS30762 Assignment 5 - Practising inheritance, smart pointers 
and friendship
_______________________________________________________________
This C++ script...

Created by Kuba Kane (ID: 11019699)
Created on Sat 18 Apr 2026
*/

#include<iostream>
#include<vector>
#include<stdexcept>
#include<memory> //using pointers
#include "Lepton.h"
#include "Electron.h"
#include "Muon.h"
#include "Tau.h"
#include "Neutrino.h"
using std::vector;

int main()
{
    try
    {
        //Vector of different leptons
        //Polymorphism - make it a vector of pointers to Lepton class, and since it is abstract (has virtual function),
        //all the info() is overriden as desired 
        vector<std::unique_ptr<Lepton>> particles;

        //Add 2 electrons by pointer
        particles.push_back(std::make_unique<Electron>());
        particles.push_back(std::make_unique<Electron>()); //default constructor

        //Add 4 muons
        for(size_t i=0; i<4; ++i) {particles.push_back(std::make_unique<Muon>());}

        //Add 1 antielectron & 1 antimuon
        particles.push_back(std::make_unique<Electron>(0, 0, 0, true));
        particles.push_back(std::make_unique<Muon>(0, 0, 0, 0, true));

        //Add muon neutrino & electron neutrino
        particles.push_back(std::make_unique<Neutrino>(Neutrino::NeutrinoFlavour::Muon));
        particles.push_back(std::make_unique<Neutrino>(Neutrino::NeutrinoFlavour::Electron));

        //Add tau & anti tau
        particles.push_back(std::make_unique<Tau>());
        particles.push_back(std::make_unique<Tau>(0, 0, 0, 0, true));

        //Iterate through vector & print out info
        for(const auto& i : particles)
        {
            std::cout<<"\n"<<string(60, '-')<<std::endl;
            i->info(); //(*i.info())
        }
        //i is std::unique_ptr<Lepton> but can let compiler decide with auto
        //cannot pass i by value as smart pointers (used for particles) cannot be copied - pass by reference
        //Set the reference to std::unique_ptr<Lepton> (i.e "i") to be const as it shouldn't be modified -
        //each particle in particles should not change
        

    }
    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
        return 1;
    }

    return 0;
}