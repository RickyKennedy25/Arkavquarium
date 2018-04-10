#include <iostream>
#include "Data.hpp"

LinkedList<Guppy*>* Data::guppies = new LinkedList<Guppy*>();
LinkedList<Piranha*>* Data::piranhas = new LinkedList<Piranha*>();
LinkedList<Food*>* Data::foods = new LinkedList<Food*>();
LinkedList<Coin*>* Data::coins = new LinkedList<Coin*>();
Snail* Data::snail = NULL;

/**
 * Do Nothing
 */
Data::Data() { }

/**
 * @return {LinkedList<Guppy*>*} list of guppies
 */
LinkedList<Guppy*>* Data::getGuppies() {
    return Data::guppies;
}

/**
 * @return {LinkedList<Piranha*>*} list of piranhas
 */
LinkedList<Piranha*>* Data::getPiranhas() {
    return Data::piranhas;
}

/**
 * @return {LinkedList<Food*>*} list of foods
 */
LinkedList<Food*>* Data::getFoods() {
    return Data::foods;
}

/**
 * @return {LinkedList<Coin*>*} list of coins
 */
LinkedList<Coin*>* Data::getCoins() {
    return Data::coins;
}

/**
 * @return {Snail*} snail
 */
Snail* Data::getSnail() {
    return Data::snail;
}
/**
 * @param {Snail*} new snail
 */
void Data::setSnail(Snail* snail) {
    delete Data::snail;
    Data::snail = snail;
}

/**
 * Destruct all linked list and create new
 */
void Data::clear() {
    delete Data::guppies;
    delete Data::piranhas;
    delete Data::foods;
    delete Data::coins;
    delete Data::snail;

    Data::guppies = new LinkedList<Guppy*>();
    Data::piranhas = new LinkedList<Piranha*>();
    Data::foods = new LinkedList<Food*>();
    Data::coins = new LinkedList<Coin*>();
    Data::snail = NULL;
}