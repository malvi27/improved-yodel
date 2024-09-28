import java.util.Scanner; 
class Rearrange
{
    public static void main(String[] args)
    {
        Scanner sc= new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr= new int[n];
        for (int i=0; i<n; i++)
        {
            arr[i]=sc.nextInt();
        }
        int pvt=-1;
        for (int i=0; i<n; i++)
        {
            if(arr[i]<0)
            {
                pvt++;
                int temp=arr[i];
                arr[i]=arr[pvt];
                arr[pvt]= temp;
            }
        }
        for (int i=0; i<n; i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
}