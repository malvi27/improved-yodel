import java.util.*;
class Pattern01
{
    public static void main(String[] args)
    {
        Scanner sc= new Scanner(System.in);
        String s=sc.nextLine();
        int n=s.length();
        int count=0, flag=0, i=0;
        s=s+" ";
        while(i<n)
        {
            if (s.charAt(i)=='0') 
                flag=0;
            else
                flag=1;
            if(i!=n)
            {
                if(s.charAt(i)==48 && s.charAt(i+1)==49)
                {
                    count++;
                }
            }
            i++;
        }
        if(flag==1)
            count--;
        System.out.println(count);
        sc.close();
    }
}
