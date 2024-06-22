//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        int num=0;
        vector<int> v; 
        for(int i=0;i<str.size();i++){
            if(str[i]==','||str[i]=='/'){
                v.push_back(num);
                num=0;
                if(str[i]==',')i++;
            }
            else{
                num=num*10+(str[i]-'0');
            }
        }
        v.push_back(num);
        
        float flag=float(v[0]*v[3])/float(v[1]*v[2]);
        // cout<<flag;
        
        string ans;
        if(flag>1){
            for(int i=0;str[i]!=',';i++){
                ans.push_back(str[i]);
            }
            return ans;
        }
        else if(flag<1){
            int i;
            for(i=0;str[i]!=' ';i++);
            i++;
            while(i<str.size()){
                ans.push_back(str[i]);
                i++;
            }
            return ans;
        }
        else return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends