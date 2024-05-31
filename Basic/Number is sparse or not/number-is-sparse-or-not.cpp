//{ Driver Code Starts
//Initial Template for C++

// C++ program to check if n is sparse or not
#include<iostream>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to check if the number is sparse or not.
    bool isSparse(int n)
    {
        int flag=0;
        int i;
        while(n){
            i=n%2;
            n/=2;
            if(flag && i){
                return 0;
            }
            else if(i && !flag){
                flag=1;
            }
            else{
                flag=0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t,n;
    
    //testcases
    cin>>t;
    while(t--)
    {
        //initializing n
        cin>>n;
        
        //printing 1 if isSparse() returns true
        //else 0
        Solution ob;
        if(ob.isSparse(n)){
            cout << "1" << endl;
        }
        else cout << "0" << endl;
        
    }
    return 0;
}

// } Driver Code Ends