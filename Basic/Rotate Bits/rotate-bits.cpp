//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            vector<int>v (2);
            d = d % 16;
            //rotate to the left
            int temp = n;
            int mask = (1 << d) - 1;
            int shift = (temp & mask); 
            temp = (temp >> d);
            temp += (shift << (16 - d));
            v[1] = temp;
            //rotate to the right
            temp = n;
            mask = ~((1 << (16 - d)) - 1);
            shift = (temp & mask);
            temp = (temp << d);
            temp += (shift >> (16 - d));
            v[0] = temp;
        
            mask = (1 << 16) - 1;
    		v[0] = (v[0] & mask);
    		
            return v;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends