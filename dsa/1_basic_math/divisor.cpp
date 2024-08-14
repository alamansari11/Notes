#include <iostream>   // Include the iostream library for input and output operations
#include <algorithm>  // Include the algorithm library (not used in this example but can be useful for other algorithms)
#include <cmath>      // Include the cmath library for mathematical functions like sqrt
#include <vector>     // Include the vector library to use the vector container

using namespace std;  // Use the standard namespace to avoid prefixing std:: before standard library names

// Function to find all divisors of a number using an efficient method
vector<int> divisorsEfficient(int &num) {
    vector<int> v1;              // Vector to store the divisors
    int sqroot = sqrt(num);      // Calculate the square root of the number to limit the loop
    for (int i = 1; i <= sqroot; i++) {  // Loop from 1 to the square root of the number
        if (num % i == 0) {      // If 'i' is a divisor of 'num'
            v1.push_back(i);     // Add 'i' to the vector
            if (i != (num / i)) {// If 'i' is not equal to the quotient (to avoid duplicates)
                v1.push_back(num / i); // Add the quotient to the vector
            }
        }
    }
    return v1;                   // Return the vector containing all divisors
}

// Function to find all divisors of a number using a brute-force method
vector<int> divisorsBruteForce(int &num) {
    vector<int> v1;              // Vector to store the divisors
    for (int i = 1; i <= num; i++) { // Loop from 1 to the number itself
        if (num % i == 0) {      // If 'i' is a divisor of 'num'
            v1.push_back(i);     // Add 'i' to the vector
        }
    }
    return v1;                   // Return the vector containing all divisors
}

int main() {
    int n1 = 36;                     // Define an integer variable 'n1' and initialize it with 36
    vector<int> result = divisorsEfficient(n1); // Call the efficient divisors function and store the result in 'result'
    
    // Loop through the vector 'result' and print each divisor
    for (auto i : result) {
        cout << i << " ";          // Print each divisor followed by a space
    }
    cout << endl;                  // Print a newline at the end
    return 0;                      // Return 0 to indicate successful execution
}
