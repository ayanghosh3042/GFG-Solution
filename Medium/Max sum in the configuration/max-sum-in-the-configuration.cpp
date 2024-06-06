//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        long long cur_sum=0;
        long long add=0;
        for(int i=0;i<n;i++){
            add+=a[i];
            cur_sum+=(long long)a[i]*(long long)i;
        }
            
        long long max=cur_sum;
        long long num=n;
        for(int i=1;i<num;i++){
            cur_sum+=-(add)+num*((long long)a[i-1]);
            max=(max<cur_sum)?cur_sum:max;
        }
        return max;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends