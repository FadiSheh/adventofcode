#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

#include "../../utils/utils.h"

using namespace std;

vector<string> list = getInputLines(2024, 2);

bool checkDistance(int a, int b)
{
    int diff = abs(a - b);
    return diff >= 1 && diff <= 3;
}

bool isSafeReport(const vector<int> &report)
{

    bool isIncreasing = report[0] < report.back();

    for (size_t i = 0; i < report.size() - 1; i++)
    {
        if (!checkDistance(report[i], report[i + 1]) || (isIncreasing != (report[i] < report[i + 1])))
        {
            return false;
        }
    }
    return true;
}

bool isSafeWithLevel(const vector<int> &report)
{

    for (size_t i = 0; i < report.size(); i++)
    {

        vector<int> newReport = report;
        newReport.erase(newReport.begin() + i);

        if (isSafeReport(newReport))
        {
            return true;
        }
    }

    return false;
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
        if (isSafeReport(report) || isSafeWithLevel(report))
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
