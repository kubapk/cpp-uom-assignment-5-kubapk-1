### Kuba Kane
# PHYS30762 Assignment 5 - Practising inheritance, smart pointers and friendship

> [!IMPORTANT]
> ### The final version of this assignment is on the version_1 branch (the default branch).

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
These guidelines are for a user who wishes to use the classes in this program, but modify the main file provided (or make their own). First note that if a derived class is included in the cpp file, it is not necessary to include the **Lepton** base class. A lepton particle cannot be constructed, since its abstract, but all objects derived from the **Lepton** class can be constructed using the default or parameterised constructors. Note that not all derived classes' constructors contain the same number of inputs, and so the class header files should be checked first to ensure the correct number and type of parameters are entered into a constructor. If a default constructor is used, the lepton is assumed not to be an antiparticle, and have its properties all set to 0. To set a lepton to be an antilepton, the parameterised constructor must be used, where the final parameter is set to be `true`.

All derived classes have the `info()` function which prints out their properties, including those inherented from the **Lepton** base class. These properties can also be printed indivudally using setters, which are defined for all properties within each derived class (inherented from **Lepton** or otherwise). The individual components of the **FourMomentum** object contained within all the lepton classes can be printed by first getting the **FourMomentum** object, and then getting the desired component, e.g. to get the x momentum of an electron use `electron_test.get_four_momentum().get_px()`. E, px, py, pz and m are all obtainable via this method.

Setters for derived lepton objects are more restrictive. There are no setters for rest mass or relative charge, as these are fixed properties of a specific lepton (e.g. a muon or an electron). The same applies for the mean lifetime for the **Muon** and **Tau** classes. The antiparticle status of a lepton is not possible to set via a setter, and must be set via a parameterised constructor (or default constructor if not an antiparticle) to ensure all properties of the lepton are updated correctly. The detector length in the **Electron** class, the time in detector in the **Muon** and **Tau** classes, as well as the flavour in the **Neutrino** class can be modified using setters. The decay mode in the **Tau** class cannot be modified via a setter, as it is determined probabilistically - a new **Tau** object set up via the constructor is the only way to change the decay model, although this is probabilistic and may not change.

**FourMomentum** components can also be modified by first getting the **FourMomentum** object and then using a setter via the **FourMomentum** class, e.g. `electron_test.get_four_momentum().set_px(100)`.

There are restrictions on E, px, py, pz, `time_in_detector`, and `detector_length`, details of which can be found in the report (see the Additional Information section). In particular, the restrictions on the **FourMomentum** object allows its objects to be created while still obeying the equation for invariant mass. The user has 2 choices of creating a **FourMomentum** object - either using its energy and not its mass, or the other way round. In the former invariant mass is a calculated quantity, and in the latter energy is a calculated quantity. The user should exercise caution to ensure the correct function from **FourMomentum** is used to construct an object, although this does offer protection if there was a desire to create a new base class, e.g. quarks, which used a **FourMomentum** object.

In the case of summing four momenta, a new **FourMomentum** object needs to be set up, and this requires setting the rest mass to be calculated from their combined energy and 3-momentum components. 

If creating your own main file from scratch, ensure to indent all code inside `try` and return an error message in `catch`, to ensure any errors are picked up by the compiler.


## Additional Information
For more information on this program, including how it works and design choices, please see `Assignment 5 Report.pdf`.

For an enlarged version of the UML diagram, please see `assignment_5_uml.pdf`, or visit the link https://lucid.app/lucidchart/1bbac6b7-964d-4fed-86ef-e02a48e03f28/view.