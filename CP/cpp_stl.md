### C++ STL

So now we are going to learn C++ STL which will ultimately help us achieve what we want to achieve.

**C++ STL:**

Standard Template Library (STL) is all that we need for competitive programming and building logic to the accordance of some tasks. It has four basic components: algorithm, container, iterators.

**Containers:**

Containers give us the ability to create simple as well as complex data structures, which are used to store data in an efficient way.

Following are some common containers:

- vector: replicates arrays
- queue: replicates queues
- stack: replicates stack
- priority_queue: replicates heaps
- list: replicates linked list
- set: replicates trees
- map: associative array

There are four types of containers:

1. **Sequence Container:** These are used when data is in some sort of sequence like arrays, linked lists.
2. **Container Adaptors:** These give different interfaces to the sequence container.
3. **Associative Container:** These are used when data is sorted, such as map, set.
4. **Unordered Associative Containers:** These are used when data is unsorted.

**Pairs in C++ STL:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // Initialization using different ways
    pair<int, int> p;
    p = make_pair(1, 7);
    pair<int, string> p1(3, "hello");
    pair<char, char> p2;
    p2.first = 'a';
    p2.second = 'b';

    // If we don't initialize the pairs then it has 0 for int data type
    pair<string, int> p3;
    pair<int, int> p4(8, 6);

    // Swapping the elements of the pairs
    p4.swap(p);

    // Creating pair of pairs
    pair<pair<string, int>, pair<char, double>> comp = {{"this", 5}, {'c', 33.5}};

    /* To unpack element of the pair we have to use tie() function in order to tie up
    the elements of pairs to different variables */
    int a, b;
    tie(a, b) = p;
    cout << p.first << "  " << p.second << endl;
    cout << p1.first << "  " << p1.second << endl;
    cout << p2.first << "  " << p2.second << endl;
    cout << p3.first << "  " << p3.second << endl;
    cout << p4.first << "  " << p4.second << endl;
    cout << comp.first.first << comp.first.second << "  " << comp.second.second << endl;
    cout << endl;
    cout << a << " " << b << endl;

    return 0;
}
```

**Tuple in C++:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    /* It is more like pairs, just it stores as many values as you want. There may be a situation where
    we can use it */
    tuple<int, char, double> tup(0, 'a', 14.25);
    tuple<int, char, double> tup2(1, 'b', 15.25);
    tuple<int, char, double, string> tup1;

    // make_tuple() is a function to make tuples
    tup1 = make_tuple(1, 'b', 55.5, "hello");

    // get<index>tuple_name is used to access the tuples
    cout << "This is tup  " << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << endl;
    cout << "This is tup1 " << get<0>(tup1) << " " << get<1>(tup1) << " " << get<2>(tup1) << " " << get<3>(tup1) << endl;

    // To find the size of tuple
    cout << tuple_size<decltype(tup)>::value << " " << tuple_size<decltype(tup1)>::value << endl;

    // Swapping the values of tuple
    tup.swap(tup2);
    cout << "This is tup  " << get<0>(tup) << " " << get<1>(tup) << " " << get<2>(tup) << endl;
    cout << "This is tup2 " << get<0>(tup2) << " " << get<1>(tup2) << " " << get<2>(tup2) << endl;

    // There is also tie() function which works the same as in pairs; it is to unpack the values
    int index;
    char a;
    double x;
    tie(index, a, x) = tup;
    cout << "Index " << index << " Character " << a << " Double " << x << endl;

    /* We can also concatenate the tuple by tuple_cat() function. It's pretty awesome.
    If we concatenate 2 tuples of sizes 3, then we get a tuple of size 6 */
    // auto is a keyword to define the data type of the new concatenated tuple
    auto tup4 = tuple_cat(tup1, tup2);
    cout << "The new tuple elements in order are : ";
    cout << get<0>(tup4) << " " << get<1>(tup4) << " ";
    cout << get<2>(tup4) << " " << get<3>(tup4) << " ";
    cout << get<4>(tup4) << " " << get<5>(tup4) << endl;

    return 0;
}
```

