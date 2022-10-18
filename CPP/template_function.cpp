#include <iostream>
#include <cstring>

template<class T>
T Max(T x, T y)
{
    return(x > y ? x : y);
}

template<> // Template specialization for 'char*' type
char* Max<char*>(char* x, char* y)
{
    return(strcmp(x,y) > 0 ? x : y);
}

template<class T*, size_t>
T Max(T* arr, size_t size)
{
    if(size < 1)
        return((T)0);
    
    for(int i = 1, t = T[0]; i < size; ++i)
    {
        if(t < arr[i])
        {
            t = arr[i];
        }
    }
    return(t);
}

int main()
{
    int a = 45;
    int b = 676;

    double p = 23.675;
    double q = 23241.23;

    char* g = const_cast<char*>("black");
    char* h = const_cast<char*>("white");

    int ia[] = {10, 20, 5};
    double da[] = {3.14};
    int *pia = ia;
    double* pda = da;
    std::cout << Max(a,b) << std::endl;
    std::cout << Max(p,q) << std::endl;
    std::cout << Max(g, h) << std::endl;
    std::cout << Max<int, size_t>(pia, sizeof(ia)/sizeof(ia[0]));

    return(0);
}

