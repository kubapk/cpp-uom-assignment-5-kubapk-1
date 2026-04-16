/*
____________________________________________
LEPTON CLASS
(Part of PHYS30762 Assignment 5)
____________________________________________
This header file (interface) defines a class for a lepton particle.

Created by Kuba Kane (ID: 11019699)
Created on Sun 22 Mar 2026
*/

//Include guard
#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<string>
#include<memory> //to use smart pointer
#include "FourMomentum.h"
using std::string;

class Lepton
{
protected:
    double mass;
    double charge;
    std::unique_ptr<FourMomentum> momentum_ptr; //Smart pointer to FourMomentum object
    bool is_antiparticle;

    //Protected function to print info in base Lepton class which can be reused
    void base_info() const;

    //Protected function to find energy given 3-momentum
    static double compute_energy(const double mass_in, const double px_in, 
    const double py_in, const double pz_in);

public:
    //Default constructor
    Lepton() = delete; //no "default lepton"

    //Declare parameterised constructor
    Lepton(const double mass_in, const double charge_in, const double px_in,
    const double py_in, const double pz_in, bool is_anti = false);
    
    //Destructor
    virtual ~Lepton() {}

    //Declare copy constructors
    Lepton(const Lepton&); //copy operation
    Lepton(Lepton&&); //move operation

    //Assignment operators
    Lepton& operator=(const Lepton&); //copy operation
    Lepton& operator=(Lepton&&); //move operation

    //Setters
    //Should not have setters for mass and charge as they are fixed properties of a 
    //specific Lepton
    void set_px(const double& px_in);
    void set_py(const double& py_in);
    void set_pz(const double& pz_in);
    //Cannot have setter for FourMomentum as mass is a defined property and should not
    //be entered by the user

    //Getters
    const FourMomentum& get_four_momentum() const {return *momentum_ptr;}
    FourMomentum& get_four_momentum() {return *momentum_ptr;} //const leptons - CHECK THIS
    const double& get_mass() const {return mass;}
    const double& get_charge() const {return charge;}

    //Member functions
    virtual void info() const = 0;
    virtual bool has_decayed() const = 0;

    //Prototyping friend functions
    friend FourMomentum operator+(const Lepton& lep1, const Lepton& lep2);
    //sum of four momenta of 2 lepton objects
    //leptons are const - should not be modified themselves
    //does not make sense for friend function to be const as it is not called
    //by a specific object 
    friend double dotProduct(const Lepton& lep1, const Lepton& lep2);
};


#endif