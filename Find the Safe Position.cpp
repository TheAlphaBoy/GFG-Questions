//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int n,int k,int sword,vector<int>&ans){
      // BC
      if(ans.size()==1){
          return ans[0];
      }
      ans.erase(ans.begin()+(sword+k-1)%ans.size());
      solve(n,k,(sword+k-1)%(ans.size()+1),ans);
  }
    int safePos(int n, int k) {
        // code here
        
        vector<int>ans;
        for(int i=0;i<n;i++) {
            ans.push_back(i+1);
        }
        // sword is used to represent killing index
        int sword=0;
        return solve(n,k,sword,ans);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends
