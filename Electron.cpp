/*
____________________________________________
ELECTRON IMPLEMENTATION
(Part of PHYS30762 Assignment 5)
____________________________________________
Implementation file for functions in Electron class.

Created by Kuba Kane (ID: 11019699)
Created on Tue 14 Apr 2026
*/

#include<iostream>
#include "Electron.h"

//CONSTRUCTORS
//Default constructor
Electron::Electron() :
    Lepton(electron_mass, electron_charge, 0, 0, 0)
{}

//Paramterised constructor
Electron::Electron(double px_in, double py_in, double pz_in) :
    Lepton(electron_mass, electron_charge, px_in, py_in, pz_in)
{}