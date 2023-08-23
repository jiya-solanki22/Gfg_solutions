//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> results;
        set<pair<int, int>> resultSet;
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };
        for (int x = 0; x < n; x++) 
        {
            for (int y = 0; y < m; y++) 
            {
                for (const auto& direction : directions) 
                {
                    if (dfs(grid, word, x, y, 0, direction)) 
                    {
                        resultSet.insert({x, y});
                    }
                }
            }
        }
        for (const auto& coord : resultSet) 
        {
            results.push_back({coord.first, coord.second});
        }
        return results;
	}
private:
    bool dfs(vector<vector<char>>& grid, const string& word, int x, int y, int index, const vector<int>& direction) {
        int n = grid.size();
        int m = grid[0].size();

        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != word[index]) {
            return false;
        }

        if (index == word.size() - 1) {
            return true;
        }

        int dx = direction[0];
        int dy = direction[1];
        int newX = x + dx;
        int newY = y + dy;

        return dfs(grid, word, newX, newY, index + 1, direction);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends