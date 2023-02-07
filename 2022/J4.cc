#include <iostream>  // std::cin, std::getline
#include <algorithm> // std::sort, std::includes
#include <vector>
#include <string>
#include <unordered_map>

namespace
{
    void print(std::vector<std::vector<std::string>> &input)
    {
        for (auto &i : input)
        {
            for (auto &j : i)
            {
                std::clog << "input: " << j << ' ';
            }
            std::clog << std::endl;
        }
        std::clog << std::endl;
    }
}

int main()
{
    // get input
    int inputCount = 0;

    // same group
    std::cin >> inputCount;
    std::vector<std::vector<std::string>> sameGroup;
    for (int i = 0; i <= inputCount; ++i)
    {
        std::string inputln = "";
        std::getline(std::cin, inputln);
        if (inputln.empty())
        {
            continue;
        }
        int dividerIndex = inputln.find(' ');
        std::string first = inputln.substr(0, dividerIndex);
        std::string second = inputln.substr(dividerIndex + 1, std::string::npos);
        sameGroup.push_back({first, second});
    }
    print(sameGroup);

    // different group
    std::cin >> inputCount;
    std::vector<std::vector<std::string>> differentGroup;
    for (int i = 0; i <= inputCount; ++i)
    {
        std::string inputln = "";
        std::getline(std::cin, inputln);
        if (inputln.empty())
        {
            continue;
        }
        int dividerIndex = inputln.find(' ');
        std::string first = inputln.substr(0, dividerIndex);
        std::string second = inputln.substr(dividerIndex + 1, std::string::npos);
        differentGroup.push_back({first, second});
    }
    print(differentGroup);

    // assigned group
    std::cin >> inputCount;
    std::vector<std::vector<std::string>> assignedGroup;
    for (int i = 0; i <= inputCount; ++i)
    {
        std::string inputln = "";
        std::getline(std::cin, inputln);
        if (inputln.empty())
        {
            continue;
        }
        int firstDividerIndex = inputln.find(' ');
        int secondDividerIndex = inputln.find(' ', firstDividerIndex + 1);
        std::string first = inputln.substr(0, firstDividerIndex);
        std::string second = inputln.substr(firstDividerIndex + 1, secondDividerIndex - firstDividerIndex);
        std::string third = inputln.substr(secondDividerIndex + 1, std::string::npos);
        assignedGroup.push_back({first, second, third});
    }
    print(assignedGroup);

    // main process
    std::unordered_map<int, int> unitViolationCount;

    // find if input meets criteria
    for (auto &currentAssignedGroup : assignedGroup)
    {
        int unitViolationCountIndex = 0;

        // sort input
        std::sort(currentAssignedGroup.begin(), currentAssignedGroup.end());

        // rule: same group
        for (auto &currentSameGroup : sameGroup)
        {
            std::sort(currentSameGroup.begin(), currentSameGroup.end());
            if (std::includes(currentAssignedGroup.begin(), currentAssignedGroup.end(), currentSameGroup.begin(), currentSameGroup.end()) == true)
            {
                unitViolationCount[unitViolationCountIndex]--;
            }
            else
            {
                unitViolationCount[unitViolationCountIndex]++;
            }
            unitViolationCountIndex++;
        }

        // rule: different group
        for (auto &currentDifferentGroup : differentGroup)
        {
            std::sort(currentDifferentGroup.begin(), currentDifferentGroup.end());
            if (std::includes(currentAssignedGroup.begin(), currentAssignedGroup.end(), currentDifferentGroup.begin(), currentDifferentGroup.end()) == false)
            {
                unitViolationCount[unitViolationCountIndex]--;
            }
            else
            {
                unitViolationCount[unitViolationCountIndex]++;
            }
            unitViolationCountIndex++;
        }
    }

    int totalViolationCount = 0;
    for (auto &currentViolationCount : unitViolationCount)
    {
        // inputCount stores the number of assigned groups here
        if (currentViolationCount.second == inputCount)
        {
            totalViolationCount++;
        }
    }
    std::cout << totalViolationCount << std::endl;

    return 0;
}