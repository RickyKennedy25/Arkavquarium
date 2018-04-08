#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "Position.hpp"

class Snail {
    private:
        const int MAX_VELOCITY = 5;
        Position* position;
        
    public:
        /**
         * Construct Snail with random position
         * @param {int} screen width
         * #param {int} screen height
         */
        Snail(int maxWidth, int maxHeight);
        
        /**
         * Returns the snail position
         */
        Position* getPosition() const;
        
        /**
         * Move position to dest not exceeding MAX_VELOCITY
         * @param {Position} destination
         */
        void moveToDestination(Position position);
        
};

#endif