#include "Position.hpp"

using namespace std;

/**
 * Construct Position with x and y
 * @param {double} absis of Position
 * @param {double} ordinate of Position
 */
Position::Position(double x, double y , bool _random) {
    if (_random) {
        this->random(x, y);
    } else {
        this->x = x;
        this->y = y;
    }
}


/**
 * @return {double} absis of the position
 */
double Position::getAbsis() const {
    return this->x;
}

/**
 * @return {double} ordinate of the position
 */
double Position::getOrdinate() const {
    return this->y;
}

/**
 * set absis of the position
 * @param {double} absis of Position
 */
void Position::setAbsis(double x) {
    this->x = x;
}

/**
 * set ordinate of the position
 * @param {double} ordinate of Position
 */
void Position::setOrdinate(double y) {
    this->y = y;
}

/**
 * Set x and y to random
 */
void Position::random(int maxWidth, int maxHeight) {
    time_t timer;
    this->delayOneSecond(1);
    time(&timer);
    // cout << timer << endl;
    // cout << "timer adalah " << timer << endl;
    srand(timer);
    int pad = maxWidth * 15 / 100;
    this->x = (rand() % (maxWidth - 2 * pad)) + pad;
    this->y = rand() % maxHeight;
}
    /**
 * Set x and y to nearest coordinate with dest
 * but no more than pythagorean distance maxVelocity
 */
    void Position::move(Position dest, double maxVelocity)
    {
        double LenV;
        double Vx, Vy;
        double Dx, Dy;
        Vx = dest.getAbsis() - this->getAbsis();
        Vy = dest.getOrdinate() - this->getOrdinate();
        LenV = sqrt(pow(Vx, 2) + pow(Vy, 2));
        Dx = (min(maxVelocity, LenV) / LenV) * Vx;
        Dy = (min(maxVelocity, LenV) / LenV) * Vy;
        this->x += Dx;
        this->y += Dy;
}

/**
 * Set x to nearest coordinate with dest
 * but no more than pythagorean distance maxVelocity
 */
void Position::moveHorizontal(Position dest, double maxVelocity) {
    double dx;
    dx = dest.getAbsis() - this->x;
    if (dx < 0) {
        this->x += max(-maxVelocity, dx);
    } else {
        this->x += min(maxVelocity, dx);
    }
    
}

/**
 * Set y to nearest coordinate with dest
 * but no more than pythagorean distance maxVelocity
 */
void Position::moveVertical(Position dest,double maxVelocity) {
    double dy;
    dy = dest.getOrdinate() - this->y;
    if (dy < 0) {
        this->y += max(-maxVelocity, dy);
    } else {
        this->y += min(maxVelocity, dy);
    }
}

/**
 * Compare this position with comp
 * @return {bool} is two position has same absis and ordinate
 */
bool Position::operator==(Position comp) {
    return this->x == comp.getAbsis() && this->y == comp.getOrdinate();
}

/**
 * Compare this position with comp
 * @return {bool} is two position has different absis or ordinate
 */
bool Position::operator!=(Position comp){
    return this->x != comp.getAbsis() || this->y != comp.getOrdinate();
}

void Position::delayOneSecond(int seconds)
{
    time_t time0; // create timers.
    time_t time1;

    time(&time0); // get current time.
    double s = 0;
    do
    {
        time(&time1);
        s = time1 - time0;
    } while (s < seconds);

}