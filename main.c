#include <stdio.h>
    struct D
    {
        char c;
        int i;
        float f;
        short s;
    };
    
    struct D obj1 = {'A', 1, 3.14f, 23};
    struct D obj2;

int main()
{

    obj2 = obj1;

    int A[5];
    printf("address of A = %llu, &A = %llu, A+1 = %llu\n", (unsigned long long)A, (unsigned long long)&A, (unsigned long long)(&A + 1) );
    return 0;

}