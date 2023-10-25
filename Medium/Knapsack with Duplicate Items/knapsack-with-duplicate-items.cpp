//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> dp(W+1 , 0);
		int ans =0;

		// looping through each weight
		for(int i=0; i<W+1; i++)
			// looping through each item
			for (int j=0; j<N; j++)
				// checking if current weight is less than or equal to the maximum weight
				if(wt[j]<= i)
					// updating the maximum value for the current weight
					dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
		// returning the maximum value for the maximum weight
		return dp[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends