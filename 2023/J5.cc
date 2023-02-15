#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace
{
    void print(const std::vector<std::vector<char>> &input)
    {
        for (const auto &i : input)
        {
            for (const auto &j : i)
            {
                std::cout << j << " ";
            }
            std::cout << "\n";
        }
        std::cout << "done\n";
    }

    bool includes(const std::vector<char> &list, const std::string &target)
    {
        size_t targetLength = target.length();
        for (size_t i = 0; i <= list.size() - targetLength; i++)
        {
            if (std::includes(list.begin() + i, list.end(), target.begin(), target.end()))
            {
                return true;
            }
        }
        return false;
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);

    // input
    std::string target;
    int r = 0, c = 0;
    std::cin >> target >> r >> c;

    std::vector<std::vector<char>> graph;
    for (int i = 0; i < r; i++)
    {
        std::vector<char> assembler;
        std::string inputln;
        do
        {
            std::getline(std::cin, inputln);
        } while (inputln.empty());

        // if encounter performance issues
        // refer to J4.cc
        for (int j = 0; j < (c * 2) - 1; j += 2)
        {
            assembler.push_back(inputln[j]);
        }
        graph.push_back(assembler);
    }

    // print(graph);

    // main
    int h = 0;
    std::string reverse = target;
    std::reverse(reverse.begin(), reverse.end());

    for (const auto &i : graph)
    {
        if (includes(i, target) || includes(i, reverse))
        {
            h++;
        }
    }

    std::cout << h;

    return 0;
}