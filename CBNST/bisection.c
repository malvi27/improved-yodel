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
    double x0, x1, x2, e, r0, r1, r2;
    while(1)
    {
        printf("Enter initial guesses: ");
        scanf("%lf%lf", &x0, &x1);
        printf("Enter error: ");
        scanf("%lf", &e);
        r0=fun(x0);
        r1=fun(x1);
        if(r0>0 && r1<0 || r0<0&&r1>0)
            break;
        else printf("Try again, values don't make the proper range.\n");
    }
    printf("Name: Malvika Bisht\n Section: C\n Class Roll: 37\n");
    printf("  x0	    x1       x2\n");
    while(1)
    {
        r0=fun(x0);
        r1=fun(x1);
        x2=(x1+x0)/2;
        r2=fun(x2);
        
        if (absl(r2)<e)
            break;
        if (r0*r2==0)
            break;
        else if (r0*r2>0) x0=x2;
        else if (r0*r2<0) x1=x2;
        printf("%lf %lf %lf\n", x0,x1,x2);
    }
    printf("%lf is the approximate root", x2);
}