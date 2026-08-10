#include<iostream>
using namespace std;
void counting(int a[],int n)
{
    int zero=0,one=0,two=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
            one++;
        else if(a[i]==2)
                two++;
        else
            zero++;
    }

   int i=0;
   while(zero--)
   {
       a[i]=0;
       i++;
   }
   while(one--)
   {
       a[i]=1;
       i++;
   }
   while(two--)
   {
       a[i]=2;
       i++;
   }
   for(int i=0;i<n;i++)
    cout<<a[i]<<"\t";
}


    int main()
    {
        int arr[]={0,1,2,1,2,1,2,1,0,0,0,1,2,1,2};
        int n=sizeof(arr)/sizeof(arr[0]);
        counting(arr,n);

    }
