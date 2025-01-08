#include <bits/stdc++.h>
using namespace std;

// Function declarations
vector<vector<int>> threeSumBrute(vector<int>& nums);
vector<vector<int>> threeSumBetterSet(vector<int>& nums);
vector<vector<int>> threeSum(vector<int>& nums);

void printResult(const vector<vector<int>>& result) {
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i != triplet.size() - 1) cout << ", ";
        }
        cout << "] ";
    }
    cout << endl;
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {}, // Edge case: empty input
        {0}, // Edge case: single element
        {0, 0}, // Edge case: two elements
        {0, 0, 0}, // Edge case: all zeroes
        {-1, 0, 1, 2, -1, -4}, // Typical case
        {-2, 0, 0, 2, 2}, // Case with duplicates
        {-5, -1, -1, 0, 1, 2, 3, 4}, // Case with negatives and positives
        {1, 1, 1, 1, 1}, // Edge case: all positive numbers
        {-1, -1, -1, -1, -1}, // Edge case: all negative numbers
        {-10, -7, -3, 2, 4, 8, 10} // Case with large range of numbers
    };

    // Test each function
    cout << "Testing threeSumBrute:\n";
    for (const auto& testCase : testCases) {
        vector<int> nums = testCase;
        vector<vector<int>> result = threeSumBrute(nums);
        printResult(result);
    }

    cout << "\nTesting threeSumBetterSet:\n";
    for (const auto& testCase : testCases) {
        vector<int> nums = testCase;
        vector<vector<int>> result = threeSumBetterSet(nums);
        printResult(result);
    }

    cout << "\nTesting threeSum:\n";
    for (const auto& testCase : testCases) {
        vector<int> nums = testCase;
        vector<vector<int>> result = threeSum(nums);
        printResult(result);
    }

    return 0;
}

// Implementations of the functions
vector<vector<int>> threeSumBrute(vector<int>& nums) {
    set<vector<int>> s;
    int element = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == element) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

vector<vector<int>> threeSumBetterSet(vector<int>& nums) {
    set<vector<int>> s;
    int element = 0;
    for (int i = 0; i < nums.size(); i++) {
        set<int> hashSet;
        for (int j = i + 1; j < nums.size(); j++) {
            int target = element - (nums[i] + nums[j]);
            if (hashSet.find(target) != hashSet.end()) {
                vector<int> temp = {nums[i], nums[j], target};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int element = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < element) {
                j++;
            } else if (sum > element) {
                k--;
            } else {
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (k > j && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return result;
}
