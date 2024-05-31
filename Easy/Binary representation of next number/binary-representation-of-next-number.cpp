//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        string add;
        int sum=0,carry=1;
        for(int i=s.size()-1;i>=0;i--){
            sum=(s[i]-'0')+carry;
            carry=sum/2;
            sum%=2;
            add.push_back(sum+'0');
        }
        if(carry)add.push_back('1');
        while(add.size() && add[add.size()-1]=='0'){
            add.pop_back();
        }
        reverse(add.begin(),add.end());
        return add;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends