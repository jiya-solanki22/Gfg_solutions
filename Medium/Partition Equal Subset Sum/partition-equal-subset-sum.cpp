//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int cal(int node, int a[], int cur, int sum, int n, vector<vector<int>> &dp)
    {
        if(node >= n){
            if(cur*2 != sum) 
                return 0;
            else 
                return 1;
        }
        if(cur*2 > sum) 
            return dp[node][cur] = 0;
        if(cur*2 == sum) 
            return dp[node][cur] = 1;
        if(dp[node][cur] != -1) 
            return dp[node][cur];
        int f = 0;
        f = cal(node+1, a, cur+a[node], sum, n, dp) | cal(node+1, a, cur, sum, n, dp);
        
        return dp[node][cur] = f;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0;i < N;i++)
            sum += arr[i];
        vector<vector<int>> dp(N, vector<int>(sum+1, -1));
        int x = cal(0, arr, 0, sum, N, dp);
        return x;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends