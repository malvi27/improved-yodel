#include<stdio.h>
#include<unistd.h>
int main()
{
    fork();
        printf("Hello\n");
    fork();
        printf("World\n");
    return 0;
}