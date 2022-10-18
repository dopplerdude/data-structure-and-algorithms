/*
Function Signature
A function's signature includes the function's name and the number, order and type of its formal parameters.
Two overloaded functions must not have the same signature.
The return value is not part of a function's signature.
These two functions have the same signature:

  int Divide (int n, int m) ; 

  double Divide (int n, int m) ;

For more details visit
https://www.csee.umbc.edu/~chang/cs202.f15/Lectures/modules/m04-overload/slides.php?print#:~:text=Function%20Signature,part%20of%20a%20function's%20signature.

*/


#include <iostream>
using namespace std;

// function overloading
void get_name(string op);
void get_name(string, int, int);
string get_name(string, int);

typedef struct mytype
{
    int a;
    void operator=(const struct mytype&);
}mytype_t;

// operator overloading
mytype_t operator+(const mytype_t&, const mytype_t&);

// operator overloading - unary operators ++, --
mytype_t& operator++(mytype_t&); // pre-increment

mytype_t operator++(mytype_t&, int); // post-increment

/********************************
* Ambigous function overloading
*********************************/
int funa(float) { return (0);}
int funa(float, int p) { return (0);}
int funa(float, int i = 5) { return (1);}

int main(void)
{
    mytype_t x = {.a = 20};
    mytype_t y = {.a = 10};
    mytype_t z = x+y;
    cout<< "z.a = x(20)+y(10)" << z.a << endl;
    ++z;
    cout << "++z = " << z.a << endl;

    x = z++;
    cout << "z++ = " << x.a << endl;
    
    get_name("Hello ");
    cout << get_name("World! ", 2) << endl;
    
    cout << "funa(3.14f) = " << funa(3.14f) << endl; 
    return(0);
}
mytype_t operator+(const mytype_t& a, const mytype_t& b)
{
    mytype_t c;
    c.a = a.a + b.a;
    return c;
}

void mytype_t::operator=(const struct mytype& rhs)
{
    a = rhs.a;
    cout<<"inside assignment operator" << endl;
}

mytype_t& operator++(mytype_t& x) // pre-increment
{
    x.a++;
    return(x);
}

mytype_t operator++(mytype_t& x, int n) // post-increment
{
    mytype_t y = x;
    x.a++;
    return(y);
}


void get_name(string op)
{
    cout << "fun1(void):" << op << endl;
}

string get_name(string ip, int n)
{
    cout << "fun2 :" << ip << endl;
    return ("from fun2");
}
