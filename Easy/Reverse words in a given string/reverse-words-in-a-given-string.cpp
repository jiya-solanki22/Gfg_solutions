//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n = S.length();
        string str = "";
        
        for (int i = n - 1; i >= 0; i--)
        {
            if (S[i] == '.')
            {
                int j = i + 1;
                while (j < n && S[j] != '.')
                {
                    str += S[j];
                    j++;
                }
                str += '.';
            }
            else if (i == 0)
            {
                int j = 0;
                while (j < n && S[j] != '.')
                {
                    str += S[j];
                    j++;
                }
            }
        }
        
        return str;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends