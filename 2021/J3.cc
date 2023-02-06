#include <iostream>

int main()
{
    while (true)
    {
        std::string input = "";
        std::cin >> input;

        if (input == "99999")
        {
            break;
        }

        unsigned short sum = input[0] + input[1];
        unsigned short previous = 0; // 0 is right, 1 is left
        
        if (sum == 0)
        {
            switch (previous)
            {
                case 0:
                    std::cout << "right ";
                    break;
                case 1:
                    std::cout << "left ";
                    break;
            }
        }
        else if (sum % 2 == 0) // sum is even
        {
            previous = 0;
            std::cout << "right ";
        }
        else // sum is odd
        {
            previous = 1;
            std::cout << "left ";
        }

        std::cout << input.substr(2) << "\n";
    }

    return 0;
}