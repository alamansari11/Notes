int reverse(int n){
    int temp=0;
    while(n>0){
        int last_digit = n%10;
        temp = temp * 10 + last_digit;
        n = n/10;
    }
    return temp;
}
#include <iostream>
using namespace std;
int main()
{
    int n = 1230;
    int result = reverse(n);
    cout<<result<<endl;
    cout<<"Hello World";

    return 0;
}