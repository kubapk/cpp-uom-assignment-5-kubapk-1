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
    energy{0}, x_momentum{0}, y_momentum{0}, z_momentum{0}, rest_mass{0} {}
    //Uses intialiser list (in case of consts)


//Parameterised constructor
FourMomentum::FourMomentum(const double mass_in, const double px_in, const double py_in, 
        const double pz_in) :
    energy{compute_energy(mass_in, px_in, py_in, pz_in)}, x_momentum{px_in}, 
    y_momentum{py_in}, z_momentum{pz_in}
    {}
    //Validation checks via compute_energy function

//Overloaded constructor with energy & mass
FourMomentum::FourMomentum(const double energy_in, const double px_in, const double py_in, 
    const double pz_in, const double mass_in) :
    energy{energy_in}, x_momentum{px_in}, y_momentum{py_in}, z_momentum{pz_in}
    {
        //Check values are valid
        validate_finite(energy_in);
        validate_finite(px_in);
        validate_finite(py_in);
        validate_finite(pz_in);
        validate_mass(mass_in);

        //Check invariant mass equation
        validate_invariant_mass(energy_in, px_in, py_in, pz_in, mass_in);
    }


//SETTERS
//Setter for x momentum
void FourMomentum::set_px(const double& px_in)
{
    validate_finite(px_in);
    energy = compute_energy(rest_mass, px_in, y_momentum, z_momentum);
    x_momentum = px_in;
}

//Setter for y momentum
void FourMomentum::set_py(const double& py_in)
{
    validate_finite(py_in);
    energy = compute_energy(rest_mass, x_momentum, py_in, z_momentum);
    y_momentum = py_in;
}

//Setter for z momentum
void FourMomentum::set_pz(const double& pz_in)
{
    validate_finite(pz_in);
    energy = compute_energy(rest_mass, x_momentum, y_momentum, pz_in);
    z_momentum = pz_in;
}


//MEMBER FUNCTIONS
//Private member function to check px, py, pz are not infinite
void FourMomentum::validate_finite(const double x)
{
    if(!std::isfinite(x))
    {
        throw std::invalid_argument("Four Momentum values contain infinity. Four momentum must be finite.");
    }
}

//Private member function to validate mass
void FourMomentum::validate_mass(const double mass_in)
{
    if(mass_in < 0 || mass_in > 1e6) //1TeV
        throw std::invalid_argument("Mass must be between 0 MeV and 1 TeV (1e6MeV)");
}

//Private member function to check invariant mass equation
void FourMomentum::validate_invariant_mass(const double energy_in, const double px_in, 
    const double py_in, const double pz_in, const double mass_in)
    {
        double invariant_mass = energy_in*energy_in - px_in*px_in - py_in*py_in - pz_in*pz_in;
        if(invariant_mass != mass_in)
            throw std::invalid_argument("Unphysical four momentum. Check invariant mass equation.");
    }

//Private member function to find energy given 3-momentum & mass
double FourMomentum::compute_energy(const double mass_in, const double px_in, 
    const double py_in, const double pz_in)
    // E^2 = m^2 + p^2
    //Function used by 
    {
        validate_finite(px_in);
        validate_finite(py_in);
        validate_finite(pz_in);
        validate_mass(mass_in);

        double E = std::sqrt(mass_in*mass_in + px_in*px_in + py_in*py_in
        + pz_in*pz_in);

        if(!std::isfinite(E))
            throw std::overflow_error("Momentum values are too large. Energy is infinite.");

        return E;
    }


//FRIEND FUNCTIONS
//Friend function to print FourMomentum
std::ostream& operator<<(std::ostream& os, const FourMomentum& fm)
{
    os << "[E = "<<fm.energy<<"MeV, px = "<<fm.x_momentum<<"MeV, py = "<<fm.y_momentum<<"MeV, pz = "<<fm.z_momentum<<"MeV]";

    return os;
}