competitive programming
how to convert int to string:-
#include <bits/stdc++.h>
using namespace std;
int main()
{


    int n=25231;
    ostringstream oss;
    oss<<n;
    string s=oss.str();
    cout<<s[1]<<endl;
    return 0;
}
sorting vector using sort():-
#include <bits/stdc++.h>
using namespace std;
int main()
{
vector <int> v;
v.push_back(19);
v.push_back(20);

v.push_back(85);
v.push_back(6);

v.push_back(1);
v.push_back(3);
for(auto i:v)
{

    cout<<i<<" ";
}
cout<<endl;
sort(v.begin(),v.end());
for(auto i:v)
{
    cout<<i<<" ";
}
    return 0;
}
find the count of occurences:-
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int i;
    cin>>i;
    ostringstream s;
    s<<i;
    string s1=s.str();
    int Count=0;
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]=='4')
        {
            Count+=1;
        }
    }
    cout<<Count<<endl;
    return 0;
}
precision of floating point numbers:-
#include <bits/stdc++.h>
using namespace std;
int main()
{
  float a=1.6565;
  //trunc(variable) will delete the digits after "."
  a=trunc(a);
  cout<<a<<endl;
  
  //Floor rounds off the given value to the closest integer which is less than the given value.
    float c=6.3546;
    c=floor(c);
    cout<<c<<endl;
  //Ceil rounds off the given value to the closest integer which is more than the given value.
    float d=3.36954;
    d=ceil(d);
    cout<<d<<endl;
    //Rounds given number to the closest integer.if above 5 greater below 5 smaller
    float e=8.633;
    e=round(e);
    cout<<e<<endl;
    /*if you want to restrict the decimal point in number itself
    than you need to do some math
    a=3.254
    suppose you want only two digit after decimal than
    (a*100)
    and than cast it remove the digits after decimal point
    after that
    a/100
    will give you only two digit after "."
    */
    float f=8.5656;
    f=(trunc(f*100))/100;
    cout<<f<<endl;
    //if you want that 8.5656 to be rounded till 2 decimals just add 0.5
    float g=8.5656;
    g=(trunc(g*100+0.5))/100;
    cout<<g<<endl;
    float b=2.355;
  //fixed will tell you that that there will be fixed number of precisions
  //setpresion(n) will set precision but this will only work in output streams you can not actually  change the floating point with this.
  cout<< fixed << setprecision(1) << b <<endl;
    return 0;
}
Lower bound in c++:-
it gives the iterator to element which is just greater than the value we called for the lower_bound
if element itself is present than it will return the iterator to the element 
and if not present and all the value present in the particular data structure is less than the value we called for the lower_bound than the address of the last +1 will be returned


Input: 10 20 30 40 50
Output: lower_bound for element 30 at index 2

Input: 10 20 30 40 50
Output: lower_bound for element 35 at index 3

Input: 10 20 30 40 50
Output: lower_bound for element 55 at index 5

Input: 10 20 30 30 30 40 50
Output: lower_bound for element 30 at index 2
program:-
// CPP program to illustrate
// std :: lower_bound
#include <bits/stdc++.h>

// Driver code
int main()
{
	// Input vector
	std::vector<int> v{ 10, 20, 30, 30, 30, 40, 50 };

	// Print vector
	std::cout << "Vector contains :";
	for (unsigned int i = 0; i < v.size(); i++)
		std::cout << " " << v[i];
	std::cout << "\n";

	std::vector<int>::iterator low1, low2, low3;

	// std :: lower_bound
	low1 = std::lower_bound(v.begin(), v.end(), 30);
	low2 = std::lower_bound(v.begin(), v.end(), 35);
	low3 = std::lower_bound(v.begin(), v.end(), 55);

    std::cout<<*low1<<std::endl;
    std::cout<<*low2<<std::endl;
    std::cout<<*low3<<std::endl;
	// Printing the lower bounds
	std::cout
		<< "\nlower_bound for element 30 at position : "
		<< (low1 - v.begin());
	std::cout
		<< "\nlower_bound for element 35 at position : "
		<< (low2 - v.begin());
	std::cout
		<< "\nlower_bound for element 55 at position : "
		<< (low3 - v.begin());

	return 0;
}

upper_bound:-
this will give the iterator to the just greater than the element we passed 
either if the element present or not it doesn't care it will just return the 
element greater than it...
// CPP program to illustrate using
// std :: upper_bound with vectors
#include <bits/stdc++.h>

// Driver code
int main()
{
	std::vector<int> v{ 10, 20, 30, 40, 50 };

	// Print vector
	std::cout << "Vector contains :";
	for (int i = 0; i < v.size(); i++)
		std::cout << " " << v[i];
	std::cout << "\n";

	std::vector<int>::iterator upper1, upper2;

	// std :: upper_bound
	upper1 = std::upper_bound(v.begin(), v.end(), 35);
	upper2 = std::upper_bound(v.begin(), v.end(), 45);

	std::cout << "\nupper_bound for element 35 is at position : "
			<< (upper1 - v.begin());
	std::cout << "\nupper_bound for element 45 is at position : "
			<< (upper2 - v.begin());

	return 0;
}
