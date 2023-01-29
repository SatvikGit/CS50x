#include <stdio.h>

int main()
{
    int k = 5;
    printf("%i\n", *(&k));
    return 0;
}