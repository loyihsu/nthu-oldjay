// function.h
#include <iostream>
#include <string>

using namespace std;

class WordCount
{
public:
    WordCount(){};
    ~WordCount(){};

    /**
    read word into 'words' array
    and count words number 'numberOfTotalWords' at same time
    **/
    void readWords();

    /**
    sort words in the 'words' array in the dictionary order.
    **/
    void sortWords();

    /**
    find out number of different words and store in 'numberOfDiffWords'
    and put different words in string array 'diffwords'

    using the 'diffwords' array to count each words appear times
    and put in 'counting'
    **/
    void countWords();

    /**
    print out the result in format:
    <words><space><appear times>
    **/
    void dumpResult();

private:
    static const int numberOfMaxWords=65536;

    string words[numberOfMaxWords]; ///store the input article
    int numberOfTotalWords;         /// the total number of words

    string *diffwords;     /// store the pointer to different words
    int numberOfDiffWords; /// the number of different words
    int *counting;         /// counts for different words
};
