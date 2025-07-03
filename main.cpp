#include <iostream>
#include "MyContainer.hpp"  

using namespace myCont;

int main() {
    MyContainer<int> container;

    // Add elements to the container
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    container.add(1);
    container.add(13);
    

    std::cout << "Original container (insertion order): " << container << "\n\n";

    // Ascending Order
    std::cout << "Ascending Order: ";
    for (auto it = container.beginAscending(); it != container.endAscending(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Descending Order
    std::cout << "Descending Order: ";
    for (auto it = container.beginDescending(); it != container.endDescending(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Side-Cross Order
    std::cout << "Side-Cross Order: ";
    for (auto it = container.beginSideCross(); it != container.endSideCross(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Reverse Order
    std::cout << "Reverse Order: ";
    for (auto it = container.beginReverse(); it != container.endReverse(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Insertion Order
    std::cout << "Insertion Order: ";
    for (auto it = container.beginOrder(); it != container.endOrder(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Middle-Out Order
    std::cout << "Middle-Out Order: ";
    for (auto it = container.beginMiddleOut(); it != container.endMiddleOut(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
