#include <iostream>
#include <vector>
#include <regex>

#include "../../utils/utils.h"

using namespace std;

vector<string> list = getInputLines(2024, 3);

void findMul()
{
    int sum = 0;
    bool calulate = true;
    smatch m;
    regex operation(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");

    for (auto &x : list)
    {
        while (regex_search(x, m, operation))
        {
            if (m[0].str() == "do()")
            {
                calulate = true;
            }
            else if (m[0].str() == "don't()")
            {
                calulate = false;
            }

            else
            {
                if (calulate)
                {
                    sum += stoi(m[1].str()) * stoi(m[2].str());
                }
            }

            x = m.suffix().str();
        }
    }

    cout << sum << endl;
}

int main()
{
    findMul();
    return 0;
}
