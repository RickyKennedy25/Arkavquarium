#ifndef COIN_HPP
#define COIN_HPP

#include "Position.hpp"
#include "Drawable.hpp"

class Coin : public Drawable {
    private:
        static const int MAX_VELOCITY=40;
        const static std::string assetPathCoin;
        const static std::string assetPathRuby;

        int value;
    public:
        /**
         * Construct Coin at random position and random value
         */
        Coin(int maxWidth, int maxHeight);
        
        /**
         * Construct Coin at position
         * @param {int} value of coin
         * @param {Position} initial position
         */
        Coin(int value, Position position);
    
        /**
         * Decrease y-position by velocity less than maxVelocity
         */
        void move(int maxHeight, double elapsedSeconds);
        
        /**
         * @return {Position*} Coin position
         */
        Position* getPosition() const;

        /**
         * @return {int} Coin value
         */
        int getValue() const;

        /**
         * @return {std::string} asset path
         */
        std::string getAssetPath();
};


#endif