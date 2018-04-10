#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "../views/Tank.hpp"
#include "../models/Fish.hpp"
#include "../models/Guppy.hpp"
#include "../models/Piranha.hpp"
#include "../models/Snail.hpp"
#include "../models/Food.hpp"
#include "../models/Coin.hpp"
#include "../models/LinkedList.hpp"
#include "../models/Data.hpp"

class AquariumController {
     private:
         Tank *tank;
         int width;
         int height;
         
    public:
        
        /**
         * Construct with some guppies, one piranha and one snail 
         * with random position
         * @param {int} height of aquarium
         * @param {int} width of aquarium
         */
        AquariumController(int width, int height);
        
        /**
         * Destruct with Delete all LinkedList
         */
        ~AquariumController();
        
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
         * @param {double} seconds elapsed since this method called last time
         * @return {bool} is the program will be still running
         */
        bool main(double elapsedSecods);
        
        /**
         * For every Food find Foods with minimum distance to Guppy
         * @param {Guppy*} Guppy to find nearest Food
         * @return {Food*} Food with minimum distance to Guppy
         */
        Food* findNearestFood(Guppy* guppy);
        
        /**
         * For every Coin find Coin with minimum distance to Snail
         * @param {Snail*} Snail to find nearest coin
         * @return {Coin*} Coin with minimum distance to snail
         */
        Coin* findNearestCoin(Snail* snail);
        
        /**
         * For every Guppy find Guppy with minimum distance to Piranha
         * @param {Piranha*} Piranha to find nearest Guppy
         * @return {Guppy*} Guppy with minimum distance to Piranha
         */
        Guppy* findNearestGuppy(Piranha* piranha);

        /**
         * Create new Coin if the fish will produce coin
         * @param {Fish} a fish to produce Coin
         *
        void produceCoin(Fish fish);*/
        
        /**
         * For every fish, move fish to nearest food if hungry, or to dest
         * For every coin, move coin to ground
         * For every food, move food to food
         * Move snail to nearest coin
         * @param {double} elapsed seconds
         */
        void moveObjects(double elapsedSecods);

        /**
         * Draw all entity
         */
        void draw();
        
};

#endif