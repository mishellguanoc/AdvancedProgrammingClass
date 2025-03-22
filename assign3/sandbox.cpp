/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"
#include <string>
#include <iostream>

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!

// Creating an instance using the default constructor
Animal defaultAnimal;
std::cout << "Default Animal: " << defaultAnimal.getSpecieType() << ", " 
          << defaultAnimal.getNumberLegs() << " legs, Domesticable? " 
          << (defaultAnimal.getIsDomesticable() ? "Yes" : "No") << "\n";

// Creating an instance using the parameterized constructor
Animal lion("Lion", 4, false);
std::cout << "Created Animal: " << lion.getSpecieType() << ", " 
          << lion.getNumberLegs() << " legs, Domesticable? " 
          << (lion.getIsDomesticable() ? "Yes" : "No") << "\n";

// Testing the setter
lion.setSpecieType("Big Cat");
std::cout << "Updated Animal: " << lion.getSpecieType() << "\n";
}