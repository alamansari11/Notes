#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSumBrute(vector<int> &nums, int target)
{

    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                for (int l = k + 1; l < nums.size(); l++)
                {
                    long long sum = static_cast<long long>(nums[i]) +
                                    static_cast<long long>(nums[j]) +
                                    static_cast<long long>(nums[k]) +
                                    static_cast<long long>(nums[l]);
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k],
                                            nums[l]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> result(s.begin(), s.end());
    return result;
}

vector<vector<int>> fourSumBetter(vector<int> &nums, int target)
{

    set<vector<int>> s;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            set<long long> hashSet;
            for (int k = j + 1; k < nums.size(); k++)
            {

                long long sum = static_cast<long long>(nums[i]) +
                                static_cast<long long>(nums[j]);
                sum += static_cast<long long>(nums[k]);
                long long tofind = target - sum;
                if (hashSet.find(tofind) != hashSet.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k],
                                        int(tofind)};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                hashSet.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> result(s.begin(), s.end());
    return result;
}

vector<vector<int>> fourSumOptimal(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        result.push_back(temp);
                        k++;
                        l--;
                        while (k < l and nums[k] == nums[k - 1])
                            k++;
                        while (l > k and nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }

        return result;
    }
int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSumBrute(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
