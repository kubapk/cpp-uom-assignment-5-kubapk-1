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
private:
    //Data members unique to the tau
    static constexpr double TAU_MASS{1777};
    static constexpr double TAU_CHARGE{-1};
    static constexpr double TAU_MEAN_LIFETIME{2.9e-13};

    double time_in_detector{0};
    
public:
    //Default constructor
    Tau(); //tau at rest (px=py=pz=0) and time in detector = 0

    //Parameterised constructor (with new data members)
    Tau(const double px_in, const double py_in, const double pz_in, const double time_in, bool is_anti = false);

    //Setters
    void set_time_in_detector(const double& time_in);

    //Getters
    const double& get_time_in_detector() const {return time_in_detector;}

    //Prototyping member functions
    void info() const;
    bool has_decayed() const;
};


#endif