// Problem: http://140.114.86.238/problem/11844/
#include <iostream>

bool generator(std::string, int);
bool palindrome(std::string);

int main(int argc, const char * argv[]) {
    int n;
    std::string temp;
    
    std::cin >> n;
    std::cin.ignore();
    while (std::getline(std::cin,temp))
        if (generator(temp,n))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    
    return 0;
}

bool palindrome(std::string input)
{
    if (input.empty() || input.size() == 1)
        return true;
    else
        if (input[0] == input[input.size()-1])
            return palindrome(input.substr(1,input.size()-2));
    
    return false;
}

bool generator(std::string str, int n)
{
    if (palindrome(str))
    {
        return true;
    } else {
        if (n > 0)
        {
            for (int i = 0; i < str.size(); i++)
            {
                std::string temp = str;
                temp.erase(temp.begin()+i);
                //std::cout << n << ": " << temp << std::endl;
                if (generator(temp, n-1))
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

