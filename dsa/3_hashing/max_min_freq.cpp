// Include the necessary header files
#include <bits/stdc++.h>
using namespace std;

// Function to count the frequency of each element and find the max and min frequency elements
void countFreq(int arr[], int n) {
    // Initialize pairs to store the elements with max and min frequency
    pair<int, int> maxElem = make_pair(arr[0], 0);
    pair<int, int> minElem = make_pair(arr[0], n);
    
    // Create a boolean vector to keep track of visited elements
    vector<bool> isVisited(n, false);

    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        // If the current element is already visited, skip it
        if (isVisited[i] == true) {
            continue;
        }

        // Initialize count for the current element
        int count = 1;

        // Check for the same element in the remaining part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                isVisited[j] = true; // Mark the element as visited
            }
        }

        // Update maxElem if current element has higher frequency
        if (count > maxElem.second) {
            maxElem = make_pair(arr[i], count);
        }

        // Update minElem if current element has lower frequency
        // or if it's the first unvisited element being processed
        if (count < minElem.second) {
            minElem = make_pair(arr[i], count);
        }
    }

    // Print the element with the maximum frequency
    cout << "Max Element: " << maxElem.first << " Frequency: " << maxElem.second << endl;

    // Print the element with the minimum frequency
    cout << "Min Element: " << minElem.first << " Frequency: " << minElem.second << endl;
}

// Main function
int main() {
    // Initialize the array
    int arr[] = {10, 5, 10, 15, 10, 5};
    
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call the function to count the frequency of elements
    countFreq(arr, n);
    
    return 0;
}
