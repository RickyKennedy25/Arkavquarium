#ifndef COIN_HPP
#define COIN_HPP

#include "Position.hpp"

class Coin {
    private:
        static const int MAX_VELOCITY=4;
        
        Position* position;
        int value;
    public:
        /**
         * Construct Coin at random position and random value
         */
        Coin();
        
        /**
         * Construct Coin at position
         * @param {int} value of coin
         * @param {Position} initial position
         */
        Coin(int value, Position position);
    
        /**
         * Decrease y-position by velocity less than maxVelocity
         */
        void move(int maxHeight);
        
        /**
         * @return {Position*} Coin position
         */
        Position* getPosition() const;

        /**
         * @return {int} Coin value
         */
        int getValue() const;
};


#endif