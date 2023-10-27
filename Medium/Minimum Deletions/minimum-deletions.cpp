//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lps(string S) { 
        int n = S.size(); 
        int L[n][n]; 
        // Initializing the diagonal elements of the matrix to 1
        for (int i = 0; i < n; i++) 
            L[i][i] = 1; 
        // Filling the remaining elements of the matrix
        for (int cl = 2; cl <= n; cl++) { 
            for (int i = 0; i < n - cl + 1; i++) { 
                int j = i + cl - 1; 
                // If the characters at both positions are same and the length is 2
                if (S[i] == S[j] && cl == 2) 
                    L[i][j] = 2; 
                // If the characters at both positions are same
                else if (S[i] == S[j]) 
                    L[i][j] = L[i + 1][j - 1] + 2; 
                // If the characters at both positions are different
                else
                    L[i][j] = max(L[i][j - 1], L[i + 1][j]); 
            } 
        } 
        // Returning the length of the longest palindromic subsequence
        return L[0][n - 1]; 
    } 
    
    // Function to find the minimum number of deletions required to make a string palindrome
    int minimumNumberOfDeletions(string S) { 
        int n = S.size(); 
        // Finding the length of the longest palindromic subsequence
        int len = lps(S); 
        // Returning the minimum number of deletions required
        return (n - len); 
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends