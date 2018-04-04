#ifndef POSITION_HPP
#define POSITION_HPP


class Position {
    private:
        /**
         * Absis of the Position
         */
        int x;
        
        /**
         * Ordinate of the Position
         */
        int y;
        
    public:
        /**
         * Construct Position with random x and y
         */
        Position();
        /**
         * Construct Position with x and y
         * @param {int} absis of Position
         * @param {int} ordinate of Position
         */
        Position(int x, int y);
        
        /**
         * @return {int} absis of the position
         */
        int getAbsis() const;

        /**
         * @return {int} ordinate of the position
         */
        int getOrdinate() const;
        
        /**
         * set ordinate of the position
         * @param {int} ordinate of Position
         */
        void setOrdinate(int) ;

        /**
         * set absis of the position
         * @param {int} absis of Position
         */
        void setAbsis (int) ;
        
        /**
         * Set x and y to random
         */
        void random();
        
        /**
         * Set x and y to nearest coordinate with dest
         * but no more than pythagorean distance maxVelocity
         */
        void move(Position dest, int maxVelocity);
        
        /**
         * Set x to nearest coordinate with dest
         * but no more than pythagorean distance maxVelocity
         */
        void moveHorizontal(Position dest, int maxVelocity);
        
        /**
         * Set y to nearest coordinate with dest
         * but no more than pythagorean distance maxVelocity
         */
        void moveVertical(Position dest,int maxVelocity);
};


#endif