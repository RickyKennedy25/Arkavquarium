#include "AquariumController.hpp"
#include <utility>



/**
 * Construct with some guppies, one piranha and one snail 
 * with random position
 * @param {int} height of aquarium
 * @param {int} width of aquarium
 */
AquariumController::AquariumController(int width, int height) {

    this->height = height;
    this->width = width;
    Data::setMoney(200); 
    Data::setEgg(0); 
    Guppy* guppy1 = new Guppy(this->width, this->height);
    Data::getGuppies()->add(guppy1);

    Guppy* guppy2 = new Guppy(this->width, this->height);
    Data::getGuppies()->add(guppy2);

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
    std::pair<double, double> clicked = this->tank->getLastClicked();
    if (clicked.first > 0 && clicked.second > 0) {
        LinkedListItem<Coin*>* cointIt = Data::getCoins()->getFirstItem();
        Coin* clickedCoin = NULL;
        Position clickPos(clicked.first, clicked.second, false);
        while (cointIt != NULL && !clickedCoin) {
            if (*(cointIt->getContent()->getPosition()) == clickPos) {
                clickedCoin = cointIt->getContent();
            }
            cointIt = cointIt->getNext();
        }

        if (clickedCoin != NULL) {
            Data::getCoins()->remove(clickedCoin);
            Data::setMoney(Data::getMoney() + clickedCoin->getValue());
            delete clickedCoin;
        } else {
            if (Data::getMoney() > Food::getPrice()) {
                Food* newFood = new Food(clicked.first, clicked.second);
                Data::getFoods()->add(newFood);
                Data::setMoney(Data::getMoney() - Food::getPrice());
            }
        }
        this->tank->resetLastClicked();
    }
    if (this->tank->quit_pressed()) {
        return false;
    }

    /*/ handler for pressed keys
    for (auto key : this->tank->get_pressed_keys()) {
        
        switch (key) {
			case SDLK_g:
				buyGuppy();
				break;
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
			case SDLK_g:
				buyGuppy();
				break;
			case SDLK_e:
				buyEgg();
				break;
			case SDLK_p:
				buyPiranha();
				break;
            case SDLK_r:
                Data::setMoney(5000);
                break;
        }
    }
    if (!stillRunning ){
          return false;
    }

    this->moveObjects(elapsedSeconds);
    this->produceCoin();
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

        while (liItemCoin != liCoin->getLastItem()) {
            // while (liItemFood->getNext() != NULL){
            tempCoin = liItemCoin->getContent();
            tempDistance = snail->getPosition()->magnitude(*(tempCoin->getPosition()));
            if (tempDistance < minDistance) {
                minDistance = tempDistance;
                nearestCoin = tempCoin;
            }
            liItemCoin = liItemCoin->getNext();
        }
        //handle last element
        tempCoin = liItemCoin->getContent();
        tempDistance = snail->getPosition()->magnitude(*(tempCoin->getPosition()));
        if (tempDistance < minDistance) {
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

    if(!(liGuppy->isEmpty())) {
        double minDistance, tempDistance;
        Guppy *nearestGuppy, *tempGuppy;

        LinkedListItem<Guppy*> *liItemGuppy = liGuppy->getFirstItem();
        nearestGuppy = liItemGuppy->getContent();
        minDistance = piranha->getPosition()->magnitude(*(nearestGuppy->getPosition()));

        while (liItemGuppy != liGuppy->getLastItem()) {
            // while (liItemFood->getNext() != NULL){
            tempGuppy = liItemGuppy->getContent();
            tempDistance = piranha->getPosition()->magnitude(*(tempGuppy->getPosition()));
            if (tempDistance < minDistance) {
                minDistance = tempDistance;
                nearestGuppy = tempGuppy;
            }
            liItemGuppy = liItemGuppy->getNext();
        }
        //handle last element
        tempGuppy = liItemGuppy->getContent();
        tempDistance = piranha->getPosition()->magnitude(*(tempGuppy->getPosition()));
        if (tempDistance < minDistance) {
            minDistance = tempDistance;
            nearestGuppy = tempGuppy;
        }

        return nearestGuppy;
    } else {
        return NULL;
    }
}

/**
 * Create new Coin for every fish if the fish will produce coin
 */
void AquariumController::produceCoin() {
    LinkedListItem<Piranha *> *currentPiranha = Data::getPiranhas()->getFirstItem();
    while (currentPiranha != NULL) {
        int coinValue = currentPiranha->getContent()->isProduceCoin();
        if (coinValue > 0) {
            Data::getCoins()->add(
                new Coin(coinValue * Guppy::getPrice(), * currentPiranha->getContent()->getPosition())
            );
        }
        currentPiranha = currentPiranha->getNext();
    }

    LinkedListItem<Guppy*>* currentGuppy = Data::getGuppies()->getFirstItem();
    while (currentGuppy != NULL) {
        int coinValue = currentGuppy->getContent()->isProduceCoin();
        if (coinValue > 0) {
            Data::getCoins()->add(
                new Coin(coinValue, * currentGuppy->getContent()->getPosition())
            );
        }
        currentGuppy = currentGuppy->getNext();
    }
}

/**
 * For every fish, move fish to nearest food if hungry, or to dest
 * For every coin, move coin to ground
 * For every food, move food to ground
 * Move snail to nearest coin
 */
void AquariumController::moveObjects(double elapsedSeconds) {
    LinkedListItem<Coin *> *currentCoin = Data::getCoins()->getFirstItem();

    while (currentCoin != NULL) {
        currentCoin->getContent()->move(this->getHeight(), elapsedSeconds);
        currentCoin = currentCoin->getNext();
    }

    LinkedListItem<Food *> *currentFood = Data::getFoods()->getFirstItem();
    while(currentFood != NULL){
        currentFood->getContent()->move(this->height-(this->height/10), elapsedSeconds);
        if (currentFood->getContent()->getPosition()->getOrdinate() >= 9*this->height/10) {
            Food* droppedFood = currentFood->getContent();
            Data::getFoods()->remove(droppedFood);
            delete droppedFood;
        }
        currentFood = currentFood->getNext();
    }

    LinkedListItem<Guppy*> *currentGuppy = Data::getGuppies()->getFirstItem();
    while (currentGuppy != NULL) {
        currentGuppy
            ->getContent()
            ->update(elapsedSeconds);
        currentGuppy
            ->getContent()
            ->setStarvingTimer(currentGuppy->getContent()->getStarvingTimer() + elapsedSeconds);

        if (currentGuppy->getContent()->isDie()){
            LinkedListItem<Guppy*> *dropedGuppy = currentGuppy;
            currentGuppy = currentGuppy->getNext();
            Data::getGuppies()->remove(dropedGuppy->getContent());
            delete dropedGuppy->getContent();
        } else {    
            if (currentGuppy->getContent()->isStarving()) {
                Food *nearestFood = this->findNearestFood(currentGuppy->getContent());
                if (nearestFood == NULL) {
                    currentGuppy
                        ->getContent()
                        ->moveToDestination(this->getWidth(), this->getHeight(), elapsedSeconds);
                } else {
                    currentGuppy
                        ->getContent()
                        ->moveToDestination(nearestFood->getPosition(), elapsedSeconds);
                    if (*(currentGuppy->getContent()->getPosition()) == *(nearestFood->getPosition())) {
                        currentGuppy->getContent()->eat();
                        Data::getFoods()->remove(nearestFood);
                        delete nearestFood;
                    }
                }
            } else {
                currentGuppy
                    ->getContent()
                    ->moveToDestination(this->getWidth(), this->getHeight(), elapsedSeconds);
            }
            currentGuppy = currentGuppy->getNext();
        }

    }

    LinkedListItem<Piranha *> *currentPiranha = Data::getPiranhas()->getFirstItem();
    while (currentPiranha != NULL) {
        currentPiranha
            ->getContent()
            ->setStarvingTimer(currentPiranha->getContent()->getStarvingTimer() + elapsedSeconds);
        if (currentPiranha->getContent()->isDie()){
            LinkedListItem<Piranha*> *dropedPiranha = currentPiranha;
            currentPiranha = currentPiranha->getNext();
            Data::getPiranhas()->remove(dropedPiranha->getContent());
            delete dropedPiranha->getContent();
        } else {
            if (currentPiranha->getContent()->isStarving()) {
                Guppy *nearestGuppy = findNearestGuppy(currentPiranha->getContent());
                if (nearestGuppy == NULL) {
                    currentPiranha
                        ->getContent()
                        ->moveToDestination(this->getWidth(), this->getHeight(), elapsedSeconds);
                } else {
                    currentPiranha
                        ->getContent()
                        ->moveToDestination(nearestGuppy->getPosition(), elapsedSeconds);
                    if (*(currentPiranha->getContent()->getPosition()) == *(nearestGuppy->getPosition())) {
                        currentPiranha->getContent()->eat(nearestGuppy->getGrowthStepInt());
                        Data::getGuppies()->remove(nearestGuppy);
                        delete nearestGuppy;
                    }
                }
            } else {
                currentPiranha
                    ->getContent()
                    ->moveToDestination(this->getWidth(), this->getHeight(), elapsedSeconds);
            }
            currentPiranha = currentPiranha->getNext();
        }
        
    }

    Snail *currentSnail = Data::getSnail();
    if(!(Data::getCoins()->isEmpty())){
        Coin *nearestcoin = findNearestCoin(currentSnail);
        currentSnail->moveToDestination(nearestcoin->getPosition(), elapsedSeconds);
        if (*(currentSnail->getPosition()) == *(nearestcoin->getPosition())) {
            Data::getCoins()->remove(nearestcoin);
            Data::setMoney(Data::getMoney()+nearestcoin->getValue());
            delete nearestcoin;
        }
    }
}

/**
 * Draw all entity
 */
void AquariumController::draw() {
    this->tank->clear_screen();
    //this->tank->draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
    this->tank->draw_image("assets/img/background.png",this->width/2,this->height/2);

    LinkedListItem<Guppy*> *guppyIt = Data::getGuppies()->getFirstItem();
    while (guppyIt != NULL) {
        this->drawDrawable(guppyIt->getContent());
        guppyIt = guppyIt->getNext();
    }

    LinkedListItem<Piranha*> *piranhaIt = Data::getPiranhas()->getFirstItem();
    while (piranhaIt != NULL) {
        this->drawDrawable(piranhaIt->getContent());
        piranhaIt = piranhaIt->getNext();
    }

    LinkedListItem<Coin*> *coinIt = Data::getCoins()->getFirstItem();
    while (coinIt != NULL) {
        this->drawDrawable(coinIt->getContent());
        coinIt = coinIt->getNext();
    }

    LinkedListItem<Food*> *foodIt = Data::getFoods()->getFirstItem();
    while (foodIt != NULL) {
        this->drawDrawable(foodIt->getContent());
        foodIt = foodIt->getNext();
    }

    Snail *currentSnail;
    currentSnail = Data::getSnail();
    this->drawDrawable(currentSnail);
    
	//Draw Money
    this->tank->draw_image("assets/img/coin_shine.png", 15, 50);
	this->tank->draw_text(std::to_string(Data::getMoney()), 35, 30, 35, 0, 0, 0);
	//Draw Egg
	this->tank->draw_image("assets/img/egg.png", this->getWidth() - 30, 55);
	this->tank->draw_text(std::to_string(Data::getEgg()), 35, this->getWidth()-70, 35, 0, 0, 0);
    
    this->tank->draw_text("Press G to buy Guppy (100 coins)        Press P to buy Piranha (1000 coins)          Press E to buy Egg (1000 coins)", 20, 15, 77, 0, 0, 0);
    
    if (this->winState()) {
        this->tank->draw_text("CONGRATULATIONS!!!", 25, (int)this->width/2, (int)this->height/2, 0, 0, 0);
    } else if (this->loseState()) {
        this->tank->draw_text("YOU LOSE!!!", 25, (int)this->width/2, (int)this->height/2, 0, 0, 0);
    } 
    
    this->tank->update_screen();
}

/**
 * Draw a drawable
 * @param {Drawable*} drawable object to draw
 */
void AquariumController::drawDrawable(Drawable* drawable) {
    this->tank->draw_image(
        drawable->getAssetPath(),
        drawable->getPosition()->getAbsis(),
        drawable->getPosition()->getOrdinate()
    );
}

void AquariumController::buyGuppy(){
	if (Data::getMoney() >= Guppy::getPrice()){
		Data::setMoney(Data::getMoney() - Guppy::getPrice());
		Guppy *g = new Guppy(this->width, this->height);
		Data::getGuppies()->add(g);
	}
}

void AquariumController::buyPiranha(){
	if (Data::getMoney() >= Piranha::getPrice()){
		Data::setMoney(Data::getMoney() - Piranha::getPrice());
		Piranha *p = new Piranha(this->width, this->height);
		Data::getPiranhas()->add(p);
	}
}

void AquariumController::buyEgg(){
	if(Data::getMoney() >= Data::getEggPrice()){
		Data::setMoney(Data::getMoney() - Data::getEggPrice());
		Data::setEgg(Data::getEgg()+1);
	}
}
        
/**
 * The game has been finished and the player wins
 * return {bool} Data::getEgg == WinCondition
 */
bool AquariumController::winState() {
    return Data::getEgg() == WIN_CONDITION;
}

/**
 * The game has been finished and the player lose
 * return {bool} there is no fish, coin, and money < 100
 */
bool AquariumController::loseState() {
    return
        Data::getGuppies()->isEmpty() &&
        Data::getPiranhas()->isEmpty() &&
        Data::getCoins()->isEmpty() &&
        Data::getMoney() < Guppy::getPrice();
}