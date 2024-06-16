//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void SieveOfEratosthenes(int n,vector<int>& v)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        prime[0] = false;
        prime[1] = false;
 
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
 
        for(int i=2;i<=n;i++){
            if(prime[i]){
                v.push_back(i);
            }
        }
        return;
    }
 
    vector<int> getPrimes(int n) {
        vector<int> v;
        SieveOfEratosthenes(n,v);
        
        int i=0,j=v.size()-1;
        long long sum;
        while(i<j){
            sum=v[i]+v[j];
            if(sum==n){
                return {v[i],v[j]};
            }
            else if(sum<n){
                i++;
            }
            else{
                j--;
            }
        }
        if(i==j && v[i]*2==n)return{v[i],v[i]};
        
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends