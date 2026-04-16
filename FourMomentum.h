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
    double energy, x_momentum, y_momentum, z_momentum; //MeV
    
    //Private function to check energy is not negative
    static void validate_energy(const double E);

public:
    //Declare default constructor
    FourMomentum();

    //Declare paramterised constructor
    FourMomentum(const double energy_in, const double x_momentum_in, const double y_momentum_in, 
        const double z_momentum_in);

    //Declare destructor
    ~FourMomentum() = default;

    //Setters
    //Do not allow user to set components of FourMomentum object

    //Getters
    const double& get_E() const {return energy;}
    const double& get_px() const {return x_momentum;}
    const double& get_py() const {return y_momentum;}
    const double& get_pz() const {return z_momentum;}

    //Prototyping friend functions
    friend std::ostream& operator<<(std::ostream& os, const FourMomentum& fm);
};


#endif