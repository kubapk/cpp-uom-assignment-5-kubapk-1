/*
____________________________________________
ELECTRON CLASS
(Part of PHYS30762 Assignment 5)
____________________________________________
This header file (interface) defines a class for an electron,
inhereted from "Lepton" class.

Created by Kuba Kane (ID: 11019699)
Created on Tue 14 Apr 2026
*/

//Include guard
#ifndef ELECTRON_H
#define ELECTRON_H

#include<iostream>
#include<string>
#include "Lepton.h"
using std::string;

class Electron : public Lepton
//public ensures Lepton protected members remain protected, and private members
//remain private
{
private:
    //Data members unique to the Electron

public:
    //Parameterised constructor (with new data members)

    //Prototyping member functions
    void info()
    {
        Lepton::info(); //call info function from Lepton
        //Print properties unique to electron
        //NEEDS TO BE MOVED TO IMPLEMENTATION FILE
    }
};


#endif