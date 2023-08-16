//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    const int MOD = 1000000007;
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        if (n == 0) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) 
        {
            for (int j = 0; j < i; ++j) 
            {
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i - j - 1]) % MOD) % MOD;
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends