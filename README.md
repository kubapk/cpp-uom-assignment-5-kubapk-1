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
In the main function for this assignment, we are never required to deal with just a lepton, but rather some specific type of lepton. Also, there is no need to work with lepton object - anything that is a lepton has a more specific particle category (e.g. electron, muon) with defined properties. Making Lepton an abstract class therefore makes most sense. To make Lepton an abstract class, at least one virtual function needs to be pure virtual. To adhere to this required redesigning a little - info() function should print any additional features beyond FourMomentum only, and so info() function can be pure virtual in base. It can then have a private function which prints the base info separately.

### Friend functions
In assignment 4, the FourMomentum class contained member function `operator+` which summed the FourMomentum object with another FourMomentum object, as well as `dotProduct` which returned a scalar dot product. In assignment 5 we want these operations to be done "inside" the Particle class. However, data from the FourMomentum object cannot be directly accessed - setters and getters from the FourMomentum objects must be used. It makes sense that these operators are not non-member functions, as this would require unecessary calling of the Particle class getters / setters. So that these functions can instead access the private data members of Particle class, i.e. the four momentum, these should be friend functions of Particle class.

Why not have operations as member functions of Particle class? This implies that the two FourMomentum objects are not equal - one FourMomentum needs to call another FourMomentum object with which it wishes to perform a sum or dotProduct operation. Member functions should represent what an object does by itself.

### Invariant mass
Including mass as a derived property is good because each particle in SM has different invariant mass. This however, links to the FourMomentum since $m^2 = E^2 - p^2$. So if a user defines (E, px, py, pz), this must give the same invariant mass. Set_px would crash because if user wanted to change it, invariant mass would change. Another option could be only let the user enter (px, py, pz) and find E based on the invariant mass. This would need to change dynamics of code at the moment, which requires a FourMomentum object to be entered, and as it is a requirement of the assignment to have Lepton class contain a FourMomentum object, it is hard to get around this. The FourMomentum class in some ways would need to take in the invariant mass in its constructors to perform the checks, as otherwise Lepton class would need to take in px, py, pz parameters as well as FourMomentum object which doesn't make much sense. Also, it assumes the user knows (px, py, pz) and doesn't know E, and it does not allow the reverse.

Actually both seem to have the problem: What if the user uses a setter to set a momentum component afterwards?

### 0/3/5 rule
The FourMomentum object has the data members E, px, py, pz which are all doubles. As there are no pointers involved (or any other objects of non-class type), we use the rule of 0 - FourMomentum object does not need to have user-defined special member functions. Since the Lepton class involves a smart pointer, we must implement the rule of 3 at least. As the assignment requires `std::move` of Electron (derived from Lepton), we need move semantics and so must implement the rule of 5.

## Notes 
 - Changed Particle class name to Lepton
 - Removed checks for particle name & particle name property of Lepton class
 - Make momentum a protected member of Lepton class
 - Add print function to Lepton class
 - Electrons, muons, taus and neutrinos class - add all of them as separate implementation & header files?
 - Pg7 PPT: sums two four-vectors = sums two four momenta that are hosted in a particle class
 - Check where all consts need to go 
 - QUICK: make lepton an abstract class, define friend functions, remove friend funcs from momentum class - then just do new changes to electron/muon etc. How will you implement everything? Idea of invariant mass being well defined and not energy? 
 - Need Lepton class to have constructor? Allowed if abstract?
 - Charge should be double or int?

 - IDEA: change it to be Lepton containing smart pointer to FourMomentum object with E, px, py, pz. Base class (Lepton) allows user to enter these - tbh don't need to define it since its abstract so user shouldn't need to construct it. Then add mass property to derived classes - and give then a new constructor which allows you to find E from inputting px, py, pz. What if user uses set_px? test_electron.momentum.set_px(10) -> should change E

 Solution: Remove setters from FourMomentum object - only allow everything to be set through Lepton class. Problem - lepton class doesn't have mass? So new setters & getters for all derived classes from Lepton?? Even if you just had a check which allowed E input and checked that together with px, py, pz it gave correct invariant mass, the user could later chang px and break this.

 Once that is done, you need to add mass and charge proeprties to derived classes, and think of adding more relating to interaction with particle detector. Once you have that idea clear, but not implemented, add antiparticle structure to classes. NOT TOO LONG ON THIS - THERE IS MUCH MORE BEYOND!