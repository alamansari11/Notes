#include <iostream>
using namespace std;
int reverse(int n){
    int temp=0;
    while(n>0){
        int last_digit = n%10;
        temp = temp * 10 + last_digit;
        n = n/10;
    }
    return temp;
}

bool palindromeBruteforce(int n){
    return reverse(n)==n;
}
bool palindromeOptimized(int n){
    
    string temp = to_string(n);
    int start = 0;
    int end = temp.size()-1;
    while(start<=end){
        if(temp[start++]!=temp[end--]){
            return false;
        }
    }
    return true;
}
int main()
{
    int n = 112211;
    
    cout<<palindromeBruteforce(n)<<endl;
    cout<<palindromeOptimized(n)<<endl;
    cout<<"Hello World";

    return 0;
}