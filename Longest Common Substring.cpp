//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        
        // Initialising the 2d vector
        vector<vector<int>>t(n+1,vector<int>(m+1));
        int ans=0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                t[0][j]=0;
                t[i][0]=0;
            }
        }
        // Implementing the LCS
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(S1[i-1]==S2[j-1]){
                t[i][j]=1+t[i-1][j-1];
                    ans=max(ans,t[i][j]);
                }
                else{
                    t[i][j]=0;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
