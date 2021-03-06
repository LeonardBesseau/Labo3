/*
 -----------------------------------------------------------------------------------
 Laboratoire : 03
 Fichier     : main.cpp
 Auteur(s)   : Léonard Besseau, Alexandra Cerottini, Nicolas Viotti
 Date        : 24.02.2020

 But         : Construire un système pouvant jouer au jeu des 7 familles

 Remarque(s) :

 Compilateur : gcc version 7.4.0
 -----------------------------------------------------------------------------------
*/

#include <iostream>
#include "Partie.h"

int main() {
    const int nbPlays = 100;
    const unsigned nbFamily = 9;
    const unsigned nbCardsPerFamily = 4;
    const unsigned nbCardsPerPlayer = 5;
    std::cout << "Debut de la partie de 7 familles" << std::endl;
    std::vector<std::string> name{"Alice", "Bobby", "Carol", "Danny"};
    MeilleurJoueur p1(name.at(0));
    Joueur p2(name.at(1));
    Joueur p3(name.at(2));
    Joueur p4(name.at(3));
    std::vector<Joueur *> list{&p1, &p2, &p3, &p4};


    for (int i = 0; i < nbPlays; ++i) {
        Partie a(list, nbFamily, nbCardsPerFamily, nbCardsPerPlayer);
        a.play(i);
    }
    std::cout << std::endl;
    std::cout << "Pourcentage de victoire apres " << nbPlays << " parties:" << std::endl;
    for (int k = 0; k < name.size(); ++k) {
        std::cout << name.at(k) << " : " << (double) list.at(k)->getScore() / nbFamily << "%" << std::endl;
    }
    return 0;
}
