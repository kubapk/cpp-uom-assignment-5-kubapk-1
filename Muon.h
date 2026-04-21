/*
____________________________________________
MUON CLASS
(Part of PHYS30762 Assignment 5)
____________________________________________
This header file (interface) defines a class for a muon,
inhereted from "Lepton" class.

Created by Kuba Kane (ID: 11019699)
Created on Thu 16 Apr 2026
*/

//Include guard
#ifndef MUON_H
#define MUON_H

#include<iostream>
#include<string>
#include "Lepton.h"
using std::string;

class Muon : public Lepton
//public ensures Lepton protected members remain protected, and private members
//remain private
{
private:
    //Static expressions
    static constexpr double MUON_MASS{105.7};
    static constexpr double MUON_CHARGE{-1};
    static constexpr double MUON_MEAN_LIFETIME{2.2e-6};
    static constexpr double MAX_TIME{3600*24*365};
    static double validate_time(const double t);

    //Variables
    double time_in_detector{0};
    
public:
    //Default constructor
    Muon(); //muon at rest (px=py=pz=0) with no time in detector

    //Parameterised constructor (with new data members)
    Muon(const double px_in, const double py_in, const double pz_in, const double time_in, bool is_anti = false);

    //Setters
    void set_time_in_detector(const double& time_in);

    //Getters
    const double& get_time_in_detector() const {return time_in_detector;}

    //Prototyping member functions
    void info() const; //override Lepton class info() function
    bool has_decayed() const;
};


#endif