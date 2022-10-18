#include <iostream>

class A
{
    int data;
    public:
    A(int val):data(val){}
    void set(int val) { data = val;}
    void print(){ std::cout << data << std::endl;}
};
const A global_a(333);


const int global = 100;
int main()
{
    const int local = 25;
    int *p = const_cast<int*>(&local);
    *p = 50;
    std::cout << local << " " << *p << std::endl;

    int* q = const_cast<int*>(&global);  
    //*q = 200;// Segmentation fault writing global const object
    std::cout << global << " " << *q << std::endl;

    
    const A a(555);
    const_cast<A&>(a).set(666);
    const_cast<A&>(a).print();

    const_cast<A&>(global_a).set(777);  //INTERESTING !!! Did not produce segmentation fault
    const_cast<A&>(global_a).print();

/* Static_cast and reinterpret_cast */
    int i = 10;
    double d = 20.5;
    double* pd = &d;

    // i = d; //warning
    // i = (int)d; // okay C-style casting
    i = static_cast<int>(d);
    std::cout << i << std::endl;

    /*An object pointer (including void*) or function pointer can be converted to an integer type using reinterpret_cast.
     This will only compile if the destination type is long enough. 
     The result is implementation-defined and typically yields the numeric address of the byte in memory that 
     the pointer pointers to.    
    Typically, long or unsigned long is long enough to hold any pointer value, but this is not guaranteed by 
    the standard.
    C++11
    If the types std::intptr_t and std::uintptr_t exist, they are guaranteed to be long enough to hold a void* 
    (and hence any pointer to object type). 
    However, they are not guaranteed to be long enough to hold a function pointer.
        
    Similarly, reinterpret_cast can be used to convert an integer type into a pointer type. 
    Again the result is implementation-defined, 
    /but a pointer value is guaranteed to be unchanged by a round trip through an integer type. 
    The standard does not guarantee that the value zero is converted to a null pointer.*/

    //i = pd; // implicit error
    //i = (int)pd; // okay C-style
    //i = static_cast<int>(pd); // error cannot convert
    unsigned long long ull = reinterpret_cast<unsigned long long>(pd); //This works
    //i = reinterpret_cast<int>(pd); //But this doesn't because lhs needs to be of the size enough to hold rhs
    
    std::cout << ull << std::endl;

/*  Dynamic_cast */
    /*
        dynamic_cast can only be used with pointers and references to classes
         or with void*
        Its purpose is to ensure that the result of the type conversion
        points to a valid complete object of the destination
        pointer type.
        If the pointed object is not a valid object of the target
        type, dynamic_cast returns a null pointer.
        In cases of references bad_cast exception is thrown
        
    */  


    return(0);
}