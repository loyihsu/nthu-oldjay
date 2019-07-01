// Problem: http://140.114.86.238/problem/11948/
#include <iostream>

void swap(int *list, int i, int j);
void quicksort(int *list, int low, int high, char order);

int main() {
    int numOfTestSet, lengthOfList, i, *list;
    char order;

    std::cin >> numOfTestSet;
    std::cin >> order;

    while(numOfTestSet--)
    {
        std::cin >> lengthOfList;
        list = new int [lengthOfList];

        for (i = 0; i < lengthOfList; i++)
        {
            std::cin >> list[i];
        }

        quicksort(list, 0, lengthOfList-1, order);

        for (i = 0; i < lengthOfList; i++)
        {
            std::cout << list[i];
            if (i < lengthOfList - 1) std::cout << " ";
            else std::cout << std::endl;
        }

        delete [] list;
    }

    return 0;
}

void swap(int *list, int i, int j)
{
    if (i != j)
    {
        int temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}

void quicksort(int *list, int low, int high, char order)
{
    if (low < high)
    {
        int pivot = list[high];
        int i = low;
        int j = high;

        while (i != j)
        {
            if (order == 'A')
            {
                while (list[i] <= pivot && i < j) i++;
                while (list[j] >= pivot && i < j) j--;
            } else if (order == 'D')
            {
                while (list[i] >= pivot && i < j) i++;
                while (list[j] <= pivot && i < j) j--;
            }
            if (i < j) swap(list, i, j);
        }

        swap(list, high, i);
    }
}