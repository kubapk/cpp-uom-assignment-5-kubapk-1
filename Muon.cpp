/*
____________________________________________
MUON IMPLEMENTATION
(Part of PHYS30762 Assignment 5)
____________________________________________
Implementation file for functions in muon class.

Created by Kuba Kane (ID: 11019699)
Created on Thu 16 Apr 2026
*/

#include<iostream>
#include "Muon.h"

//CONSTRUCTORS
//Default constructor
Muon::Muon() :
    Lepton(MUON_MASS, MUON_CHARGE, 0, 0, 0)
    //Time in detector defaults to 0
    {}

//Paramterised constructor
Muon::Muon(const double px_in, const double py_in, const double pz_in, const double time_in, bool is_anti) :
    Lepton(MUON_MASS, MUON_CHARGE, px_in, py_in, pz_in, is_anti),
    time_in_detector{validate_time(time_in)}
    {}


//SETTERS
//Setter for time_in_detector
void Muon::set_time_in_detector(const double& time_in)
{
    time_in_detector = validate_time(time_in);
}


//MEMBER FUNCTIONS
//Info function 
void Muon::info() const
{
    if(is_antiparticle)
        std::cout<<"Particle: anti-muon"<<std::endl;
        //i.e. if it is antiparticle
    else
        std::cout<<"Particle: muon"<<std::endl;

    Lepton::base_info(); //call info function from Lepton
    std::cout<<"Mean lifetime: "<<MUON_MEAN_LIFETIME<<"s"<<std::endl;
    std::cout<<"Time in detector: "<<time_in_detector<<"s"<<std::endl;
}

//Member function to check if muon has decayed
bool Muon::has_decayed() const
{
    return time_in_detector >= MUON_MEAN_LIFETIME;
    //True if time is greater than mean lifetime
}

//Private member function to validate time input
double Muon::validate_time(const double t)
{
    if(t < 0.0)
        throw std::invalid_argument("Time cannot be negative");

    if(t > MAX_TIME)
        throw std::invalid_argument("Time in detector cannot be greater than "
            "1 millisecond (1e-13s)");

    return t;
}