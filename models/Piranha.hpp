#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "Fish.hpp"

class Piranha : public Fish {
    private:
        /**
         * Piranha has just eat a guppy 
         */
        bool isJustEatGuppy;

    public:
        /**
         * Construct Piranha with isJustEatGuppy as False
         */
        Piranha();
        
        /**
         * Set isJustEatGuppy to false
         * @return {bool} isJustEatGuppy before edited
         */
        bool isProduceCoin();
        
        /**
         * Set isJustEatGuppy to True
         */
        void eatGuppy();
};

#endif