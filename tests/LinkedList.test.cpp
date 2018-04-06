#include "../models/LinkedList.hpp"

int main() {
    LinkedList<int>* ll = new LinkedList<int>();

    ll->add(1);
    std::cout << ll->getFirst() << std::endl;
}