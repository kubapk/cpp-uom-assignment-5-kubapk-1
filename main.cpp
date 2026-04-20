/*
_____________________________TITLE_____________________________
PHYS30762 Assignment 5 - Practising inheritance, smart pointers 
and friendship
_______________________________________________________________
This C++ script creates a vector of different leptons (from 
derived classes), and prints their info, and then sums & takes
takes the dot product of the four momenta of 2 of the leptons.
Electrons are also moved via pointers, and shared pointer is
created for tau lepton.

Created by Kuba Kane (ID: 11019699)
Created on Sat 18 Apr 2026
*/

#include<iostream>
#include<vector>
#include<stdexcept>
#include<memory> //using pointers
#include "Lepton.h"
#include "Electron.h"
#include "Muon.h"
#include "Tau.h"
#include "Neutrino.h"
using std::vector;

int main()
{
    try
    {
        //VECTOR OF DIFFERENT LEPTONS
        //Polymorphism - make it a vector of pointers to Lepton class, and since it is abstract (has virtual function),
        //all the info() is overriden as desired 
        vector<std::unique_ptr<Lepton>> particles;

        //Add 2 electrons by pointer
        particles.push_back(std::make_unique<Electron>(10, 20, 0));
        particles.push_back(std::make_unique<Electron>(0, 5, 0));

        //Add 4 muons
        for(size_t i=0; i<4; ++i) {particles.push_back(std::make_unique<Muon>());}

        //Add 1 antielectron & 1 antimuon
        particles.push_back(std::make_unique<Electron>(5, 10, 5, true));
        particles.push_back(std::make_unique<Muon>(0.5, 1, 0, 0, true));

        //Add muon neutrino & electron neutrino
        particles.push_back(std::make_unique<Neutrino>(Neutrino::NeutrinoFlavour::Muon));
        particles.push_back(std::make_unique<Neutrino>(Neutrino::NeutrinoFlavour::Electron));

        //Add tau & anti tau
        particles.push_back(std::make_unique<Tau>());
        particles.push_back(std::make_unique<Tau>(0, 0, 0, 0, true));

        //PRINT PARTICLES INFO
        //Iterate through vector & print out info
        for(const auto& i : particles)
        {
            std::cout<<"\n"<<string(60, '-')<<std::endl;
            i->info(); //(*i.info())
        }
        //"i" is std::unique_ptr<Lepton> but can let compiler decide with auto
        //cannot pass i by value as smart pointers (used for particles) cannot be copied - pass by reference
        //Set the reference to std::unique_ptr<Lepton> (i.e "i") to be const as it shouldn't be modified -
        //each particle in particles should not change


        //SUM OF FOUR-MOMENTA OF 2 ELECTRONS
        //Get the 2 electron objects (use const to prevent modification)
        //Forces treatment as lepton objects
        //need to be reference to Lepton as cannot have abstract lepton class
        const Lepton& elec_1 = *particles[0];
        const Lepton& elec_2 = *particles[1];

        FourMomentum momenta_2_electrons = sum_momenta(elec_1, elec_2);
        std::cout<<"\n\nSum of four momenta of 2 electrons\n"<<string(60, '-')<<std::endl;
        std::cout<<momenta_2_electrons<<std::endl;


        //DOT PRODUCT OF ANTI ELECTRON & ANTI MUON
        const Lepton& anti_elec = *particles[6];
        const Lepton& anti_muon = *particles[7];

        double dot_anti_elec_muon = dot_product_momenta(anti_elec, anti_muon);
        std::cout<<"\n\nDot product of anti electron & anti muon\n"<<string(60, '-')<<std::endl;
        std::cout<<dot_anti_elec_muon<<std::endl;


        //MOVE ELECTRONS
        //Create electron object
        Electron fast_electron(10, 10, 10);
        //Declare unique pointer to Electron object
        std::unique_ptr<Electron> electron_ptr;
        //Assign pointer to address of an electron
        electron_ptr = std::make_unique<Electron>(fast_electron);

        //Move fast electron to a new pointer
        std::unique_ptr<Electron> electron_ptr_2 = std::move(electron_ptr);

        //Print info
        std::cout<<"\n\nMoving electron pointer\n"<<string(60, '-')<<std::endl;
        //electron_ptr->info();
        electron_ptr_2->info();


        //SHARED POINTER FOR TAU LEPTON
        std::shared_ptr<Tau> tau_ptr = std::make_shared<Tau>(5, 5, 0, 3.4e-10);

        //Give new pointers the same pointer
        std::shared_ptr<Tau> tau_ptr_2 = tau_ptr;
        std::shared_ptr<Tau> tau_ptr_3 = tau_ptr;

        //Use count
        std::cout<<"\n\nShared tau pointer\n"<<string(60, '-')<<std::endl;
        std::cout<<"Use count of shared pointer = "<<tau_ptr.use_count()<<std::endl;
        std::cout<<"\nFrom original pointer: "<<std::endl;
        tau_ptr->info();
        std::cout<<"\nFrom pointer 2: "<<std::endl;
        tau_ptr_2->info();
        std::cout<<"\nFrom pointer 3: "<<std::endl;
        tau_ptr_3->info();


        //TAU LEPTON SEEN BY MULTIPLE DETECTORS
        //Must be vectors of shared pointers
        vector<std::shared_ptr<Lepton>> detector_1_particles;
        vector<std::shared_ptr<Lepton>> detector_2_particles;
        detector_1_particles.push_back(tau_ptr);
        detector_2_particles.push_back(tau_ptr);
        std::cout<<"\n\nDectectors with same tau\n"<<string(60, '-')<<std::endl;
        std::cout<<"Use count of shared pointer = "<<tau_ptr.use_count()<<std::endl;

        std::cout<<"\nDetector 1 contains: "<<std::endl;
        for(const auto& j : detector_1_particles)
        {
            j->info();
        }

        std::cout<<"\nDetector 2 contains: "<<std::endl;
        for(const auto& k : detector_2_particles)
        {
            k->info();
        }


    }
    catch(const std::exception& e)
    {
        std::cout<<"Error: "<<e.what()<<std::endl;
        return 1;
    }

    return 0;
}