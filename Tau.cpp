/*
____________________________________________
TAU IMPLEMENTATION
(Part of PHYS30762 Assignment 5)
____________________________________________
Implementation file for functions in tau class.

Created by Kuba Kane (ID: 11019699)
Created on Thu 16 Apr 2026
*/

#include<iostream>
#include "Tau.h"

//CONSTRUCTORS
//Default constructor
Tau::Tau() :
    Lepton(TAU_MASS, TAU_CHARGE, 0, 0, 0)
    //Time in detector defaults to 0
    {}

//Paramterised constructor
Tau::Tau(const double px_in, const double py_in, const double pz_in, const double time_in, bool is_anti) :
    Lepton(TAU_MASS, TAU_CHARGE, px_in, py_in, pz_in, is_anti),
    time_in_detector{validate_time(time_in)}
    {}


//SETTERS
//Setter for time_in_detector
void Tau::set_time_in_detector(const double& time_in)
{
    time_in_detector = validate_time(time_in);
}


//MEMBER FUNCTIONS
//Info function 
void Tau::info() const
{
    if(is_antiparticle)
        std::cout<<"Particle: anti-tau"<<std::endl;
    else
        std::cout<<"Particle: tau"<<std::endl;

    Lepton::base_info(); //call info function from Lepton
    std::cout<<"Mean lifetime: "<<TAU_MEAN_LIFETIME<<"s"<<std::endl;
    std::cout<<"Time in detector: "<<time_in_detector<<"s"<<std::endl;
}

//Member function to check if tau has decayed (same as muon)
bool Tau::has_decayed() const
{
    return time_in_detector >= TAU_MEAN_LIFETIME;
}

//Private member function to validate time input
double Tau::validate_time(const double t)
{
    if(t < 0.0)
        throw std::invalid_argument("Time cannot be negative");

    if(t > MAX_TIME)
        throw std::invalid_argument("Time in detector cannot be greater than "
            "1 second (1s)");

    return t;
}