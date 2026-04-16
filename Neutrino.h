/*
____________________________________________
NEUTRINO CLASS
(Part of PHYS30762 Assignment 5)
____________________________________________
This header file (interface) defines a class for a tau,
inhereted from "Lepton" class.

Created by Kuba Kane (ID: 11019699)
Created on Thu 16 Apr 2026
*/

//Include guard
#ifndef NEUTRINO_H
#define NEUTRINO_H

#include<iostream>
#include<string>
#include "Lepton.h"
using std::string;

class Neutrino : public Lepton
{
private:
    //Data members unique to the muon
    static constexpr double NEUTRINO_MASS{0}; //Do something about this!
    static constexpr double NEUTRINO_CHARGE{-1};
    
public:
    //Default constructor
    Neutrino(); //neutrino at rest (px=py=pz=0)

    //Parameterised constructor (with new data members)
    Neutrino(const double px_in, const double py_in, const double pz_in, const double time_in, bool is_anti = false);

    //Prototyping member functions
    void info() const;
    bool has_decayed() const {return false;}
};


#endif