#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"

using namespace myCont;

TEST_CASE("Basic add and remove") {
    MyContainer<int> container;
    container.add(10);
    container.add(20);
    container.add(30);
    
    CHECK(container.size() == 3);
    
    container.remove(20);
    CHECK(container.size() == 2);
    
    CHECK_THROWS_AS(container.remove(100), std::runtime_error);
}

TEST_CASE("AscendingOrderIterator works correctly") {
    MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(2);

    std::vector<int> expected = {1, 2, 3};
    std::vector<int> result;
    for (auto it = container.beginAscending(); it != container.endAscending(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}

TEST_CASE("DescendingOrderIterator works correctly") {
    MyContainer<int> container;
    container.add(3);
    container.add(1);
    container.add(2);

    std::vector<int> expected = {3, 2, 1};
    std::vector<int> result;
    for (auto it = container.beginDescending(); it != container.endDescending(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}

TEST_CASE("SideCrossOrderIterator works correctly") {
    MyContainer<int> container;
    container.add(1);
    container.add(2);
    container.add(3);
    container.add(4);

    // SideCross should alternate from smallest to largest: 1 4 2 3
    std::vector<int> expected = {1, 4, 2, 3};
    std::vector<int> result;
    for (auto it = container.beginSideCross(); it != container.endSideCross(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}

TEST_CASE("ReverseOrderIterator works correctly") {
    MyContainer<int> container;
    container.add(1);
    container.add(2);
    container.add(3);

    std::vector<int> expected = {3, 2, 1};
    std::vector<int> result;
    for (auto it = container.beginReverse(); it != container.endReverse(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}

TEST_CASE("OrderIterator (insertion order) works correctly") {
    MyContainer<int> container;
    container.add(5);
    container.add(10);
    container.add(15);

    std::vector<int> expected = {5, 10, 15};
    std::vector<int> result;
    for (auto it = container.beginOrder(); it != container.endOrder(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}

TEST_CASE("MiddleOutOrderIterator works correctly") {
    MyContainer<int> container;
    container.add(1);
    container.add(2);
    container.add(3);
    container.add(4);
    container.add(5);

    // Middle is index 2 (element 3), then alternating right/left outwards: 3 4 2 5 1
    std::vector<int> expected = {3, 4, 2, 5, 1};
    std::vector<int> result;
    for (auto it = container.beginMiddleOut(); it != container.endMiddleOut(); ++it) {
        result.push_back(*it);
    }

    CHECK(result == expected);
}
