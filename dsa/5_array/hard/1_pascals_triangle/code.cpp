#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    if (r == 0 || n == r)
        return 1;
    int ans = 1;
    for (int i = 0; i < r; i++) {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }
    return ans;
}

vector<int> generateRow(int row) {
    vector<int> result;
    long long ans = 1;
    result.push_back(ans);
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        result.push_back(ans);
    }
    return result;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascalsTriangle;
    for (int row = 1; row <= numRows; row++) {
        pascalsTriangle.push_back(generateRow(row));
    }
    return pascalsTriangle;
}

void testVariation1() {
    cout << "Variation 1: Element at Position (r, c)\n";
    vector<pair<pair<int, int>, int>> testCases = {
        {{4, 2}, 6}, {{5, 5}, 1}, {{0, 0}, 1}, {{3, 0}, 1}, {{7, 3}, 35}
    };

    for (auto &testCase : testCases) {
        int r = testCase.first.first;
        int c = testCase.first.second;
        int expected = testCase.second;
        int result = nCr(r, c);
        cout << "Input: (" << r << ", " << c << ") -> Output: " << result 
             << " (Expected: " << expected << ")\n";
    }
    cout << endl;
}

void testVariation2() {
    cout << "Variation 2: n-th Row of Pascal’s Triangle\n";
    vector<pair<int, vector<int>>> testCases = {
        {0, {1}}, {1, {1, 1}}, {4, {1, 4, 6, 4, 1}}, 
        {6, {1, 6, 15, 20, 15, 6, 1}}, {10, {1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1}}
    };

    for (auto &testCase : testCases) {
        int n = testCase.first;
        vector<int> expected = testCase.second;
        vector<int> result = generateRow(n + 1);  // Row is 1-based in function
        cout << "Input: " << n << " -> Output: ";
        for (int val : result) cout << val << " ";
        cout << "(Expected: ";
        for (int val : expected) cout << val << " ";
        cout << ")\n";
    }
    cout << endl;
}

void testVariation3() {
    cout << "Variation 3: First n Rows of Pascal’s Triangle\n";
    vector<pair<int, vector<vector<int>>>> testCases = {
        {1, {{1}}}, 
        {3, {{1}, {1, 1}, {1, 2, 1}}},
        {5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}},
        {0, {}}, 
        {7, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}, {1, 5, 10, 10, 5, 1}, {1, 6, 15, 20, 15, 6, 1}}}
    };

    for (auto &testCase : testCases) {
        int n = testCase.first;
        vector<vector<int>> expected = testCase.second;
        vector<vector<int>> result = generate(n);
        cout << "Input: " << n << " -> Output:\n";
        for (auto &row : result) {
            for (int val : row) cout << val << " ";
            cout << endl;
        }
        cout << "Expected:\n";
        for (auto &row : expected) {
            for (int val : row) cout << val << " ";
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    testVariation1();
    testVariation2();
    testVariation3();
    return 0;
}
