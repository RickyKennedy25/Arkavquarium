#ifndef FISH_HPP
#define FISH_HPP

#include "Position.hpp"

#define Orientation int
#define GrowthStep int
#define Status int

class Fish {
    protected:
        static const int STATUS_IDLE = 1;
        static const int STATUS_STARVING = 2;
        static const int GROWTH_STEP_ONE = 3;
        static const int GROWTH_STEP_TWO = 4;
        static const int GROWTH_STEP_THREE = 5;
        static const int ORIENTATION_LEFT = 6;
        static const int ORIENTATION_RIGHT = 7;
        static const int MAX_VELOCITY = 6;
        /**
         * Time from Fish eat until starving
         * @todo set constant
         */
        static const int REPLETE_TIME = 12;
        /**
         * Time from Fish starving until die
         * @todo set constant
         */
        static const int STARVATION_TIME = 17;
        static const int FIRST_GROWTH_EAT_COUNTER = 7;
        static const int SECOND_GROWTH_EAT_COUNTER = 15;

        int status;
        Position* position;
        /**
         * Destination of Fish when Fish is idle
         */
        Position* destination;
        GrowthStep growthStep;
        Orientation orientation;
        int starvingTimer;
        int eatCounter;
        
    public:
        /**
         * Construct Fish
         * Set status to STATUS_IDLE
         * Set position to random new position
         * Set destination to random new position
         * Set growthStep to GROWTH_STEP_ONE
         * Set starvingTimer to zero
         * Set orientation according to destination
         * Set eatCounter to zero
         */
        Fish();
        
        /**
         * Getter  
         */
        int getStatus() const;
        Position* getPosition() const;
        Position* getDestination() const;
        int getGrowthStep() const;
        int getStarvingTimer() const;
        int getOrientation() const;
        int getEatCounter() const;

        /**
         * Setter
         */
        void setStatus(Status status);
        void setPosition(Position* position);
        void setDestination(Position* position);
        void setGrowthStep(GrowthStep growthStep);
        void setStarvingTimer(int starvingTimer);
        void setOrientation(Orientation orientation);
              
        virtual bool isProduceCoin()=0;
        
        /**
         * @return {bool} REPLETE TIME <= starvingTimer <= STARVING TIME 
         */
        bool isStarving();
        
        /**
         * Increment eatCounter
         * If exceed minimum eatCounter, upgrade growthStep to next step
         */
        void eat();
        
        /**
         * Move Fish to the dest
         * @param {Position} is the nearest Food for Guppy
         *   or nearest Guppy for Piranha
         */
        void moveToDestination(Position* position);
        
        /**
         * Move Fish to their default destination
         * If Fish Position equal to default destination
         * random new destination 
         */
        void moveToDestination();
};

#endif