/*
____________________________________________
LEPTON IMPLEMENTATION
(Part of PHYS30762 Assignment 5)
____________________________________________
This implementation file defines setters, constructors, and assignment
operators for the "Lepton" class.

Created by Kuba Kane (ID: 11019699)
Created on Wed 25 Mar 2026
*/

#include<iostream>
#include<memory> //for smart pointer
#include <stdexcept>
#include <cmath> //for sqrt
#include "Lepton.h"


//CONSTRUCTORS
//Default constructor



//Paramterised constructor
Lepton::Lepton(const double mass_in, const double charge_in, const double px_in,
    const double py_in, const double pz_in) :
    mass{mass_in}, charge{charge_in}, 
    momentum_ptr{std::make_unique<FourMomentum>(compute_energy(mass_in, px_in, py_in, pz_in), 
    px_in, py_in, pz_in)} 
    {}


//SETTERS
//Setter for particle momentum
void Lepton::set_four_momentum(const FourMomentum& momentum_in) 
{momentum = momentum_in;}


//MEMBER FUNCTIONS
//Protected function to print base info
void Lepton::base_info() const
{
    std::cout<<"Four-momentum: "<<momentum<<std::endl;
}

//Protected function to find energy
static double compute_energy(const double mass_in, const double x_momentum_in, 
    const double y_momentum_in, const double z_momentum_in)
    // E^2 = m^2 + p^2
    {
        return std::sqrt(mass_in*mass_in + x_momentum_in*x_momentum_in + y_momentum_in*y_momentum_in
        + z_momentum_in*z_momentum_in);
    }


//FRIEND FUNCTIONS
//Friend function to add FourMomentum of 2 leptons
FourMomentum operator+(const Lepton& lep1, const Lepton& lep2)
{
    //Using (+, -, -, -) convention for Minkowski matrix (dot product)
    return(FourMomentum(
        lep1.momentum.get_E()+lep2.momentum.get_E(),
        lep1.momentum.get_px()+lep2.momentum.get_px(),
        lep1.momentum.get_py()+lep2.momentum.get_py(),
        lep1.momentum.get_pz()+lep2.momentum.get_pz()));
}


//Friend function to take dot product of 2 leptons
double dotProduct(const Lepton& lep1, const Lepton& lep2)
//p.q = E_p*E_q - p_x*q_x - p_y*q_y - p_z*p_z
{
    return(lep1.momentum.get_E()*lep2.momentum.get_E()
    - lep1.momentum.get_px()*lep2.momentum.get_px()
    - lep1.momentum.get_py()*lep2.momentum.get_py()
    - lep1.momentum.get_pz()*lep2.momentum.get_pz());
}