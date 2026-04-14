### Kuba Kane
# PHYS30762 Assignment 5 - Practising inheritance, smart pointers and friendship

## User Guidelines
### Running the program as-is
This code was run on VSC using a Windows 11 device. The compilation line used was `TBC`. The program can then be run by calling the file `TBC`.

### Modifying the main file, `main.cpp`


## Program Reasoning
### Unique or shared smart pointer
FourMomentum class contains a unique smart pointer because FourMomentum should belong to only one particle. Shared pointers allow multiple pointers to point to the same object. That means if the user wanted to change the FourMomentum object of one particle, it would also change it of all particles which point to the same FourMomentum. Only when the last pointer goes out of scope does the memory become freed, meaning FourMomentum of one object cannot be deleted until all shared pointers become out of scope. These properties make it not useful for the FourMomentum object.

### Abstract derived class or not?
In the main function for this assignment, we are never required to deal with just a lepton, but rather some specific type of lepton. Also, there is no need to work with lepton object - anything that is a lepton has a more specific particle category (e.g. electron, muon) with defined properties. Making Lepton an abstract class therefore makes most sense.

### Friend functions
In assignment 4, the FourMomentum class contained member function `operator+` which summed the FourMomentum object with another FourMomentum object, as well as `dotProduct` which returned a scalar dot product. In assignment 5 we want these operations to be done "inside" the Particle class. However, data from the FourMomentum object cannot be directly accessed - setters and getters from the FourMomentum objects must be used. It makes sense that these operators are not non-member functions, as this would require unecessary calling of the Particle class getters / setters. So that these functions can instead access the private data members of Particle class, i.e. the four momentum, these should be friend functions of Particle class.

Why not have operations as member functions of Particle class? This implies that the two FourMomentum objects are not equal - one FourMomentum needs to call another FourMomentum object with which it wishes to perform a sum or dotProduct operation. Member functions should represent what an object does by itself.


## Notes 
 - Changed Particle class name to Lepton
 - Removed checks for particle name & particle name property of Lepton class
 - Make momentum a protected member of Lepton class
 - Add print function to Lepton class
 - Electrons, muons, taus and neutrinos class - add all of them as separate implementation & header files?
 - Pg7 PPT: sums two four-vectors = sums two four momenta that are hosted in a particle class
 - Check where all consts need to go 
 - QUICK: make lepton an abstract class, define friend functions, remove friend funcs from momentum class - then just do new changes to electron/muon etc. How will you implement everything? Idea of invariant mass being well defined and not energy? 