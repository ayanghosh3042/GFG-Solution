//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minDeletions(int arr[], int n) 
	{ 
	    int dp[n];
	    dp[0]=1;
	    int len=1;
	    for(int i=1;i<n;i++){
	        dp[i]=1;
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i] && dp[i]<dp[j]+1){
	                dp[i]=dp[j]+1;
	            }
	        }
	        len=(len<dp[i])?dp[i]:len;
	    }
	    return n-len;
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

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

	    

	    Solution ob;
	    cout << ob.minDeletions(arr, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends