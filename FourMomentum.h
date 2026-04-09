/*
____________________________________________
FOUR MOMENTUM CLASS
(Part of PHYS30762 Assignment 4)
____________________________________________
This header file (interface) defines a class for a particle.

Created by Kuba Kane (ID: 11019699)
Created on Sun 22 Mar 2026
*/

//Include guard
#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include<iostream>
#include<vector>
#include<memory> //to use unique_ptr
using std::vector;

class FourMomentum
{
private:
    //Declare "four_momentum_ptr" as a unique pointer to a vector of doubles
    std::unique_ptr<vector<double>> four_momentum_ptr;
    
    //Private function to check energy is not negative
    static void validate_energy(const double E);

public:
    //Declare default constructor
    FourMomentum();

    //Declare paramterised constructor
    FourMomentum(const double energy_in, const double x_momentum_in, const double y_momentum_in, 
        const double z_momentum_in);

    //Declare destructor
    ~FourMomentum();

    //Declare copy constructors
    FourMomentum(const FourMomentum&); //copy operation
    FourMomentum(FourMomentum&&); //move operation 
    //copy is const since copying should not change original copy
    //move is not const since FourMomentum pointer passed in will be given new pointer (null)

    //Declare assignment operators
    FourMomentum& operator=(const FourMomentum&); //copy operation
    FourMomentum& operator=(FourMomentum&&); //move operation

    //Setters
    void set_E(const double energy_in);
    void set_px(const double x_momentum_in);
    void set_py(const double z_momentum_in);
    void set_pz(const double y_momentum_in);
    //Not const funcs as four momentum is modified

    //Getters
    const double& get_E() const {return (*four_momentum_ptr)[0];}
    const double& get_px() const {return (*four_momentum_ptr)[1];}
    const double& get_py() const {return (*four_momentum_ptr)[2];}
    const double& get_pz() const {return (*four_momentum_ptr)[3];}
    //get_E() is a const function which returns a reference to a const double (ensures *this
    //is not modified)

    //Prototyping member functions (overload operators)
    FourMomentum operator+(const FourMomentum& fm) const;
    double dotProduct(const FourMomentum& fm) const;

    //Prototyping friend functions
    friend std::ostream& operator<<(std::ostream& os, const FourMomentum& fm);
};


#endif