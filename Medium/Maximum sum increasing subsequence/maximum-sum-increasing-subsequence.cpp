//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int i, j, max = 0;  
        int maxSum[n];  
        
        //Initialize msis values for all indexes
        for ( i = 0; i < n; i++ )  
            maxSum[i] = arr[i];  
        
        //Compute maximum sum values in bottom up manner
        for ( i = 1; i < n; i++ )  
            for ( j = 0; j < i; j++ )  
                if (arr[i] > arr[j] && maxSum[i] < maxSum[j] + arr[i])  
                    maxSum[i] = maxSum[j] + arr[i];  
        
        //Pick maximum of all msis values
        for ( i = 0; i < n; i++ )  
            if ( max < maxSum[i] )  
                max = maxSum[i];  
        
        return max;  
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends