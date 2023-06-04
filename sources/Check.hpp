// #pragma once

// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;
// namespace ariel{


//     class MagicalContainer{

//         vector<int> elements = {};


//         public:
//             void set_mystical_elements(vector<int>& container){
//               elements = container;
//             }

//             MagicalContainer(){}

//             void addElement(int num_to_add){
//                 elements.push_back(num_to_add);
//             }

//             void removeElement(int num_to_remove){

//                 for(auto i= elements.begin(); i!=elements.end();i++){

//                     if(*i == num_to_remove){
//                         elements.erase(i);
//                         i--;
//                     }
//                 }
//             }
         
//             int size() {
//                 return static_cast<int>(elements.size());
//             }

//             vector<int>& get_vector(){
//                 return elements;
//             }

//             ~MagicalContainer()= default; 
//             MagicalContainer (const MagicalContainer &other){}

//             MagicalContainer& operator=(const MagicalContainer& other) {
//                     if (this != &other){
//                         this->elements = other.elements;
//                     }
//                     return *this;
//             }

//                 // Move constructor
//                 MagicalContainer(MagicalContainer&& other) noexcept {
//                     // Move constructor implementation
//                 }

//                 // Move assignment operator
//                 MagicalContainer& operator=(MagicalContainer&& other) noexcept {
//                     if (this != &other){
//                         this->elements = other.elements;
//                     }
//                     return *this;
//                 }
                


//         //public:

//             class AscendingIterator{
                 
//                 MagicalContainer &container;
//                 int curr_index = 0;

//                 public:
//                 AscendingIterator(MagicalContainer &container): container(container){
//                     sort(container.get_vector().begin(),container.get_vector().end());
//                 }

//                 AscendingIterator begin(){
//                     return AscendingIterator(container);
//                 }
//                 AscendingIterator end(){
//                     AscendingIterator end(container);
//                     end.curr_index = container.size();
//                     return end;
//                 }
    
//                     int& operator*() const {
//                         return container.get_vector()[static_cast<vector<int>::size_type>(curr_index)];
//                     }
    

//                     //Destructor
//                     ~AscendingIterator() = default;

//                     // Copy constructor
//                     AscendingIterator(const AscendingIterator& other) :container(other.container){
//                     }

//                     // Copy assignment operator
//                     AscendingIterator& operator=(const AscendingIterator& other) {
//                         if (this != &other){
//                             *this = other.container;
//                         }
//                         return *this;
//                     }

//                         // Move constructor
//                         AscendingIterator(AscendingIterator&& other) noexcept : container(other.container) {
//                         }

//                     // Move assignment operator
//                     AscendingIterator& operator=(AscendingIterator&& other) noexcept {
//                         if (this != &other){
//                             return *this = other.container;
//                         }

//                         return *this;
//                     }
                 
         
//                     AscendingIterator operator++(){
//                         AscendingIterator temp(*this);  // Create a copy of the current object
//                         curr_index++;                   // Increment the index
//                         return temp;                    // Return the copy
//                     }

//                     bool operator==(const AscendingIterator& other_iterator) const {
//                         return curr_index == other_iterator.curr_index;
//                     }

//                     bool operator!=(const AscendingIterator& other_iterator) const {
//                         return !(curr_index == other_iterator.curr_index);
//                     }


//             };


//             class PrimeIterator{

//                 int curr_index =0;
//                 MagicalContainer &container;
                
//                 bool static is_prime(int num){
//                     if(num == 2 || num==3){
//                         return true;
//                     }
//                     if(num <=1){
//                         return false;
//                     }
//                     for(int j = 2; j<=sqrt(num); j++){
//                         if(num % j ==0){
//                             return false;
//                         }
//                     }
//                     return true;

//                 }

//                 public:

//                 PrimeIterator(MagicalContainer &container): container(container){
//                     vector<int> is_prime_vector ={};
//                     for(size_t i = 0; i<container.size(); i++){
//                         if(is_prime(container.get_vector()[i])){
//                             is_prime_vector.push_back(container.get_vector()[i]);
//                         }
//                     }
//                     sort(is_prime_vector.begin(),is_prime_vector.end());

//                     container.set_mystical_elements(is_prime_vector);
//                 }

//                 PrimeIterator begin(){
//                     return PrimeIterator(container);
//                 }
//                 PrimeIterator end(){
//                     PrimeIterator end(container);
//                     end.curr_index = container.size();
//                     return end; 
//                 }




// //Copy constructor
//                 PrimeIterator(const PrimeIterator& other_container) : container(other_container.container){} //Copy constructor

//                 int& operator*() const {
//                     return container.get_vector()[static_cast<vector<int>::size_type>(curr_index)];
//                 }

