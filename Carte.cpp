//
// Created by leonard on 3/6/20.
//

#include "Carte.h"
#include <algorithm>


Carte::Carte(unsigned short familly, unsigned short member) : familly(familly), member(member) {}

unsigned short Carte::getFamilly() const {
    return familly;
}

unsigned short Carte::getMember() const {
    return member;
}

std::string Carte::toString() const {
    return std::to_string(familly) + getMemberName();
}

std::string Carte::getMemberName() const {
    std::string output;
    unsigned short number = member;
    do {
        char b = 'A' + number % 26;
        output += b;
        number /= 26;
    } while (number > 0);

    std::reverse(output.begin(), output.end());
    return output;
}

std::ostream &operator<<(std::ostream &lhs, const Carte &rhs) {
    return lhs << rhs.toString();
}