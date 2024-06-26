//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void Coverage(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& temp){
        int count=0;
        count=((i!=0)?mat[i-1][j]:0)+((i!=mat.size()-1)?mat[i+1][j]:0)
        +((j!=0)?mat[i][j-1]:0)+((j!=mat[0].size()-1)?mat[i][j+1]:0);
        
        temp[i][j]=count;
        if(i!=0)temp[i-1][j]=0;
        if(i!=temp.size()-1)temp[i+1][j]=0;
        if(j!=0)temp[i][j-1]=0;
        if(j!=temp[0].size()-1)temp[i][j+1]=0;
    }
    void MakeZeros(vector<vector<int> >& mat) {
        vector<vector<int>> temp(mat.size(),vector<int> (mat[0].size()));
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                temp[i][j]=mat[i][j];
            }
        }
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(!temp[i][j]){
                    Coverage(i,j,temp,mat);
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends