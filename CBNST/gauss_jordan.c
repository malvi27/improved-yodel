#include<stdio.h>
int n;
void convertToDiagonal(float a[][n+1], int n)
{
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                ratio=a[j][i]/a[i][i];
                for(k=0;k<n+1;k++)
                    a[j][k]=a[j][k] - (ratio*a[i][k]);

                printf("ALTERATION:\n");
                for( x=0;x<n;x++)
                {
                for(y=0;y<n+1;y++)
                    printf("%f ",a[x][y]);
                printf("\n");   
                }
                printf("\n");
                
            } 
        }
    }
}

void printValue(float a[][n+1],int n)
{  
    int i;
    printf("Values of unknowns are:\n");
    for(i=0;i<n;i++)
        printf("Value of Variable %d=%f\n",i,a[i][n]/a[i][i]);
   
}

int main()
{
    int i,j,k,x,y;
    float ratio;

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
    convertToDiagonal(a,n);
    printf("Diagonal Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
            printf("%.2f  ",a[i][j]);
        printf("\n");
    }
    printf("\n");
    printValue(a,n); 
    return 0;
}