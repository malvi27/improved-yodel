#include<stdio.h>
#include <stdlib.h>
#include<math.h>
double fun(double a)
{
    return (cos(a)-3*a+1);
}

double f(double a)
{
    return (cos(a)+1)/3;
}

double f2(double a)
{
    return (acos(3*a-1));
}

double absl(double b)
{
    if(b<0) b=-b;
    return b;
}

double f_(double a)
{
    return absl(sin(a)/3);
}

double f2_(double a)
{
    return absl(3/(sqrt(1-pow((3*a-1),2))));
}

void main()
{   
    double a, b, c,c_, e, r0, r1, r2;
    int flag;
    while(1)
    {
        printf("Enter initial guesses: ");
        scanf("%lf%lf", &a, &b);
        printf("Enter error: ");
        scanf("%lf", &e);
        r0=fun(a);
        r1=fun(b);
        if(r0>0 && r1<0 || r0<0&&r1>0)
        {
            if ((f_(a)<1 && f2_(a)>=1) || (f_(a)<1 && f2_(a)<1 && f_(a)<f2_(a)))
            {
                a=(a+b)/2;
                printf("Initial guess= %lf\n",a);
                flag=0;
                break;
            }       
            else if ((f2_(a)<1 && f_(a)>=1) || (f_(a)<1 && f2_(a)<1 && f_(a)<f2_(a)))
            {
                a=(a+b)/2;
                printf("Initial guess= %lf\n",a);
                flag=1;
                break;
            }
            else exit(0);
        }
        else printf("Try again, values don't make the proper range");

    }
    printf("Name: Malvika Bisht\nSec: C\nRoll No.: 37\n");
    printf("Value of phi1'(x0)=%lf\nValue of phi2'(x0)=%lf\n\n", f_(a), f2_(a));
    printf("Iteration\t x\n");
    int count=0;
    while(1)
    {
        count++;
        if (flag==0)
        {
            c=f(a);
            c_=f_(a);
        }
        else
        {
            c=f2(a);
            c_=f2_(a);
        }
        r2=fun(c);
        printf("-> %d: \t\t%lf\n",count,c);
        if (absl(r2)<e)
            break;
        a=c;
        
    }
    printf("%lf is the approximate root after %d iterations", c, count);
}