yair340@gmail.com
yair mandel

project Description:

MyContainer is a generic (templated) C++ container that allows storing elements of any type (default: integers) and provides a variety of custom iterators for traversing the container in different orders:

    Ascending Order

    Descending Order

    Side-Cross Order (alternating from edges inward)

    Reverse Order

    Insertion Order

    Middle-Out Order (starting from the middle outward)

The project demonstrates the use of templates, containers and custom iterators.


Project Structure:

    MyContainer.hpp - Implementation of the container and its iterator templates

    main.cpp - Example usage demonstrating various iterators and output

    test.cpp - Automated unit tests using the Doctest framework

    Makefile - Build script for compiling the project, running tests, and memory checks via Valgrind


Usage Instructions:

Build and Run the Demo - 
make main
./main

Run Automated Tests-
make test
./test

Memory Leak Check with Valgrind-
make valgrind


Key Features:

    Generic container implemented with C++ templates

    Custom iterators supporting multiple traversal orders

    Exception handling for error conditions

    Internal data storage using std::vector

    Comprehensive unit tests using Doctest

    Support for adding, removing elements, size retrieval, and output formatting


Iterator Types Overview:

    AscendingOrderIterator: Iterates elements in ascending sorted order

    DescendingOrderIterator: Iterates elements in descending sorted order

    SideCrossOrderIterator: Alternates between the smallest and largest remaining elements

    ReverseOrderIterator: Iterates elements in reverse insertion order

    OrderIterator: Iterates elements in insertion order

    MiddleOutOrderIterator: Starts from the middle element and moves outward

