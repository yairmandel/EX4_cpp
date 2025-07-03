//yair340@gmail.com
#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

namespace myCont {
    // Generic class
    template<typename T = int>
    class MyContainer {
        private:
            std::vector<T> data;

        public:
            void add(const T& value){
                data.push_back(value);
            }

            void remove(const T& value){
               auto it = std::remove(data.begin(), data.end(), value);
                if (it == data.end())
                throw std::runtime_error("Element not found");
               
                data.erase(it, data.end());
            }
            


            size_t size() const{
                return data.size();
            }
            
            // Direct access to internal data (for use with iterators)
            const std::vector<T>& getData() const {
                return data;
            }

            // Output operator to print the container contents
            friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
                for (const T& val : container.data)
                    os << val << " ";
                return os;
            }
            
            // Iterator declarations and access methods
            
            // Ascending Order Iterator
            class AscendingOrderIterator;
            AscendingOrderIterator beginAscending() const {
                return AscendingOrderIterator(data);
            }
            AscendingOrderIterator endAscending() const {
                return AscendingOrderIterator(data, true);
            }

            // Descending Order Iterator
            class DescendingOrderIterator;
            DescendingOrderIterator beginDescending() const {
                return DescendingOrderIterator(data);
            }
            DescendingOrderIterator endDescending() const {
                return DescendingOrderIterator(data, true);
            }

            // Side Cross Order Iterator
            class SideCrossOrderIterator;
            SideCrossOrderIterator beginSideCross() const {
                return SideCrossOrderIterator(data);
            }
            SideCrossOrderIterator endSideCross() const {
                return SideCrossOrderIterator(data, true);
            }

            // Reverse Order Iterator
            class ReverseOrderIterator;
            ReverseOrderIterator beginReverse() const {
                return ReverseOrderIterator(data);
            }
            ReverseOrderIterator endReverse() const {
                return ReverseOrderIterator(data, true);
            }

            // Insertion Order Iterator
            class OrderIterator;
            OrderIterator beginOrder() const {
                return OrderIterator(data);
            }
            OrderIterator endOrder() const {
                return OrderIterator(data, true);
            }

