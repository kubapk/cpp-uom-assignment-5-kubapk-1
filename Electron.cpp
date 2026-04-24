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
using std::string;

//CONSTRUCTORS
//Default constructor
Electron::Electron() :
    Lepton(ELECTRON_MASS, ELECTRON_CHARGE, 0, 0, 0),
    detector_length{0}
{}

//Paramterised constructor
Electron::Electron(const double px_in, const double py_in, const double pz_in, 
        const double detector_length_in, bool is_anti) :
    Lepton(ELECTRON_MASS, ELECTRON_CHARGE, px_in, py_in, pz_in, is_anti),
    detector_length{detector_length_in}
    {
        //Check detector length is valid
        validate_detector_length(detector_length_in);
    }


//SETTERS
void Electron::set_detector_length(const double& detector_length_in)
{
    validate_detector_length(detector_length_in);
    detector_length = detector_length_in;

}

//MEMBER FUNCTIONS
//Private member function to validate detector length input
void Electron::validate_detector_length(const double detector_length_in)
{
    if(detector_length_in < 0.0)
            throw std::invalid_argument("Detector length cannot be negative");

        if(detector_length_in > 15)
            throw std::invalid_argument("Tungsten detector length cannot be greater than 15cm");
}

//Info member function
void Electron::info() const
{
    if(is_antiparticle) //i.e. if it is antiparticle
        std::cout<<"Particle: positron"<<std::endl;
    else
        std::cout<<"Particle: electron"<<std::endl;

    Lepton::base_info(); //call info function from Lepton
    std::cout<<"Shower depth in tungsten: "<<shower_depth_in_tungsten()<<"cm"<<std::endl;
    std::cout<<"Tungsten detector length: "<<detector_length<<"cm"<<std::endl;
    std::cout<<"Shower status: "<<shower_contained(detector_length)<<std::endl;
}

//Member function to calculate shower depth
double Electron::shower_depth_in_tungsten() const
//Tungsten = W
{
    double W_critical_energy = 7.97; //MeV
    double W_radiation_length = 0.3504; //cm
    double electron_energy = momentum_ptr->get_E(); //MeV

    //If electron doesn't have enough energy to shower
    if(electron_energy <= W_critical_energy)
        return 0;

    //If electron has enough energy to shower
    double shower_depth = (W_radiation_length * log(momentum_ptr->get_E() / W_critical_energy)) / log(2.0);

    return shower_depth;
}

//Member function to determine if shower contained
string Electron::shower_contained(const double detector_length_in) const
{
    if(shower_depth_in_tungsten()==0)
        return "No electromagnetic shower develops";

    if(detector_length_in >= shower_depth_in_tungsten())
        return "Shower contained";

    return "Shower not contained";
}