//                 PrimeIterator operator++(){
//                     // Increment the index
//                     PrimeIterator temp(*this);
//                     curr_index++;
//                     return temp;
//                 }

//                 bool operator==(const PrimeIterator& other) const{
//                     return curr_index == other.curr_index;
//                 }

//                 bool operator!=(const PrimeIterator& other) const{
//                     return !(curr_index == other.curr_index);
//                 }



//                  // Default destructor
//                 ~PrimeIterator() = default;

            

//                 // Copy assignment operator
//                 PrimeIterator& operator=(const PrimeIterator& other) {
//                     if (this != &other){
//                         *this = other.container;
//                     }
                 
//                     return *this;
//                 }

//                 // Move constructor
//                 PrimeIterator(PrimeIterator&& other) noexcept: container(other.container){
//                 }

//                 // Move assignment operator
//                 PrimeIterator& operator=(PrimeIterator&& other) noexcept {
//                     if (this != &other){
//                         *this = other.container;
//                     }

//                     return *this;
//                 }
//             };

//             class SideCrossIterator{
                 
//                 MagicalContainer &container;
//                 int curr_index =0;

//                 public:
//                 SideCrossIterator(MagicalContainer &container): container(container){

//                     int ijk = 0;
//                     size_t beagin = 0;
//                     size_t end = container.get_vector().size()-1;
//                     vector<int> cross ={};
//                     sort(container.get_vector().begin(),container.get_vector().end());

//                     while(beagin <= end){

//                         if (beagin == end){
//                             cross.push_back(container.get_vector()[beagin]);
//                             break;
//                         }
//                         if(ijk % 2 == 0){
//                             cross.push_back(container.get_vector()[beagin]);
//                             beagin++;
//                         }

//                         else{
//                             cross.push_back(container.get_vector()[end] );
//                             end--;
//                         }
//                         ijk++;
//                     }
            
//                               container.set_mystical_elements(cross);
//                 }
          
//                 SideCrossIterator begin(){
//                     return SideCrossIterator(container);
//                 }
//                 SideCrossIterator end(){
//                     SideCrossIterator end(container);
//                     end.curr_index = container.size();
//                     return end;         
//                 }


//             int& operator*() const {
//                 return container.get_vector()[static_cast<vector<int>::size_type>(curr_index)];
//             }

//             SideCrossIterator& operator++(){
//                 // Increment the index
//                 curr_index++;
//                 return *this;
//             }

//             bool operator==(const SideCrossIterator& other) const{
//                 return curr_index == other.curr_index;
//             }


//             ~SideCrossIterator() = default;

//                 // Copy constructor
//                 SideCrossIterator(const SideCrossIterator& other): container(other.container) {
//                     // Copy constructor implementation
//                 }

//                 // Copy assignment operator
//                 SideCrossIterator& operator=(const SideCrossIterator& other) {
//                     if (this != &other){
//                        *this = other.container;
//                     }

//                     return *this;
//                 }

//                 // Move constructor
//                 SideCrossIterator(SideCrossIterator&& other) noexcept : container(other.container){
//                 }

//                 // Move assignment operator
//                 SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {
//                     if (this != &other){
//                        *this = other.container;
//                     }
//                     return *this;
//                 }
//             };
//     }; 
// }

// #pragma once

// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;
// namespace ariel{


//     class MagicalContainer{

//         vector<int> elements = {};


//         public:
//             void set_mystical_elements(vector<int>& container){
//               elements = container;
//             }

//             MagicalContainer(){}

//             void addElement(int num_to_add){
//                 elements.push_back(num_to_add);
//             }

//             void removeElement(int num_to_remove){

//                 for(auto i= elements.begin(); i!=elements.end();i++){

//                     if(*i == num_to_remove){
//                         elements.erase(i);
//                         i--;
//                     }
//                 }
//             }
         
//             int size() {
//                 return static_cast<int>(elements.size());
//             }

//             vector<int>& get_vector(){

//             }

//             ~MagicalContainer()= default; 
//             MagicalContainer (const MagicalContainer &other){}

//             MagicalContainer& operator=(const MagicalContainer& other) {
                   

//             }

//                 // Move constructor
//                 MagicalContainer(MagicalContainer&& other) noexcept {
//                     // Move constructor implementation
//                 }

//                 // Move assignment operator
//                 MagicalContainer& operator=(MagicalContainer&& other) noexcept {
                    

//                 }
                


//         //public:

//             class AscendingIterator{
                 
//                 MagicalContainer &container;
//                 int curr_index = 0;

//                 public:
//                 AscendingIterator(MagicalContainer &container): container(container){
//                     sort(container.get_vector().begin(),container.get_vector().end());
//                 }

