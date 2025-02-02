#include <math.h>
#include <algorithm>
#include <bitset>
#include <chrono>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
template <typename T>
inline void inspect(T& t) {
    typename T::iterator i1 = t.begin(), i2 = t.end();
    while (i1 != i2) {
        std::cout << (*i1) << ' ';
        i1++;
    }
    std::cout << '\n';
}

/////////////////////////////////////////////////////////////
using namespace std;

/*
Generating k integers less than n without duplicates
*/

vector<int> uniqueRandom(const int& k,
                         const int& n) {  // create k unique random integer
    // ranging from 0 to n-1 inclusive
    if (k > n) {
        throw runtime_error("invalid k value: k has to be less than n");
    }

    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<int> nums;
    nums.reserve(n);

    for (int i = 0; i < n; ++i) {  
		// first initialize full range of integers in a vector
        nums.push_back(i);
    }

    for (int i = 0; i < k; ++i) {  
		// while moving forward in the vector,
        // randomly swap ith number with another
        // integer in nums[i+1, n)
        int j = rand() % (n - i);
        swap(nums[i], nums[i + j]);
    }
    // only return the first k elements
    return vector<int>(nums.begin(), nums.begin() + k);
}

int main() {
    vector<int> r = uniqueRandom(10, 100);
    inspect<vector<int>>(r);

    return 0;
}
