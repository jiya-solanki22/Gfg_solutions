//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int N, M;
    void floodFill(vector<vector<char>> &mat, int x, int y, char prevC, char newC)
    {
        // Base cases
        if (x < 0 || x >= N || y < 0 || y >= M)
            return;
        if (mat[x][y] != prevC)
            return;
        mat[x][y] = newC;
        floodFill(mat, x+1, y, prevC, newC);
        floodFill(mat, x-1, y, prevC, newC);
        floodFill(mat, x, y+1, prevC, newC);
        floodFill(mat, x, y-1, prevC, newC);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        N = n;
        M = m;
        vector<vector<char>> temp = mat;
        for(int i = 0;i < n;i++)
		    for(int j = 0;j < m;j++)
		        if(temp[i][j] == 'O')
		            temp[i][j] = '-';
		for(int i = 0;i < n;i++)
			if(temp[i][0] == '-')
			    floodFill(temp, i, 0, '-', 'O');
		for(int i = 0;i < n;i++)
			if(temp[i][m-1] == '-')
			    floodFill(temp, i, m-1, '-', 'O');
		for(int i = 0;i < m;i++)
			if(temp[0][i] == '-')
			    floodFill(temp, 0, i, '-', 'O');
		for(int i = 0;i < m;i++)
			if(temp[n-1][i] == '-')
			    floodFill(temp, n-1, i, '-', 'O');
		for(int i = 0;i < n;i++)
			for(int j = 0;j < m;j++)
				if(temp[i][j] == '-')
				    temp[i][j] = 'X';
	    return temp;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends