#include <iostream>  // std::cin, std::getline
#include <algorithm> // std::sort, std::includes
#include <vector>
#include <string>
#include <unordered_map>

namespace
{
    void print(const std::vector<std::vector<std::string>> &input)
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

    void print(const std::vector<std::string> &input)
    {
        for (auto &i : input)
        {
            std::clog << i << " ";
        }
        std::clog << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

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

        std::vector<std::string> assembler = {first, second};
        std::sort(assembler.begin(), assembler.end());

        sameGroup.push_back(assembler);
    }
    // print(sameGroup);

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

        std::vector<std::string> assembler = {first, second};
        std::sort(assembler.begin(), assembler.end());

        differentGroup.push_back(assembler);
    }
    // print(differentGroup);

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
        std::string second = inputln.substr(firstDividerIndex + 1, secondDividerIndex - firstDividerIndex - 1);
        std::string third = inputln.substr(secondDividerIndex + 1, std::string::npos);

        // std::clog << "first: " << first << "\n"
        //           << "second: " << second << "\n"
        //           << "third: " << third << "\n";

        std::vector<std::string> assembler = {first, second, third};
        std::sort(assembler.begin(), assembler.end());

        assignedGroup.push_back(assembler);
    }
    // print(assignedGroup);

    // main process
    std::unordered_map<int, int> unitViolationCount;
    unsigned totalViolationCount = 0;

    // find if input meets criteria
    for (auto &currentAssignedGroup : assignedGroup)
    {
        int unitViolationCountIndex = 0;

        // std::clog << "\ngroup:\n";
        // print(currentAssignedGroup);

        // rule: same group
        for (auto &currentSameGroup : sameGroup)
        {
            // std::clog << "current rule:\n";
            // print(currentSameGroup);

            if (std::includes(currentAssignedGroup.begin(), currentAssignedGroup.end(), currentSameGroup.begin(), currentSameGroup.end()) == true)
            {
                // std::clog << "unit violation count of " << unitViolationCountIndex << " change: -1\n";
                unitViolationCount[unitViolationCountIndex]--;
            }
            else
            {
                // std::clog << "unit violation count of " << unitViolationCountIndex << " change: +1\n";
                unitViolationCount[unitViolationCountIndex]++;
            }
            unitViolationCountIndex++;
        }

        // rule: different group
        for (auto &currentDifferentGroup : differentGroup)
        {
            // std::clog << "current rule:\n";
            // print(currentDifferentGroup);

            if (std::includes(currentAssignedGroup.begin(), currentAssignedGroup.end(), currentDifferentGroup.begin(), currentDifferentGroup.end()) == true)
            {
                totalViolationCount++;
            }
        }
    }

    for (auto &currentViolationCount : unitViolationCount)
    {
        // inputCount stores the number of assigned groups here
        if (currentViolationCount.second == inputCount)
        {
            totalViolationCount++;
        }
    }
    std::cout << totalViolationCount;

    return 0;
}