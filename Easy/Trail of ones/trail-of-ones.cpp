//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int modpower(int x, int n, int m) 
{
    if (n == 0) //base case 
        return 1%m; 
    long long u = modpower(x,n/2,m);  
    u = (u*u)%m;
    if (n%2 == 1) //when 'n' is odd
        u = (u*x)%m;
    return u;
}
    int numberOfConsecutiveOnes(int n) {
        int dp[n+1];
        dp[1]=2;
        dp[2]=3;
        int mod=1e9+7;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
        }
        return (modpower(2,n,mod)-dp[n]+mod)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends