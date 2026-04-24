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

    //Declare private default constructor
    FourMomentum();

    //Declare private parameterised constructor
    FourMomentum(const double energy_in, const double px_in, const double py_in, 
        const double pz_in, const double mass_in);
    
    //Private function to check input is not infinite
    static void validate_finite(const double x);

    //Private function to check mass is valid
    static void validate_mass(const double mass_in);

    //Private function to check invariant mass equation
    //NOT NEEDED - WILL ALWAYS BE FOLLOWED DUE TO FUNCTIONS BELOW

    //Private function to find energy given 3-momentum & mass
    static double compute_energy(const double mass_in, const double px_in, 
    const double py_in, const double pz_in);

    //Private function to find mass given 3-momentum & energy
    static double compute_mass(const double energy_in, const double px_in, 
    const double py_in, const double pz_in);

public:
    //Declare destructor
    ~FourMomentum() = default;

    //Setters
    void set_px(const double& px_in);
    void set_py(const double& py_in);
    void set_pz(const double& pz_in);
    //Do not allow user to set energy, as this would change invariant mass 
    //(not allowed for defined particles)
    //DO not allow user to set mass, as a particle's mass cannot be changed

    //Getters
    const double& get_E() const {return energy;}
    const double& get_px() const {return x_momentum;}
    const double& get_py() const {return y_momentum;}
    const double& get_pz() const {return z_momentum;}
    const double& get_rest_mass() const {return rest_mass;}

    //Member functions
    //FourMomentum from mass
    static FourMomentum four_momentum_from_mass(const double mass_in, const double px_in, 
        const double py_in, const double pz_in);

    //FourMomentum from energy
    static FourMomentum four_momentum_from_energy(const double energy_in, const double px_in, 
        const double py_in, const double pz_in);

    //FourMomentum default
    static FourMomentum default_four_momentum();

    //Prototyping friend functions
    friend std::ostream& operator<<(std::ostream& os, const FourMomentum& fm);
};


#endif