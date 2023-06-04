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
                            break;
                        }
                    }
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
                
                    AscendingIterator(MagicalContainer &container): container(container), curr_index(0){}

                    //Destructor
                    ~AscendingIterator() = default;

                    // Copy constructor
                    AscendingIterator(const AscendingIterator& other) :container(other.container){}

                    // Move constructor
                    AscendingIterator(AscendingIterator&& other) noexcept : container(other.container) {}

                    // Copy assignment operator
                    AscendingIterator& operator=(const AscendingIterator& other) {
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
                        return AscendingIterator(container);
                    }
                    
                    AscendingIterator end() const {
                        AscendingIterator end(container);
                        end.curr_index = container.size();
                        return end;
                    }


            };

/************************************ SideCrossIterator **************************************************/

            class SideCrossIterator {
                 
                MagicalContainer &container;
                int curr_index;
                bool from_start;

                public:
                    SideCrossIterator(MagicalContainer &cont, int curr, bool flag): container(cont), curr_index(curr), from_start(flag) {}
                    SideCrossIterator(MagicalContainer &container): container(container), curr_index(0), from_start(true) {}

                    // Default destructor
                    ~SideCrossIterator() = default;

                    // Copy constructor
                    SideCrossIterator(const SideCrossIterator& other): container(other.container) {}
                    
                    // Move constructor
                    SideCrossIterator(SideCrossIterator&& other) noexcept : container(other.container) {}
                    
                    // Copy assignment operator
                    SideCrossIterator& operator=(const SideCrossIterator& other) {
                        if (this != &other) {
                            container = other.container;
                            curr_index = other.curr_index;
                            from_start = other.from_start;
                        }
                        return *this;
                    }

                    // Move assignment operator
                    SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {
                        if (this != &other) {
                            container = other.container;
                            curr_index = other.curr_index;
                            from_start = other.from_start;
                        }
                        return *this;
                    }

                    int& operator*() const {
                        return container.getElements()[static_cast<vector<int>::size_type>(curr_index)];
                    }

                    SideCrossIterator& operator++() { //++i
                        if (from_start){
                            if(curr_index != container.size()/2){
                                ++curr_index;
                            }
                            else{
                                curr_index = container.size();
                            }
                        }

                        from_start = !from_start;
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
                        return curr_index == other.curr_index && from_start == other.from_start;
                    }

                    bool operator!=(const SideCrossIterator& other) const{
                        return !(curr_index == other.curr_index && from_start == other.from_start);
                    }

                    SideCrossIterator begin() const {
                        return SideCrossIterator(container,0,true);
                    }

                    SideCrossIterator end() const {
                        return SideCrossIterator(container,container.size(),false);;         
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
                        vector<int> prime_v ={};

                        for(size_t i = 0; i<container.size(); i++){
                            if(isPrime(container.getElements()[i])){
                                prime_v.push_back(container.getElements()[i]);
                            }
                        }

                        sort(prime_v.begin(),prime_v.end());

                        container.set_mystical_elements(prime_v);
                    }

                    // Default destructor
                    ~PrimeIterator() = default;

                    //Copy constructor
                    PrimeIterator(const PrimeIterator& other) : container(other.container), curr_index(other.curr_index) {}

                    // Move constructor
                    PrimeIterator(PrimeIterator&& other) noexcept: container(other.container) {}

                    // Copy assignment operator
                    PrimeIterator& operator=(const PrimeIterator& other) {
                        if (this != &other){
                            *this = other.container;
                        }    
                        
                        return *this;
                    }

                    // Move assignment operator
                    PrimeIterator& operator=(PrimeIterator&& other) noexcept {
                        if (this != &other){
                            *this = other.container;
                        }
                        return *this;
                    }

                    int& operator*() const {
                        return container.getElements()[static_cast<vector<int>::size_type>(curr_index)];
                    }

                    PrimeIterator operator++(){ // ++i
                        ++curr_index;
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
                        return curr_index == other.curr_index && &container == &other.container;
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
