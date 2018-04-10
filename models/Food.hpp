#ifndef FODD_HPP
#define FODD_HPP


#include "Position.hpp"

class Food {
    private:
      const static std::string assetPath;
      /**
         * Max velocity of the food movement
         */
      const int MAX_VELOCITY = 20;

      /**
         * Position of the food
         */
      Position *position;
        
    public:
        /**
         * Construct Food at destined position
         * @param {double} absis of food
         * @param {double} ordinate of food
         */
        Food(double x, double y);
        
        /**
         * Construct Food at x,0
         * @param {int} absis position
         */
        Food(int x);
        
        /**
         * Move Food to bottom
         * @param {int} minimum height
         * @param {double} elapsed seconds
         */
        void move(int y, double elapsedSeconds);
        
        /**
         * @return {Position} Food Position 
         **/
        Position* getPosition();

        /**
         * @return {std::string} asset path
         */
        static std::string getAssetPath();
};

#endif