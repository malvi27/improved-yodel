#include<stdio.h>
double fun(double a)
{
    return ((a*a*a)-5*a+1);
}
double absl(double b)
{
    if(b<0) b=-b;
    return b;
}
void main()
{   
    double x0, x1, x2, e, r0, r1, r2; int N;
    printf("Enter initial guesses: ");
    scanf("%lf%lf", &x0, &x1);
    printf("Enter error: ");
    scanf("%lf", &e);
    printf("Enter no. of Iterations: ");
    scanf("%d", &N);
    int i=0;
    printf("Name: Malvika Bisht\nSection: C\nRoll No.: 37\n");
    printf("\t\t x0	    x1       x2\n");
    while(i<N)
    {
        r0=fun(x0);
        r1=fun(x1);

        x2=(x0*r1-x1*r0)/(r1-r0);
        r2=fun(x2);
        printf("Iteration %d: %lf %lf %lf\n", i+1,x0,x1,x2);
        if (absl(r2)<e)
            break;
        else 
        {
            x0=x1;
            x1=x2;
        };
        
        i++;
    }
    if(absl(r2)>e)
    {
        printf("NOT CONVERGENT!!!");
    }
    else printf("%lf is the approximate root", x2);
}