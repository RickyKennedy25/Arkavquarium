#ifndef DATA_HPP
#define DATA_HPP

#include "Drawable.hpp"
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
		static int money;
		static int egg;
<<<<<<< HEAD
=======
		static int eggPrice;
>>>>>>> 326c31f0b5d2af490f031f552ca50b96d3b03030
    
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
<<<<<<< HEAD
		 * @return {int} money
		 */
		static int getMoney();

		/**
		 * @return {int} egg
		 */
		static int getEgg();

		/**
		 * @param {int} money
		 */
		static void setMoney(int money);

		/**
		 * @param {int} egg
		 */
=======
		* @return {int} money
		*/
		static int getMoney();

		/**
		* @return {int} egg
		*/
		static int getEgg();

		/**
		 * @return {int} eggPrice
		 */
		static int getEggPrice();

		/**
		* @param {int} money
		*/
		static void setMoney(int money);

		/**
		* @param {int} egg
		*/
>>>>>>> 326c31f0b5d2af490f031f552ca50b96d3b03030
		static void setEgg(int egg);

        /**
         * @param {Snail*} new snail
         */
        static void setSnail(Snail* snail);

        /**
         * Destruct all linked list and create new
         */
        static void clear();
		 

};

#endif
