#include<stdio.h>

int n;
void UpperTriangular(float a[][n+1],int n)
{
    int i,j,x,y,k;
    float ratio; int count=0;
    for( i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j>i)
            {
                count++;
                ratio=a[j][i]/a[i][i];
                for(k=0;k<n+1;k++)
                    a[j][k]=a[j][k] -( ratio * a[i][k]);

                printf("ALTERATION %d:\n", count);
                for( x=0;x<n;x++)
                {
                for(y=0;y<n+1;y++)
                    printf("%.2f ",a[x][y]);
                printf("\n");   
                }
                printf("\n");
                
            } 
        }
     }
}

void BackSubstitution(float a[][n+1],float value[],int n)
{   
    int i,j;
    float sum;
    value[n-1]=a[n-1][n]/a[n-1][n-1]; 

    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
            sum=sum+a[i][j]*value[j];  
        value[i] = (a[i][n]-sum)/a[i][i];
    } 
}

void print(float value[],int n)
{  
    int i;
    printf("Values of unknowns are:\n");
    for(i=0;i<n;i++)
        printf("Value[%d]=%f\n",i,value[i]);
    
}

int main()
{
    int i,j,k,x,y;
    float sum,ratio;
    printf("Enter the order of matrix:\n");
    scanf("%d",&n);
    float a[n][n+1],value[n];
    printf("Enter the Augmented Matrix\n");
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n+1;j++)
            scanf("%f",&a[i][j]);
    }

    printf("\nName: Malvika Bisht\nSection: C\nRoll No.: 37\n\n");
    printf("Intermediate Matrix Transformation:\n ");
    UpperTriangular(a,n);
    printf("UTM:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
            printf("%.2f  ",a[i][j]);
        printf("\n");
    }
    printf("\n");
    printf("Backward Substitution:\n");
    BackSubstitution(a,value,n);
    print(value,n); 
    return 0;
}
