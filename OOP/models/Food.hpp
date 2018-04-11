#ifndef FODD_HPP
#define FODD_HPP

#include "Position.hpp"
#include "Drawable.hpp"

class Food : public Drawable {
    private:
        const static std::string assetPath;
        const static int PRICE = 10; 
        /**
         * Max velocity of the food movement
         */
        const int MAX_VELOCITY = 30;      
    public:
        /**
         * Construct Food at destined position
         * @param {double} absis of food
         * @param {double} ordinate of food
         */
        Food(double x, double y);
        
        /**
         * Move Food to bottom
         * @param {int} minimum height
         * @param {double} elapsed seconds
         */
        void move(int y, double elapsedSeconds);
        
        /**
         * @return {Position} Food Position 
         **/
        Position* getPosition() const;

        /**
         * @return {std::string} asset path
         */
        std::string getAssetPath();

        /**
         * @return {int} food price
         */
        static int getPrice();
};

#endif