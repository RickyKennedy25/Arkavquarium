#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "Fish.hpp"

class Piranha : public Fish {
private:
        const static int PRICE;
        const static int MAX_VELOCITY;
        const static std::string assetPath;
        /**
         * Piranha has just eat a guppy
         * 0 if false
         * x+1 if just eat guppy with growth step x
         */
        int isJustEatGuppy;

public:
        /**
         * Construct Piranha with isJustEatGuppy as False
         */
        Piranha(int maxWidth, int maxHeight);

        /**
         * Set isJustEatGuppy to 0
         * @return {int} isJustEatGuppy
         */
        int isProduceCoin();

        /**
         * Set isJustEatGuppy to True
         * @param {int} growth step of fish eaten
         */
        void eat(int x);

        /**
         * @return {std::string} asset path
         */
        std::string getAssetPath();

        static int getPrice();
};
#endif