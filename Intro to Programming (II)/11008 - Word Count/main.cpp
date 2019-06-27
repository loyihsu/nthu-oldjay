// main.cpp
#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    WordCount wc;

    wc.readWords();
    wc.sortWords();
    wc.countWords();
    wc.dumpResult();

    return 0;
}
