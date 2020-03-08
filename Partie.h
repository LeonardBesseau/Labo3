//
// Created by leonard on 3/6/20.
//

#ifndef LABO3_PARTIE_H
#define LABO3_PARTIE_H

#include "Carte.h"
#include "Joueur.h"
#include <vector>
#include <array>

class Partie {
public:
    Partie(unsigned nbPlayer,unsigned  nbFamilly, unsigned cardsPerFamily, unsigned cardsPerPlayer );

    unsigned int getTurns() const;

    const std::vector<Carte> &getStack() const;

    const std::vector<Joueur> &getPlayerList() const;

    void displayStack();

private:
    unsigned turns;
    unsigned cardPerFamilly;
    std::vector<Carte> stack;
    std::vector<Joueur> player;
};


#endif //LABO3_PARTIE_H