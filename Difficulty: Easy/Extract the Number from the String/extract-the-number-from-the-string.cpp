//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isNumber(char ch){
        if(ch<='9' and ch>='0')return true;
        return false;
    }
    long long ExtractNumber(string str) {
        long long num=0,max=0;
        bool flag=false;
        str.push_back('.');
        for(int i=0;i<str.size();i++){
            if(!isNumber(str[i])){
                if(!flag)max=(max<num)?num:max;
                num=0;
                flag=false;
            }
            else{
                num=num*10+(str[i]-'0');
                if(str[i]=='9')flag=true;
            }
        }
        return (max==0)?-1:max;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends