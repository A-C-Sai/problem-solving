#include <bits/stdc++.h>
using namespace std;

enum day
{
    mon,
    tue,
    wed
};

typedef int marks;

int main()
{
    // int x, y;
    // cin >> x >> y;
    // cout << "Value of x: " << x << endl
    //      << "Value of y: " << y << endl;

    // marks m1 = 2, m2 = 3;
    // cout << m1 << " " << m2 << endl;

    // day d = (day)mon;

    int A[] = {2, 4, 7, 5, 9};

    for (auto x : A)
    {
        cout << x << endl;
    }

    return 0;
}

/* Data Types

    #################
         Derived
    #################

    1. Array
    2. Pointer
    3. Reference

    #################
       Primitives
    #################

    1. int
        - short       |  short int     | 2 bytes
        - int         |  integer       | 2 bytes
        - long        |  long int      | 4 bytes
        - long long   |  long long int | 8 bytes

    2. char
        - char      | character     | 1 byte
        - wchar_t   | wide char     | 2 bytes
        - char16_t  | unicode char  | 2 bytes
        - char32_t  | unicode char  | 4 bytes

    3. float        | single-precision | 4 bytes
    4. double       | double-precision | 8 bytes
    5. bool         |   true / false   | undefined
    6. void

    #################
      user-defined
    #################

    1. struct
    2. class
    3. enum
    4. union


*/

/* Modifiers

    1. signed - [short/long/long long] int, char
    2. unsigned - [short/long/long long] int, char
    3. long - int, double
    3. short - int

*/

/* Type Qualifiers
    const: Objects of type const cannot be altered during execution. Const objects cannot be modified by your program while it is running.
*/

// overflow - works in a circular fashion

/* Operators

    1. Arthmetic + - * / %
    2. Relational < <= > >= == !=
    3. Logical && || !
    4. Bitwise & | << >> ~ ^
    5. Increment/ Decrement ++ -- [pre/post]
    6. Assignment =
*/

// enum feedback {poor=0,satisfactory=1,good=2,excellent=3};
// feedback = poor;

/* Loops

    1. for
    2. while
    3. do while
    4. for each

*/

// if the sum of the factors of a number is double the number then it is a perfect number

/* Heap Memory Allocation

    int* p;
    p = new int[5];
    delete []p;
    p = nullptr;

*/

/* Reference

    int c = 10, e = 20;
    int &d = c; // now d is an alias for c (l-value / address of c) (reference; doesn't occupy any memory) (points to same location as c) (within the main function it will always point to c, cannot change this)
    cout << &c << " " << d << endl;
    cout << &c << " " << &d << endl;

*/

// functions can be overloaded different number of parameters, different data types of paramentes and different return type. If the number of paramneters and types match but return type is different it will result in a name conflict.

/* Template Functions (generic functions in terms of datatype)
    template <class T, class R>
    T max(T x, R y){
        if (x>y) return x;
        else return y;
    }
*/

// functions can have default parameters
// parameter passing - pass by reference - in-line function
// we can return by reference allowing us to use function on the left hand side of assignment (not sure about use case)