# Assignment 8 - Inheritance

## Description

This program uses a base class `Field` that holds three components in a dynamically allocated `double *value`. The classes `Electric_Field` and `Magnetic_Field` inherit from it.
- `Field` has a default constructor (sets components to 0), a constructor that takes x, y, z, a copy constructor, and `printMagnitude()` to print the components.
- `Electric_Field` calculates the electric field of a spherical charge using Gauss' law, E = Q / (4 pi r^2 eps0).
- `Magnetic_Field` calculates the magnetic field of a current-carrying wire using Ampere's law, B = mu0 I / (2 pi r).
- Both derived classes overload `+` to add two fields and `<<` to print the components.
## Files

- `assignment8.cpp` - all of the classes and `main()`
## How to compile and run

```
g++ -o assignment8 assignment8.cpp
./assignment8
```
## Sample output

```
Electric field components:
x = 0, y = 100000, z = 1000
Magnetic field components:
x = 2e-05, y = 0, z = 3e-05

Electric field from Gauss' law (Q = 1e-6 C, r = 0.5 m): 35951 N/C
Magnetic field from Ampere's law (I = 10 A, r = 0.05 m): 4e-05 T

e2 = (1, 2, 3)
e3 = (4, 5, 6)
e2 + e3 = (5, 7, 9)

b2 = (1e-05, 2e-05, 3e-05)
b3 = (4e-05, 5e-05, 6e-05)
b2 + b3 = (5e-05, 7e-05, 9e-05)
```
