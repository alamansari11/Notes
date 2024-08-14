#include <bits/stdc++.h>

using namespace std;

// Function to perform the spiral walk
vector<vector<int>> spiralOrder(int rows, int cols, int rStart, int cStart) {
    int rd = 1, lu = 2;
        vector<vector<int>> result;
        cout<<"entered"<<result.size()<<endl;
        while(result.size() < (rows*cols)){
            int cstartrd = cStart+rd;
            while(cStart <= cstartrd){
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                result.push_back({rStart, cStart});
            }
                cStart++;
            }
            int rStartrd= rStart+rd;
            while(rStart <= rStartrd){
               if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                result.push_back({rStart, cStart});
            }
                rStart++;
            }
            rd = rd+2;
            int cStartlu= cStart-lu;
            while(cStart >= cStartlu){
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                result.push_back({rStart, cStart});
            }
                cStart--;
            }
            int rStartlu = rStart-lu;
            while(rStart >= rStart-lu){
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                result.push_back({rStart, cStart});
            }
                rStart--;
            }
            lu = lu+2;
        }
        return result;
}

int main() {
    // Input values
    // int rows = 5;          // Example value, replace with your input
    // int cols = 6;          // Example value, replace with your input
    // int rStart = 1;        // Example value, replace with your input
    // int cStart = 4;        // Example value, replace with your input
    int rows = 1, cols = 4, rStart = 0, cStart = 0;

    // Call the function
    vector<vector<int>> result = spiralOrder(rows, cols, rStart, cStart);

    // Output the result
    for (const auto &coord : result) {
        cout << "[" << coord[0] << "," << coord[1] << "] ";
    }
    cout << endl;

    return 0;
}
