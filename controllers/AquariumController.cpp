#include "AquariumController.hpp"

/**
 * Construct with some guppies, one piranha and one snail 
 * with random position
 * @param {int} height of aquarium
 * @param {int} width of aquarium
 */
AquariumController::AquariumController(int width, int height) {

    this->height = height;
    this->width = width;
    
    Guppy* guppy1 = new Guppy(this->width, this->height);
    Data::getGuppies()->add(guppy1);

    Guppy* guppy2 = new Guppy(this->width, this->height);
    Data::getGuppies()->add(guppy2);

    Piranha* piranha = new Piranha(this->width, this->height);
    Data::getPiranhas()->add(piranha);

    Snail* snail = new Snail(this->width, this->height);
    Data::setSnail(snail);

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
    LinkedList<Food*> *liFood = Data::getFoods();
    
    if(!(liFood->isEmpty())){

        double minDistance,tempDistance;
        Food *nearestFood,*tempFood;
        
        LinkedListItem<Food*> *liItemFood = liFood->getFirstItem();
        nearestFood = liItemFood->getContent();
        minDistance = guppy->getPosition()->magnitude(*(nearestFood->getPosition()));
        
        while (liItemFood != liFood->getLastItem()){
        // while (liItemFood->getNext() != NULL){ 
            tempFood = liItemFood->getContent();
            tempDistance = guppy->getPosition()->magnitude(*(tempFood->getPosition()));
            if(tempDistance < minDistance){
                minDistance = tempDistance;
                nearestFood = tempFood;
            }
            liItemFood = liItemFood->getNext();
        }
        //handle last element
        tempFood = liItemFood->getContent();
        tempDistance = guppy->getPosition()->magnitude(*(tempFood->getPosition()));
        if(tempDistance < minDistance){
            minDistance = tempDistance;
            nearestFood = tempFood;
        }
        
        return nearestFood;
    } else {
        return NULL;
    }

    
}

/**
 * For every Coin find Coin with minimum distance to Snail
 * @param {Snail*} Snail to find nearest coin
 * @return {Coin*} Coin with minimum distance to snail
 */
Coin* AquariumController::findNearestCoin(Snail* snail) {
    LinkedList<Coin *> *liCoin = Data::getCoins();

    if(!(liCoin->isEmpty())){

        double minDistance, tempDistance;
        Coin *nearestCoin, *tempCoin;

        LinkedListItem<Coin *> *liItemCoin = liCoin->getFirstItem();
        nearestCoin = liItemCoin->getContent();
        minDistance = snail->getPosition()->magnitude(*(nearestCoin->getPosition()));

        while (liItemCoin != liCoin->getLastItem())
        {
            // while (liItemFood->getNext() != NULL){
            tempCoin = liItemCoin->getContent();
            tempDistance = snail->getPosition()->magnitude(*(tempCoin->getPosition()));
            if (tempDistance < minDistance)
            {
                minDistance = tempDistance;
                nearestCoin = tempCoin;
            }
            liItemCoin = liItemCoin->getNext();
        }
        //handle last element
        tempCoin = liItemCoin->getContent();
        tempDistance = snail->getPosition()->magnitude(*(tempCoin->getPosition()));
        if (tempDistance < minDistance)
        {
            minDistance = tempDistance;
            nearestCoin = tempCoin;
        }

        return nearestCoin;
    } else {
        return NULL;
    }
}

/**
 * For every Guppy find Guppy with minimum distance to Piranha
 * @param {Piranha*} Piranha to find nearest Guppy
 * @return {Guppy*} Guppy with minimum distance to Piranha
 */
