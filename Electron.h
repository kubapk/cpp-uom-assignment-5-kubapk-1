/*
____________________________________________
ELECTRON CLASS
(Part of PHYS30762 Assignment 5)
____________________________________________
This header file (interface) defines a class for an electron,
inhereted from "Lepton" class.

Created by Kuba Kane (ID: 11019699)
Created on Tue 14 Apr 2026
*/

//Include guard
#ifndef ELECTRON_H
#define ELECTRON_H

#include<iostream>
#include<string>
#include "Lepton.h"
using std::string;

class Electron : public Lepton
//public ensures Lepton protected members remain protected, and private members
//remain private
{
private:
    //Data members unique to the Electron
    static constexpr double electron_mass{0.511};
    static constexpr double electron_charge{-1};
    
public:
    //Default constructor
    Electron(); //electron at rest (px=py=pz=0)

    //Parameterised constructor (with new data members)
    Electron(const double px_in, const double py_in, const double pz_in);

    //Prototyping member functions
    void info() const
    {
        Lepton::base_info(); //call info function from Lepton
        //Print properties unique to electron
        //NEEDS TO BE MOVED TO IMPLEMENTATION FILE
    }
};


#endif