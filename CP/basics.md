```markdown
### C++ BASICS

**First Day:**

From today onward we are going to learn C++ then STL followed by data structures and algorithm, competitive programming.

#### Why you should choose C++:

C++ provides you with a lot of extra features and speed that other languages don't. It has STL, which is so powerful and gives you a lot of freedom to play around with data structures (inbuilt).

**1) C++: Speed and Extra Features**

**Sample Program:**

```cpp
#include <iostream>
using namespace std;

int main(){
    cout << "hello world";
    return 0;
}
```

`#include` will tell the preprocessor to include the basic input and output stream i.e `<iostream>`.
`using namespace std;` it is saying to use the namespace as `std` to avoid name conflicts that happen a lot.

Now compiler calls a function `main()`. For that, we have to define it first. We have to define it with a data type, mostly `int`, since the function has return type `int`. It has to return `0` or some integer value.

**2) Day 2: Basic Syntax in C++**

- Input/output in C++:
  - Extraction Operator `>>`
  - Insertion Operator `<<`

```cpp
int a;
cin >> a;
cout << a;
```

Using `cin.ignore(numeric_limits::max(),'\n');`: Typing `cin.ignore(numeric_limits::max(),'\n');` after the `cin` statement discards everything in the input stream including the newline.

```cpp
// C++ Code to explain how 
// "cin.ignore(numeric_limits 
// <streamsize>::max(),'\n');" 
// discards the input buffer 
#include<iostream> 

// for <streamsize> 
#include<ios>	 

// for numeric_limits 
#include<limits> 
using namespace std; 

int main() 
{ 
    int a; 
    char str[80]; 

    // Enter input from user 
    // - 4 for example 
    cin >> a; 

    // Discards the input buffer 
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 

    // Get input from user - 
    // GeeksforGeeks for example 
    cin.getline(str, 80); 

    // Prints 4 
    cout << a << endl; 

    // Printing string : This 
    // will print string now 
    cout << str << endl; 

    return 0; 
}
```

In C and C++, there is a problem of input buffer if we use some different function to take input. What happens is after the first input we put enter which will insert `"\n"` into the input stream which will be considered as second input and that's why we don't get the desired result.

Note: `cin.ignore(numeric_limits<streamsize>::max(),'\n'); cin.sync();`


### Operators and Their Precedence in C++

#### Operator Precedence Chart

The table below describes the precedence order and associativity of operators in C / C++. Precedence of operators decreases from top to bottom.


| OPERATOR | DESCRIPTION                                       |ASSOCIATIVITY  |
|----------|---------------------------------------------------|---------------|
| ()       | Parentheses (function call)                       | left-to-right |
| []       | Brackets (array subscript)                        |               |
| .        | Member selection via object name                  |               |
| ->       | Member selection via pointer                      |               |
| ++/--    | Postfix increment/decrement                       |               |
| ++/--    | Prefix increment/decrement                        | right-to-left |
| +/-      | Unary plus/minus                                  |               |
| !~       | Logical negation/bitwise complement               |               |
| (type)   | Cast (convert value to temporary value of type)   |               |
| *        | Dereference                                       |               |
| &        | Address (of operand)                              |               |
| sizeof   | Determine size in bytes on this implementation    |               |
| *, /, %  | Multiplication/division/modulus                   | left-to-right |
| +/-      | Addition/subtraction                              | left-to-right |
| << , >>  | Bitwise shift left, Bitwise shift right           | left-to-right |
| < , <=   | Relational less than/less than or equal to        | left-to-right |
| > , >=   | Relational greater than/greater than or equal to  | left-to-right |
| == , !=  | Relational is equal to/is not equal to            | left-to-right |
| &        | Bitwise AND                                       | left-to-right |
| ^        | Bitwise exclusive OR                              | left-to-right |
| \|       | Bitwise inclusive OR                              | left-to-right |
| &&       | Logical AND                                       | left-to-right |
| \|\|     | Logical OR                                        | left-to-right |
| ?:       | Ternary conditional                               | right-to-left |
| =        | Assignment                                        | right-to-left |
| += , -=  | Addition/subtraction assignment                   |               |
| *= , /=  | Multiplication/division assignment                |               |
| %= , &=  | Modulus/bitwise AND assignment                    |               |
| ^= , \|= | Bitwise exclusive/inclusive OR assignment         |               |
| <<=, >>= | Bitwise shift left/right assignment               |               |
| ,        | Expression separator                              | left-to-right |

