```markdown
### OOPs

**Classes:**

Classes in C++ are like blueprints of objects. They are user-defined data types with their own data members and member functions, which can be accessed through instances of classes known as objects.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Vehicles{
public:
    string car, bus, truck;
    void print(){
        cout<<"This is entered vehicles"<<endl;
        cout<<car<<" "<<bus<<" "<<truck<<endl;
    }
};

int main(){
    Vehicles v;
    v.bus = "luxury";
    v.car = "sport";
    v.truck = "imp/exp";
    v.print();
    return 0;
}
```

**Access Modifiers:**

Access modifiers are keywords that define certain rules for classes and functions. They help in achieving data hiding, keeping information hidden from everyone.

these are nothing but only keyword which defines certain rules for the classes and function 
it helps to follow one of the important aspects of programming that is Data hiding 
which helps to keep the information hidden from every one ....

there are three access modifiers namely  
public, private ,protected ....
public:-
in this every data member is acessible to any class or any function
private:-
in this data members are only accesssible to the member function of the class and friend function .....
protected :- 
in this the data members are accesssible to the member function of the same classes and subclasses 
and also friend function ......

```cpp
// Example not provided in the original text
```

**Inheritance:**

Inheritance is the capability of a class to derive properties from other classes. A sub-class inherits properties from a super class.

the capability of class to derive properties from other classes is known as Inheritance 
sub-class :- it is class which inherit properties from superclass..
super class:-this are the classes from which the properties are inherited .....

where inheritance should use?
consider we have to make class of car ,bus,truck , etc 
we have to add function like apply_brake() , fuel(), light()....
so for this we need to write this function in every class individually which is abosolutely a tedious tasks 
hence inheritance comes into picture 
so we can just make a class vehicle which consist of function apply_brake() , fuel (), light().. and than inherit it into class of car, bus ,truck  



```cpp
// Example not provided in the original text
```

**Operator Overloading:**

```cpp
#include <bits/stdc++.h>
using namespace std;
class Complex{
private:
    int re;
    int im;
public:

    Complex(int _re=0,int _im=0):re(_re),im(_im){}
    Complex& operator ++()//preincrement
    {
        ++re;
        ++im;
        return *this;
    }
    Complex& operator++(int);//post-increment
    Complex operator+(Complex &);//binary plus
    friend ostream& operator<<(ostream &,Complex &);//this can also works as global function and member function
    operator int(){
     int s=re+im;
     return s;
    }
    operator double();
};
Complex& Complex::operator++(int)    //we need to use :: before operator because whose operator is we are going to be define should be consider
{
    re++;
    im++;
    return *this; //this is pointer to the  current object and *this is give the object itself
}
Complex Complex::operator+(Complex &q)//binary +operator it works on two operands
{
    Complex p;
    p.re=re+q.re;
    p.im=im+q.im;
    return p;
}
ostream& operator<<(ostream &os,Complex &c)
{
    os<<"real :"<<c.re<<endl;
    os<<"imaginary :"<<c.im<<endl;
    return os;
}
Complex::operator double() /*no need to define return type as (no return  of anything */
{
    double s=re+im+0.00;
    return s;
}
using namespace std;
int main()
{
    Complex c1(55,66);
     cout<<c1;
     cout<<"pre-increment"<<endl;
      ++c1;
     cout<<c1;

    Complex c2(77,88);
    cout<<"post-increment"<<endl;
    c2++;
    cout<<c2;
    cout<<"binary plus"<<endl;
    Complex c3=c1+c2;
   cout<<c3;
int s=c3;
cout<<s<<endl;
double s1=c3;
cout<<s1<<endl;
    return 0;
}
```

**Templates in C++:**

1. Function Templates

```cpp
#include <iostream>
using namespace std;
template <class T>
T maximum(T a,T b)
{
    return(a>b?a:b);
}

int main()
{
    cout<<maximum(1,2);
    return 0;
}
```

2. Class Templates

```cpp
#include <iostream>
using namespace std;
template <class  T>
class Calculator{
private:
    T num1,num2;
public:
    Calculator(T n1,T n2):num1(n1),num2(n2){}
    void display()
    {
    cout<<"Numbers are :"<<num1<<"  "<<num2<<endl;
    cout<<"addition is :"<<add()<<endl;
    cout<<"substract is :"<<sub()<<endl;
    cout<<"division is :"<<div()<<endl;
    cout<<"multiplication is :"<<mul()<<endl;
    cout<<"remainder is :"<<rem()<<endl;
    }
    T add(){return num1+num2;}
    T sub(){return num1-num2;}
    T div(){return num1/num2;}
    T mul(){return num1*num2;}
    T rem();
};
template<class T>
T Calculator<T>::rem()
{
    T res=num1%num2;
    return (res);
}

int main()
{
    Calculator<int> c(1,1);
    c.display();
    return 0;
}
```

**Exceptions in C++:**

```cpp
#include <iostream>
#include <exception>
using namespace std;
class myexception:public exception{};
class myclass{};
void h()
{
    throw myclass();
}
void g()
{
    try
    {
    h();
    }
    catch(int){cout<<"integer"<<endl;}
    catch(double){cout<<"double"<<endl;}
    catch(...){throw;}

}
void f()
{
    try{
    g();
    }
    catch(myexception){cout<<"myexception"<<endl;}
    catch(exception){cout<<"exception"<<endl;}
    catch(...){throw;}
}
int main()
{
    try{
    f();
    }
    catch(...){cout<<"unknown"<<endl;}
    return 0;
}
```

**Function Pointers:**

```cpp
#include <bits/stdc++.h>
using namespace std;
int add(int x,int y){
   return x+y;
}
int sub(int x,int y){
   return x-y;
}
int mul(int x,int y){
   return x*y;
}

int main()
{
   int (*funptr[3])(int,int){add,sub,mul};
 int (*funptr1)(int,int);
    funptr1=add;
   cout<<"this is funptr1 "<<funptr1(7,8)<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<(funptr[i](5,6))<<endl;
    }
    return 0;
}
```
```