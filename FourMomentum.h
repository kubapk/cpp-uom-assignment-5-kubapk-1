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
#include<vector>
using std::vector;


class FourMomentum
{
private:
    //Variables
    double energy, x_momentum, y_momentum, z_momentum; //MeV

    //Declare private default constructor
    FourMomentum();

    //Declare private parameterised constructor
    FourMomentum(const double energy_in, const double px_in, const double py_in, 
        const double pz_in);
    
    //Private function to check px, py, pz are not infinite
    static void validate_3_momentum(const double px, const double py, const double pz);

    //Private function to find energy given 3-momentum
    static double compute_energy(const double mass_in, const double px_in, 
    const double py_in, const double pz_in);

    //Private function to check is valid mass
    static void validate_mass(const double mass_in);

public:
    //Declare destructor
    ~FourMomentum() = default;

    //Setters
    void set_px(const double& px_in);
    void set_py(const double& py_in);
    void set_pz(const double& pz_in);

    //Getters
    const double& get_E() const {return energy;}
    const double& get_px() const {return x_momentum;}
    const double& get_py() const {return y_momentum;}
    const double& get_pz() const {return z_momentum;}

    //FourMomentum from mass
    static FourMomentum four_momentum_from_mass(const double mass_in, const double px_in, 
        const double py_in, const double pz_in);

    //FourMomentum from energy
    static FourMomentum four_momentum_from_energy(const double energy_in, const double px_in, 
        const double py_in, const double pz_in);

    //Prototyping friend functions
    friend std::ostream& operator<<(std::ostream& os, const FourMomentum& fm);
};


#endif