Guppy* AquariumController::findNearestGuppy(Piranha* piranha) {
    LinkedList<Guppy*> *liGuppy = Data::getGuppies();

    if((liGuppy->isEmpty())){

        double minDistance, tempDistance;
        Guppy *nearestGuppy, *tempGuppy;

        LinkedListItem<Guppy*> *liItemGuppy = liGuppy->getFirstItem();
        nearestGuppy = liItemGuppy->getContent();
        minDistance = piranha->getPosition()->magnitude(*(nearestGuppy->getPosition()));

        while (liItemGuppy != liGuppy->getLastItem())
        {
            // while (liItemFood->getNext() != NULL){
            tempGuppy = liItemGuppy->getContent();
            tempDistance = piranha->getPosition()->magnitude(*(tempGuppy->getPosition()));
            if (tempDistance < minDistance)
            {
                minDistance = tempDistance;
                nearestGuppy = tempGuppy;
            }
            liItemGuppy = liItemGuppy->getNext();
        }
        //handle last element
        tempGuppy = liItemGuppy->getContent();
        tempDistance = piranha->getPosition()->magnitude(*(tempGuppy->getPosition()));
        if (tempDistance < minDistance)
        {
            minDistance = tempDistance;
            nearestGuppy = tempGuppy;
        }

        return nearestGuppy;
    } else {
        return NULL;
    }
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
 * For every food, move food to ground
 * Move snail to nearest coin
 */
void AquariumController::moveObjects() {
    
    LinkedList<Coin *> *liCoin = Data::getCoins();
    LinkedListItem<Coin *> *liItemCoin = liCoin->getFirstItem();
    Coin* currentCoin;

    while(liItemCoin != NULL){
        currentCoin = liItemCoin->getContent();
        currentCoin->move(this->getHeight());
        liItemCoin = liItemCoin->getNext();
    }

    LinkedList<Food *> *liFood = Data::getFoods();
    LinkedListItem<Food *> *liItemFood = liFood->getFirstItem();
    Food* currentFood;
    Position* lowerPosition = new Position(this->getWidth(),this->getHeight());

    while(liItemFood != NULL){
        currentFood = liItemFood->getContent();
        currentFood->move(lowerPosition);
        liItemFood = liItemFood->getNext();
    }

    LinkedList<Guppy*> *liGuppy = Data::getGuppies();
    LinkedListItem<Guppy*> *liItemGuppy = liGuppy->getFirstItem();
    Guppy* currentGuppy;

    // while(liItemGuppy != liGuppy->getLastItem()){
    while(liItemGuppy != NULL){ 
        currentGuppy = liItemGuppy->getContent();   
        if(currentGuppy->isStarving()){
            Food *nearestFood;
            nearestFood = findNearestFood(currentGuppy);
            currentGuppy->moveToDestination(nearestFood->getPosition());
        } else {
            currentGuppy->moveToDestination(this->getWidth(), this->getHeight());
        }
        liItemGuppy = liItemGuppy->getNext();
    }

    LinkedList<Piranha *> *liPiranha = Data::getPiranhas();
    LinkedListItem<Piranha *> *liItemPiranha = liPiranha->getFirstItem();
    Piranha *currentPiranha;

    // while(liItemPiranha != liPiranha->getLastItem()){
    while (liItemPiranha != NULL)
    {
        currentPiranha = liItemPiranha->getContent();
        if (currentPiranha->isStarving())
        {
            Guppy *nearestGuppy;
            nearestGuppy = findNearestGuppy(currentPiranha);
            currentPiranha->moveToDestination(nearestGuppy->getPosition());
        }
        else
        {
            currentPiranha->moveToDestination(this->getWidth(), this->getHeight());
        }
        liItemPiranha = liItemPiranha->getNext();
    }

    Snail *currentSnail = Data::getSnail();
    Coin *nearestcoin ;
    if(!(liCoin->isEmpty())){
        nearestcoin = findNearestCoin(currentSnail);
        currentSnail->moveToDestination(*(nearestcoin->getPosition()));
    }
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
        this->tank->draw_image(
            Guppy::getAssetPath(),
            guppyIt->getContent()->getPosition()->getAbsis(),
            guppyIt->getContent()->getPosition()->getOrdinate()
        );
        guppyIt = guppyIt->getNext();
    }

    this->tank->update_screen();
}

