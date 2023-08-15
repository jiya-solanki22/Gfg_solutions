//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxSubArraySum(int a[],int n)
    {
       int maxSum=a[0];
       int curr=a[0];
       for(int i=1;i<n;i++)
       {
            curr=max(a[i],curr+a[i]);
            maxSum=max(maxSum,curr);
       }
       maxSum=max(0,maxSum);
       return maxSum;
    }
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int i, count=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
                a[i]=1;
            else
            {
                count++;
                a[i]=-1;
            }
        }
        return (count+maxSubArraySum(a,n));
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends