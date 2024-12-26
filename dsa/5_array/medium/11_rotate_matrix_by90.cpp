#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void rotateOptimal(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    void rotateBrute(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int tempRow = 0, tempCol=0;
        vector<vector<int>> newMatrix(row, std::vector<int>(col, 0));
        for(int rowI = row-1;rowI>=0;rowI--)
        {
            tempRow=0;
            for(int colI=0;colI<col;colI++)
            {
                newMatrix[tempRow][tempCol] = matrix[rowI][colI];
                tempRow++;
            }
            tempCol++;
        }
        matrix = newMatrix;
    }

};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void runTestCases() {
    Solution solution;

    // Test Case 1: Single Element Matrix
    vector<vector<int>> matrix1 = {{1}};
    cout << "Test Case 1: Single Element Matrix" << endl;
    solution.rotateBrute(matrix1);
    printMatrix(matrix1);

    // Test Case 2: 2x2 Matrix
    vector<vector<int>> matrix2 = {{1, 2}, {3, 4}};
    cout << "\nTest Case 2: 2x2 Matrix" << endl;
    solution.rotateBrute(matrix2);
    printMatrix(matrix2);

    // Test Case 3: 3x3 Matrix
    vector<vector<int>> matrix3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "\nTest Case 3: 3x3 Matrix" << endl;
    solution.rotateBrute(matrix3);
    printMatrix(matrix3);

    // Test Case 4: 4x4 Matrix
    vector<vector<int>> matrix4 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    cout << "\nTest Case 4: 4x4 Matrix" << endl;
    solution.rotateBrute(matrix4);
    printMatrix(matrix4);

    // Test Case 5: Invalid (Non-square matrix)
    vector<vector<int>> matrix5 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "\nTest Case 5: Rectangular Matrix (Invalid for Rotation)" << endl;
    try {
        solution.rotateBrute(matrix5);
        printMatrix(matrix5);
    } catch (const exception& e) {
        cout << "Error: Non-square matrix cannot be rotated. " << e.what() << endl;
    }
}

int main() {
    runTestCases();
    return 0;
}
