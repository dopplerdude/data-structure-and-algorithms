#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int* square(int*, int);

int main()
{
    printf("Hello world!\n");
    int in[7] = {-70, -50, -10, 5, 50, 65, 70};
    int* out = square(&in[0], sizeof(in)/ sizeof(in[0]));
    int idx;
    for(idx = 0; idx < 7; idx++)
    {
        printf("%d ", out[idx]);
    }
    free(out);
    printf("\n");

    struct A
    {
        int a;
        char c;
    };

    struct B
    {
        int *a;
        char c;
    };

    struct C
    {
        short a;
        char c;
    };

    struct foo10 {
    char c1;
    int a;
    int b;
    char c;
    struct foo10 *p;
    short x;    
    }foo[2];

    printf("sizeof(A) = %llu\n", sizeof(struct A));
    printf("sizeof(B) = %llu\n", sizeof(struct B));
    printf("sizeof(C) = %llu\n", sizeof(struct C));
    printf("sizeof(foo10) = %llu\n", sizeof(struct foo10)); 
    printf("&foo.c1 = %llu, &foo.a = %llu, &foo.b = %llu, &foo.c = %llu, &foo.p = %llu, &foo.x = %llu, &foo[1].c1 = %llu\n",
    &foo[0].c1, &foo[0].a, &foo[0].b, &foo[0].c, &foo[0].p, &foo[0].x, &foo[1].c1);
    printf("Sizeof(long int) = %u\n", sizeof(long int));
    return(0);
}

int* square(int* in, int len)
{
    int temp = abs(in[0]), tmp;
    int idx, odx;
    int* out = (int*)malloc(len * sizeof(int));
    for(odx = 0; odx < len; odx++)
    {
        idx = 0;
        for(; (idx + 1) < len; idx++)
        {
            if(abs(in[idx]) > abs(in[idx+1]))
            {
                temp = in[idx];
                in[idx] = in[idx + 1];
                in[idx + 1] = temp;
            }
        }
        
    }
    for(idx = 0; idx < len; idx++)
        out[idx] = in[idx] * in[idx];

    return(out);
}

