#ifndef FODD_HPP
#define FODD_HPP


#include "Position.hpp"

class Food {
    private:
      const static std::string assetPath;
      /**
         * Max velocity of the food movement
         */
      const int MAX_VELOCITY = 4;

      /**
         * Position of the food
         */
      Position *position;
        
    public:
        /**
         * Construct Food at random position and 0 ordinate
         */
        Food(int maxWidth, int maxHeight);
        
        /**
         * Construct Food at x,0
         * @param {int} absis position
         */
        Food(int x);
        
        /**
         * Move Food to bottom
         * @param {double} elapsed seconds
         */
        void move(double elapsedSeconds);
        
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