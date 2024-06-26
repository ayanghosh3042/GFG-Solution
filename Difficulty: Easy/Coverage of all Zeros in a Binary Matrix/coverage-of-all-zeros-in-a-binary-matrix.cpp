//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int Coverage(int i,int j,vector<vector<int>>& mat){
        int count=0;
        count=((i!=0)?mat[i-1][j]:0)+((i!=mat.size()-1)?mat[i+1][j]:0)
        +((j!=0)?mat[i][j-1]:0)+((j!=mat[0].size()-1)?mat[i][j+1]:0);
        return count;
    }
    int findCoverage(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(!mat[i][j]){
                    count+=Coverage(i,j,mat);
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends