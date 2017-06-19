#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <string>
#include <set>

using std::set;
using std::string;

namespace mtm{
namespace escaperoom{


    typedef enum{
        EASY_ENIGMA , MEDIUM_ENIGMA , HARD_ENIGMA
    } Difficulty;

    class Enigma{
    public:

        // Constructs a new Enigma with the specified data.
        //
        // @param name : the name of the enigma.
        // @param difficulty : the difficulty of the enigma.
        // @param numOfElements : the number of elements in the enigma.
        Enigma(const std::string& name, const Difficulty& difficulty, const int& numOfElements);


        //copy constructor
        //
        //@param enigma : the enigma to be copied.
        Enigma(const Enigma& enigma) = default;

        //assignment operator
        //
        //@param enigma : the enigma to be assigned.
        Enigma& operator=(const Enigma& enigma) = default;

        // Comparison operators for Enigmas. enigmas are compared as described in
        // the exercise sheet.
        //
        // @param enigma : the right-hand side operand.
        bool operator==(const Enigma& enigma) const;
        bool operator!=(const Enigma& enigma) const;
        bool operator<(const Enigma& enigma) const;
        bool operator>(const Enigma& enigma) const;

        bool operator<=(const Enigma& enigma) const = delete;
        bool operator>=(const Enigma& enigma) const = delete;

        // method returns true if both enigmas are equaly complex.
        //definition of equaly complex is described in the exercise sheet.
        //
        //@param enigma : the enigma being compared to.
        bool areEqualyComplex(const Enigma& enigma) const;

        // return the difficulty level of the enigma.
        //
        Difficulty getDifficulty() const;

        // Prints the data of the Enigma in the following format:
        //
        //     "<name> (<Difficulty>) <number of items>"
        //
        // @param output : the output stream to which the data is printed.
        // @param enigma : the enigma whose data is printed.
        friend std::ostream& operator<<(std::ostream& output, const Enigma& enigma);

        ~Enigma() = default;

        //Function returns the name of the enigma.
        //
        string getName() const;


    };

    std::ostream& operator<<(std::ostream& output, const Enigma& enigma);
} // end of namespace eascaperoom
} // end of namespace mtm



#endif //ENIGMA_H
