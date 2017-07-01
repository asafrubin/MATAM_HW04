#include "Enigma.h"
#include "Exceptions.h"
#include <cstring>
#include <iostream>

using namespace mtm::escaperoom;

Enigma::Enigma(const std::string &name, const Difficulty &difficulty, const int &numOfElements)
        : name(name), difficulty(difficulty), numOfElements(numOfElements) {}


Enigma::Enigma(const std::string& name, const Difficulty& difficulty, const unsigned int& numOfElements, const set<string>& elements)
        : name(name), difficulty(difficulty), numOfElements(numOfElements)
{
    if(elements.size() != numOfElements){
        throw EnigmaIllegalSizeParamException();
    }
    this->elements = elements;
}

Enigma::Enigma(const std::string& name, const Difficulty& difficulty)
        : name(name), difficulty(difficulty), numOfElements(0) {}

void Enigma::addElement(const string& element)
{
    elements.insert(element);
}

void Enigma::removeElement(const string& element)
{
    auto result = elements.erase(element);
    //need to verify result
    if(result != 0){
        throw EnigmaNoElementsException();
    }
}

bool Enigma::operator==(const Enigma& enigma) const
{
    return (this->name == enigma.name && this->difficulty == enigma.difficulty);
}

bool Enigma::operator!=(const Enigma& enigma) const
{
    return !(*this == enigma);
}

bool Enigma::operator<(const Enigma& enigma) const
{
    return (this->difficulty < enigma.difficulty);
}

bool Enigma::operator>(const Enigma& enigma) const
{
    return (this->difficulty > enigma.difficulty);
}

bool Enigma::areEqualyComplex(const Enigma& enigma) const
{
    return (this->difficulty == enigma.difficulty && this->numOfElements == enigma.numOfElements);
}

Difficulty Enigma::getDifficulty() const
{
    return difficulty;
}

int Enigma::getNumOfElements() const
{
    return this->numOfElements;
}

std::ostream& operator<<(std::ostream& output, const Enigma& enigma)
{
    output << enigma.getName() << " (" << enigma.getDifficulty() << ") " << enigma.getNumOfElements();
    return output;
}

string Enigma::getName() const
{
    return name;
}