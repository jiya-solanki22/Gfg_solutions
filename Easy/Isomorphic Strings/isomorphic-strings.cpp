//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        int n1=str1.length();
        int n2=str2.length();
        if(n1!=n2)
            return false;
        unordered_map<char, char> mapping;
        unordered_set<char> usedChars;

        for (size_t i = 0; i < str1.size(); ++i) {
        char char1 = str1[i];
        char char2 = str2[i];

        if (mapping.find(char1) != mapping.end()) {
            if (mapping[char1] != char2) {
                return false;
            }
        } else {
            if (usedChars.find(char2) != usedChars.end()) {
                return false;
            }
            mapping[char1] = char2;
            usedChars.insert(char2);
        }
    }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends