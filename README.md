### Kuba Kane
# PHYS30762 Assignment 5 - Practising inheritance, smart pointers and friendship

## User Guidelines
### Running the program as-is
This code was run on VSC using a Windows 11 device. The compilation line used was `g++ -std=c++17 main.cpp Neutrino.cpp Tau.cpp Muon.cpp Electron.cpp Lepton.cpp FourMomentum.cpp -o main.exe -Wall`. The program can then be run by calling the file `main.exe`.

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

### Modifying the FourMomentum class
(See invariant mass above) The FourMomentum class was modified, as it originally contained just one private data member which was a pointer to a four-vector containing E, px, py, pz, which caused issues when creating derived classes which had derived (rest) masses (wouldn't necessarily obey the equation for invariant mass). This was resolved by making the FourMomentum class have E, px, py, pz as data members themselves, allowing the 3-momentum to be set by the user, and then using the invariant mass equation to determine the energy and define the FourMomentum object. This could work with keeping it as a four-vector within the FourMomentum class but logically doesn't make much sense (suggest FourMomentum vector is property of FourMomentum class), and is more difficult to modify.

The issue with having setters adjusting px, py, pz later could only be resolved by removing them directly from the FourMomentum class, and instead only allowing them to be changed via the Lepton class. This is much easier when FourMomentum contains E, px, py, pz as members directly. 

Another issue with the FourMomentum class as it does not verify the invariant mass formula, and so a user could create a FourMomentum object with an invalid invariant mass. However, the Lepton class and any of its derived classses cannot take a FourMomentum object as an input, and so there is no benefit in the user creating a FourMomentum object. To be secure, FourMomentum object could have Lepton as a friend class, and its constructor as private, thus only allowing the FourMomentum constructor to be used via the Lepton class. If user whishes to extend to e.g. baryons or quarks, then these must also be friend classes of the FourMomentum class. 

**Problem with this is classes derived from Lepton class cannot use FourMomentum object.**

### 0/3/5 rule
The FourMomentum object has the data members E, px, py, pz which are all doubles. As there are no pointers involved (or any other objects of non-class type), we use the rule of 0 - FourMomentum object does not need to have user-defined special member functions. Since the Lepton class involves a smart pointer, we must implement the rule of 3 at least. As the assignment requires `std::move` of Electron (derived from Lepton), we need move semantics and so must implement the rule of 5. All derived classes inherit the constructors and assignment operators defined in Lepton base class, and since they do not have any pointers, we use rule of 0 for derived classes.

### Compile line
Compile line must include all classes defined even if they are derived (code is still needed).

### Static functions
Even if in class they are static, in impelementation cannot be static - must be called from class name so that they are linked together.

### constexpr
constexpr specifies that the value of an object or a function can be evaluated at compile-time and the expression can be used in other constant expressions. Makes it obvious these are physical constants and there are no changes of setting this incorrectly. Useful for electron_mass and electron_charge as we don't ever want these values to change during compilation or run time. These were set to private data members, to keep it separate from the getter get_mass and get_charge - give user only one way to access them, and this is consistent across all derived classes.

Think of FourMomentum as an object. get_four_momentum will give us FourMomentum(E, px, py, pz), but if you print it out then it will use friend function to print it how you have specified.

### Antiparticle
Introduce boolean parameter in Lepton base class `is_antiparticle`, which is true if it is an antiparticle, and false if it is not. The charge is then set to be negative of inputted charge if antiparticle. Note the user can never in reality set the charge - derived classes specify this, and do not have setters for charge. If user does not specify boolean parameter it defaults to false. 

Setting bool to be default false only needs to be done in class file, and not implementation file (in main constructor defined as in class file) - implementation takes whatever else.

An issue ocurred where muon was printing as antimuon even though `is_antiparticle` is false by default. This arised because `is_antiparticle` was not updated using the constructor, meaning when the constructor was called, `is_antiparticle` was not updated. This required adding a line to constructor which set `is_antiparticle` to match input from constructor.

Shouldn't be `const bool` because we want to print out a specific text in the `info()` function depending on value of bool. But can have `bool const` because it just means the Muon object which calls it cannot be modified. Also shouldn't be `static bool` as it depends on the time_in_detector specified for the specific Muon object (not idependent of object properties).

### Destructor
The destructor in FourMomentum was not defined (not even as default) in FourMomentum class when changes were made to remove the delete destructor message - this caused there to be an error when the FourMomentum object was attempted to be desrtoyed. This is a result of the line `std::unique_ptr<FourMomentum> momentum_ptr;` which when goes out of scope must have a defined destructor. 

### Using const for functions (getters)
In neutrino class used `get_flavour` to output a string for the flavour. It is used within the info function and the user can also call it (hence why it is public). As it is just returning a string which doesn't exist in memory before, the variable is temporary and so it should not be returned by reference (this would cause an error as the pointer would not have anything to point to once it goes out of scope at the end of the `get_flavour` function). Since the output of the function is temporary, there is no need to use `const get_flavour` as that would just set the temporary inside the function to a const, which goes out of scope anyway.

### Neutrinos
Default constructor must contain flavour as an input, as all neutrinos are born with a specific flavour.

Neutrinos cannot be entered with an invalid neutrino - must be called via enumerator which only has 3 options. If however there is an uninitialised variable `NeutrinoFlavour flavour;`, this could be passed through with an invalid (null) flavour. Hence the need for throw logic error if enumerator reaches end.

### Class input validation
Added check on the user input for time in detector, so they could not enter a negative time, or an arbitarily large time (taken to be 1ms - WHY? CORRESPONDS TO HIGH ENERGY?). The 3-momentum can contain any positive or negative floats, but should not allow infinite values. If a user enters a very large momentum, it may overflow to `inf` which cannot be used in calculations. Infinite values must therefore be checked for and throw an error. This is done via FourMomentum class.

### Assumptions
Electron and Neutrino have has_decayed=false because they are stable particles so for any time in the detector they are most likely to not have decayed. To ensure this holds, and that the user can't enter arbitrarily large numbers, we set a limit on the time_in_detector. In the program logic, if during the maximum of time_in_detector the Lepton doesn't decay, it doesn't need that property and so it always has has_decayed=false.

Charge of Leptons is always an integer, so charge changed to int everywhere.

### Decay modes for tau
A muon decays into electron, antineutrino and muon neutrino at about 100% probability. Antimuon also has about 100% probability of decaying into positrion, neutrino and anti muon neutrino. Taus on the other hand have different decay modes, which can be purely hadronic (64.8% of time), or emit electron & electron nuetrino (17.8% of time), or emit muon & muon neutrino (17.4% of the time). Therefore feasible to introduce decay modes to tau class. Use enumerator class to specify these 3 possibilities, and then a function to output one of these according to these probabilities, and then print out what the tau decays to according to the enumerator.

`get_decay_mode` returns a string which didn't exist in memory before. Since the variable is temporary, it should not be returned by reference (this would cause an error as the pointer would not have anything to point to once it goes out of scope at the end of the `get_decay_mode` function). Since the output of the function is temporary, there is also no need to use `const get_decay_mode` as that would just set the temporary inside the function to a const, which goes out of scope anyway.


## Notes 
 - Check where all consts need to go 
 - Have all properties as data members (mass, charge, particle name, particle decay status) of the class - get_mass and get_charge virtual funcs in Lepton class and override them in each derived class 
 - If something can be derived, don’t store it as a property of a class
 - Should bool be const? 
 - Tau can have unique property different from muon?
 - Time in detector and all of its checks are repeated in muon & tau - not good
 - E.g. tau takes in some input number which the user can decide, and this is returned or some calculation is returned as a property of that particle
 - random decay times using exponential distributions
 - Time in detector doesn't make sense - cannot measure 10^-6 seconds of existence - see random decay times above
 - Random generator to generate a specific lifetime about mean lifetime - then this decay time becomes a property of the class
 - Add oscillations to neutrino. While born with a definite flavor, a neutrino's flavor changes as it propagates through space, meaning it is not restricted to one flavour for its entire existence. Neutrinos only fully commit to a specific flavor when they interact with matter, behaving like one of the three standard types upon detection.
 - Is there something you can do with gamma / beta or relativity as "time in detector" doesn't really make sense - at least be more specific about what you mean by this
 - FourMomentum class must have constructor moved to private so that the user cannot access it directly.
 - Can user use FourMomentum? Make Lepton a friend class of FourMomentum and FourMomentum constructor private - only Lepton can construct FourMomentum object, and not user.
 - Print which object (particle name) the energy is infinite for
 - Make FourMomentum only accessible to lepton class (must declare lepton class in the same line)
 - Check 2dp for all outputs in info func
 - Control invalid inputs for DecayMode?
 - Cannot set precision of results because then everything afterwards is set to 2dp - confirm this

 - DIFFERENTIATE TAU & MUO
 - TIME IN DETECTOR - USE DISTANCE / VELOCITY INSTEAD
 - DITRIBUTION AWAY FROM MEAN LIFETIME TO USE AS ACTUAL LIFETIME?

 

## Resolved
 - Use generation getter inside constructor for neutrino! And make sure flavour works in the same way! GENERATION IS NOT PROPERTY (DATA MEMBER) OF NEUTRINO - IT IS DERVIVED FROM FLAVOUR
 - Change names of mass to rest mass and charge to relative charge?
 - Do something whith shared pointer to show performance usage (vectors of different particle detectors)
 - Add getters for decay status? NO - USER CAN GET THIS BY PARTICLE.HAS_DECAYED(), AND SINCE THIS CAN BE A DERIVED CALCULATION IT SHOULD NOT BE A PROPERTY And


## References
 [1] https://www.geeksforgeeks.org/cpp/pure-virtual-functions-and-abstract-classes/

 [2] https://en.cppreference.com/w/cpp/language/rule_of_three.html

 [3] https://www.geeksforgeeks.org/cpp/understanding-constexper-specifier-in-cpp/

 [4] https://www.geeksforgeeks.org/cpp/sqrt-sqrtl-sqrtf-cpp/

 [5] https://www.geeksforgeeks.org/cpp/enum-classes-in-c-and-their-advantage-over-enum-datatype/

 [6] https://www.geeksforgeeks.org/cpp/range-based-loop-c/

 [7] https://en.wikipedia.org/wiki/Particle_decay

 [8] https://physics.stackexchange.com/questions/282245/muon-decay-mode

 [9] https://en.wikipedia.org/wiki/Muon

 [10] https://en.wikipedia.org/wiki/Tau_(particle)

 [11] https://tikz.net/sm_decay_matrix/

 [12] https://www.geeksforgeeks.org/cpp/stduniform_real_-distribution-class-in-c-with-examples/

 [13] https://www.w3schools.com/cpp/cpp_switch.asp


 - Changed Particle class name to Lepton
 - Removed checks for particle name & particle name property of Lepton class