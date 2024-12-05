#include <iostream>
#include <vector>
#include <regex>

#include "../../utils/utils.h"

using namespace std;

vector<string> list = getInputLines(2024, 3);

void findMul()
{

    int sum = 0;
    regex operation(R"(mul\((\d+),(\d+)\))");

    for (const auto &x : list)
    {

        std::sregex_iterator begin(x.begin(), x.end(), operation);
        std::sregex_iterator end;

        for (std::sregex_iterator it = begin; it != end; ++it)
        {
            std::smatch match = *it;
            sum += stoi(match[1]) * stoi(match[2]);
        }
    }

    cout << sum << endl;
}

int main()
{
    findMul();
    return 0;
}
