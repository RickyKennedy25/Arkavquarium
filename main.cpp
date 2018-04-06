#include "controllers/AquariumController.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <chrono>

using namespace std::chrono;

high_resolution_clock::time_point start = high_resolution_clock::now();

double time_since_start()
{
    high_resolution_clock::time_point now = high_resolution_clock::now();
        return duration_cast<duration<double>>(now - start).count();
}

int main( int argc, char* args[] )
{
    AquariumController *aquarium = new AquariumController(600, 800);

    bool running = true;
    double prevtime = time_since_start();

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        running = aquarium->main(sec_since_last);
    }

    delete aquarium;

    return 0;
}
