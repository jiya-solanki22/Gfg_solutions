//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rowSum(n,0);
        vector<int> colSum(n,0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }
        int maxSum = 0;
        for (int i = 0; i < n; ++i)
        {
            maxSum = max(maxSum, rowSum[i]);
            maxSum = max(maxSum, colSum[i]);
        }
        int count = 0;
        for (int i = 0, j = 0; i < n && j < n;) 
        {
            int diff = min(maxSum - rowSum[i],  maxSum - colSum[j]);
            matrix[i][j] += diff;
            rowSum[i] += diff;
            colSum[j] += diff;
            count += diff;
            if (rowSum[i] == maxSum)
                ++i;
            if (colSum[j] == maxSum)
                ++j;
        }
        return count;
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
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends