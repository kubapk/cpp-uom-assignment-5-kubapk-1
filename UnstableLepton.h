/*
____________________________________________
UNSTABLE LEPTON CLASS
(Part of PHYS30762 Assignment 5)
____________________________________________
This header file (interface) defines an abstract class
for unstable leptons, derived from the Lepton class.

Created by Kuba Kane (ID: 11019699)
Created on Thu 16 Apr 2026
*/

//Include guard
#ifndef UNSTABLELEPTON_H
#define UNSTABLELEPON_H

#include<iostream>
#include<string>
#include "Lepton.h"
using std::string;

class UnstableLepton : public Lepton
//public ensures Lepton protected members remain protected, and private members
//remain private
{
private:
    //Static expressions
    static double validate_time(const double t);

    //Variables
    double time_in_detector{0};
    
public:
    //Default constructor
    UnstableLepton(); //muon at rest (px=py=pz=0) with no time in detector

    //Parameterised constructor (with new data members)
    UnstableLepton(const double px_in, const double py_in, const double pz_in, const double time_in, bool is_anti = false);

    //Setters
    void set_time_in_detector(const double& time_in);

    //Getters
    const double& get_time_in_detector() const {return time_in_detector;}

    //Prototyping member functions
    void info() const; //override Lepton class info() function
    bool has_decayed() const;
};


#endif