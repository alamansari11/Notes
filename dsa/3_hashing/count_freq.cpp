// Include the necessary header files
#include <bits/stdc++.h>
using namespace std;

// Function to count the frequency of each element in the array
void countFreq(int arr[], int n) {
    // Create a boolean vector to keep track of visited elements
    vector<bool> isVisited(n, false);
    
    // Loop through each element in the array
    for(int i = 0; i < n; i++) {
        // If the current element is already visited, skip it
        if(isVisited[i] == true) {
            continue;
        }
        
        // Initialize count for the current element
        int count = 1;
        
        // Check for the same element in the remaining part of the array
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                isVisited[j] = true; // Mark the element as visited
            }
        }
        
        // Print the element and its frequency
        cout << "Element: " << arr[i] << " Frequency: " << count << endl;
    }
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
