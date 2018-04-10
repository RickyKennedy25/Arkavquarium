#ifndef GUPPY_HPP
#define GUPPY_HPP

#include <iostream>
#include "Fish.hpp"

class Guppy : public Fish {
    private:
        /**
         * Period time for Guppy producing coin
         */
        const static double PRODUCE_COIN_PERIOD;
        const static std::string assetPath;
        /**
         * Timer for producing coin
         * Updated every update method is called
         */
        double produceCoinTimer;
    public:
        /**
         * Construct Guppy
         * Set produceCoinTimer to 0
         */
        Guppy(int maxWidth, int maxHeight);
        
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

        /**
         * @return {std::string} asset path
         */
        std::string getAssetPath();
};

#endif