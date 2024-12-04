#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <unordered_map>

#include "../../utils/utils.h"

using namespace std;

vector<string> list = getInputLines(2024, 1);
vector<int> numbers1;
vector<int> numbers2;

void init()
{

    numbers1.reserve(list.size());
    numbers2.reserve(list.size());

    for (const auto& line : list)
    {
        istringstream iss(line);
        int val1, val2;
        iss >> val1 >> val2;
        numbers1.push_back(val1);
        numbers2.push_back(val2);
    }
}

void distance()
{

    sort(numbers1.begin(), numbers1.end());
    sort(numbers2.begin(), numbers2.end());

    auto calculate = [](int a, int b)
    { return abs(a - b); };
    int sum = transform_reduce(numbers1.begin(), numbers1.end(), numbers2.begin(), 0, plus<>(), calculate);

    cout << sum << endl;
}

void similarity()
{
    unordered_map<int, int> map;
    for (int num : numbers2)
    {
        map[num]++;
    }

    auto calculate = [&map](int num)
    { return num * map[num]; };

    int sum = transform_reduce(
        numbers1.begin(), numbers1.end(), 0, plus<>(), calculate);

    cout << sum << endl;
}

int main()
{

    init();
    distance();
    similarity();

    return 0;
}
