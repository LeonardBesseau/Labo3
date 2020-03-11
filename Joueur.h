//
// Created by leonard n 3/6/20.
//

#ifndef LABO3_JOUEUR_H
#define LABO3_JOUEUR_H

#include <vector>
#include "Carte.h"
#include <string>
#include <iostream>


class Joueur {
    friend std::ostream &operator<<(std::ostream &lhs, const Joueur &rhs);

public:
    /**
     * Construct a player
     * @param name a string with the name of the player
     * @param cartes a vector of Carte the deck of the player
     */
    Joueur(const std::string &name, const std::vector<Carte> &cartes);

    /**
     * Check if a family is completed and if it is, put the family on the table
     * @param cardsPerFamily an unsigned with the number of cards per family
     */
    void detecterFamille(unsigned cardsPerFamily);

    /**
     * Indicates if the player has no more card in its deck
     * @return true if deck is empty, false otherwise
     */
    bool mainVide() const;

    //   void demanderCarte(Joueur &joueur, const unsigned short &famille, unsigned short member);

    /**
     * Add a Carte to the player deck
     * @param carte the carte to add
     * @param cardsPerFamily the number of card per family
     */
    void ajoutCarte(Carte &carte, unsigned cardsPerFamily);

    /**
     * Add the carte on the table when a family is completed
     * @param index the starting position of the family
     * @param cardsPerFamily the number of cards per family
     * @attention assume the deck is sorted
     */
    void ajoutSurTable(unsigned index, unsigned cardsPerFamily);

    /**
     * Get the number of cards on the table
     * @return an unsigned with the number of cards
     */
    unsigned nbCarteStack();


    /**
     * Player game loop
     * @param target a player to ask a card to
     * @param cardsPerFamily the number of cards per family
     */
    void play(Joueur &target, unsigned cardsPerFamily);

    /**
     * Indicates if the demanded card is in the player game and can be exchanged
     * @param c the card to exchange
     * @return true if the card can be exchanged, false otherwise
     * @attention if the card can be exchanged, the card will be remove from the player deck
     */
    bool giveCard(const Carte &c);

    /**
     * Get the player name
     * @return a string with the player name
     */
    const std::string &getNomJoueur() const;


    //unsigned short compteCarte(){};

protected:
    /**
     * Chose which card to ask
     * @return a Carte, the one to ask from the other player
     */
    virtual Carte choseCard() const;

private:
    std::string nomJoueur;
    std::vector<Carte> cartesEnMains;
    std::vector<Carte> familleSurTable;
};


#endif //LABO3_JOUEUR_H
