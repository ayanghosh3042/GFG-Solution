//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], int l,int mid,int u){
        int i=l,j=mid+1;
        int k=0;
        long long count=0;
        long long int *v=new long long int[u-l+1];
        while(i<=mid && j<=u){
            if(arr[i]<=arr[j]){
                v[k++]=arr[i++];
                
            }
            else{
                v[k++]=arr[j++];
                count+=(mid-i+1);
            }
        }
        while(i<=mid){
            v[k++]=arr[i++];
        }
        while(j<=u){
            v[k++]=arr[j++];
            count+=(mid-i+1);
        }
        
        for(int i=l;i<=u;i++){
            arr[i]=v[i-l];
        }
        delete []v;
        return count;
    }
    long long int mergeSort(long long arr[], long long l,long long u){
        long long int x=0,y=0,z=0;
        if(l<u){
            long long mid=(l+u)/2;
            x=mergeSort(arr,l,mid);
            y=mergeSort(arr,mid+1,u);
            z=merge(arr,l,mid,u);
        }
        return x+y+z;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long x=mergeSort(arr,0,N-1);
        // for(int i=0;i<N;i++){
        //     cout<<arr[i]<<" ";
        // }
        return x;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends