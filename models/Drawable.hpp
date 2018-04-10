#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "Position.hpp"
#include <iostream>

class Drawable {
    protected:
        Position* position;
    public:
        Drawable() {};
        virtual Position* getPosition() const=0;
        virtual std::string getAssetPath()=0;
};

#endif