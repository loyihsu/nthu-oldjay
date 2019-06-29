// Problem: http://140.114.86.238/problem/10673/
#include <iostream>
#include <list>

int main(void)
{   
    std::list<std::string> queue;
    std::string command, temp;
    
    while (std::cin >> command)
    {
        if (command == "Push")
        {
            std::cin >> temp;
            queue.push_back(temp);
        } else if (command == "Pop")
        {
            if (!queue.empty())
                queue.pop_front();
        } else if (command == "Front")
        {
            if (queue.empty())
                std::cout << "empty\n";
            else std::cout << queue.front() << "\n";
        }
    }
}