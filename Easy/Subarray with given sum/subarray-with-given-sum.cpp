//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int last=0;
        int start=0;
        unsigned long long sum=0;
        bool flag=false;
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum>=s)
            {
                last=i;
                while(s<sum && start<last)
                {
                    sum -= arr[start];
                    start++;
                }
                if(sum==s)
                {
                    v.push_back(start + 1);
                    v.push_back(last + 1);
                    flag = true;
                    break;
                }
            }
        }
        if(flag==false)
            v.push_back(-1);
        return v;    
    }
    
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends