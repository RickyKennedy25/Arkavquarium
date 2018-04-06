#include "AquariumController.hpp"

/**
 * Construct with some guppies, one piranha and one snail 
 * with random position
 * @param {int} height of aquarium
 * @param {int} width of aquarium
 */
AquariumController::AquariumController(int height, int width) {

    Guppy* guppy1 = new Guppy();
    Data::getGuppies()->add(guppy1);

    Guppy* guppy2 = new Guppy();
    Data::getGuppies()->add(guppy2);

    Piranha* piranha = new Piranha();
    Data::getPiranhas()->add(piranha);

    this->height = height;
    this->width = width;

    this->tank = new Tank(this->width, this->height);
    this->tank->init();
}

/**
 * Destruct with Delete all LinkedList
 */
AquariumController::~AquariumController() {
    this->tank->close();
}

/**
 * @return {int} width of Aquarium
 */
int AquariumController::getWidth() const {
    return this->width;
}

/**
 * @return {int} height of Aquarium
 */
int AquariumController::getHeight() const {
    return this->height;
}
    
/**
 * Move Guppies, Piranhas, Foods, Coins, and Snail
 * Create new Guppy randomly
 * @param {double} seconds elapsed since this method called last time
 * @return {bool} is the program will be still running
 */
bool AquariumController::main(double elapsedSeconds) {
    bool stillRunning = true;
    
    this->tank->handle_input();
    if (this->tank->quit_pressed()) {
        return false;
    }

    /* handler for pressed keys
    for (auto key : this->tank->get_pressed_keys()) {
        
        switch (key) {
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
        }
    }*/

    for (auto key : this->tank->get_tapped_keys()) {
        switch (key) {
            // x for quit
            case SDLK_x:
                stillRunning = false;
                break;
        }
    }
    if (!stillRunning) return false;

    this->draw();

    return true;
}

/**
 * For every Food find Foods with minimum distance to Guppy
 * @param {Guppy*} Guppy to find nearest Food
 * @return {Food*} Food with minimum distance to Guppy
 */
Food* AquariumController::findNearestFood(Guppy* guppy) {
    return NULL;
}

/**
 * For every Coin find Coin with minimum distance to Snail
 * @param {Snail*} Snail to find nearest coin
 * @return {Coin*} Coin with minimum distance to snail
 */
Coin* AquariumController::findNearestCoin(Snail* snail) {
    return NULL;
}

/**
 * For every Guppy find Guppy with minimum distance to Piranha
 * @param {Piranha*} Piranha to find nearest Guppy
 * @return {Guppy*} Guppy with minimum distance to Piranha
 */
Guppy* AquariumController::findNearestGuppy(Piranha* piranha) {
    return NULL;
}

/**
 * Create new Coin if the fish will produce coin
 * @param {Fish} a fish to produce Coin
 *
void AquariumController::produceCoin(Fish fish) {
    //
}*/

/**
 * For every fish, move fish to nearest food if hungry, or to dest
 * For every coin, move coin to ground
 * For every food, move food to food
 * Move snail to nearest coin
 */
void AquariumController::moveObjects() {
    //
}

/**
 * Draw all entity
 */
void AquariumController::draw() {
    this->tank->clear_screen();
    //this->tank->draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
    this->tank->draw_image("assets/img/Tanks.jpg",this->width/2,this->height/2);

    LinkedListItem<Guppy*>* guppyIt;
    guppyIt = Data::getGuppies()->getFirstItem();
    while (guppyIt != NULL) {
        std::cout << guppyIt->getContent()->getPosition()->getAbsis() << std::endl;/*
        this->tank->draw_image(
            Guppy::getAssetPath(),
            guppyIt->getContent()->getPosition()->getAbsis(),
            guppyIt->getContent()->getPosition()->getOrdinate()
        );*/
        guppyIt = guppyIt->getNext();
    }

    this->tank->update_screen();
}