/*
____________________________________________
PARTICLE CLASS
(Part of PHYS30762 Assignment 4)
____________________________________________
This header file (interface) defines a class for a particle.

Created by Kuba Kane (ID: 11019699)
Created on Sun 22 Mar 2026
*/

//Include guard
#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include "FourMomentum.h"
using std::string;

class Particle
{
private:
    string name{"electron"};
    FourMomentum momentum;
    //FourMomentum is an object whose only data member is a unique_ptr, which need not be specified
    //as it is handled by the default constructor within FourMomentum class (which specifies the unique
    //ptr to a vector of four "0.0" doubles)

    //Private member function to check if name is valid
    static string validate_name(const string& name_in);

public:
    //Default constructor
    Particle() = default; //takes values as above

    //Declare parameterised constructor
    Particle(const string& name_in, const FourMomentum& momentum_in);
    //Since the objects are large here, they are passed by reference to avoid unnecessary copying
    
    //Destructor
    ~Particle() {}

    //Copy constructors
    Particle(const Particle&) = default;
    Particle(Particle&&) = default;

    //Assignment operators
    Particle& operator=(const Particle&) = default;
    Particle& operator=(Particle&&) = default;

    //Setters
    void set_name(const string& name_in);
    void set_four_momentum(const FourMomentum& momentum_in);

    //Getters
    const string& get_name() const {return name;}
    const FourMomentum& get_four_momentum() const {return momentum;}
    FourMomentum& get_four_momentum() {return momentum;}

    //Prototyping friend functions
    friend std::ostream& operator<<(std::ostream& os, const Particle& p);
};


#endif