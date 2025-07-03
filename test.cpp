// yair340@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"

using namespace myCont;

TEST_CASE("Basic add and remove for int and char") {
    MyContainer<int> intContainer;
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);
    CHECK(intContainer.size() == 3);
    intContainer.remove(20);
    CHECK(intContainer.size() == 2);
    CHECK_THROWS_AS(intContainer.remove(100), std::runtime_error);

    MyContainer<char> charContainer;
    charContainer.add('a');
    charContainer.add('b');
    charContainer.add('c');
    CHECK(charContainer.size() == 3);
    charContainer.remove('b');
    CHECK(charContainer.size() == 2);
    CHECK_THROWS_AS(charContainer.remove('z'), std::runtime_error);
}

TEST_CASE("Basic operations with doubles") {
    MyContainer<double> doubleContainer;
    doubleContainer.add(1.1);
    doubleContainer.add(3.3);
    doubleContainer.add(2.2);

    std::vector<double> expected = {1.1, 3.3, 2.2};
    std::vector<double> result;
    for (auto it = doubleContainer.beginOrder(); it != doubleContainer.endOrder(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
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

TEST_CASE("DescendingOrderIterator with chars") {
    MyContainer<char> container;
    container.add('b');
    container.add('a');
    container.add('c');

    std::vector<char> expected = {'c', 'b', 'a'};
    std::vector<char> result;
    for (auto it = container.beginDescending(); it != container.endDescending(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("SideCrossOrderIterator with doubles") {
    MyContainer<double> container;
    container.add(1.1);
    container.add(2.2);
    container.add(3.3);
    container.add(4.4);

    std::vector<double> expected = {1.1, 4.4, 2.2, 3.3};
    std::vector<double> result;
    for (auto it = container.beginSideCross(); it != container.endSideCross(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("ReverseOrderIterator with char") {
    MyContainer<char> container;
    container.add('x');
    container.add('y');
    container.add('z');

    std::vector<char> expected = {'z', 'y', 'x'};
    std::vector<char> result;
    for (auto it = container.beginReverse(); it != container.endReverse(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}

TEST_CASE("MiddleOutOrderIterator with ints") {
    MyContainer<int> container;
    container.add(1);
    container.add(2);
    container.add(3);
    container.add(4);
    container.add(5);

    std::vector<int> expected = {3, 4, 2, 5, 1};
    std::vector<int> result;
    for (auto it = container.beginMiddleOut(); it != container.endMiddleOut(); ++it) {
        result.push_back(*it);
    }
    CHECK(result == expected);
}
TEST_CASE("Removing duplicated elements") {
    MyContainer<int> container;
    container.add(5);
    container.add(5);
    container.add(5);
    container.remove(5);
    CHECK(container.size() == 0);
}
TEST_CASE("Empty container edge cases") {
    MyContainer<int> container;
    CHECK(container.size() == 0);
    CHECK_THROWS_AS(container.remove(10), std::runtime_error);
}

