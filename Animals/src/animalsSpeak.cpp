#include <iostream>
#include <vector>
#include "animalClasses.h"

int main()
{
    //declare a vector of animal pointers here
    std::vector<Animal*> animals;

    //put some different kinds of animal pointers (dogs, cats, budgies) in your vector
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Budgie());
    animals.push_back(new Labrador());
    animals.push_back(new Terrier());

    //loop through all the animals in your vector and call Speak() on them in turn
    for (Animal* animal : animals) {
        animal->speak();
    }

    // Clean up memory
    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}