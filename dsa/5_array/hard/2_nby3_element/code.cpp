#include <bits/stdc++.h>
using namespace std;

// tc: O(n^2) sc: O(1)
vector<int> majorityElementBrute(vector<int>& v) {
    vector<int> result;
    for (int i = 0; i < v.size(); i++) {
        if (result.size() == 0 || result[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < v.size(); j++) {
                if (v[i] == v[j]) {
                    cnt++;
                }
            }
            if (cnt > (v.size() / 3)) {
                result.push_back(v[i]);
            }
            if (result.size() == 2)
                break;
        }
    }
    return result;
}

// tc: O(n) sc: O(n)
vector<int> majorityElementBetter(vector<int>& v) {
    unordered_map<int, int> um;
    for (auto i : v) {
        um[i]++;
    }
    vector<int> result;
    for (auto i : um) {
        if (i.second > (v.size() / 3)) {
            result.push_back(i.first);
            if (result.size() == 2)
                break;
        }
    }
    return result;
}

// tc : O(n)
vector<int> majorityElementOptimalMooreVotingExtended(vector<int>& v) {
    int cnt1 = 0, cnt2 = 0, elem1 = INT_MIN, elem2 = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        if (cnt1 == 0 && v[i] != elem2) {
            elem1 = v[i];
            cnt1++;
        } else if (cnt2 == 0 && v[i] != elem1) {
            elem2 = v[i];
            cnt2++;
        } else if (v[i] == elem1)
            cnt1++;
        else if (v[i] == elem2)
            cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    vector<int> result;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == elem1)
            cnt1++;
        if (v[i] == elem2)
            cnt2++;
    }
    if (cnt1 > v.size() / 3)
        result.push_back(elem1);
    if (cnt2 > v.size() / 3)
        result.push_back(elem2);
    return result;
}

void testFunctions() {
    vector<vector<int>> testCases = {
        {3, 2, 3},              // Simple case, one majority element
        {1},                    // Single element
        {1, 2, 3},              // No majority elements
        {1, 1, 1, 2, 3, 4, 5},  // One majority element
        {1, 2, 2, 3, 3, 3, 3},  // One majority element with multiple occurrences
        {1, 1, 1, 2, 2, 2, 3},  // Two majority elements
        {},                     // Empty array
        {1, 1, 1, 1, 1},        // All elements are the same
    };

    for (auto& testCase : testCases) {
        cout << "Input: [";
        for (size_t i = 0; i < testCase.size(); i++) {
            cout << testCase[i] << (i + 1 < testCase.size() ? ", " : "");
        }
        cout << "]\n";

        auto bruteResult = majorityElementBrute(testCase);
        auto betterResult = majorityElementBetter(testCase);
        auto optimalResult = majorityElementOptimalMooreVotingExtended(testCase);

        cout << "Brute Force Output: [";
        for (size_t i = 0; i < bruteResult.size(); i++) {
            cout << bruteResult[i] << (i + 1 < bruteResult.size() ? ", " : "");
        }
        cout << "]\n";

        cout << "Better Output: [";
        for (size_t i = 0; i < betterResult.size(); i++) {
            cout << betterResult[i] << (i + 1 < betterResult.size() ? ", " : "");
        }
        cout << "]\n";

        cout << "Optimal Output: [";
        for (size_t i = 0; i < optimalResult.size(); i++) {
            cout << optimalResult[i] << (i + 1 < optimalResult.size() ? ", " : "");
        }
        cout << "]\n\n";
    }
}

int main() {
    testFunctions();
    return 0;
}
