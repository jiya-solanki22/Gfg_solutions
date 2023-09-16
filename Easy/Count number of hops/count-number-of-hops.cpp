//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    const int MOD = 1000000007;
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(dp[i]+dp[i-1]) % MOD;
            if(i>=2)
            {
                dp[i]=(dp[i]+dp[i-2]) % MOD;
            }
            if(i>=3)
            {
                dp[i]=(dp[i]+dp[i-3]) % MOD;
            }
        }
        return dp[n];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends