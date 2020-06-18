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

void enlargeArray(wordItem *& array, int &size, int scale) {
    // Use a reference to a pointer
    // passing argument as reference so that the original size changes (think of aliasing)

    wordItem *newArray = new wordItem[size*scale];
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    // delete old array
    delete[] array;

    array = newArray;
    size = scale*size;
}

bool isTaboo(std::string &checkWord, std::string checkAgainst[]){
    // check to see if the supplied word is in the list of taboo words

    for (size_t i = 0; i < 50; i++) {
        if (checkWord == checkAgainst[i]){
            return true;
        }
    }
    return false;
}

bool exists(std::string &checkWord, wordItem *& checkIn, int &size){
    for (size_t i = 0; i < size; i++) {
        if (checkWord == checkIn[i].word) {
            return true;
        }
    }
    return false;
}

int findWord(std::string &checkWord, wordItem *& checkIn, int &size){
    int position = 0;
    for (size_t i = 0; i < size; i++) {
        if (checkWord == checkIn[i].word){
            position = i;
            break;
        }
    }
    return position;
}

int getTotal(wordItem *& checkIn, int &wordC){
    // finds total number of unique words

    int total = 0;

    for (size_t i = 0; i < wordC; i++) {
        total = total + checkIn[i].count;
    }
    return total;
}

void sortArray(wordItem *& checkIn, int length){            // CHECKED AND WORKS
    // garbage method of sorting the array. Dont ask questions

    wordItem temp;
    for (size_t i = 0; i < length; i++) {
        for (size_t j = 0; j < length; j++) {
            if (checkIn[i].count > checkIn[j].count) {
                temp = checkIn[j];
                checkIn[j] = checkIn[i];
                checkIn[i] = temp;
            }
        }
    }
}

int main(int argc, char **argv) {
    
    // Threw some errors before so I added this 
    if (argc > 4) {
        return -1;
    }

    int arrayLength = 100;
    int doubledCount = 0;
    int wordCount = 0;

    // Read inputs
    int N = std::stoi(argv[1]);             //ranking start
    std::ifstream refText(argv[2]);         //reference text
    std::ifstream tabooList(argv[3]);       //list of taboo words
    
    // Hold 50 taboo words in string array
    std::string tabooWords[50];
    
    for(int i = 0; i < 50; i++){
        std::getline(tabooList, tabooWords[i]);
    }

    // Create dynamic array for unique words
    wordItem *uniqueWords = new wordItem[arrayLength];

    // Go through the refText. Add unique words to uniqueWords
    while(!refText.eof()){
        std::string holder;
        refText >> holder;
        if (!isTaboo(holder, tabooWords)) {
            if (!exists(holder, uniqueWords, arrayLength))
            {
                uniqueWords[wordCount].word = holder;
                uniqueWords[wordCount].count = 1;
                wordCount ++;
            } else {
                int location = findWord(holder, uniqueWords, arrayLength);
                // std::cout << holder << " " << location << std::endl; // CHECKED AND WORKS
                uniqueWords[location].count++;
            }  
        }
        // If wordCount hits arrayLength, double uniqueWords size
        if (wordCount == arrayLength) {
            enlargeArray(uniqueWords, arrayLength, 2);
            doubledCount++;
        }
    }

    int totalUniques = getTotal(uniqueWords, wordCount);

    // Sort the words in order of descending frequency
    sortArray(uniqueWords, wordCount);
    
    // Print output block of code. Can ignore.
    return 0;
}