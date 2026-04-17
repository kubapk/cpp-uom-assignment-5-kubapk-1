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
Neutrino::Neutrino() :
    Lepton(NEUTRINO_MASS, NEUTRINO_CHARGE, 0, 0, 0)
    {}

//Paramterised constructor
Neutrino::Neutrino(const double px_in, const double py_in, const double pz_in, 
    const NeutrinoFlavour flavour_in, bool is_anti = false) :
        Lepton(NEUTRINO_MASS, NEUTRINO_CHARGE, px_in, py_in, pz_in, is_anti),
        flavour{flavour_in},
        generation{determine_generation(flavour_in)}
        {}


//GETTERS
//Getter for flavour
const string& Neutrino::get_flavour() const
{
    switch(flavour)
    {
        case NeutrinoFlavour::Electron: return "electron neutrino";
        case NeutrinoFlavour::Muon: return "muon neutrino";
        case NeutrinoFlavour::Tau: return "tau neutrino";
    }
}

//Getter for generation
const int& Neutrino::get_generation() const
{
    return generation;
}


//MEMBER FUNCTIONS
//Info function 
void Neutrino::info() const
{
    if(is_antiparticle)
        std::cout<<"Particle: anti-neutrino"<<std::endl;
    else
        std::cout<<"Particle: neutrino"<<std::endl;

    std::cout<<"Flavour: "<<get_flavour()<<std::endl;
    std::cout<<"Generation: "<<generation<<std::endl;
    Lepton::base_info(); //call info function from Lepton
}

//Private member to find generation
const int Neutrino::determine_generation(NeutrinoFlavour f)
{
    switch(f)
    {
        case NeutrinoFlavour::Electron: generation = 1; break;
        case NeutrinoFlavour::Muon: generation = 2; break;
        case NeutrinoFlavour::Tau: generation =2; break;
    }
}
//break is used to ensure the switch jumps out after it reaches 
//the correct case