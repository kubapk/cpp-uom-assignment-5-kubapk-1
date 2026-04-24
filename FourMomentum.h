/*
____________________________________________
FOUR MOMENTUM CLASS
(Part of PHYS30762 Assignment 5)
____________________________________________
This header file (interface) defines a class for four momentum.

Created by Kuba Kane (ID: 11019699)
Created on Sun 22 Mar 2026
*/

//Include guard
#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include<iostream>


class FourMomentum
{
private:
    double energy, x_momentum, y_momentum, z_momentum, rest_mass;
    
    //Private function to check input is not infinite
    static void validate_finite(const double x);

    //Private function to check mass is valid
    static void validate_mass(const double mass_in);

    //Private function to check invariant mass equation
    static void validate_invariant_mass(const double energy_in, const double px_in, 
    const double py_in, const double pz_in, const double mass_in);

    //Private function to find energy given 3-momentum & mass
    static double compute_energy(const double mass_in, const double px_in, 
    const double py_in, const double pz_in);

public:
    //Declare default constructor
    FourMomentum();

    //Declare parameterised constructor
    FourMomentum(const double mass_in, const double px_in, const double py_in, 
        const double pz_in);

    //Declare overloaded constructor with energy & mass
    FourMomentum(const double energy_in, const double px_in, const double py_in, 
        const double pz_in, const double mass_in);
        //Must have different number of components to overload constructor

    //Declare destructor
    ~FourMomentum() = default;

    //Setters
    void set_px(const double& px_in);
    void set_py(const double& py_in);
    void set_pz(const double& pz_in);
    //Do not allow user to set energy, as this would break invariant mass equation
    //DO not allow user to set mass, as a particle's mass cannot be changed

    //Getters
    const double& get_E() const {return energy;}
    const double& get_px() const {return x_momentum;}
    const double& get_py() const {return y_momentum;}
    const double& get_pz() const {return z_momentum;}

    //Prototyping friend functions
    friend std::ostream& operator<<(std::ostream& os, const FourMomentum& fm);
};


#endif