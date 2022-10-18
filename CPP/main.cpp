#include <iostream>

class Base
{
 protected:
 static int a;   
 public:
    Base()
    {
        std::cout<< "Base Constructor" << std::endl;
    }

    ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    }

    /* Virtual Functions
    * Dynamic Binding possible only for pointer and reference
    * data types and for member functions that are declared as 
    * virtual in base class
    */
    virtual void b()
    {
        std::cout<<"Base::b()" << std::endl;
    }

    void f()
    {
        std::cout << "f()" << std::endl;
    }
   void f(char c)
    {
        std::cout << "f(char)" << std::endl;
    }
    
};

class Base_1
{
  
 public:
    Base_1()
    {
        std::cout<< "Base_1 Constructor" << std::endl;
    }

    ~Base_1()
    {
        std::cout << "Base_1 Destructor" << std::endl;
    }
};

class Derived : public Base
{
    private:
    Base_1 b1;
 public:
    Derived()
    {
        std::cout << "Derived Constructor" << a << std::endl;
    }

    ~Derived()
    {
        std::cout <<"Derived Destructor" << std::endl;
    }

    void virtual b()
    {
        std::cout << "Derived::b()" << std::endl;
    }
    
    using Base::f;  //unmasking f() and f(char)
    
    //overloading f from Base class which implicitly 
    //masks visibility of f() and f(char) from Base
    void f(int) 
    {
        std::cout << "f(int)" << std::endl;
    }
};

int Base::a = 0;
int main()
{
    Derived D;

    Base* pBase = &D;
    Base& rBase = D;

    pBase->b(); // Dynamic binding
    rBase.b();  // Dynamic binding

    pBase->f();
    //pBase->f(1); // Error
    
    D.f();
    D.f(1);
    D.f('a');
    return(0);
}
