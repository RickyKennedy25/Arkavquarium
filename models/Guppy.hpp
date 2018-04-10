#ifndef GUPPY_HPP
#define GUPPY_HPP

#include <iostream>
#include "Fish.hpp"

enum tGrowthStep { stepOne, stepTwo, stepThree };

class Guppy : public Fish {
    private:
        const static int MAX_VELOCITY;
        /**
         * Period time for Guppy producing coin
         */
        const static double PRODUCE_COIN_PERIOD;
        const static int COIN_VALUE_STEP_ONE;
        const static int COIN_VALUE_STEP_TWO;
        const static int COIN_VALUE_STEP_THREE;
        const static int PRICE;
        const static std::string assetPath;
        /**
         * Timer for producing coin
         * Updated every update method is called
         */
        double produceCoinTimer;
        tGrowthStep growthStep;
    public:
        /**
         * Construct Guppy
         * Set produceCoinTimer to 0
         */
        Guppy(int maxWidth, int maxHeight);
        
        /**
         * @return {tGrowthStep} this growthStep
         */
        tGrowthStep getGrowthStep() const;
        
        /**
         * @return {int} this growthStep in int
         */
        int getGrowthStepInt() const;
        
        /**
         * @param {tGrowthStep} new growthStep
         */
        void setGrowthStep(tGrowthStep growthStep);
        
        /**
         * Modulo produceCoinTimer with PRODUCE_COIN_PERIOD
         * @return {int} 0 if PRODUCE_COIN_PERIOD == produceCoinTimer before edited
         *               this growthStep value if not
         */
        int isProduceCoin();
        
        /**
         * Increment produceCoinTimer
         * If isStarving, move Guppy to nearest food
         * If position is equal destination, random new destination
         * Otherwise move to destination
         */
        void update();

        /**
         * Override parent eat(). After parent eat(),
         * if exceed minimum eatCounter, upgrade growthStep to next step
         */
        void eat();

        /**
         * @return {std::string} asset path
         */
        std::string getAssetPath();

        /**
         * @return {int} guppy price
         */
        static int getPrice();
};

#endif