            // Middle-Out Order Iterator
            class MiddleOutOrderIterator;
            MiddleOutOrderIterator beginMiddleOut() const {
                return MiddleOutOrderIterator(data);
            }
            MiddleOutOrderIterator endMiddleOut() const {
                return MiddleOutOrderIterator(data, true);
            }
       
    };
    
    //Generic AscendingOrderIterator implementation 
    template<typename T>
    class MyContainer<T>::AscendingOrderIterator {
    private:
        std::vector<T> sorted_data;  
        size_t index;

    public:
       
        AscendingOrderIterator(const std::vector<T>& data, bool is_end = false) 
            : sorted_data(data), index(0) 
        {
            std::sort(sorted_data.begin(), sorted_data.end());
            if (is_end) index = sorted_data.size();
        }
       
        const T& operator*() const {
            return sorted_data[index];
        }

        AscendingOrderIterator& operator++() {
            ++index;
            return *this;
        }
        
        AscendingOrderIterator operator++(int) {
            AscendingOrderIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const AscendingOrderIterator& other) const {
            return index == other.index;
        }
       
        bool operator!=(const AscendingOrderIterator& other) const {
            return index != other.index;
        }
    
    };
    
    //Generic DescendingOrderIterator implementation 
    template<typename T>
    class myCont::MyContainer<T>::DescendingOrderIterator {
    private:
        std::vector<T> sorted_data;
        size_t index;

    public:
        DescendingOrderIterator(const std::vector<T>& data, bool is_end = false)
            : sorted_data(data), index(0) 
        {
            std::sort(sorted_data.begin(), sorted_data.end(), std::greater<T>()); 
            if (is_end) index = sorted_data.size();
        }

        const T& operator*() const {
            return sorted_data[index];
        }

        DescendingOrderIterator& operator++() {
            ++index;
            return *this;
        }

        DescendingOrderIterator operator++(int) {
            DescendingOrderIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const DescendingOrderIterator& other) const {
            return index == other.index;
        }

        bool operator!=(const DescendingOrderIterator& other) const {
            return index != other.index;
        }
    };

    //Generic SideCrossOrderIterator implementation 
    template<typename T>
    class MyContainer<T>::SideCrossOrderIterator {
    private:
        std::vector<T> cross_data;
        size_t index;

    public:
        SideCrossOrderIterator(const std::vector<T>& data, bool is_end = false)
            : index(0)
        {
            // First, sort the data in ascending order
            std::vector<T> sorted_data = data;
            std::sort(sorted_data.begin(), sorted_data.end());

            // Build the side-cross traversal order
            size_t left = 0;
            size_t right = sorted_data.size() - 1;

            while (left <= right) {
                if (left == right) {
                    cross_data.push_back(sorted_data[left]);
                } else {
                    cross_data.push_back(sorted_data[left]);
                    cross_data.push_back(sorted_data[right]);
                }
                ++left;
                if (right > 0) --right;  // prevent unsigned underflow
            }

            if (is_end) {
                index = cross_data.size();
            }
        }

        const T& operator*() const {
            return cross_data[index];
        }

        SideCrossOrderIterator& operator++() {
            ++index;
            return *this;
        }

        SideCrossOrderIterator operator++(int) {
            SideCrossOrderIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const SideCrossOrderIterator& other) const {
            return index == other.index;
        }

        bool operator!=(const SideCrossOrderIterator& other) const {
            return index != other.index;
        }
    };

    //Generic ReverseOrderIterator implementation 
    template<typename T>
    class MyContainer<T>::ReverseOrderIterator {
    private:
        std::vector<T> reversed_data;
        size_t index;

    public:
        // Constructor: creates a reversed copy of the data
        ReverseOrderIterator(const std::vector<T>& data, bool is_end = false)
            : reversed_data(data), index(0)
        {
            std::reverse(reversed_data.begin(), reversed_data.end());
            if (is_end) {
                index = reversed_data.size();  // position after the last element
            }
        }

        // Dereference operator - returns the current element
        const T& operator*() const {
            return reversed_data[index];
        }

        // Pre-increment operator - moves to the next element
        ReverseOrderIterator& operator++() {
            ++index;
            return *this;
        }

        // Post-increment operator (optional but often implemented)
        ReverseOrderIterator operator++(int) {
            ReverseOrderIterator temp = *this;
            ++(*this);
            return temp;
        }

        // Equality operator
        bool operator==(const ReverseOrderIterator& other) const {
            return index == other.index;
        }

        // Inequality operator
        bool operator!=(const ReverseOrderIterator& other) const {
            return index != other.index;
        }
    };

    //Generic OrderIterator implementation 
    template<typename T>
    class MyContainer<T>::OrderIterator {
    private:
        const std::vector<T>& original_data;
        size_t index;

    public:
        // Constructor: takes a reference to the original container data
        OrderIterator(const std::vector<T>& data, bool is_end = false)
            : original_data(data), index(0)
        {
            if (is_end) {
                index = original_data.size();  // position after the last element
            }
        }

        // Dereference operator - returns the current element
        const T& operator*() const {
            return original_data[index];
        }

        // Pre-increment operator - move to the next element
        OrderIterator& operator++() {
            ++index;
            return *this;
        }

        // Post-increment operator (optional)
        OrderIterator operator++(int) {
            OrderIterator temp = *this;
            ++(*this);
            return temp;
        }

        // Equality operator
        bool operator==(const OrderIterator& other) const {
            return index == other.index;
        }

        // Inequality operator
        bool operator!=(const OrderIterator& other) const {
            return index != other.index;
        }
    };

    //Generic MiddleOutOrderIterator implementation 
    template<typename T>
    class MyContainer<T>::MiddleOutOrderIterator {
    private:
        std::vector<T> ordered_data;
        size_t index;

    public:
        // Constructor: builds the middle-out order
        MiddleOutOrderIterator(const std::vector<T>& data, bool is_end = false) : index(0) {
            size_t n = data.size();
            if (n == 0) return;

            size_t mid = n / 2;
            if (n % 2 == 0) mid--; // you can choose rounding behavior

            // Fill ordered_data in middle-out pattern
            ordered_data.push_back(data[mid]);

            size_t left = mid;
            size_t right = mid;

            while (left > 0 || right < n - 1) {
                if (right < n - 1) {
                    right++;
                    ordered_data.push_back(data[right]);
                }
                if (left > 0) {
                    left--;
                    ordered_data.push_back(data[left]);
                }
            }

            if (is_end) {
                index = ordered_data.size();  // past-the-end iterator
            }
        }

        // Dereference operator
        const T& operator*() const {
            return ordered_data[index];
        }

        // Pre-increment operator
        MiddleOutOrderIterator& operator++() {
            ++index;
            return *this;
        }

        // Post-increment operator
        MiddleOutOrderIterator operator++(int) {
            MiddleOutOrderIterator temp = *this;
            ++(*this);
            return temp;
        }

        // Equality comparison
        bool operator==(const MiddleOutOrderIterator& other) const {
            return index == other.index;
        }

        // Inequality comparison
        bool operator!=(const MiddleOutOrderIterator& other) const {
            return index != other.index;
        }
    };

}
