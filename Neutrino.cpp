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
Neutrino::Neutrino(double px_in, double py_in, double pz_in, bool is_anti) :
    Lepton(NEUTRINO_MASS, NEUTRINO_CHARGE, px_in, py_in, pz_in, is_anti)
    {}


//MEMBER FUNCTIONS
//Info function 
void Neutrino::info() const
{
    if(is_antiparticle)
        std::cout<<"Particle: anti-neutrino"<<std::endl;
    else
        std::cout<<"Particle: neutrino"<<std::endl;

    Lepton::base_info(); //call info function from Lepton
}