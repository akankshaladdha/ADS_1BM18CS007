#include<bits/stdc++.h>
using namespace std;

void secondLargest(int arr[],int n)
{
    int large = -99999;
    int secondlarge = -99999;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>large)
        {
            secondlarge = large;
            large = arr[i];
        }
        else
        {
            if(arr[i]>secondlarge)
                secondlarge = arr[i];
        }
    }
    cout<<"Elements except 2 greatest elements are"<<endl;
     for(int i = 0;i<n;i++)
     {
         if(arr[i]<secondlarge)
            cout<<arr[i]<<"  ";
     }
}
int main()
{
    int t;
    cout<<"Enter no of test cases"<<endl;
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"Enter no of elements"<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter elements"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        secondLargest(arr,n);
        cout<<endl;
    }
}