**Arrays Container in C++:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    // Static arrays are not used much, still maybe useful due to their predefined classes or functions
    // Initialization: array<data_type, array_size> array_name;
    array<int, 10> arr = {2, 5, 6, 1, 3, 1, 2};

    // Since the array size is 10 and we initialized only 7 values, other indexes will contain zeros 0
    // .at(index) is a method which returns value at the specified index
    cout << arr.at(2) << endl;

    // .front() gives the element at the front
    cout << arr.front() << endl;

    // .back() will return the last element
    cout << arr.back() << endl;

    // .fill() will fill every index with the specified value
    array<int, 10> arr1;
    arr1.fill(1);
    for(int i : arr1){
        cout << i << " ";
    }
    cout << endl;

    // .empty() function will clear the array
    arr1.empty();
    cout << "The size of the array: " << arr1.size() << endl;
    cout << "arr1.begin() will return a pointer to the first element: " << arr1.begin() << endl;
   

 cout << "arr1.end() will return a pointer to the last element: " << arr1.end() << endl;

    return 0;
}
```

**Vectors in C++:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    /* Vectors are dynamic in nature, means it can grow and shrink at runtime */
    // Different initialization
    vector<int> v = {10, 20, 2, 032, 032, 0, 3, 20, 20, 0};
    for(auto i: v){
        cout << i << " ";
    }
    cout << endl;

    // .begin() and .end() are iterators returns beginning and ending of vector
    vector<string> v1(5, "alam");
    for(auto i = v1.begin(); i != v1.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    // Traversing the vectors in reverse manner
    for(auto i = v.rbegin(); i != v.rend(); i++){
        cout << *i << " ";
    }
    cout << endl;

    // Pushing values in vectors
    vector<int> v2;
    for(int i = 0; i < 11; i++){
        v2.push_back(i);
    }

    // Size of vectors
    cout << v2.size() << " is the size of vectors" << endl;

    // Maximum element that can be stored in vector
    cout << v2.max_size() << endl;

    // Remove the last element
    v2.pop_back();

    // Inserting element at beginning
    v2.insert(v2.begin(), 5);

    // We can also access vector as like we do in array 
    // v[3] will give whatever present in the vector index 3

    return 0;
}
```

**List in C++:**

```cpp
#include <bits/stdc++.h>
using namespace std;

/* List is basically a doubly linked list. In list, traversing through the list is very costly,
and insertion and deletion are very quick */
// Traversing through the list and printing
void show_list(list<int> l){
    for(auto i = l.begin(); i != l.end(); i++){
        cout << *i << " ";
    }
    cout << '\n';
}

int main(){
    list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    show_list(l);

    // push_front will add an element to the front
    l.push_front(-1);

    // front() gives you the element at front
    cout << l.front() << endl;

    // push_back will append an element to the back
    l.push_back(11);
    show_list(l);

    // back() will give you the element at back
    cout << l.back() << endl;

    // pop_front() and pop_back() will remove an element from respective location
    l.pop_front();
    l.pop_back();
    show_list(l);

    return 0;
}
```

**Sort Function:**

The default sort function can only sort the things which are defined in that. What if we want to customize the sort function? We can do that by passing the third argument, which will be a function that has the definition of how the sort function should work.

**Maps:**

Program to print the dictionary from a to z:

```cpp
#include <bits/stdc++.h>
using namespace std;

/* Map is like dictionaries in Python */
int main(){
    map<int, string> m;
    int j = 64;
    for(int i = 1; i < 27; i++){
        m[i] = char(j + i);
    }
    for(auto i : m){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
```

**Stacks:**

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(21);
    s.push(22);
    s.push(24);
    s.push(25);
    cout << s.size() << endl;
    cout << s.empty() << endl;
    cout << s.top() << endl;
    while (!s.empty()) {
        cout << ' ' << s.top();
        s.pop();
    }
    cout << endl;
    cout << s.empty() << endl;
    return 0;
}
```

**Queue:**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    q.push(21);
    q.push(22);
    q.push(24);
    q.push(25);
    cout << q.size() << endl;
    cout << q.empty() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;
    while (!q.empty()) {
        cout << ' ' << q.front();
        q.pop();
    }
    cout << endl;
    cout << q.empty() << endl;
    return 0;
}