#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace
{
    int continuousCount(const std::string &string, size_t startIndex, char target)
    {
        int count = 0;
        for (; string[startIndex] == target; startIndex++, count++);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    // get input
    int inputc = 0;
    std::vector<std::string> inputv;

    std::cin >> inputc;

    for (int i = 0; i < inputc; i++)
    {
        std::string input;
        do
        {
            std::cin >> input;
        } while (input.empty());
        inputv.push_back(input);
    }

    // main
    for (const std::string &string : inputv)
    {
        std::clog << string << "\n";
        
    }

    return 0;
}