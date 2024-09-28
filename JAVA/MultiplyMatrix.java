import java.util.Scanner;
class MultiplyMatrix
{
    public static int[][] matrixMultiply(int[][] m1, int r, int[][] m2, int c, int x)
    {
        int [][] result= new int[r][c];
        int i=0, j=0, k=0;
        for (i=0; i<r; i++)
        {
            for (j=0; j<c; j++)
            {
                for (k=0; k<x; k++)
                {
                    result[i][j]+= m1[i][k] * m2[k][j];
                }
            }
        }
        return result;
    }
    public static void main(String[] args)
    {
        int[][] a;
        int[][] b;
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the number of rows and number of columns: ");
        int r1= sc.nextInt();
        int c1= sc.nextInt();
        int r2= sc.nextInt();
        int c2= sc.nextInt();
        a= new int[r1][c1];
        b= new int[r2][c2];
        if (c1==r2)
        {
            int i=0,j=0;
            System.out.println("ARRAY A: ");
            for (i=0; i< r1; i++ )
            {
                System.out.println("Input row: "+i);
                for (j=0; j<c1; j++)
                {
                    a[i][j]=sc.nextInt();
                }
            }

            System.out.println("\nARRAY B: ");
            for (i=0; i< r2; i++ )
            {
                System.out.println("Input row: "+i);
                for (j=0; j<c2; j++)
                {
                    b[i][j]=sc.nextInt();
                }
            }
            int[][] result =matrixMultiply(a, r1, b, c2, r2);
            System.out.println("\n The new Array after multiplication is: ");
            for (i=0; i< r1; i++ )
            {
                for (j=0; j<c2; j++)
                {
                    System.out.print(result[i][j]+" ");
                }
                System.out.println(" ");
            }
        }
        else
        {
            System.out.println("Matrix Multiply not possible");
        }
    }
}