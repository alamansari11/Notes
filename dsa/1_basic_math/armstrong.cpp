                                
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int armstrongBruteForce(int num) {
    int to_compare = num;
    int sum = 0;
    while(num > 0) {
        int temp = num % 10;
        sum += pow(temp,3);
        num = num /10;
    }
    return sum==to_compare;
}

int main() {
    int n1 = 370;
    int result = armstrongBruteForce(n1);
    cout<<result<<endl;
    return 0;
}


                                
                            