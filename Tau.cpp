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
#include<random> //to generate random numbers
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
    time_in_detector{validate_time(time_in)},
    decay_mode{generate_decay_mode()}
    {}


//SETTERS
//Setter for time_in_detector
void Tau::set_time_in_detector(const double& time_in)
{
    time_in_detector = validate_time(time_in);
}


//GETTERS
//Getter for time in detector
const double& Tau::get_time_in_detector() const 
{
    return time_in_detector;
}

//Getter for decay mode
string Tau::get_decay_mode() const
{
    //Compare the value of decay_mode (set via constructors) with each case
    switch(decay_mode)
    {
        case DecayMode::Hadronic: 
            return "Hadronic decay";
        case DecayMode::Electron: 
            return "tau -> tau neutrino + electron + electron antineutrino";
        case DecayMode::Muon:
            return "tau -> tau neutrino + muon + muon antineutrino";
    }
    throw std::logic_error("Invalid tau decay mode");
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
    std::cout<<(has_decayed()? "Decay type: "+get_decay_mode() : "")<<std::endl;
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

//Private member function to generate decay mode (Monte Carlo)
//To access DecayMode class must specify it is within Tau class
Tau::DecayMode Tau::generate_decay_mode()
{
    static std::random_device rdm; //rdm is random seed
    static std::mt19937 gen(rdm()); //Mersenne Twister random number generator creates random number "gen" 
    //using the seed "rdm"

    //Continuous values between 0 (inclusive) and 1 (exclusive) with uniform probability
    std::uniform_real_distribution<> u(0.0, 1.0);

    //Sample random number between 0 and 1 using "gen"
    double sample{u(gen)};

    //Hadronic if prob between 0 and 0.648
    if(sample < PROB_HADRONIC)
        return DecayMode::Hadronic;

    //Electron if prob between 0.648 and 0.826 (i.e. 17.8%)
    if(sample < PROB_HADRONIC + PROB_ELECTRON)
        return DecayMode::Electron;

    //Muon otherwise (the 17.4% left)
    return DecayMode::Muon;

    
}