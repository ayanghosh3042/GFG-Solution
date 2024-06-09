//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution1 {
    
public:
    string longestPalindrome(string s) {
        bool dp[s.size()][s.size()]={0};
        for(int i=0;i<s.size();i++)dp[i][i]=1;
        int st=0,end=0;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                st=i;
                end=i+1;
            }
        }
        int i;
        for( i=2;i<s.size();i++){
            for(int j=s.size()-i;j>=0;j--){
                if(s[j]==s[j+i] && dp[j+1][j+i-1]){
                    dp[j][j+i]=1;
                    st=j;
                    end=j+i;
                }
            }
        }
        
        string str;
        for(int i=st;i<=end;i++){
            str.push_back(s[i]);
        }
        return str;
    }
};

class Solution {
  public:
    string longestPalin (string S) {
        Solution1 s;
        return s.longestPalindrome(S);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends