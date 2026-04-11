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
#include "FourMomentum.h"
using std::string;

class Lepton
{
protected:
    FourMomentum momentum;
    //FourMomentum is an object whose only data member is a unique_ptr, which need not be specified
    //as it is handled by the default constructor within FourMomentum class (which specifies the unique
    //ptr to a vector of four "0.0" doubles)
public:
    //Default constructor
    Lepton() = default; //takes values as above

    //Declare parameterised constructor
    Lepton(const FourMomentum& momentum_in);
    //Since the objects are large here, they are passed by reference to avoid unnecessary copying
    
    //Destructor
    ~Lepton() {}

    //Copy constructors
    Lepton(const Lepton&) = default;
    Lepton(Lepton&&) = default;

    //Assignment operators
    Lepton& operator=(const Lepton&) = default;
    Lepton& operator=(Lepton&&) = default;

    //Setters
    void set_four_momentum(const FourMomentum& momentum_in);

    //Getters
    const FourMomentum& get_four_momentum() const {return momentum;}
    FourMomentum& get_four_momentum() {return momentum;}

    //Member functions
    void info()
    {
        std::cout<<"Lepton: four momentum = "<<momentum<<"e"<<std::endl;
    }
};


#endif