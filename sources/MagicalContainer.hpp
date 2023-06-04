#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;
namespace ariel{


    class MagicalContainer{

        vector<int> elements = {};

        public:
                void set_mystical_elements(vector<int>& container){
                    elements = container;
                }

                MagicalContainer(){}

                void addElement(int element){
                    elements.push_back(element);
                    sort(elements.begin(), elements.end());
                }

                void removeElement(int element ){

                    for(auto i= elements.begin(); i!=elements.end(); ++i) {
                        if(*i == element){
                            elements.erase(i);
                            return;
                        }
                    }
                    
                    throw runtime_error("Error: The value doesn't exist");

                }
            
                int size() const {
                    return elements.size();            
                }

                vector<int>& getElements(){
                    return elements;
                }

                ~MagicalContainer()= default; 
                MagicalContainer (const MagicalContainer &other){}
                // Move constructor
                MagicalContainer(MagicalContainer&& other) noexcept {}

                MagicalContainer& operator=(const MagicalContainer& other) {
                        if (this != &other) {
                            this->elements = other.elements;
                        }
                        return *this;
                }

                
                // Move assignment operator
                MagicalContainer& operator=(MagicalContainer&& other) noexcept {
                    if (this != &other){
                        this->elements = other.elements;
                    }
                    return *this;
                }
                



/************************************ AscendingIterator **************************************************/


            class AscendingIterator {
                 
                MagicalContainer &container;
                int curr_index = 0;

                public:
                    AscendingIterator( MagicalContainer &container, int curr): container(container), curr_index(curr) {}
                    AscendingIterator(MagicalContainer &container): container(container), curr_index(0){}

                    //Destructor
                    ~AscendingIterator() = default;

                    // Copy constructor
                    AscendingIterator(const AscendingIterator& other) :container(other.container) , curr_index(other.curr_index){}

                    // Move constructor
                    AscendingIterator(AscendingIterator&& other) noexcept : container(other.container) {}

                    // Copy assignment operator
                    AscendingIterator& operator=(const AscendingIterator& other) {
                       if(&container != &other.container){ // throw error if we try to assign different containers
                            throw runtime_error("Error: Iterators cannot be assigned if they belong to different containers.");
                        }

                       if (this != &other) {
                            container = other.container;
                            curr_index = other.curr_index;
                        }

                        return *this;
                    }

                    // Move assignment operator
                    AscendingIterator& operator=(AscendingIterator&& other) noexcept {
                        if (this != &other) {
                            container = other.container;
                            curr_index = other.curr_index;
                        }

                        return *this;
                    }
                 
                    int& operator*() const {
                        return container.getElements()[static_cast<vector<int>::size_type>(curr_index)];
                    }

                    AscendingIterator operator++() { //++i
                        if(curr_index >= container.getElements().size() || *this == end()){ // throw error when try to increase while we at the end
                            throw runtime_error("Error: Iterator out of bounds!!!");
                        }
                        ++curr_index;
                        return *this;
                    }

                    // Greater than comparison
                    bool operator>(const AscendingIterator& other) const {
                        return curr_index > other.curr_index;
                    }

                    // Less than comparison
                    bool operator<(const AscendingIterator& other) const {
                        return curr_index < other.curr_index;
                    }
                    
                    bool operator==(const AscendingIterator& other) const {
                        return curr_index == other.curr_index;
                    }

                    bool operator!=(const AscendingIterator& other) const {
                        return !(*this == other);
                    }

                    AscendingIterator begin() const {
                        return AscendingIterator(container, 0);
                    }
                    
                    AscendingIterator end() const {
                        return AscendingIterator(container,container.size());
                    }


            };

/************************************ SideCrossIterator **************************************************/

            class SideCrossIterator {
                 
                MagicalContainer &container;
                int curr_index;

                public:
                    SideCrossIterator(MagicalContainer &cont, int curr): container(cont), curr_index(curr){}
                    SideCrossIterator(MagicalContainer &container): container(container), curr_index(0) {}

                    // Default destructor
                    ~SideCrossIterator() = default;

                    // Copy constructor
                    SideCrossIterator(const SideCrossIterator& other): container(other.container), curr_index(other.curr_index) {}
                    
