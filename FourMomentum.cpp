/*
____________________________________________
FOUR MOMENTUM IMPLEMENTATION
(Part of PHYS30762 Assignment 4)
____________________________________________
This implementation file defines member functions (including setters) for the 
"FourMomentum" class, as well as its constructor and assignment operator for 
copy and move operations.

Created by Kuba Kane (ID: 11019699)
Created on Tue 24 Mar 2026
*/

#include<iostream>
#include <stdexcept>
#include "FourMomentum.h"


//CONSTRUCTORS
//Default constructor
FourMomentum::FourMomentum() :
    //Initialise unique pointer, pointing to a vector of 4 doubles each allocated as "0.0"
    four_momentum_ptr{std::make_unique<vector<double>>(4, 0.0)} {}
    //Uses intialiser list (in case of consts)


//Parameterised constructor
FourMomentum::FourMomentum(const double energy_in, const double x_momentum_in, const double y_momentum_in, 
    const double z_momentum_in)
{
    //Check energy is not less than or equal to 0
    validate_energy(energy_in);

    four_momentum_ptr = std::make_unique<vector<double>>();
    (*four_momentum_ptr).push_back(energy_in);
    (*four_momentum_ptr).push_back(x_momentum_in);
    (*four_momentum_ptr).push_back(y_momentum_in);
    (*four_momentum_ptr).push_back(z_momentum_in);
}


//Destructor
FourMomentum::~FourMomentum() 
{std::cout<<" >> Calling FourMomentum destructor"<<std::endl;}


//Copy constructor
FourMomentum::FourMomentum(const FourMomentum& fm) : 
    //Unique pointer does not allow copy so need to extend  copy semantics to implement 
    //copy constructor manually - use deep copy
    //fm is a reference to FourMomentum, whose only data member is a unique pointer
    //to a vector of 4 doubles
    //Unique pointer does not require memory to be dynamically allocated, and then
    //have elements copied 1 by 1
    //Can instead use copy constructor from vector class

    //Initialise unique_ptr called "four_momentum_ptr" (just like default constructor), using 
    //make_unique, and in the brackets put the vector which it should copy
    //To get this vector, note fm is FourMomentum object, we just want pointer to four momentum
    //class
    four_momentum_ptr{std::make_unique<vector<double>>(*fm.four_momentum_ptr)} 
    {std::cout<<" >> Calling FourMomentum copy constructor"<<std::endl;}
    //copy constructor uses initialisation rather than assignment


//Copy assignment operator
FourMomentum& FourMomentum::operator=(const FourMomentum& fm)
{
    std::cout<<" >> Calling FourMomentum copy assignment operator"<<std::endl;
    //Check for self-assignment
    if(&fm == this) return *this;
    //if fm as FourMomentum object (i.e. dereferenced fm) is same as object calling assignment
    //operator ("this"), then just return "this"

    //Smart pointers handle dynamic memory allocation and so delete is not needed, we use vector
    //copy constructor
    four_momentum_ptr = std::make_unique<vector<double>>(*fm.four_momentum_ptr);
    return *this;
}


//Move constructor
FourMomentum::FourMomentum(FourMomentum&& fm) :
    four_momentum_ptr{std::move(fm.four_momentum_ptr)} 
    {std::cout<<" >> Calling FourMomentum move constructor"<<std::endl;}
    //Standard library unique pointers allow us to transfer ownership (to a different object) using
    //std::move - this transfers the pointers with each other, so the new four_momentum_ptr becomes
    //the four_momentum_ptr of "fm"


//Move assignment operator
FourMomentum& FourMomentum::operator=(FourMomentum&& fm)
//Return reference to new FourMomentum object after assignment - more memory efficient
{
    std::cout<<" >> Calling FourMomentum move assignment operator"<<std::endl;
    if(&fm == this) return *this;

    four_momentum_ptr = std::move(fm.four_momentum_ptr);
    return *this; //returns dereferenced four_momentum_ptr
}


//SETTERS
//Setter for energy
void FourMomentum::set_E(const double energy_in)
{
    //Check energy is not less than or equal to 0
    validate_energy(energy_in);

    (*four_momentum_ptr)[0] = energy_in;
}


//Setters for px, py, pz
void FourMomentum::set_px(const double x_momentum_in) {(*four_momentum_ptr)[1] = x_momentum_in;}
void FourMomentum::set_py(const double y_momentum_in) {(*four_momentum_ptr)[2] = y_momentum_in;}
void FourMomentum::set_pz(const double z_momentum_in) {(*four_momentum_ptr)[3] = z_momentum_in;}


//MEMBER FUNCTIONS
//"+" operator overloading
FourMomentum FourMomentum::operator+(const FourMomentum& fm) const
{
    //Use parameterised constructor, summing component in class to inputted component "fm"
    return FourMomentum(
    get_E() + fm.get_E(),
    get_px() + fm.get_px(),
    get_py() + fm.get_py(),
    get_pz() + fm.get_pz()
    );
}


//Dot product
double FourMomentum::dotProduct(const FourMomentum& fm) const
{
    //Using (+, -, -, -) convention for Minkowski matrix (dot product)
    return(get_E()*fm.get_E() - get_px()*fm.get_px() - get_py()*fm.get_py() - get_pz()*fm.get_pz());
}


//Private member function to check for energy
void FourMomentum::validate_energy(const double E)
{
    if(E < 0)
    {
        throw std::invalid_argument("Energy in FourMomentum is negative. Energy must not be negative.");
    }
}


//FRIEND FUNCTIONS
//Friend function to print FourMomentum
std::ostream &operator<<(std::ostream &os, const FourMomentum &fm)
{
    os << "[E = "<<fm.get_E()<<"MeV, px = "<<fm.get_px()<<"MeV, py = "<<fm.get_py()<<"MeV, pz = "<<fm.get_pz()<<"MeV]";

    return os;
}