#include <iostream>
#include <string>
#include <regex>

int main()
{
    // get input
    std::string input = "";
    do
    {
        std::getline(std::cin, input);
    } while (input.empty());

    for (const char &character : input)
    {
        if (character == '+')
        {
            std::cout << " tighten ";
        }
        else if (character == '-')
        {
            std::cout << " loosen ";
        }
        else if (std::regex_match(std::to_string(character), std::regex("4[8-9]|5[0-7]"))) // the ascii reference between '0' and '9'
        {
            std::cout << character << "\n";
        }
        else // character is [A-Z]
        {
            std::cout << character;
        }
    }

    return 0;
}