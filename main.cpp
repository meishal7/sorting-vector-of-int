/*
main.cpp 
This program generates random numbers type int and adds numbers in vector in ascending order, then prints the vector in descending order.
Author: Elena Mudrakova
Module: 1
Project: Homework 1

Algorithm: 
Before main()
1. #include <iostream>
  #include <vector> //for using vectors
  #include <cstdlib> //for using rand()
2. Include functions prototypes.
In main()
3. Declare int lenght = 30 (length can be any int)
4. Call generateRand(length)
After main()
5. Declare vector<int> inserting(vector<int> &vec, int n)
    5.1 Set int position = -1
    5.2 Declare int insertingIndex
    5.3 while(position)
        5.3.1 if vector is empty then add number to vector
              Set position = 1
              Set insertingIndex = 0
              Return vector
        5.3.2 Create for-loop
              In for loop:
              5a. if current element less then inserting value, then insert value before current element. Set position to 1, return vector.
        After for loop:
        5.3.3 Push number in vector back (it means above conditions are false and number is less or equal to current element). Position = 1, return vector.
6. Declare void generateRand(int length)
    6.1 Declare vector of int
    6.2 Create for-loop
        In for-loop:
        6a. Generate reandom number in desired range.
        6b. Call inserting(vec, num). Num here is random number that was generated.
    After for-loop:
    6.3 Print vector in descending order using for-loop.
*/
#include <iostream>
#include <vector> //for using vectors
#include <cstdlib> //for using rand()
using namespace std;

//Prototypes
vector<int> inserting(vector<int> &vec, int n);
void generateRand(int length);

int main(){
  int length = 30;
  generateRand(length);

  return 0;
}

//Functions declaration
//A function for inserting int in vector in appropriate position
//in ascending order
vector<int> inserting(vector<int> &vec, int n){
  int position = -1;
  int insertingIndex;
  while(position){
    //If vector is empty then add int to vector
    if(vec.empty()){
        vec.push_back(n);
        insertingIndex = 0;
        position = 1;
        return vec;
    }
    //If vector isn't empty then iterate through vector and find needed position
    for(int i = 0; i<vec.size(); i++){
        if(vec[i] < n){
        auto insertingIndex = vec.begin() + i;
        auto newIt = vec.insert(insertingIndex, n);
        position = 1;
        return vec;
      }
      
      
    }
    //If inserting int is smaller oe equal current element
    //add int to vector back
    vec.push_back(n);
    position = 1;
    return vec;
  }
  
  
  return vec;
}

//A function for generating random number
void generateRand(int length){
  vector<int> vec;
  for(int i=0; i<length; i++){
    int num = rand ()% 10 + 1;
    inserting(vec, num);
  }
  //Printing in descending order
  for(int i=length-1; i>=0; --i){
    cout << vec[i] << " ";
  }

}



