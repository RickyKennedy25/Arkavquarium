#include "Position.hpp"
#include <stdlib.h>
#include <math.h>
#include <algorithm>


#define minHeight 1
#define minWidth 1

using namespace std;

/**
 * Construct Position with x and y
 * @param {double} absis of Position
 * @param {double} ordinate of Position
 */
Position::Position(double x, double y , bool random) {
    srand(0);
    this->x = x;
    this->y = y;
    if(random){
        int maxWidth = (int)x;
        int maxHeight = (int)y;
        this->x = (rand() + minWidth) % (maxWidth + 1);
        this->y = (rand() + minHeight) % (maxHeight + 1);
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
void Position::random(double x, double y) { // biar diganti ricky
    srand(0);
    this->x = (rand() + minWidth) % (800 + 1); //800 max_height
    this->y = (rand() + minHeight) % (600 + 1); //600 max_width
}

/**
 * Set x and y to nearest coordinate with dest
 * but no more than pythagorean distance maxVelocity
 */
void Position::move(Position dest, double maxVelocity) {
    double LenV;
    double Vx,Vy;
    double Dx,Dy;
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
    //
    double Dx;
    Dx = dest.getAbsis();
    if(Dx < this->x){
        this->x += max(maxVelocity,Dx);
    }else{
        this->x += min(maxVelocity,Dx);
    }
    
}

/**
 * Set y to nearest coordinate with dest
 * but no more than pythagorean distance maxVelocity
 */
void Position::moveVertical(Position dest,double maxVelocity) {
    double Dy;
    Dy = dest.getAbsis();
    if (Dy < this->y){
        this->y += max(maxVelocity, Dy);
    }
    else{
        this->y += min(maxVelocity, Dy);
    }
}