#### Loops

**Entry Controlled Loops:**

1) **For Loops:**
```cpp
for (initialization; condition; increment/decrement){
    //statement 
}
```

2) **While Loops:**

```cpp
while(condition){
    //statement
    increment /decrement
}
```

**Exit Controlled Loops:**

1) **Do While Loop:**

```cpp
do{
    //statement
    increment/decrement
}while(condition);
```

**Note:**

- Use `for` loop when the number of iterations is known already.
- Use `while` loop when you are not sure of the number of iterations but the termination condition is known.
- Use `do while` for menu-driven programs: programs in which the loop should run at least one time.

#### Decision Making in C++

1) **If Else:**

```cpp
if (condition){
    //statement;
}
else{
    //statement;
}
```

2) **If Else If:**

```cpp
if(condition){
    //statement;
}
else if {
    //statement;
}
else{
    //some other statement
}
```

A better alternative to nested `if else if` statements is `switch` cases:

```cpp
switch (n){
    case 1:
        // code to be executed if n = 1;
        break;
    case 2:
        // code to be executed if n = 2;
        break;
    default:
        // code to be executed if n doesn't match any cases
}
```

```

```


```markdown
### Functions in C++

#### Syntax:
```cpp
return_type func_name(arguments){
    //statements;
}
```

In functions, we can pass values by using two methods:

1. **Pass by Value:**
   - In this, real values/actual parameters have no effect or no change. The copy of values is stored in the dummy variable or parameters.

2. **Pass by Pointer:**
   - In this, the address of the variable is passed, and therefore whatever operation is performed is directly performed on the actual variable.
   
Example:
```cpp
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 10, b = 20;
    swap(&a, &b);
    cout << a << b << endl;
    return 0;
}
```

3. **Pass by Reference:**
   - In this, the actual variables themselves are passed, not their copies. Changes made inside the function affect the original variables.

Example:
```cpp
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 10, b = 20;
    swap(a, b);
    cout << a << b << endl;
    return 0;
}
```

4. **Pass by Value:**
   - In this, the actual values don't get changed as it does not perform on them.

Example:
```cpp
void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a = 10, b = 20;
    swap(a, b);
    cout << a << b << endl;
    // There will be no effect on the values as the formal parameters get swapped not the actual ones.
    return 0;
}
```

### Arrays in C++

An array is a collection of items of similar types stored at a contiguous location in memory.

The basic declaration of arrays is as follows:
```cpp
data_type arr_name[size] = {values};
```
Example:
```cpp
int arr[3] = {1, 2, 3};
```

### Strings in C++

```cpp
#include <iostream>
using namespace std;

int main(){
    // String in C++
    // Initialization by raw strings
    string str1 = "hello"; // str1("hello")
    // Initialization by existing string
    string str2(str1);
    // Initialization with character by number of occurrences
    string str3(5, '#');

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;
    
    // Gives the length of the string
    cout << str3.length() << endl;

    // Gives the first character of the string
    char c = str3.front();
    cout << c << endl;

    // Appending the string to an existing string
    cout << str3.append("****") << endl;

    // Give the last character of the given character
    char d = str3.back();
    cout << d << endl;

    // Finding the particular text or pattern in the given text
    cout << str3.find('#') << endl;

    // Replacing characters in the given string
    string str4 = "this is a functions";
    str4.replace(2, 8, "ese are strings ");
    cout << str4 << endl;

    return 0;
}
```
**Output:**
```
hello
hello
#####
5
#
#####****
*
0
these are strings functions
```

### Pointers in C++

Pointer is a concept more related to memory. There are two important things related to pointers:

- Dereferencing Operator: `*`
- Referencing Operator: `&`

Pointer Declaration:
```cpp
int *ptr; // It stores the address of another variable, array, structure, class, or function
int var = 10;
ptr = &var;
```

If we want to access the values stored at that particular address through a pointer, we can do the following:
```cpp
printf("%d", *ptr);
```

### Reference in C++

Reference variables are very useful for changing data or we can say that it actually does not create a copy of data, it is the data as if it's just another name.

Example:
```cpp
int x = 10;
int &a = x; // Now we can access the values of x by a also
```
```