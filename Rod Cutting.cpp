//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        // It's a question of Unbounded Knapsack
        
        int w=n;
        int len[n];
        
        // indexing is 1-based
        for(int i=1;i<=n;i++){
            len[i]=i;
        }
        // Initiallising the dp s per conditions in question 
        vector<vector<int>>t(n+1,vector<int>(w+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(len[i]<=j){
                    t[i][j]=max(price[i-1]+t[i][j-len[i]] , t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][w];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
