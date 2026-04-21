/*
____________________________________________
NEUTRINO IMPLEMENTATION
(Part of PHYS30762 Assignment 5)
____________________________________________
Implementation file for functions in neutrino class.

Created by Kuba Kane (ID: 11019699)
Created on Thu 16 Apr 2026
*/

#include<iostream>
#include "Neutrino.h"

//CONSTRUCTORS
//Default constructor
Neutrino::Neutrino(NeutrinoFlavour flavour_in) :
    Lepton(NEUTRINO_MASS, NEUTRINO_CHARGE, 0, 0, 0),
    flavour{flavour_in}
    {}

//Paramterised constructor
Neutrino::Neutrino(const double px_in, const double py_in, const double pz_in, 
    const NeutrinoFlavour flavour_in, bool is_anti) :
        Lepton(NEUTRINO_MASS, NEUTRINO_CHARGE, px_in, py_in, pz_in, is_anti),
        flavour{flavour_in}
        {}


//GETTERS
//Getter for flavour
string Neutrino::get_flavour() const
{
    switch(flavour)
    {
        case NeutrinoFlavour::Electron: return "electron";
        case NeutrinoFlavour::Muon: return "muon";
        case NeutrinoFlavour::Tau: return "tau";
    }
    throw std::logic_error("Invalid neutrino flavour - cannot get flavour");
}

//Getter for generation
int Neutrino::get_generation() const
{
    switch(flavour)
    {
        case NeutrinoFlavour::Electron: return 1;
        case NeutrinoFlavour::Muon: return 2;
        case NeutrinoFlavour::Tau: return 3;
    }
    throw std::logic_error("Invalid neutrino flavour - cannot get generation");
}


//MEMBER FUNCTIONS
//Info function 
void Neutrino::info() const
{
    if(is_antiparticle)
        std::cout<<"Particle: anti "<<get_flavour()<<" neutrino"<<std::endl;
    else
        std::cout<<"Particle: "<<get_flavour()<<" neutrino"<<std::endl;

    std::cout<<"Flavour: "<<get_flavour()<<std::endl;
    std::cout<<"Generation: "<<get_generation()<<std::endl;
    Lepton::base_info(); //call info function from Lepton
}

//break is used to ensure the switch jumps out after it reaches 
//the correct case