#include<stdio.h>
#include<math.h>

int main()
{
    float x,u1,u,y;
    int i,j,n,fact, interval=0, uniform=1;
    printf("Enter no. of terms\n");
    scanf("%d",&n);
    float a[n][n+1];
    printf("Enter Values of X\n");
    for(i=0;i<n;i++)
          scanf("%f",&a[i][0]);
    printf("Enter Values of Y\n");
    for(i=0;i<n;i++)
          scanf("%f",&a[i][1]); 

    //Check for uniformity of intervals
    interval = a[1][0] - a[0][0];
    for(i = 1; i < n - 1; i++) {
        if((a[i+1][0] - a[i][0]) != interval) {
            uniform = 0;
            break;
        }
    }

    if (!uniform) //If x intervals are not uniform, we don't want to move forward.
    {
        printf("The intervals of X are not uniform. Exiting program.\n");
        return 0;
    }
    printf("Enter value of x for which you want y : ");
    scanf("%f",&x);
  
    for(j=2;j<n+1;j++)
    {
        for(i=0;i<n-j+1;i++)
            a[i][j] = a[i+1][j-1]-a[i][j-1];
    }

    printf("\n\nThe Difference Table is as follows:\n");
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n-i;j++)
            printf("%.0f ",a[i][j]);
        printf("\n");
    }

    u= (x - a[0][0])/(a[1][0]-a[0][0]);
    printf("\nu= %f\n", u);
    y=a[0][1]; 
    u1=u;
    fact=1;
    for(i=2;i<=n;i++)
    {
        y=y+(u1*a[0][i])/fact;
        fact=fact*i; 
        u1=u1*(u-(i-1));
    }
    printf("\n\nApproximate value at X=%g is = %f", x,y);


}