//                 AscendingIterator begin(){ //**

//                 }
//                 AscendingIterator end(){ //**
        
//                 }
    
//                     int& operator*() const { //**

//                     }
    

//                     //Destructor
//                     ~AscendingIterator() = default;

//                     // Copy constructor
//                     AscendingIterator(const AscendingIterator& other) :container(other.container){
//                     }

//                     // Copy assignment operator
//                     AscendingIterator& operator=(const AscendingIterator& other) { //**
                        
//                     }

//                         // Move constructor
//                         AscendingIterator(AscendingIterator&& other) noexcept : container(other.container) {
//                         }

//                     // Move assignment operator
//                     AscendingIterator& operator=(AscendingIterator&& other) noexcept { //**
                        
//                     }
                 
         
//                     AscendingIterator operator++(){ //**
                    
//                     }

//                     bool operator==(const AscendingIterator& other_iterator) const { //**

//                     }

//                     bool operator!=(const AscendingIterator& other_iterator) const { //**

//                     }


//             };


//             class PrimeIterator{

//                 int curr_index =0;
//                 MagicalContainer &container;
                
//                 bool static is_prime(int num){ //**
                   

//                 }

//                 public:

//                 PrimeIterator(MagicalContainer &container): container(container){
//                     vector<int> is_prime_vector ={};
//                     for(size_t i = 0; i<container.size(); i++){
//                         if(is_prime(container.get_vector()[i])){
//                             is_prime_vector.push_back(container.get_vector()[i]);
//                         }
//                     }
//                     sort(is_prime_vector.begin(),is_prime_vector.end());

//                     container.set_mystical_elements(is_prime_vector);
//                 }

//                 PrimeIterator begin(){ //**

//                 }
//                 PrimeIterator end(){ //**
                    
//                 }




// //Copy constructor
//                 PrimeIterator(const PrimeIterator& other_container) : container(other_container.container){} //Copy constructor

//                 int& operator*() const { //**
//                 }

//                 PrimeIterator operator++(){ //**
                    
//                 }

//                 bool operator==(const PrimeIterator& other) const{
//                     return curr_index == other.curr_index;
//                 }

//                 bool operator!=(const PrimeIterator& other) const{
//                     return !(curr_index == other.curr_index);
//                 }

//                  // Default destructor
//                 ~PrimeIterator() = default;

//                 // Copy assignment operator
//                 PrimeIterator& operator=(const PrimeIterator& other) { //**
                    
//                 }

//                 // Move constructor
//                 PrimeIterator(PrimeIterator&& other) noexcept: container(other.container){
//                 }

//                 // Move assignment operator
//                 PrimeIterator& operator=(PrimeIterator&& other) noexcept { //**
                    
//                 }
//             };

//             class SideCrossIterator{
                 
//                 MagicalContainer &container;
//                 int curr_index =0;

//                 public:
//                 SideCrossIterator(MagicalContainer &container): container(container){

//                     int ijk = 0;
//                     size_t beagin = 0;
//                     size_t end = container.get_vector().size()-1;
//                     vector<int> cross ={};
//                     sort(container.get_vector().begin(),container.get_vector().end());

//                     while(beagin <= end){

//                         if (beagin == end){
//                             cross.push_back(container.get_vector()[beagin]);
//                             break;
//                         }
//                         if(ijk % 2 == 0){
//                             cross.push_back(container.get_vector()[beagin]);
//                             beagin++;
//                         }

//                         else{
//                             cross.push_back(container.get_vector()[end] );
//                             end--;
//                         }
//                         ijk++;
//                     }
            
//                               container.set_mystical_elements(cross);
//                 }
          
//                 SideCrossIterator begin(){ //**

//                 }
//                 SideCrossIterator end(){ //**
                            
//                 }


//             int& operator*() const {//**

//             }

//             SideCrossIterator& operator++(){ //**
                
//             }

//             bool operator==(const SideCrossIterator& other) const{
//                 return curr_index == other.curr_index;
//             }


//             ~SideCrossIterator() = default;

//                 // Copy constructor
//                 SideCrossIterator(const SideCrossIterator& other): container(other.container) {
//                     // Copy constructor implementation
//                 }

//                 // Copy assignment operator
//                 SideCrossIterator& operator=(const SideCrossIterator& other) {
//                     if (this != &other){
//                        *this = other.container;
//                     }

//                     return *this;
//                 }

//                 // Move constructor
//                 SideCrossIterator(SideCrossIterator&& other) noexcept : container(other.container){
//                 }

//                 // Move assignment operator
//                 SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {
//                     if (this != &other){
//                        *this = other.container;
//                     }
//                     return *this;
//                 }
//             };
//     }; 
// }
