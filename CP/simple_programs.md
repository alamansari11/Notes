```markdown
### BASIC C++ PROGRAMS

**BASIC LOGICS OF PROGRAM:**

This article is about some basic programs with all the logic behind it.

**Leap Year Finder:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    /* Since a leap year comes after every four years, 
    it should be divisible by four and should not 
    be a century year, that is, it should not be divisible by 100
    or simply it should be divisible by 400 */

    while(true){
        int year;
        cin>>year;
        if(year%4==0 and year%100!=0){
            cout<<"Leap year"<<endl;
        }
        else if(year%400==0){
            cout<<"Leap year"<<endl;
        }
        else{
            cout<<"Not a leap year"<<endl;
        }
    }
    return 0;
}
```

**Prime Number:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    while(true){
        bool isPrime = true;
        int num;
        cout<<"Enter a positive number"<<endl;
        cin>>num;

        // 0 and 1 are not primes
        if(num < 2){
            isPrime = false;
        }
        else{
            int x = sqrt(num);
            for(int i = 2; i <= x; i++){
                if(num%i == 0){
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime){
            cout<<num<<" is a prime number"<<endl;
        }
        else{
            cout<<num<<" is not a prime number"<<endl;
        }
    }
    return 0;
}
```

**Vowels:**

```cpp
#include <iostream>
using namespace std;

int main(){
    char c;
    do{
        cout<<"Enter a character or enter zero to exit"<<endl;
        cin>>c;

        // The below expressions evaluate to 1 if c is one of the vowels
        int isLower = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        int isUpper = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

        // isalpha() is an inbuilt library function which will return true if it is an alphabet
        if(!isalpha(c) && c != '0'){
            cout<<"Please enter a valid character"<<endl;
        }
        else if(isLower || isUpper){ // If either one of these evaluates to 1 then we go inside
            cout<<c<<" is a vowel"<<endl;
        }
        else if(c != '0'){ // If it is not a vowel and not to exit the program, then it must be a consonant
            cout<<c<<" is a consonant"<<endl;
        }
    }while(c != '0'); // To make it a menu-driven program

    return 0;
}
```

**Reverse the Number:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = 1234;
    int rev = 0;
    while(num > 0){
        int temp = num % 10; // Storing the last digit
        rev = rev * 10 + temp; // Adding it to the rev 
        num = num / 10; // Truncate the last digit
    }
    cout<<rev;

    return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int start = 0;
    int End = s.length() - 1;
    while(start <= End){
        char temp = s[start];
        s[start] = s[End];
        s[End] = temp;
        start++;
        End--;
    }
    cout<<s<<endl;
    return 0;
}