//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        vector<int> v;
        int diff = INT_MAX;
        int res_a = -1, res_b = -1;
        sort(brr, brr + m);
    
        for (int i = 0; i < n; i++) 
        {
            int target = x - arr[i];
            int low = 0, high = m - 1;
            while (low <= high) 
            {
                int mid = low + (high - low) / 2;
                if (brr[mid] == target) 
                {
                    v.push_back(arr[i]);
                    v.push_back(brr[mid]);
                    return v;
                }
                if (abs(brr[mid] - target) < diff) 
                {
                    diff = abs(brr[mid] - target);
                    res_a = arr[i];
                    res_b = brr[mid];
                }
                
                if (brr[mid] < target) 
                {
                    low = mid + 1;
                } 
                else 
                {
                    high = mid - 1;
                }
            }
        }
        if (res_a != -1 && res_b != -1) 
        {
            v.push_back(res_a);
            v.push_back(res_b);
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends