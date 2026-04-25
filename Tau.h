/*
____________________________________________
TAU CLASS
(Part of PHYS30762 Assignment 5)
____________________________________________
This header file (interface) defines a class for a tau,
inhereted from "Lepton" class.

Created by Kuba Kane (ID: 11019699)
Created on Thu 16 Apr 2026
*/

//Include guard
#ifndef TAU_H
#define TAU_H

#include<iostream>
#include<string>
#include "Lepton.h"
using std::string;

class Tau : public Lepton
{
public:
    enum class DecayMode{Hadronic, Electron, Muon};

private:
    //Constant expressions
    static constexpr double TAU_MASS{1777};
    static constexpr int TAU_CHARGE{-1};
    static constexpr double TAU_MEAN_LIFETIME{2.9e-13};
    static constexpr double MAX_TIME{1.0}; //1 second

    static constexpr double PROB_HADRONIC{0.648};
    static constexpr double PROB_ELECTRON{0.178};
    static constexpr double PROB_MUON{0.174};

    //Constant functions
    static double validate_time(const double t);
    static DecayMode generate_decay_mode();

    //Variables
    double time_in_detector{0};
    DecayMode decay_mode;
    
public:
    //Default constructor
    Tau(); //tau at rest (px=py=pz=0) and time in detector = 0

    //Parameterised constructor (with new data members)
    Tau(const double px_in, const double py_in, const double pz_in, const double time_in, bool is_anti = false);

    //Setters
    void set_time_in_detector(const double& time_in);

    //Getters
    const double& get_time_in_detector() const;
    string get_decay_mode() const;

    //Prototyping member functions
    void info() const;
    bool has_decayed() const;
};


#endif