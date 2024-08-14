/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
void recur1toN(int n)
{
    if(n>1){
        recur1toN(n-1);
    }
    cout<<n<<endl;
}
void recurNto1(int n)
{
    if(n==0){
        return;
    }
    cout<<n<<endl;
    recurNto1(n-1);
}
int sum1toN(int n,int sum)
{
    if(n==0){
        return sum;
    }
    sum +=n;
    return sum1toN(n-1,sum);
}
int sum1toNanother(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n + sum1toNanother(n-1);
}
int factorial(int n)
{
    if(n<1){
        return 1;
    }
    return n * factorial(n-1);
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reverseArray(int arr[],int i,int n)
{
    if(i<n){
        swap(arr[i],arr[n]);
        reverseArray(arr,i+1,n-1);
    }
    return;
}
bool checkStringPalindrome(string s,int i)
{
    if(i>=s.length()/2) return true;
    if(s[i]!=s[s.length()-1-i]) return false;
    return checkStringPalindrome(s,i+1);
}
int fibonacci(int n){
    if(n==1 or n==0){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
int main()
{
    // recur1toN(5);
    // recurNto1(5);
    // cout<<sum1toN(5,0);
    // cout<<sum1toNanother(5);
    // cout<<factorial(5);
    
    // int arr[]={1,2,3,4,5};
    // reverseArray(arr,0,4);
    // printArray(arr,5);
    
    // string s = "aa";
    // cout<<checkStringPalindrome(s,0)<<endl;
    
    // cout<<fibonacci(4)<<endl;
    
    

    return 0;
}
