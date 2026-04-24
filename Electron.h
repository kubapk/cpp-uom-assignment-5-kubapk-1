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
    //Constants
    static constexpr double ELECTRON_MASS{0.511};
    static constexpr double ELECTRON_CHARGE{-1};
    //This is best to have as a property which can be printed in Lepton already
    static void validate_detector_length(const double detector_length_in);

    //Variables
    double detector_length; //cm
    
public:
    //Default constructor
    Electron(); //electron at rest (px=py=pz=0)

    //Parameterised constructor (with new data members)
    Electron(const double px_in, const double py_in, const double pz_in, 
        const double detector_length_in, bool is_anti = false);

    //Setters
    void set_detector_length(const double& detector_length_in);

    //Getters
    const double& get_detector_length() const {return detector_length;}

    //Prototyping member functions
    void info() const; //override Lepton class info() function
    bool has_decayed() const {return false;}
    double shower_depth_in_tungsten() const;
    string shower_contained(const double detector_length_in) const;

};


#endif