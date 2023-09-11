//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int max_n=INT_MIN;
        int i=0;
        int j=n-1;
        if(n==1)
        {
            return arr[0];
        }
        while(i<=j)
        {
            if(arr[i]>=arr[j] && arr[i]>max_n)
            {
                max_n=arr[i];
            }
            else if(arr[i]<arr[j] && arr[j]>max_n)
            {
                max_n=arr[j];
            }
            i++;
            j--;
        }
        return max_n;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        cout << ob.largest(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends