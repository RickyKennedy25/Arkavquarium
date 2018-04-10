#ifndef FISH_HPP
#define FISH_HPP

#include "Position.hpp"
#include "Orientation.hpp"
#include "Drawable.hpp"

enum tStatus { starving, idle };

class Fish : public Drawable {
    protected:
        /**
         * Time from Fish eat until starving
         * @todo set constant
         */
        static const int REPLETE_TIME = 12;
        /**
         * Time from Fish starving until die
         * @todo set constant
         */
        static const int STARVATION_TIME = 24;
        static const int FIRST_GROWTH_EAT_COUNTER = 7;
        static const int SECOND_GROWTH_EAT_COUNTER = 15;

        tStatus status;
        double maxVelocity;
        /**
         * Destination of Fish when Fish is idle
         */
        Position* destination;
        tOrientation orientation;
        double starvingTimer;
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
        Fish(int maxWidth, int maxHeight);
        
        /**
         * Getter  
         */
        tStatus getStatus() const;
        Position* getPosition() const;
        Position* getDestination() const;
        double getStarvingTimer() const;
        tOrientation getOrientation() const;
        int getEatCounter() const;

        /**
         * Setter
         */
        void setStatus(tStatus status);
        void setPosition(Position* position);
        void setDestination(Position* position);
        void setStarvingTimer(double starvingTimer);
        void setOrientation(tOrientation orientation);
              
        virtual int isProduceCoin()=0;
        
        /**
         * @return {bool} REPLETE TIME <= starvingTimer <= STARVING TIME 
         */
        bool isStarving();

        /**
         * @return {bool} starvingTimer > STARVING TIME
         */
        bool isDie();
        
        /**
         * Increment eatCounter
         */
        void eat();
        
        /**
         * Move Fish to the dest
         * @param {Position} is the nearest Food for Guppy
         *   or nearest Guppy for Piranha
         */
        void moveToDestination(Position* position, double elapsedSeconds);
        
        /**
         * Move Fish to their default destination
         * If Fish Position equal to default destination
         * random new destination 
         */
        void moveToDestination(int maxWidth, int maxHeight, double elapsedSeconds);

        /**
         * @return {int} price of this kind of fish
         */
        static int getPrice();
};

#endif
