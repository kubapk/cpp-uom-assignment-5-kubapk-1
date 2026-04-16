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

//Destructor
//Copy constructor
//Copy assignment operator
//Move constructor 
//Move assignment operator


//SETTERS
//Setter for x momentum
void Lepton::set_px(const double& px_in)
{
    //Get current py and pz
    double py = (*momentum_ptr).get_py();
    double pz = (*momentum_ptr).get_pz();

    //Set new four momentum with new px_in
    momentum_ptr = std::make_unique<FourMomentum>((compute_energy(mass, px_in, py, pz), 
    px_in, py, pz));
}

void Lepton::set_py(const double& py_in)
{
    //Get current px and pz
    double px = (*momentum_ptr).get_px();
    double pz = (*momentum_ptr).get_pz();

    //Set new four momentum with new px_in
    momentum_ptr = std::make_unique<FourMomentum>((compute_energy(mass, px, py_in, pz), 
    px, py_in, pz));
}

void Lepton::set_pz(const double& pz_in)
{
    //Get current px and pz
    double px = (*momentum_ptr).get_px();
    double py = (*momentum_ptr).get_py();

    //Set new four momentum with new px_in
    momentum_ptr = std::make_unique<FourMomentum>((compute_energy(mass, px, py, pz_in), 
    px, py, pz_in));
}


//MEMBER FUNCTIONS
//Protected function to print base info
void Lepton::base_info() const
{
    std::cout<<"Four-momentum: "<<*momentum_ptr<<std::endl;
}

//Protected function to find energy
static double compute_energy(const double mass_in, const double x_momentum_in, 
    const double y_momentum_in, const double z_momentum_in)
    // E^2 = m^2 + p^2
    {
        return std::sqrt(mass_in*mass_in + x_momentum_in*x_momentum_in + y_momentum_in*y_momentum_in
        + z_momentum_in*z_momentum_in);
    }
//Static function to ensure the energy cannot be modified by any setters or getters during run time 
//- belongs to the class rather than any specific object of the class


//FRIEND FUNCTIONS
//Friend function to add FourMomentum of 2 leptons
FourMomentum operator+(const Lepton& lep1, const Lepton& lep2)
{
    return(FourMomentum(
        lep1.momentum_ptr->get_E()+lep2.momentum_ptr->get_E(),
        lep1.momentum_ptr->get_px()+lep2.momentum_ptr->get_px(),
        lep1.momentum_ptr->get_py()+lep2.momentum_ptr->get_py(),
        lep1.momentum_ptr->get_pz()+lep2.momentum_ptr->get_pz()));
}


//Friend function to take dot product of 2 leptons
double dotProduct(const Lepton& lep1, const Lepton& lep2)
//p.q = E_p*E_q - p_x*q_x - p_y*q_y - p_z*p_z
{
    return(lep1.momentum_ptr->get_E()*lep2.momentum_ptr->get_E()
    - lep1.momentum_ptr->get_px()*lep2.momentum_ptr->get_px()
    - lep1.momentum_ptr->get_py()*lep2.momentum_ptr->get_py()
    - lep1.momentum_ptr->get_pz()*lep2.momentum_ptr->get_pz());
}