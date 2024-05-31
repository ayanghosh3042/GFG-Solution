//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	unsigned int L0=0;
    	unsigned int L1=0;
    	for(int i=1;i<32;i+=2){
    	    L0+=1<<i;
    	    L1+=1<<(i-1);
    	}
    	L1&=n;
    	L0&=n;
    	L1<<=1;
    	L0>>=1;
    	return (L1|L0);
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends