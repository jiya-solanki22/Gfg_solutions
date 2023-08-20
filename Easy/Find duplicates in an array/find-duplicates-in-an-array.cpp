//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int>v;
        unordered_set<int>seen;
        unordered_set<int>duplicates;
        for(int i=0;i<n;i++)
        {
            if(seen.find(arr[i])!=seen.end())
            {
                duplicates.insert(arr[i]);
            }
            seen.insert(arr[i]);
        }
        if(duplicates.empty())
        {
            v.push_back(-1);
        }
        else
        {
            for(int i: duplicates)
            {
                v.push_back(i);
            }
            sort(v.begin(),v.end());
        }
        return v;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(arr[i]==arr[j])
        //         {
        //             v.push_back(arr[j]);
        //         }
        //     }
        // }
        
        // if(v.empty())
        // {
        //     v.push_back(-1);
        // }
        // else
        // {
        //     sort(v.begin(),v.end());
        // }
        // return v;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends