//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    vector<int> H(26,-1);
    int max=0;
    int start=-1;
    int i;
    for(i=0;i<S.size();i++)
    {
        if(H[S[i]-'a']>=start){
            max=((i-start)>max)?(i-start):max;
            start=H[S[i]-'a']+1;
            H[S[i]-'a']=i;
        }
        else{
            H[S[i]-'a']=i;
        }
    }
    return ((i-start)>max)?(i-start):max;
}