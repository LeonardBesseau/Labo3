/* ---------------------------
Laboratoire : 02
Fichier : Carte.h
Auteur(s) : Besseau
Date : 06-03-2020

But :

Remarque(s) :

Compilateur : gcc version 7.4.0

--------------------------- */
#ifndef LABO3_CARTE_H
#define LABO3_CARTE_H

#include <string>
#include <iostream>

class Carte {
    friend std::ostream &operator<<(std::ostream &lhs, const Carte &rhs);

public:
    /**
     * Construct a Carte with a family and a member
     * @param familly an unsigned
     * @param member an unsigned
     * @attention no check for uniqueness are made there can be multiple card with the same family and member
     */
    Carte(unsigned short familly, unsigned short member);

    /**
     * Get the member attribute
     * @return an unsigned with the value of the familly
     */
    unsigned short getFamily() const;

    bool operator<(const Carte &rhs) const;

    bool operator>(const Carte &rhs) const;

    bool operator<=(const Carte &rhs) const;

    bool operator>=(const Carte &rhs) const;

    bool operator==(const Carte &rhs) const;

    bool operator!=(const Carte &rhs) const;

private:
    /**
     * Construct a string composed of alphabetical character from the member value
     * @return a string the member value in base 26
     */
    std::string getMemberName() const;

    unsigned short family;
    unsigned short member;
};


#endif //LABO3_CARTE_H
