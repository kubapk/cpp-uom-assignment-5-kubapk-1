/*
____________________________________________
ELECTRON IMPLEMENTATION
(Part of PHYS30762 Assignment 5)
____________________________________________
Implementation file for functions in Electron class.

Created by Kuba Kane (ID: 11019699)
Created on Tue 14 Apr 2026
*/

#include<iostream>
#include<cmath>
#include "Electron.h"

//CONSTRUCTORS
//Default constructor
Electron::Electron() :
    Lepton(ELECTRON_MASS, ELECTRON_CHARGE, 0, 0, 0),
    detector_length{0}
{}

//Paramterised constructor
Electron::Electron(const double px_in, const double py_in, const double pz_in, 
        const double detector_length_in, bool is_anti = false) :
    Lepton(ELECTRON_MASS, ELECTRON_CHARGE, px_in, py_in, pz_in, is_anti),
    detector_length{detector_length_in}
    {
        //Check detector length is valid
        if(detector_length_in < 0.0)
            throw std::invalid_argument("Detector length cannot be negative");

        if(detector_length_in > 1000)
            throw std::invalid_argument("Detector length cannot be greater than 1000cm");
    }


//MEMBER FUNCTIONS
void Electron::info() const
{
    if(is_antiparticle) //i.e. if it is antiparticle
        std::cout<<"Particle: positron"<<std::endl;
    else
        std::cout<<"Particle: electron"<<std::endl;

    Lepton::base_info(); //call info function from Lepton
    std::cout<<"Shower depth in tungsten: "<<shower_depth_in_tungsten()<<std::endl;
    std::cout<<"Tungsten detector length: "<<detector_length<<std::endl;
    std::cout<<"Shower contained: "<<(shower_contained(detector_length)? "Yes" : "No")<<std::endl;
}

double Electron::shower_depth_in_tungsten() const
//Tungsten = W
{
    double W_critical_energy = 7.97; //MeV
    double W_radiation_length = 0.3504; //cm
    double shower_depth = (W_radiation_length * log(momentum_ptr->get_E() / W_critical_energy)) / log(2.0);

    return shower_depth;
}

bool Electron::shower_contained(const double detector_length_in) const
{
    return detector_length_in >= shower_depth_in_tungsten();
}