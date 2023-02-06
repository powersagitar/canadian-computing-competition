#include <iostream>
#include <vector>
#include <string>

namespace
{
    void print(std::vector<std::vector<unsigned>> &input)
    {
        std::cout << "the vector contains:\n";
        for (const auto &i : input)
        {
            for (const auto &j : i)
            {
                std::cout << j << " ";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // get input
    unsigned canvasSide = 0;
    std::cin >> canvasSide;

    unsigned inputCount = 0;
    std::cin >> inputCount;
    std::vector<std::vector<unsigned>> trees;
    for (unsigned i = 0; i < inputCount; i++)
    {
        std::string inputln = "";
        do
        {
            std::getline(std::cin, inputln);
        } while (inputln.empty());

        unsigned divider = inputln.find(' ');
        unsigned y = stoul(inputln.substr(0, divider));
        unsigned x = stoul(inputln.substr(divider + 1));
        
        // coordinates use 0 based indexing
        trees.push_back({x - 1, y - 1});
    }

    print(trees);

    // main process
    if (trees.size() == 0)
    {
        std::cout << canvasSide;
        return 0;
    }

    for (unsigned currentSide = canvasSide; currentSide > 0; currentSide--)
    {
        for (unsigned y = 0; y <= canvasSide - currentSide; y++)
        {
            for (unsigned x = 0; x <= canvasSide - currentSide; x++)
            {
                // check if a tree is in the selection area
                bool treeInSelection = false;
                for (const auto &currentTree : trees)
                {
                    if (currentTree[0] >= x && currentTree[0] < x + currentSide && currentTree[1] >= y && currentTree[1] < y + currentSide)
                    {
                        treeInSelection = true;
                        break;
                    }
                }
                if (treeInSelection == false)
                {
                    std::cout << currentSide;
                    return 0;
                }
            }
        }
    }

    return 0;
}