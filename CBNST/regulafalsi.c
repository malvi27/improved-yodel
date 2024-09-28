#include<stdio.h>
double fun(double a)
{
    return ((a*a*a)-2*a-5);
}
double absl(double b)
{
    if(b<0) b=-b;
    return b;
}
void main()
{   
    double a, b, c, e, r0, r1, r2;
    while(1)
    {
        printf("Enter initial guesses: ");
        scanf("%lf%lf", &a, &b);
        printf("Enter error: ");
        scanf("%lf", &e);
        r0=fun(a);
        r1=fun(b);
        if(r0*r1<0)
            break;
        else printf("Try again, values don't make the proper range");
    }
    printf("Name: Malvika Bisht\nSec: C\nRoll No.: 37\n");
    printf("  x0	    x1     x2\n");
    while(1)
    {
        r0=fun(a);
        r1=fun(b);
        c=(a*r1-b*r0)/(r1-r0);
        r2=fun(c);
        
        if (absl(r2)<e)
            break;
        if (r0*r2==0)
            break;
        else if (r0*r2<0) b=c;
        else if (r1*r2<0) a=c;
        printf("%lf %lf %lf\n", a,b,c);
    }
    printf("%lf is the approximate root", c);
}