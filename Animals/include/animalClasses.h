#pragma once

class Animal {
public:
    virtual void speak() = 0;  // pure virtual function
    virtual ~Animal() = default;  // virtual destructor
};

class Mammal : public Animal {
public:
    virtual void speak() = 0;  // still abstract
};

class Bird : public Animal {
public:
    virtual void speak() = 0;  // still abstract
};

class Dog : public Mammal {
public:
    void speak() override;
};

class Labrador : public Dog {};
class Terrier : public Dog {};

class Cat : public Mammal {
public:
    void speak() override;
};

class Budgie : public Bird {
public:
    void speak() override;
};
