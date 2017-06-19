#include "Enigma.h"
#include <cstring>
#include <iostream>

using namespace mtm::escaperoom;

Enigma::Enigma(const std::string& name, const Difficulty& difficulty, const int& numOfElements)
{
    this->name = name;
    this->difficulty = difficulty;
    this->numOfElements = numOfElements;
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