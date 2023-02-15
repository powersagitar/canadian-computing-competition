#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace
{
    int continuousCount(const std::string &string, size_t startIndex, const char &target)
    {
        int count = 0;
        for (; string[startIndex] == target; startIndex++, count++)
        {
        }
        return count;
    }

    int continuousCount(const std::string &string, size_t startIndex, const std::string &target)
    {
        int count = 0;
        size_t length = target.length();
        for (; string.substr(startIndex, length) == target; startIndex += length, count++)
        {
        }
        return count;
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
        // std::clog << string << "\n";

        std::string substr;
        for (size_t i = 0; i < string.length(); i++)
        {
            if (string[i] == '(')
            {
                size_t closeBracket = string.find(')', i);
                std::string tmpSubstr = string.substr(i, closeBracket - i + 1);

                // only execute the first occurrence of the substring in a duplication
                if (!(tmpSubstr != substr))
                {
                    continue;
                }

                substr = tmpSubstr;
                int count = continuousCount(string, i, substr);
                std::cout << count << " ( ";

                continue;
            }
        }
    }

    return 0;
}