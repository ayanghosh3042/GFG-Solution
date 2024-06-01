//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        int H[26]={0};
        for(int i=0;i<s.size();i++){
            H[s[i]-'a']++;
        }
        int x=0,y=0;
        for(int i=0;i<26;i++){
            if(!H[i])continue;
            if(i%2==0 && H[i]%2==1){
                y++;
            }
            else if(i%2 && H[i]%2==0){
                x++;
            }
        }
        return ((x+y)%2)?"ODD":"EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends