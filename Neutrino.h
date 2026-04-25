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
public:
    //Enumerator class for neutrino flavour (public so user can access it)
    //Defines a new class Flavour which has 3 specified possibilities
    //Not defined outside class to control scope to just Neutrino class - 
    //otherwise may be complication with Electron class etc.
    enum class NeutrinoFlavour {Electron, Muon, Tau};
    
private:
    //Constants
    static constexpr double NEUTRINO_MASS{0}; //Do something about this!
    static constexpr int NEUTRINO_CHARGE{-1};

    //Variables
    NeutrinoFlavour flavour;
    
public:
    //Default constructor
    Neutrino(NeutrinoFlavour flavour_in); //neutrino at rest (px=py=pz=0),
    //compulsory to take flavour - cannot have flavourless neutrino

    //Parameterised constructor (with new data members)
    Neutrino(const double px_in, const double py_in, const double pz_in, 
        const NeutrinoFlavour flavour_in, bool is_anti = false);
    
    //Setters
    void set_flavour(const NeutrinoFlavour& nf);

    //Getters
    string get_flavour() const; //return by value so that string is not temporary
    int get_generation() const;
    //getters do not have const in front as the string/int which is returned
    //needs to be used - CHECK

    //Prototyping member functions
    void info() const;
    bool has_decayed() const {return false;}
};


#endif