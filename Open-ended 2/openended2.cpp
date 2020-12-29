#include<bits/stdc++.h>
using namespace std;

bool UniqueDigit(vector<int>arr)
{
    sort(arr.begin(), arr.end());

    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i]==arr[i+1])
            return false;
    }

    return true;
}

int main()
{

    int l,r;
    cout<<"Enter left and right extreme"<<endl;
    cin>>l>>r;
    cout<<"Nos in range having unique digits are"<<endl;
    for(int i=l;i<=r;i++)
    {
        vector<int> arr;

        int n=i,rem;

        while(n>0)
        {
            rem = n % 10;
            n /= 10;
            arr.push_back(rem);
        }

        if(UniqueDigit(arr))
        {
            cout<<i<<" ";
        }

    }
}
