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


//FRIEND FUNCTIONS
//Friend function to print Lepton data
std::ostream& operator<<(std::ostream& os, const Lepton& p)
{
    os << "Lepton: \nFour momentum: "<<p.momentum;

    return os;
}
