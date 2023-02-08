#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace
{
    bool contains(const std::vector<std::vector<int>> &all, const std::vector<int> &key)
    {
        for (const auto &i : all)
        {
            if (std::includes(i.begin(), i.end(), key.begin(), key.end()))
            {
                return true;
            }
        }
        return false;
    }
}

int main()
{
    unsigned short m = 0, n = 0;
    std::cin >> m >> n;

    int rooms[m][n];
    for (unsigned short r = 0; r < m; r++)
    {
        std::string inputln = "";
        do
        {
            std::getline(std::cin, inputln);
        } while (inputln.empty());

        size_t startingIndex = 0;
        for (unsigned short c = 0; c < n; c++)
        {
            size_t endingIndex = inputln.find(' ', startingIndex);
            rooms[r][c] = std::stoi(inputln.substr(startingIndex, endingIndex - startingIndex));
            startingIndex = endingIndex + 1;
        }
    }

    // main process
    // solution: bfs
    std::vector<std::vector<int>> queue = {{1, 1}}; // this queue uses 1 based indexing
    while (queue.size())
    {
        unsigned short r = queue[0][0], c = queue[0][1];

        int product = rooms[r - 1][c - 1];
        std::clog << "product: " << product << "\n";
        for (int firstMultiplier = 1; firstMultiplier <= product; firstMultiplier++)
        {
            if (product % firstMultiplier == 0)
            {
                int secondMultiplier = product / firstMultiplier;

                std::clog << "first multiplier: " << firstMultiplier << "\nsecond multipiler: " << secondMultiplier << "\n\n";
                
                if (firstMultiplier <= m && secondMultiplier <= n && !contains(queue, {firstMultiplier, secondMultiplier}));
                {
                    if (firstMultiplier == m && secondMultiplier == n)
                    {
                        std::cout << "yes";
                        return 0;
                    }
                    queue.push_back({firstMultiplier, secondMultiplier});
                }
            }
        }

        queue.erase(queue.begin());
    }
    std::cout << "no";

    return 0;
}