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
    int x, y;
    cin >> x >> y;
    cout << "Value of x: " << x << endl
         << "Value of y: " << y << endl;

    marks m1 = 2, m2 = 3;
    cout << m1 << " " << m2 << endl;

    day d = (day)mon;

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