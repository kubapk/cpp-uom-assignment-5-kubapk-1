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
#include<stdexcept>
#include<cmath> //to check for infinite values
#include "FourMomentum.h"


//CONSTRUCTORS
//Default constructor
FourMomentum::FourMomentum() :
    //Set momentum objects to be 0
    energy{0}, x_momentum{0}, y_momentum{0}, z_momentum{0} {}
    //Uses intialiser list (in case of consts)


//Parameterised constructor
FourMomentum::FourMomentum(const double energy_in, const double px_in, const double py_in, 
    const double pz_in) :
    energy{energy_in}, x_momentum{px_in}, y_momentum{py_in}, z_momentum{pz_in}
{
    //Check momentum values are valid
    validate_3_momentum(px_in, py_in, pz_in);
}


//SETTERS
//No setters for FourMomentum - do not allow user to change these


//MEMBER FUNCTIONS
//Private member function to check px, py, pz are not infinite
void FourMomentum::validate_3_momentum(const double px, const double py, const double pz)
{
    if(!std::isfinite(px) || !std::isfinite(py) || !std::isfinite(pz))
    {
        throw std::invalid_argument("Momentum values contain infinity. Momentum must be finite.");
    }
}

//Private member function to find energy given 3-momentum
//Static function to ensure the energy cannot be modified by any setters or getters during run time 
//- belongs to the class rather than any specific object of the class
double FourMomentum::compute_energy(const double mass_in, const double px_in, 
    const double py_in, const double pz_in)
    // E^2 = m^2 + p^2
    {
        validate_mass(mass_in);

        double E = std::sqrt(mass_in*mass_in + px_in*px_in + py_in*py_in
        + pz_in*pz_in);

        if(!std::isfinite(E))
            throw std::overflow_error("Momentum values are too large. Energy is infinite.");

        return E;
    }

//Private member function to validate mass
void FourMomentum::validate_mass(const double mass_in)
{
    if(mass_in < 0 || mass_in > 1e6) //1TeV
        throw std::invalid_argument("Mass must be between 0 MeV and 1 TeV (1e6MeV)");
}

//Public member function to find FourMomentum from mass
FourMomentum FourMomentum::four_momentum_from_mass(const double mass_in, const double px_in, 
    const double py_in, const double pz_in)
    {
        validate_mass(mass_in);

        return FourMomentum(compute_energy(mass_in, px_in, py_in, pz_in), 
        px_in, py_in, pz_in);
    }

//Public member function to find FourMomentum from energy
FourMomentum FourMomentum::four_momentum_from_energy(const double energy_in, const double px_in, 
    const double py_in, const double pz_in)
    {
        if(energy_in*energy_in < px_in*px_in + py_in*py_in + pz_in*pz_in)
            throw std::invalid_argument("Invalid energy for FourMomentum");

        return FourMomentum(energy_in, px_in, py_in, pz_in);
    }


//FRIEND FUNCTIONS
//Friend function to print FourMomentum
std::ostream& operator<<(std::ostream& os, const FourMomentum& fm)
{
    os << "[E = "<<fm.energy<<"MeV, px = "<<fm.x_momentum<<"MeV, py = "<<fm.y_momentum<<"MeV, pz = "<<fm.z_momentum<<"MeV]";

    return os;
}