#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // get input
    int argc = 0;
    std::vector<std::string> argv;

    std::cin >> argc;
    for (int i = 0; i < argc; i++)
    {
        std::string input;
        do
        {
            std::cin >> input;
        } while (input.empty());

        argv.push_back(input);
    }

    // main
    for (const std::string &string : argv)
    {
        bool prevFirstOccurence = true;

        for (size_t i = 0; i < string.length(); i++)
        {
            if (string[i] == '(')
            {
                size_t closeBracket = string.find(')');
                std::string substr = string.substr(i, closeBracket + 1);
                int count = std::count(string.begin() + i, string.end(), substr);
                std::cout << count << " ";

                continue;
            }
            else if (string[i] == ')')
            {
                std::cout << ") ";

                continue;
            }
            // else
            if (prevFirstOccurence)
            {
                int count = std::count(string.begin() + i, string.end(), string[i]);
                std::cout << count << " ";
                prevFirstOccurence = false;
            }
            std::cout << string[i] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}