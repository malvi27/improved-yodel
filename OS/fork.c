#include<stdio.h>
#include<unistd.h>
void main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int sodd=0, seve=0;
    pid_t p_id;
    p_id = fork();
    if(p_id==0)
    {  
        while(n--){
            if (arr[n]%2!=0)
            sodd=sodd+arr[n];
        }
        printf("ODD SUM BY CHILD: %d\n",  sodd);
    }
    else if(p_id>0)
    {
        while(n--){
            if (arr[n]%2==0)
                seve=seve+arr[n];
        }
        printf("EVEN SUM BY PARENT: %d\n",  seve);
    }
    else
        printf("Fork failed\n");
}