                    // Copy assignment operator
                    SideCrossIterator& operator=(const SideCrossIterator& other) {
                        if(&container != &other.container){ // throw error if we try to assign different containers
                            throw runtime_error("Error: Iterators cannot be assigned if they belong to different containers.");
                        }
                        if (this != &other) {
                            container = other.container;
                            curr_index = other.curr_index;
                        }
                        return *this;
                    }

                    int& operator*() const {
                        if (!(curr_index % 2)) { 
                            return container.elements.at((std::vector<int>::size_type)(curr_index / 2));
                        }
                        else {
                            return container.elements.at((std::vector<int>::size_type)(container.size() - 1 - (curr_index - 1 ) / 2));
                        }   
                    }                 

                    SideCrossIterator& operator++() { //++i
                        if(curr_index >= container.getElements().size() || *this == end()){ // throw error when try to increase while we at the end
                            throw runtime_error("Error: Iterator out of bounds!!!");
                        }
                        curr_index++;
                        return *this;
                    }

                    bool operator>(const SideCrossIterator& other) const {
                        return curr_index > other.curr_index;
                    }

                    // Less than comparison
                    bool operator<(const SideCrossIterator& other) const {
                        return curr_index < other.curr_index;
                    }
                    bool operator==(const SideCrossIterator& other) const{
                        return curr_index == other.curr_index && &container == &other.container;
                    }

                    bool operator!=(const SideCrossIterator& other) const{
                        return !(*this == other);                    
                    }

                    SideCrossIterator begin() const {
                        return SideCrossIterator(container,0);
                    }

                    SideCrossIterator end() const {
                        return SideCrossIterator(container,container.size());;         
                    }

            };

/************************************ PrimeIterator **************************************************/
            class PrimeIterator{

                MagicalContainer &container;
                int curr_index;
                
                 bool isPrime(int num) {
                    if (num <= 1){
                        return false;
                    }
                    for (int i = 2; i <= std::sqrt(num); i++) {
                        if (num % i == 0){
                            return false;
                        }   
                    }
                    return true;
                }

                public:

                    PrimeIterator(MagicalContainer &cont, int curr) : container(cont), curr_index(curr) {}
                    PrimeIterator(MagicalContainer &container): container(container), curr_index(0) {
                        // Skip non-prime numbers at the beginning
                        while (curr_index < container.size() && !isPrime(container.getElements().at((std::vector<int>::size_type)curr_index))) {
                            curr_index++;
                        }
                    }

                    // Default destructor
                    ~PrimeIterator() = default;

                    //Copy constructor
                    PrimeIterator(const PrimeIterator& other) : container(other.container), curr_index(other.curr_index) {}

                    // Copy assignment operator
                    PrimeIterator& operator=(const PrimeIterator& other) {
                        if(&container != &other.container){ // throw error if we try to assign different containers
                            throw runtime_error("Error: Iterators cannot be assigned if they belong to different containers.");
                        }
                        if (this != &other){
                            container = other.container;
                            curr_index = other.curr_index;          
                        }
                        return *this;
                    }

                    int& operator*() const {
                        return container.getElements()[static_cast<vector<int>::size_type>(curr_index)];
                    }

                    PrimeIterator operator++(){ // ++i
                        if(curr_index >= container.getElements().size() || *this == end()){// throw error when try to increase while we at the end
                            throw runtime_error("Error: Iterator out of bounds!!!");
                        }
                        curr_index++;
                        if (curr_index < container.size() && !isPrime(container.getElements().at((std::vector<int>::size_type)curr_index))) {
                            curr_index++;
                        }
                        return *this;
                    }

                    bool operator>(const PrimeIterator& other) const {
                        return curr_index > other.curr_index;
                    }

                    // Less than comparison
                    bool operator<(const PrimeIterator& other) const {
                        return curr_index < other.curr_index;
                    }

                    bool operator==(const PrimeIterator& other) const{
                        return &container == &other.container && curr_index == other.curr_index ;
                    }

                    bool operator!=(const PrimeIterator& other) const{
                        return !(*this == other);                    
                    }

                    PrimeIterator begin() const {
                        return PrimeIterator(container, 0);
                    }
                    PrimeIterator end() const {
                        return PrimeIterator(container,container.size());

                    }
            };

    }; 
}
