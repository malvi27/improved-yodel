#include<stdio.h>
#include<math.h>
double fun(double a)
{
    return (cos(a)-a*exp(a));
}
double fun_(double a)
{
    return (-sin(a)-exp(a)*(a+1));
}
double absl(double b)
{
    if(b<0) b=-b;
    return b;
}
void main()
{   
    double x0, x1, x2, x, e, r0, r1, r2;
    while(1)
    {
        printf("Enter initial guesses: ");
        scanf("%lf%lf", &x0, &x1);
        printf("Enter error: ");
        scanf("%lf", &e);
        r0=fun(x0);
        r1=fun(x1);
        if (r0*r1<0)
        {
            x=(x0+x1)/2;
            printf("The selected guess is %lf\n", x);
            break;
        }
        printf("No interval found, try guessing again!\n");   
    }
    int i=0;
    printf("OUTPUT\nName: Malvika Bisht\nSection: C\nRoll No.: 37\n");
    printf("\t\t X\n");
    while(1)
    {
        r0=fun(x);
        r1=fun_(x);
        x=x-r0/r1;
        r2=fun(x);
        printf("Iteration %d: %lf\n", i+1,x);
        if (absl(r2)<e || r2==0)
            break;
        i++;
    }
    printf("%lf is the approximate root", x);
}