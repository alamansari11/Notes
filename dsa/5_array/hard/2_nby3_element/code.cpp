#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
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

// Time Complexity: O(N2 * log(no. of unique triplets))
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

// Time Complexity: O(NlogN)+O(N2)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int element = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < element) {
                j++;
            } else if (sum > element) {
                k--;
            } else {
                result.push_back({nums[i], nums[j], nums[k]});
                j++; k--;
                while (j < k && nums[j] == nums[j - 1]) j++; // Skip duplicates for j
                while (k > j && nums[k] == nums[k + 1]) k--; // Skip duplicates for k
            }
        }
    }
    return result;
}

void printResults(const vector<vector<int>>& results) {
    for (const auto& triplet : results) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i < triplet.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    if (results.empty()) cout << "No triplets found\n";
    cout << "-------------------\n";
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {},                          // Edge case: empty array
        {0, 0, 0},                   // Edge case: single triplet with all zeroes
        {1, 2, 3, 4, 5},             // No valid triplets
        {-1, 0, 1, 2, -1, -4},       // Mixed positive and negative numbers with duplicates
        {0, -1, 2, -3, 1},           // Normal case with multiple triplets
        {-2, 0, 1, 1, 2},            // Case with duplicates that need to be skipped
        {0, 0, 0, 0, 0},             // All elements are zero
        {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 4}, // Large case with multiple duplicates
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ":\n";
        vector<int> nums = testCases[i];

        cout << "Brute Force Results:\n";
        printResults(threeSumBrute(nums));

        cout << "Better (Set-based) Results:\n";
        printResults(threeSumBetterSet(nums));

        cout << "Optimized Results:\n";
        printResults(threeSum(nums));
    }

    return 0;
}
