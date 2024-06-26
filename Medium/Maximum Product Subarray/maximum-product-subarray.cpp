//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    if(n==1)return arr[0];
	    long long int maxi=1,mini=1;
	    long long int max_pro=INT_MIN;
	    int amax=-1;
	    for(int i=0;i<n;i++){
	        if(arr[i]>0){
	            maxi*=arr[i];
	            mini=min(mini*arr[i],(long long)1);
	        }
	        else if(arr[i]==0){
	            maxi=mini=1;
	        }
	        else{
	            long long t=maxi;
	            maxi=max(mini*arr[i],(long long)1);
	            mini=t*arr[i];
	        }
	        max_pro=max(max_pro,maxi);
	        amax=max(amax,arr[i]);
	    }
	    return (max_pro==1 && amax==0)?0:max_pro;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends