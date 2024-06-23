//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.size()!=str2.size())return false;
        
        char H[26]={0};
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                if(H[str1[i]-'a']==0)H[str1[i]-'a']=str2[i];
                else if(H[str1[i]-'a']!=str2[i])return false;
            }
        }
        char H1[26]={0};
        for(int i=0;i<str2.size();i++){
            if(str1[i]!=str2[i]){
                if(H1[str2[i]-'a']==0)H1[str2[i]-'a']=str1[i];
                else if(H1[str2[i]-'a']!=str1[i])return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends