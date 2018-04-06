#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "Fish.hpp"

class Guppy : public Fish {
    private:
        /**
         * Period time for Guppy producing coin
         * @todo set constant
         */
       const int PRODUCE_COIN_PERIOD =5;
        /**
         * Timer for producing coin
         * Updated every update method is called
         */
       int produceCoinTimer;
    public:
        /**
         * Construct Guppy
         * Set produceCoinTimer to 0
         */
        Guppy();
        
        /**
         * Modulo produceCoinTimer with PRODUCE_COIN_PERIOD
         * @return {bool} PRODUCE_COIN_PERIOD == produceCoinTimer before edited
         */
        bool isProduceCoin();
        
        /**
         * Increment produceCoinTimer
         * If isStarving, move Guppy to nearest food
         * If position is equal destination, random new destination
         * Otherwise move to destination
         */
        void update();
};

#endif