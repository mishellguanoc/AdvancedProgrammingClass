#include "class.h"
#include <string>
#include <iostream>

//Default constructor
Animal::Animal(){
    specieType = "Unknown";
    numberLegs = 0;
    isDomesticable = false;
}



//Custom constructor
Animal::Animal(std::string specieType, int numberLegs, bool isDomesticable){
    this->specieType = specieType;
    this->numberLegs = numberLegs;
    this->isDomesticable = isDomesticable;
}

//Destructor
Animal::~Animal(){
    std::cout << "Animal object destroyed. \n"; 
}

//Getters
std::string Animal::getSpecieType() const {
    return specieType;
}

int Animal::getNumberLegs() const {
    return numberLegs;
}

bool Animal::getIsDomesticable() const {
    return isDomesticable;
}
// Setter
void Animal::setSpecieType(std::string newSpecieType) {
    specieType = newSpecieType;
}

// Private function (not used, but here for completeness)
std::string Animal::determineCategory() const {
    return (isDomesticable) ? "Domestic" : "Wild";
}