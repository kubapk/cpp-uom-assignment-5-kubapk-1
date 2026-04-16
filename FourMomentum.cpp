/*
____________________________________________
FOUR MOMENTUM IMPLEMENTATION
(Part of PHYS30762 Assignment 5)
____________________________________________
Implementation file for FourMomentum class.

Created by Kuba Kane (ID: 11019699)
Created on Tue 24 Mar 2026
*/

#include<iostream>
#include <stdexcept>
#include "FourMomentum.h"


//CONSTRUCTORS
//Default constructor
FourMomentum::FourMomentum() :
    //Set momentum objects to be 0
    energy{0}, x_momentum{0}, y_momentum{0}, z_momentum{0} {}
    //Uses intialiser list (in case of consts)


//Parameterised constructor
FourMomentum::FourMomentum(const double energy_in, const double x_momentum_in, const double y_momentum_in, 
    const double z_momentum_in) :
    energy{energy_in}, x_momentum{x_momentum_in}, y_momentum{y_momentum_in}, z_momentum{z_momentum_in}
{
    //Check energy is not less than or equal to 0
    validate_energy(energy_in);
}


//Destructor
FourMomentum::~FourMomentum() 
{std::cout<<" >> Calling FourMomentum destructor"<<std::endl;}


//SETTERS
//No setters


//MEMBER FUNCTIONS
//Private member function to check for energy
void FourMomentum::validate_energy(const double E)
{
    if(E < 0)
    {
        throw std::invalid_argument("Energy in FourMomentum is negative. Energy must not be negative.");
    }
}


//FRIEND FUNCTIONS
//Friend function to print FourMomentum
std::ostream& operator<<(std::ostream& os, const FourMomentum& fm)
{
    os << "[E = "<<fm.energy<<"MeV, px = "<<fm.x_momentum<<"MeV, py = "<<fm.y_momentum<<"MeV, pz = "<<fm.z_momentum<<"MeV]";

    return os;
}