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
//Paramterised constructor
Lepton::Lepton(const double mass_in, const double charge_in, const double px_in,
    const double py_in, const double pz_in, bool is_anti) :
        mass{mass_in}, 
        charge{is_anti? -charge_in : charge_in}, //if true, if false
        momentum_ptr{std::make_unique<FourMomentum>(compute_energy(mass_in, px_in, py_in, pz_in), 
        px_in, py_in, pz_in)},
        is_antiparticle{is_anti}
        {}

//Copy constructor
//Smart pointers are not copyable by default, so we must do deep copy - copy elements manually
//Default copy constructor uses default constructor for FourMomentum
//Here we enforce it to copy from object specified when constructing object,
//i.e. "lep", the object we want to make a copy of
//Don't need to use "new"  here - handled by smart pointer
Lepton::Lepton(const Lepton& lep) :
    momentum_ptr{std::make_unique<FourMomentum>(*lep.momentum_ptr)}
    //Other properties of Lepton can use default constructors
    {}

//Copy assignment operator
Lepton& Lepton::operator=(const Lepton& lep)
{
    //Check for self-assignment using this = ref to original object in class
    if(&lep == this) return *this;

    //Smart pointers handle dynamic memory allocation 
    //Manually copy momentum (deep copy) as smart pointer cannot do copy
    momentum_ptr = std::make_unique<FourMomentum>(*lep.momentum_ptr);
    return *this;
}

//Move constructor 
//Don't need to use "delete" or "new" here - handled by smart pointer
//Smart pointers have move semantics already - can use std::move here
//std::move transfers the pointers with each other, so the new momentum_ptr becomes
//the momentum_ptr of "lep"
Lepton::Lepton(Lepton&& lep) :
    momentum_ptr{std::move(lep.momentum_ptr)}
    {}

//Move assignment operator
Lepton& Lepton::operator=(Lepton&& lep)
{
    //Check for self-assignment
    if(&lep == this) return *this;

    //Move by assignment
    momentum_ptr = std::move(lep.momentum_ptr);
    return *this; //return object with new momentum_ptr
}

//SETTERS
//Setter for x momentum
void Lepton::set_px(const double& px_in)
{
    //Get current py and pz
    double py = (*momentum_ptr).get_py();
    double pz = (*momentum_ptr).get_pz();

    //Set new four momentum with new px_in
    momentum_ptr = std::make_unique<FourMomentum>(compute_energy(mass, px_in, py, pz), 
    px_in, py, pz);
}

//Setter for y momentum
void Lepton::set_py(const double& py_in)
{
    //Get current px and pz
    double px = (*momentum_ptr).get_px();
    double pz = (*momentum_ptr).get_pz();

    //Set new four momentum with new px_in
    momentum_ptr = std::make_unique<FourMomentum>(compute_energy(mass, px, py_in, pz), 
    px, py_in, pz);
}

//Setter for z momentum
void Lepton::set_pz(const double& pz_in)
{
    //Get current px and pz
    double px = (*momentum_ptr).get_px();
    double py = (*momentum_ptr).get_py();

    //Set new four momentum with new px_in
    momentum_ptr = std::make_unique<FourMomentum>(compute_energy(mass, px, py, pz_in), 
    px, py, pz_in);
}


//MEMBER FUNCTIONS
//Protected function to print base info
void Lepton::base_info() const
{
    std::cout<<"Spin: 0.5"<<std::endl;
    std::cout<<"Mass: "<<mass<<"MeV"<<std::endl;
    std::cout<<"Charge: "<<charge<<"e"<<std::endl;
    std::cout<<"Four-momentum: "<<*momentum_ptr<<std::endl;
    std::cout<<"Decay status: "<<(has_decayed()? "Decayed" : "Not decayed")<<std::endl;
}

//Protected function to find energy
double Lepton::compute_energy(const double mass_in, const double px_in, 
    const double py_in, const double pz_in)
    // E^2 = m^2 + p^2
    {
        return std::sqrt(mass_in*mass_in + px_in*px_in + py_in*py_in
        + pz_in*pz_in);
    }
//Static function to ensure the energy cannot be modified by any setters or getters during run time 
//- belongs to the class rather than any specific object of the class


//FRIEND FUNCTIONS
//Friend function to add FourMomentum of 2 leptons
FourMomentum sum_momenta(const Lepton& lep1, const Lepton& lep2)
{
    return(FourMomentum(
        lep1.momentum_ptr->get_E()+lep2.momentum_ptr->get_E(),
        lep1.momentum_ptr->get_px()+lep2.momentum_ptr->get_px(),
        lep1.momentum_ptr->get_py()+lep2.momentum_ptr->get_py(),
        lep1.momentum_ptr->get_pz()+lep2.momentum_ptr->get_pz()));
}


//Friend function to take dot product of 2 leptons
double dot_product_momenta(const Lepton& lep1, const Lepton& lep2)
//p.q = E_p*E_q - p_x*q_x - p_y*q_y - p_z*p_z
{
    return(lep1.momentum_ptr->get_E()*lep2.momentum_ptr->get_E()
    - lep1.momentum_ptr->get_px()*lep2.momentum_ptr->get_px()
    - lep1.momentum_ptr->get_py()*lep2.momentum_ptr->get_py()
    - lep1.momentum_ptr->get_pz()*lep2.momentum_ptr->get_pz());
}