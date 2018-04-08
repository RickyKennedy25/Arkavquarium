#ifndef POSITION_HPP
#define POSITION_HPP

class Position
{
  private:
    /**
         * Absis of the Position
         */
    double x;

    /**
         * Ordinate of the Position
         */
    double y;

  public:
    /**
         * Construct Position with x and y
         * @param {double} absis of Position
         * @param {double} ordinate of Position
         */
    Position(double x, double y, bool random = false);

    /**
         * @return {double} absis of the position
         */
    double getAbsis() const;

    /**
         * @return {double} ordinate of the position
         */
    double getOrdinate() const;

    /**
         * set absis of the position
         * @param {double} absis of Position
         */
    void setAbsis(double x);

    /**
         * set ordinate of the position
         * @param {double} ordinate of Position
         */
    void setOrdinate(double y);

    /**
         * Set x and y to random
         */
    void random(int maxHeight, int maxWidth);

    /**
         * Set x and y to nearest coordinate with dest
         * but no more than pythagorean distance maxVelocity
         */
    void move(Position dest, double maxVelocity);

    /**
         * Set x to nearest coordinate with dest
         * but no more than pythagorean distance maxVelocity
         */
    void moveHorizontal(Position dest, double maxVelocity);

    /**
         * Set y to nearest coordinate with dest
         * but no more than pythagorean distance maxVelocity
         */
    void moveVertical(Position dest, double maxVelocity);

    /**
         * compare this position with comp
         * if equal return true
         * else return false 
         */
    bool operator==(Position comp);

    /**
         * compare this position with comp
         * if notequal return true
         * else return false 
         */
    bool operator!=(Position comp);

    void delayOneSecond(int seconds);
};

#endif