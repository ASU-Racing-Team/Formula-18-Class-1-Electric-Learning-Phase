# C++ Programming Crash Course
C++ is a double edged sword in embedded applications.
___
## Syntax
Everything in C plus...
### Classes/Struct Object Oriented
Classes and Structs are them same thing in C++, and both are similar to structs in C, sort of.
A Class is a blue print for an **object**, that blue print can specify what attributes (variables with a value) that object has, and what operations can be done on that object.
```C++
#include <iostream>

using namespace std;

class Point{
    public:
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

struct Vector3D {
    public:
    int x;
    int y;
    int z;
    Vector3D(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

int main(void){
    Point p(5, 10);
    Vector3D v(9,8,7);
    cout << p.x <<" "<< p.y << endl;
    cout << v.x << " " << v.y << " " << v.z << endl;
    return 0;
}
```
### Templates
templates is a C++ feature that is intended to replace C MACROS and be more powerful and easier to use, the most basic usage is for templating function to accept different data type as i
```C++

template <class Ty>
myType GetMax (Ty a, Ty b) {
    return (a > b ? a : b);
}

int x,y;
GetMax <int> (x,y);
```
### Lambda Expressions
a Lambda is function that lives inside a scope and can have no name
```C++
    auto glambda = [](auto a, auto b) { return a < b; };
    bool b = glambda(3, 3.14);
```
