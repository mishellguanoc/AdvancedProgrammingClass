
#ifndef CLASS_H
#define CLASS_H

#include <string>

class Animal {
    private:
        std::string specieType;
        int numberLegs;
        bool isDomesticable;

        /*Private function for internal use*/
        std::string determineCategory() const;
    public:
        //Default constructor
        Animal();

        //Custom constructor for Animal
        Animal(std::string specieType, int numberLegs, bool isDomesticable);

        //Destructor
        ~Animal();

        // method to get specieType, numberLegs, isDomesticable, respectively
        std::string getSpecieType() const; //getter
        int getNumberLegs() const; //getter
        bool getIsDomesticable() const; //getter

        void setSpecieType(std::string newSpecieType); //setter
    };

#endif