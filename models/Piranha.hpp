#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "Fish.hpp"

class Piranha : public Fish {
private:
        const static std::string assetPath;
        /**
         * Piranha has just eat a guppy 
         */
        bool isJustEatGuppy;

public:
        /**
         * Construct Piranha with isJustEatGuppy as False
         */
        Piranha(int maxWidth, int maxHeight);

        /**
         * Set isJustEatGuppy to false
         * @return {bool} isJustEatGuppy before edited
         */
        bool isProduceCoin();

        /**
         * Set isJustEatGuppy to True
         */
        void eatGuppy();

        /**
         * @return {std::string} asset path
         */
        std::string getAssetPath();

};

#endif