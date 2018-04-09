#ifndef FODD_HPP
#define FODD_HPP


#include "Position.hpp"

class Food {
    private:
        /**
         * Max velocity of the food movement
         */
        const int MAX_VELOCITY=4;
        
        /**
         * Position of the food
         */
        Position* position;
        
    public:
        /**
         * Construct Food at random position and 0 ordinate
         */
        Food();
        
        /**
         * Construct Food at x,0
         * @param {int} absis position
         */
        Food(int x);
        
        /**
         * Move Food to dest
         * @param {Positon} destination
         */
        void move(Position* dest);
        
        /**
         * @return {Position} Food Position 
         **/
        Position* getPosition();

};

#endif