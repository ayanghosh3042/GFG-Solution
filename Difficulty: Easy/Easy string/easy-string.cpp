//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string S){
    if(S[0]<='Z'){
            S[0]=S[0]-'A'+'a';
        }
    char pre=S[0];
    int count=1;
    string str;
    for(int i=1;i<S.size();i++){
        if(S[i]<='Z'){
            S[i]=S[i]-'A'+'a';
        }
        if(S[i]==pre){
            count++;
        }
        else{
            str+=to_string(count);
            str.push_back(pre);
            pre=S[i];
            count=1;
        }
    }
    str+=to_string(count);
    str.push_back(pre);
    return str;
}

