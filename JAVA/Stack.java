class FixedStack
{
    private int stck[];
    private int top;
    FixedStack( int size)
    {
        stck=new int[size];
        top=-1;
    }
    public void push(int item)
    {
        if (top==stck.length)
        {
            System.out.println("FULL");
        }
        else
            stck[++top]=item;
    }
    public int pop()
    {
        if (top==-1)
        {
            System.out.println("Stack Underflow");
            return -1;
        }
        else 
        {
            return stck[top--];
        }
    }
}

class Stack
{
    public static void main(String[] args)
    {
        FixedStack fs= new FixedStack(12);
        int i=0,n;
        for (i=0; i<12; i++)
        {
            fs.push(i);
        }
        for (i=0; i<12; i++)
        {
            n= fs.pop();
            System.out.println(n);
        }

    }
}