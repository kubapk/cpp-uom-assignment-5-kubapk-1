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
//Electron::Electron() :
//Paramterised constructor
Electron::Electron(double mass_in, double charge_in,
                   double px_in, double py_in, double pz_in)
    : Lepton(mass_in, charge_in, px_in, py_in, pz_in)
{}