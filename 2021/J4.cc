#include <iostream>
#include <string>
#include <algorithm> // std::swap, std::is_sorted

int main()
{
    std::string input = "";
    std::cin >> input;

    unsigned swapCount = 0;

    while (!std::is_sorted(input.begin(), input.end()))
    {
        for (size_t index = 0; index < input.length(); index++)
        {
            for (size_t swapTarget = index + 1; swapTarget < input.length(); swapTarget++)
            {
                if (input[swapTarget] < input[index])
                {
                    std::swap(input[index], input[swapTarget]);
                    swapCount++;
                }
            }
        }
    }

    std::cout << "output string: " << input << "\n";
    std::cout << "swap count: " << swapCount;

    return 0;
}