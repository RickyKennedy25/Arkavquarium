#ifndef DATA_HPP
#define DATA_HPP

#include "Fish.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Snail.hpp"
#include "Food.hpp"
#include "Coin.hpp"
#include "LinkedList.hpp"

class Data {
    private:
        static LinkedList<Guppy*> *guppies;
        static LinkedList<Piranha*> *piranhas;
        static LinkedList<Food*> *foods;
        static LinkedList<Coin*> *coins;
        static Snail *snail;
    
    public:
        /**
         * Do nothing
         */
        Data();

        /**
         * @return {LinkedList<Guppy*>*} list of guppies
         */
        static LinkedList<Guppy*>* getGuppies();

        /**
         * @return {LinkedList<Piranha*>*} list of piranhas
         */
        static LinkedList<Piranha*>* getPiranhas();

        /**
         * @return {LinkedList<Food*>*} list of foods
         */
        static LinkedList<Food*>* getFoods();

        /**
         * @return {LinkedList<Coin*>*} list of coins
         */
        static LinkedList<Coin*>* getCoins();

        /**
         * @return {Snail*} snail
         */
        static Snail* getSnail();

        /**
         * Destruct all linked list and create new
         */
        static void clear();

};

#endif