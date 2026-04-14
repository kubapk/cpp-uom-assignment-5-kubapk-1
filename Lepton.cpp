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
#include<unordered_set> //to store unique elements
#include <stdexcept>
#include "Lepton.h"


//CONSTRUCTORS
//Paramterised constructor
Lepton::Lepton(const FourMomentum& momentum_in) 
{
    set_four_momentum(momentum_in); //four_momentum_in can be passed in by the user using paramterised 
    //constructor FourMomentum(E, px, py, pz)
}


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