#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "Position.hpp"
#include "Orientation.hpp"
#include "Drawable.hpp"

class Snail : public Drawable {
    private:
      const static std::string assetPath;
      const int MAX_VELOCITY = 40;
      tOrientation orientation;
        
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
        void moveToDestination(Position* position, double elapsedSeconds);

        /**
         * @return {std::string} asset path
         */
        std::string getAssetPath();
};

#endif