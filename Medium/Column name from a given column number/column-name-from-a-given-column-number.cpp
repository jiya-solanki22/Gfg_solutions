//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string res = "";
    	int temp;
    	while (n)
    	{
    	    n--;
    		temp = n % 26;
    		res += ('A' + temp);
    		n /= 26;
    	}
    	reverse (res.begin (), res.end ());
    	return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends