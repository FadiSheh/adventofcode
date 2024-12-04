#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <numeric>

#include "../../utils/utils.h"

using namespace std;

int main()
{

    vector<string> list = getInputLines(2024, 1);
    vector<int> numbers1;
    vector<int> numbers2;
    numbers1.reserve(list.size());
    numbers2.reserve(list.size());

    for (size_t i = 0; i < list.size(); i++)
    {
        istringstream iss(list[i]);
        int val1, val2;
        iss >> val1 >> val2;
        numbers1.push_back(val1);
        numbers2.push_back(val2);
    }

    sort(numbers1.begin(), numbers1.end());
    sort(numbers2.begin(), numbers2.end());

    auto calculate = [](int a, int b) { return abs(a - b); };
    int sum = transform_reduce(numbers1.begin(), numbers1.end(), numbers2.begin(), 0, plus<>(),calculate);

    cout << sum << endl;
    
    return 0;
}
