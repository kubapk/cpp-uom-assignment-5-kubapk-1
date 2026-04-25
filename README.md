### Kuba Kane
# PHYS30762 Assignment 5 - Practising inheritance, smart pointers and friendship

> [!IMPORTANT]
> The final version of this assignment is on the version_1 branch (the default branch).

## Program Summary
This program uses classes to represent different leptons and functions or properties unique to them. All classes, bar the **FourMomentum** class, are derived from the **Lepton** class, and contain mass, charge, as well as a unique pointer to a four momentum object. The classes used in this program are summarised below.

- **FourMomentum:** Contains energy (E), x momentum (px), y momentum (py), z momentum (pz) and rest mass (m). Its default and parameterised constructors are private, and if a user wishes to create a FourMomentum object, this can be done via one of two static functions. The first accepts energy and the 3-momentum components as an input, calculating rest mass via the equation for invariant mass. The second accepts mass and the 3-momentum components as an input, calculating energy via the same equation. Static validation functions are also present to ensure sensible values are entered for all of the data members.

- **Lepton:** Abstract base class which contains rest mass, relative charge, a unique pointer to a **FourMomentum** object, and a bool which if true signifies an antilepton (flips the charge). The class contains a `base_info()` function which prints out the mass, charge, and four momentum. The constructor takes in inputs for px, py, pz, and using m computes E and thus the four momentum object. The default constructor sets all of these to 0. `info()` and `has_decayed` are pure virtual functions which print out additional info (in derived classes) and a bool which if true signifies the lepton has decayed.

- **Electron:** Class derived from **Lepton** which sets the rest mass and relative charge as constants. This class includes a function to use these details to find the shower depth of the electron in tungsten, as well as determine if a tungsten detector can contain the shower via the `detector_length` data member. The class overrides the `info()` function with its properties and the shower contained status.

- **Muon:** Class derived from **Lepton** which sets the rest mass, mean lifetime, and relative charge as constants. This class adds a `time_in_detector` function which, if greater than the mean lifetime, sets `has_decayed` to be true.

- **Tau:** Class derived from **Lepton** which behaves exactly like the **Muon** class, but includes an additional data member which sets the decay mode (channel). This is done via a nested enumator class, which sets 3 possibilities (Hadronic, Electron, Muon) corresponding to its possible decays. The private member function `generate_decay_mode()` use a Monte Carlo simulation to output one of the decay modes according to their probabilities of occuring. The getter `get_decay_mode()` uses a switch to output the decay products - used in the `info()` function.

- **Neutrino:** Class derived from **Lepton** which sets the rest mass and relative charge as constants, and includes a nested enumerator class **NeutrinoFlavour** to set the possible flavours of the neutrino (via `flavour` data member of **Neutrino** class). A switch is used to return the flavour via the flavour getter and the `info()` function. A switch is also used to output the generation of the flavour.

The **Lepton** base class contains a friend function to sum 2 **FourMomentum** objects, and also obtain their dot product. The main function shows this behaviour, as well as storing vectors of mixed leptons, moving a pointer to an electron, and using a shared pointer for a tau.

## User Guidelines
### Running the program as-is
This code was run on VSC using a Windows 11 device. The compilation line used was `g++ -std=c++17 main.cpp Neutrino.cpp Tau.cpp Muon.cpp Electron.cpp Lepton.cpp FourMomentum.cpp -o main.exe -Wall`. The program can then be run by calling the file `main.exe`.


### Modifying the main file, `main.cpp`


## Additional Information
For more information on this program, including how it works and design choices, please see `Assignment 5 Report.pdf`.

For an enlarged version of the UML diagram, please see `assignment_5_uml.pdf`, or visit the link https://lucid.app/lucidchart/1bbac6b7-964d-4fed-86ef-e02a48e03f28/view.