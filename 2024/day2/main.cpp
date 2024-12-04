#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

#include "../../utils/utils.h"

using namespace std;

vector<string> list = getInputLines(2024, 2);

bool distance(int a, int b, bool isIncreased)
{
    int val = a - b;
    return ((isIncreased && val < 0) || (!isIncreased && val > 0)) && abs(val) < 4;
}

bool isIncreased(int a, int b)
{
    return a < b;
}

void isSafe()
{

    vector<vector<int>> reports;
    reports.reserve(list.size());

    for (const auto &line : list)
    {
        vector<int> values;
        istringstream iss(line);
        int val;

        while (iss >> val)
        {
            values.push_back(val);
        }

        reports.push_back(move(values));
    }

    int sum = 0;

    for (const auto &report : reports)
    {

        bool isIncreasing = isIncreased(report[0], report.back());
        bool isSafe = true;

        for (size_t i = 0; i < report.size() - 1; i++)
        {
            if (!distance(report[i], report[i + 1], isIncreasing))
            {
                isSafe = false;
                break;
            }
        }

        if (isSafe)
        {
            sum++;
        }
    }

    cout << sum << endl;
}

int main()
{

    isSafe();

    return 0;
}
