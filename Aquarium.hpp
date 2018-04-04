#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "Fish.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "Snail.hpp"
#include "Food.hpp"
#include "Coin.hpp"
#include "Linklist.hpp"

class Aquarium {
     private:
         LinkedList<Guppy> guppies;
         LinkedList<Piranha> piranhas;
         LinkedList<Food> foods;
         LinkedList<Coin> coins;
         Snail snail;
         int width;
         int height;
         
    public:
        /**
         * Construct with some guppies, one piranha and one snail 
         * with random position
         * height of aquarium is equal 600
         * width of aquarium is equal 800
         */
        Aquarium();
        
        /**
         * Construct with some guppies, one piranha and one snail 
         * with random position
         * @param {int} height of aquarium
         * @param {int} width of aquarium
         */
        Aquarium(int height, int width);
        
        /**
         * Destruct with Delete all LinkedList
         */
        ~Aquarium();
        
        /**
         * @return {int} width of Aquarium
         */
        int getWidth() const;
        
        /**
         * @return {int} height of Aquarium
         */
        int getHeight() const;
         
        /**
         * Move Guppies, Piranhas, Foods, Coins, and Snail
         * Create new Guppy randomly
         */
        void main();
        
        /**
         * For every Food find Foods with minimum distance to Guppy
         * @param {Guppy} Guppy to find nearest Food
         * @return {Food} Food with minimum distance to Guppy
         */
        Food findNearestFood(Guppy guppy);
        
        /**
         * For every Coin find Coin with minimum distance to Snail
         * @param {Snail} Snail to find nearest coin
         * @return {Coin} Coin with minimum distance to snail
         */
        Coin findNearestCoin(Snail snail);
        
        /**
         * For every Guppy find Guppy with minimum distance to Piranha
         * @param {Piranha} Piranha to find nearest Guppy
         * @return {Guppy} Guppy with minimum distance to Piranha
         */
        Guppy findNearestGuppy(Piranha piranha);

        /**
         * Create new Coin if the fish will produce coin
         * @param {Fish} a fish to produce Coin
         */
        void produceCoin(Fish fish);
        
        /**
         * For every fish, move fish to nearest food if hungry, or to dest
         * For every coin, move coin to ground
         * For every food, move food to food
         * Move snail to nearest coin
         */
        void moveObjects();

        /**
         * Draw all entity to an interface
         */
        void draw();
        
};



#endif