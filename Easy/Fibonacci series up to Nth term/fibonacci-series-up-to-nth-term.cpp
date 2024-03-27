//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        int t1=0,t2=1,t;
        int mod=1e9+7;
        vector<int> v;
        for(int i=0;i<=n;i++){
            v.push_back(t1);
            t=(t2%mod+t1%mod)%mod;
            t1=t2;
            t2=t;
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends