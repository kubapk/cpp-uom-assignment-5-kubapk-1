### Kuba Kane
# PHYS30762 Assignment 5 - Practising inheritance, smart pointers and friendship

## User Guidelines
### Running the program as-is
This code was run on VSC using a Windows 11 device. The compilation line used was `g++ -std=c++17 test.cpp Neutrino.cpp Tau.cpp Muon.cpp Electron.cpp Lepton.cpp FourMomentum.cpp -o test.exe -Wall`. The program can then be run by calling the file `TBC`.

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

## Notes 
 - Pg7 PPT: sums two four-vectors = sums two four momenta that are hosted in a particle class
 - Check where all consts need to go 
 - Charge should be double or int? LEPTONS ALWAYS HAVE INT CHARGES - more specific requirements? But user never gets to change charge.
 - Potentially make get_mass and get_charge virtual funcs in Lepton class and override them in each derived class - bit more manual, code repeating
 - Change names of mass to rest mass and charge to relative charge?
 - Getters get_mass etc do not return unit while get_four_momentum does - but how to do units without printing in getters? Then cannot pass mass into something else.
 - Give number of decimal places to four momentum energy when calculated - see previous weeks
 - Allowed values for px, py, pz
 - Remove energy check as due to calculation from mass, the energy will always be positive?
 - Should bool be const? 
 - Include lepton name in Lepton class, so that it can be a property which you get and is later changed?
 - Tau can have unique property - decay 
 - Have it so properties are always defined and never just in print function?
 - E.g. tau takes in some input number which the user can decide, and this is returned or some calculation is returned as a property of that particle - BUT JUST DO SIMPLE ONES FIRST SO THAT YOU HAVE THE IDEA OF DERIVED CLASSES - THESE CAN BE MODIFIED LATER!
 - Has decayed as a data member of muon? That way is a specified property, and then can use getter to get that property - just ensure if time in detector is updated, so is has_decayed.
 - Maximum time for time_in_detector? They shouldn't be able to enter 100s of years
 - random decay times using exponential distributions
 - Has decayed as a virtual func in Lepton and returns false in Electron?
 - Time in detector doesn't make sense - cannot measure 10^-6 seconds of existence - see random decay times above
 - Random generator to generate a specific lifetime about mean lifetime - then this decay time becomes a property of the class
 - Add getters for decay status? And particle name?
 - Enum which raises error for else case (types of neutrinos)

 - IDEA: change it to be Lepton containing smart pointer to FourMomentum object with E, px, py, pz. Base class (Lepton) allows user to enter these - tbh don't need to define it since its abstract so user shouldn't need to construct it. Then add mass property to derived classes - and give then a new constructor which allows you to find E from inputting px, py, pz. What if user uses set_px? test_electron.momentum.set_px(10) -> should change E

 Solution: Remove setters from FourMomentum object - only allow everything to be set through Lepton class. Problem - lepton class doesn't have mass? So new setters & getters for all derived classes from Lepton?? Even if you just had a check which allowed E input and checked that together with px, py, pz it gave correct invariant mass, the user could later chang px and break this.

 Once that is done, you need to add mass and charge proeprties to derived classes, and think of adding more relating to interaction with particle detector. Once you have that idea clear, but not implemented, add antiparticle structure to classes. NOT TOO LONG ON THIS - THERE IS MUCH MORE BEYOND!

 ## References
 [1] https://www.geeksforgeeks.org/cpp/pure-virtual-functions-and-abstract-classes/

 [2] https://en.cppreference.com/w/cpp/language/rule_of_three.html

 [3] https://www.geeksforgeeks.org/cpp/understanding-constexper-specifier-in-cpp/

 [4] https://www.geeksforgeeks.org/cpp/sqrt-sqrtl-sqrtf-cpp/


- Changed Particle class name to Lepton
 - Removed checks for particle name & particle name property of Lepton class