#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

/**
 * Input: ./Assignment2 <frequentWords starting at rank N> <readText> <ignoreText>
 * 
 * &a --> gives memory adress of variable a
 * * a --> type to hold the memory addresses 
 * 
 * arrays are basically stored as a pointer
 *  int *a;
    int b[] = {1,2,3};
    a = b;

 * dynamic memory. When memory allocation needs to be changed during runtime
 * example with vector arrays. You want to increase the size of array during run time.
 * cannot predetermine the amount of values to store before compiling.
 **/

struct wordItem
{
    std::string word;
    int count;
};

void arrayDouble(int *& array, int size) {
// Use a reference to a pointer

    int *newArray = new int[size*2];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    // delete old array

    array = newArray;
}

int main(int argc, char **argv){
    // cout << argv[1] << endl;
    // cout << argc <<endl;
    // int N = 10;
    // int *b = new int[N];
    // arrayDouble(b, N);
    
    int arrayLength = 100;
    int doubledCount = 0;

    std::ifstream refText(argv[3]);
    std::ifstream avoidWords(argv[2]);
    std::string avoidWords[50];

    

    // std::cout << sizeof(b) << std::endl;
    
    // std::cout << sizeof(b) << std::endl;
    return 0;
}