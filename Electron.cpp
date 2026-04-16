/*
____________________________________________
ELECTRON IMPLEMENTATION
(Part of PHYS30762 Assignment 5)
____________________________________________
Implementation file for functions in Electron class.

Created by Kuba Kane (ID: 11019699)
Created on Tue 14 Apr 2026
*/

#include<iostream>
#include "Electron.h"

//CONSTRUCTORS
//Default constructor
Electron::Electron() :
    Lepton(ELECTRON_MASS, ELECTRON_CHARGE, 0, 0, 0)
{}

//Paramterised constructor
Electron::Electron(double px_in, double py_in, double pz_in, bool is_anti) :
    Lepton(ELECTRON_MASS, ELECTRON_CHARGE, px_in, py_in, pz_in, is_anti)
{}


//MEMBER FUNCTIONS
void Electron::info() const
{
    if(is_antiparticle) //i.e. if it is antiparticle
        std::cout<<"Particle: positron"<<std::endl;
    else
        std::cout<<"Particle: electron"<<std::endl;

    Lepton::base_info(); //call info function from Lepton
}