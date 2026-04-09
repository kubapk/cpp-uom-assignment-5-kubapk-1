/*
____________________________________________
PARTICLE IMPLEMENTATION
(Part of PHYS30762 Assignment 4)
____________________________________________
This implementation file defines setters, constructors, and assignment
operators for the "Particle" class.

Created by Kuba Kane (ID: 11019699)
Created on Wed 25 Mar 2026
*/

#include<iostream>
#include<unordered_set> //to store unique elements
#include <stdexcept>
#include "Particle.h"


//CONSTRUCTORS
//Paramterised constructor
Particle::Particle(const string& name_in, const FourMomentum& momentum_in) 
{
    set_name(name_in); //Name check is done via setter to avoid code repetition
    set_four_momentum(momentum_in); //four_momentum_in can be passed in by the user using paramterised 
    //constructor FourMomentum(E, px, py, pz)
}


//SETTERS
//Setter for particle name
void Particle::set_name(const string& name_in)
{
    name = validate_name(name_in);
}


//Setter for particle momentum
void Particle::set_four_momentum(const FourMomentum& momentum_in) 
{momentum = momentum_in;}


//MEMBER FUNCTIONS
//Private member function to check for valid particle names
string Particle::validate_name(const string& name_in)
{
    static const std::unordered_set<string> valid_names = {
        "electron", "muon", "tau", "electron neutrino", "muon neutrino",
        "tau neutrino", "up", "charm", "top", "down", "strange", "bottom",
        "photon", "gluon", "W+ boson", "W- boson", "Z boson",
        "Higgs boson"};

    if(!valid_names.count(name_in))
    //if name is not in the unordered set, 0 is returned (false)
    {
        throw std::invalid_argument("Invalid particle name. Ensure name is one of the 18 valid"
        " particle names, as specified in README.");
    }

    return name_in;
}


//FRIEND FUNCTIONS
//Friend function to print Particle data
std::ostream& operator<<(std::ostream& os, const Particle& p)
{
    os << "Particle: "<<p.name<<"\nFour momentum: "<<p.momentum;

    return os;
}
