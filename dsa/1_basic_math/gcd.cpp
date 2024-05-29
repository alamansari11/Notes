                                
#include <iostream>
#include <algorithm>

using namespace std;

int findGcdBruteForce(int n1, int n2) {
    // Iterate from the minimum of
    // n1 and n2 down to 1
    // Start from the minimum of n1 and n2
    // because the GCD cannot
    // exceed the smaller number
    
    for(int i = min(n1, n2); i > 0; i--) {
        // Check if i is a common
        // factor of both n1 and n2
        if(n1 % i == 0 && n2 % i == 0) {
            // If i is a common factor,
            // return it as the GCD
            return i;
        }
    }
    // If no common factors are found,
    // return 1 (as 1 is always a
    // divisor of any number)
    return 1;
}

int findGcdOptimized(int n1,int n2){
    if(n1==0)return n2;
    if(n2==0) return n1;
    if(n1 > n2){
        return findGcdOptimized(n1-n2,n2);
    }
    else{
        return findGcdOptimized(n1,n2-n1);
    }
    return 1;
}


int main() {
    int n1 = 20, n2 = 15;
    
    // Find the GCD of n1 and n2
    int gcd = findGcdBruteForce(n1, n2);
    int ogcd = findGcdOptimized(n1,n2);

    cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;
    cout << "GCD of " << n1 << " and " << n2 << " is: " << ogcd << endl;

    return 0;
}


                                
                            